#pragma once
#ifndef u_vars_hpp
#define u_vars_hpp

class c_vars
{
public:
	// menu
	bool g_open = true;
	int g_menu_key = VK_INSERT;
	int walkbind = 0;
	int longbind = 0;
	int speedbind = 0;

	// cheat
	bool no_recoil = false;
	bool admin_flags = false;
	bool doublejump = false;
	bool walkonwater = false;
	bool spyderman = false;
	bool always_shoot = false;
	bool longeject = false;
	bool thickbullet = false;
	bool instacompound = false;
	bool speedhack = false;
	bool nospread = false;

	float speedamount = 0;
	float neckamount = 0;
	float flyspeed = 10;
	float fov_ammount = 90;
	float gravity_ammount = 2.5f;
};
inline c_vars vars; 

#endif // !u_vars_hpp
