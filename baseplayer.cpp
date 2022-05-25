#pragma once
#include "baseplayer.hpp"
#include <xstring>

std::string name;

auto c_baseplayer::set_spyderman(bool toggle) -> void
{
	if (toggle)
	{
		auto movement = read<uintptr_t>((uintptr_t)this + 0x4E8);
		write<float>(movement + 0xC8, 0.f);
	}
}
auto c_baseplayer::set_recoil(bool toggle) -> void
{
	if (toggle)
	{
		auto player_input = read<uintptr_t>((uintptr_t)this + 0x4E0);
		write<Vector2>(player_input + 0x64, Vector2(0, 0));
	}
}
auto c_baseplayer::set_flag(int flag, bool toggle) ->void /*4 = admin flag*/
{
	if (toggle)
	{
		write<int>((uintptr_t)this + 0x680, 4);
	}
}
auto c_baseplayer::set_fov(float value) ->void /*admin flags*/
{
	auto graphics_convar = read<uintptr_t>( g_Base + 0x3347EE8 /* maybe incorrect "*/);
	auto graphics_current = read<uintptr_t>(graphics_convar + 0xB8);
	write<float>(graphics_current + 0x18, value);
}
auto c_baseplayer::set_gravity(float value) ->void /*admin flags*/
{
	auto movement = read<uintptr_t>((uintptr_t)this + 0x4E8);
	write<float>( movement + 0x84, value);
}
void c_baseplayer::set_doublejump(bool toggle) /*admin flags*/
{
	if (toggle)
	{
		if (GetAsyncKeyState(VK_SPACE))
		{
			auto movement = read<uintptr_t>((uintptr_t)this + 0x4E8);
			write<Vector3>(movement + 0xc8, Vector3(0, 10000000, 0));
			write<Vector3>(movement + 0xc4, Vector3(99999999, 99999999, 99999999));
		}
	}
}

const unsigned int screenWidth = GetSystemMetrics(SM_CXSCREEN);
const unsigned int screenHeight = GetSystemMetrics(SM_CYSCREEN);

void c_baseplayer::set_walkonwater(bool toggle) {
	if (toggle)
	{
		bool stuff = true;
		auto movement = read<uintptr_t>((uintptr_t)this + 0x4E8);
		if (GetAsyncKeyState(VK_SPACE))
		{
			stuff = false;
		}
		if (stuff == true && vars.walkonwater)
		{
			write<float>(movement + 0xc4, 0.f);//groundAngle
			write<float>(movement + 0xc8, 0.f);//groundAngleNew
			write<float>(movement + 0x84, 0.f);//gravityMultiplier
		}
	}
}

void c_baseplayer::set_thickbullet(bool toggle) {
	if (toggle)
	{
		auto List = read<DWORD64>((uintptr_t)this + 0x358); //private List<Projectile> createdProjectiles;
		List = read<DWORD64>(List + 0x10);
		for (int i = 0; i < 8; ++i)
		{
			UINT64 Item = read<UINT64>(List + 0x20 + (i * 0x8));
			write<float>(Item + 0x2C, 1.5f);
		}
	}
}

auto aimSway = 0x19C;// public float aimSway;
auto aimSwaySpeed = 0x1A8;// public float aimSwaySpeed;
auto aimCone = 0x2E8;// public float aimCone;
auto hipAimCone = 0x2EC;// public float hipAimCone;
auto aimconePenaltyPerShot = 0x2F0;// public float aimconePenaltyPerShot;
auto aimConePenaltyMax = 0x2F4;// public float aimConePenaltyMax;

void c_baseplayer::set_noaimcone(bool toggle) {
	if (toggle)
	{
		auto Held = read<DWORD64>((uintptr_t)this + 0x580/*HeldEntity 0x40 0x580*/);
		write(Held + 0x31C, 0.f/*StancePenalty 0x31C*/);
		write(Held + 0x320, 0.f/*AimconePenalty 0x320*/);
		write(Held + 0x2E8, 0.f/*AimCone 0x2E8*/);
		write(Held + 0x2EC, 0.f/*HipAimCone 0x2EC*/);
		write(Held + 0x2F0, 0.f/*AimconePenaltyPerShot 0x2F0*/);
	}
}

void c_baseplayer::set_instantcompound(bool toggle) {
	if (toggle)
	{// helditem - 
	    //auto baseprojectile = read<uintptr_t>(activeid + 0x90);
		auto activeid = read<uintptr_t>((uintptr_t)this + 0x5D0);
		auto inventory = read<uintptr_t>((uintptr_t)this + 0x690);
		auto inventorybelt = read<uintptr_t>(inventory + 0x20);
		write<float>((uintptr_t)this + 0x378, 0);//stringHoldDurationMax
		write<float>((uintptr_t)this + 0x37C, 1000000);//stringBonusDamage
		write<float>((uintptr_t)this + 0x388, 1000000);//movementPenaltyRampUpTime
	}
}

void c_baseplayer::set_speedhack(int key) {
	if (GetAsyncKeyState(key))
	{
		//write<float>((uintptr_t)this + 0x28, vars.speedamount);
	}
}

void c_baseplayer::set_always_shoot(bool toggle) {
	auto movement = read<uintptr_t>((uintptr_t)this + 0x4E8);
	auto modelstate = read<uintptr_t>((uintptr_t)this + 0x5f8);
	if (toggle)
	{

		write<int>(modelstate + 0x24, 4);
		write<float>(movement + 0x4C, 1.f);
	}
}
void c_baseplayer::set_longneck(int key) {

	if (GetAsyncKeyState(key))
	{
		uintptr_t eyes = read<DWORD64>((uintptr_t)this + 0x688);
		write<Vector3>(eyes + 0x38, Vector3(0, 0.8f, 0));
	}
}
