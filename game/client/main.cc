#include "client/pch.hh"

#include "client/main.hh"

#include "common/config/map.hh"
#include "common/debug/assert.hh"
#include "common/utils/epoch.hh"

#include "client/game.hh"
#include "client/globals.hh"
#include "client/render.hh"

void client::main(void)
{
    glfwSetErrorCallback([](int error_code, const char* message) {
        spdlog::error("GLFW[{}]: {}", error_code, message);
    });

#if defined(__unix__)
    // Wayland constantly throws random bullshit at me
    // when I'm dealing with pretty much anything cross-platform
    // on pretty much any kind of UNIX and Linux distribution
    glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_X11);
#endif

    qf_force_assert_msg(glfwInit(), "GLFW: glfwInit() failed");

    render_impl::setupWindowing();

    globals::window = glfwCreateWindow(640, 480, "QFengine", nullptr, nullptr);
    qf_force_assert_msg(globals::window, "GLFW: glfwCreateWindow() failed");

    render_impl::initialize();

    // Setup fixed frametime so that the game doesn't
    // tick until the player joins the game
    globals::fixed_frametime_us = UINT64_MAX;
    globals::fixed_frametime_avg = 0.0;
    globals::fixed_frametime = 0.0;
    globals::fixed_framecount = 0;

    // Initial frametime state
    globals::frametime_us = 0;
    globals::frametime_avg = 0.0;
    globals::frametime = 0.0;
    globals::framecount = 0;

    globals::curtime = utils::unixMicroseconds();

    glfwGetFramebufferSize(globals::window, &globals::window_width, &globals::window_height);
    globals::window_aspect = static_cast<float>(globals::window_width) / static_cast<float>(globals::window_height);

    client_game::initializeEarly();

    globals::client_config.loadFromFile("config.conf", true);
    globals::client_config.loadFromFile("user.conf", true);

    client_game::initialize();

    render_impl::initializeLate();

    std::uint64_t last_curtime = globals::curtime;
    std::uint64_t fixed_accumulator, fixed_frames;

    while(!glfwWindowShouldClose(globals::window)) {
        globals::curtime = utils::unixMicroseconds();
        globals::frametime_us = globals::curtime - last_curtime;
        globals::frametime = 1.0e-6 * static_cast<double>(globals::frametime_us);
        globals::frametime_avg += globals::frametime;
        globals::frametime_avg *= 0.5;

        if(globals::fixed_frametime_us == UINT64_MAX) {
            fixed_frames = 0;
            fixed_accumulator = 0;
        }
        else {
            fixed_accumulator += globals::frametime_us;
            fixed_frames = fixed_accumulator / globals::fixed_frametime_us;
            fixed_accumulator %= globals::fixed_frametime_us;
        }

        globals::num_drawcalls = 0;
        globals::num_triangles = 0;

        last_curtime = globals::curtime;

        render_impl::prepare();

        for(std::uint64_t i = 0; i < fixed_frames; ++i)
            client_game::fixedUpdate();
        client_game::update();

        render_impl::renderWorld();

        client_game::layout();

        render_impl::renderImGui();

        render_impl::present();

        for(std::uint64_t i = 0; i < fixed_frames; ++i)
            client_game::fixedUpdateLate();
        client_game::updateLate();

        glfwPollEvents();

        // This causes all the enqueued events to get processed;
        // this might be useful whenever I would feel like
        // it's time to be porting gamepad support from Voxelius
        globals::dispatcher.update();

        globals::fixed_framecount += fixed_frames;
        globals::framecount += 1;
    }

    client_game::shutdownEarly();

    spdlog::info("client: shutdown after {} frames", globals::framecount);
    spdlog::info("client: average framerate: {:.03f} FPS", 1.0 / globals::frametime_avg);
    spdlog::info("client: average frametime: {:.03f} ms", 1000.0 * globals::frametime_avg);

    render_impl::shutdown();

    glfwDestroyWindow(globals::window);
    glfwTerminate();

    globals::client_config.saveToFile("config.conf");

    client_game::shutdown();
}
