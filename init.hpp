#pragma once
#include "common.hpp"
// get base addy and local player
class c_init
{
public:
	auto cheat() -> bool;
	auto local_player() -> uintptr_t;
};
inline c_init* init;
