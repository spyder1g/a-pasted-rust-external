#pragma once
#include "cheat.hpp"
auto c_cheat::create() -> void
{
	auto local_player = reinterpret_cast<c_baseplayer*>(init->local_player());
	if (local_player != 0 /*in server wont be 0*/)
	{
		local_player->set_spyderman(vars.spyderman);
		local_player->set_recoil(vars.no_recoil);
		local_player->set_flag(4, vars.admin_flags);
		local_player->set_fov(vars.fov_ammount /* base 90 */);
		local_player->set_gravity(vars.gravity_ammount /* base 2.5f */);
		local_player->set_doublejump(vars.doublejump);
		local_player->set_always_shoot(vars.always_shoot);
		local_player->set_walkonwater(vars.walkonwater);
		local_player->set_longneck(vars.longbind);
		local_player->set_noaimcone(vars.nospread);
		local_player->set_instantcompound(vars.instacompound);
		local_player->set_speedhack(vars.speedbind);
		//local_player->set_instanteoka(vars.instanteoka);
		//local_player->set_omni_sprint(vars.omnisprint);
	}
}