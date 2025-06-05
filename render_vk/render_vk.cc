#include "render_vk/pch.hh"

#include "client/render.hh"

#include "shared/gameinfo.hh"

#include "client/globals.hh"

void render_impl::setupWindowing(void)
{
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
}

void render_impl::initialize(void)
{
    spdlog::error("render_vk: I am not implemented!");
    spdlog::error("render_vk: enjoy a plain empty window!");
}

void render_impl::initializeLate(void)
{
    std::string window_title(std::format("[Vulkan] {}", gameinfo::game_name));
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
}

void render_impl::renderWorld(void)
{
}

void render_impl::renderImGui(void)
{
}
