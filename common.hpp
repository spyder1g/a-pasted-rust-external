#pragma once

// windows headers
#include <msxml.h>    
#include <atomic>
#include <mutex>
#include <Windows.h>
#include <TlHelp32.h>
#include <cstdint>
#include <vector>
#include <random>
#include <memoryapi.h>
#include <string>
#include <thread>
#include <chrono>
#include <iostream>
#include <string_view>
#include <mutex>
#include <chrono>
#include <functional>
#include <dwmapi.h>
#include <dinput.h>
#include <d3d9.h>
#include <WinSock.h>
#include <cstdint>

// libs
#pragma comment(lib, "Dwmapi.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

using Callback = std::function<void()>;

// imgui
#include "vendor/ImGui/imgui.h"
#include "vendor/ImGui/imgui_impl_dx9.h"
#include "vendor/ImGui/imgui_impl_win32.h"
#include "vendor/ImGui/imgui_internal.h"


// utils
#include "u_vector.hpp"
#include "u_gapi.hpp"
#include "u_vars.hpp"
#include "u_fonts.hpp"
#include "u_lock.h"
#include "u_junk.h"
#include "u_shared.h"




// driver com :/
#include "driver.hpp"

// structure (gui)
#include "structure.hpp"

// init cheat
#include "init.hpp"

// baseplayer funcs
#include "baseplayer.hpp"

// create cheat
#include "cheat.hpp"

// make scene xox
#include "scene.hpp"

// draw gui
#include "gui.hpp"

