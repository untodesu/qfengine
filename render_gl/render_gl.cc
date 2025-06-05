#include "render_gl/pch.hh"

#include "client/render.hh"

#include "client/globals.hh"

#include "shared/gameinfo.hh"

void render_impl::setupWindowing(void)
{
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_SAMPLES, 0);

#if defined(__APPLE__)
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
}

void render_impl::initialize(void)
{
    glfwMakeContextCurrent(globals::window);
    glfwSwapInterval(1);
}

void render_impl::initializeLate(void)
{
    std::string window_title(std::format("[OpenGL] {}", gameinfo::game_name));
    glfwSetWindowTitle(globals::window, window_title.c_str());
}

void render_impl::shutdown(void)
{
}

void render_impl::prepare(void)
{
}

void render_impl::present(void)
{
    glfwSwapBuffers(globals::window);
}

void render_impl::renderWorld(void)
{
}

void render_impl::renderImGui(void)
{
}
