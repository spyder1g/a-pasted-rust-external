#pragma once
#include "scene.hpp"
auto wnd_proc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) -> bool
{
	return true;
}
auto init_ui() -> void  
{
	ImGui::StyleColorsDark();

	ImGuiIO& io = ImGui::GetIO(); (void)io;

	ImFontConfig font_config;
	font_config.OversampleH = 1; //or 2 is the same
	font_config.OversampleV = 1;
	font_config.PixelSnapH = 1;

	static const ImWchar ranges[] =
	{
		0x0020, 0x00FF, // Basic Latin + Latin Supplement
		0x0400, 0x044F, // Cyrillic
		0,
	};
	structure.c_font_defult = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\tahoma.ttf", 15.f);
	structure.c_font_icon = io.Fonts->AddFontFromMemoryTTF((void*)iconfont, sizeof(iconfont), 30, &font_config, ranges);
}
auto create_scene() -> void 
{
	// create cheat 
	cheat->create();
	// draw gui 
	gui->draw();
}
auto c_scene::create() -> void
{
	GAPI::MakeWindow("hook_with_imgui", "c_hook_with_imgui", wnd_proc, init_ui, create_scene, &vars.g_open, &vars.g_menu_key);
}

