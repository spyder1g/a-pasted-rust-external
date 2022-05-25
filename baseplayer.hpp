#pragma once
#include "common.hpp"

// functions
class c_baseplayer
{
public:
	auto set_spyderman(bool toggle) -> void;
	auto set_recoil(bool toggle) -> void;
	auto set_flag(int flag, bool toggle) -> void;
	auto set_fov(float value) ->void;
	auto set_gravity(float value) ->void;
	void set_doublejump(bool toggle);
	void set_always_shoot(bool toggle);
	void set_walkonwater(bool toggle);
	void set_longneck(int key);
	void set_thickbullet(bool toggle);
	void set_noaimcone(bool toggle);
	void set_instantcompound(bool toggle);
	void set_speedhack(int key);
	//void set_instanteoka(bool toggle);
	//void set_omni_sprint(bool toggle);
};
