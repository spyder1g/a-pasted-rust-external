#pragma once
#include "init.hpp"
auto c_init::cheat() -> bool
{
	initialize();
	socket_connect = connect();
	if (socket_connect == INVALID_SOCKET)
	{
		std::cout << "Connection failed.\n";
		return TRUE;
	}

	clean_piddbcachetable(socket_connect);
	clean_mmunloadeddrivers(socket_connect);
	spoof_drives(socket_connect);

	exe = find_process_by_id("RustClient.exe");

	const auto base_address = get_process_base_address(socket_connect, exe);
	u_Base = get_dll(socket_connect, exe, 0); // UnityPlayer.dll
	g_Base = get_dll(socket_connect, exe, 1); // GameAssembly.dll


	return true;
}
auto c_init::local_player() -> uintptr_t
{
	uintptr_t local_player_pointer_1 = read<uintptr_t>(g_Base + 0x334A268);
	uintptr_t local_player_pointer_2 = read<uintptr_t>(local_player_pointer_1 + 0xB8);
	uintptr_t local_player_pointer_3 = read<uintptr_t>(local_player_pointer_2 + 0x0);
	uintptr_t local_player_pointer_4 = read<uintptr_t>(local_player_pointer_3 + 0x10);
	uintptr_t local_player_pointer_5 = read<uintptr_t>(local_player_pointer_4 + 0x28);
	uintptr_t local_player_pointer_6 = read<uintptr_t>(local_player_pointer_5 + 0x18);
	uintptr_t local_player_pointer_7 = read<uintptr_t>(local_player_pointer_6 + 0x20);

	return read<uintptr_t>(local_player_pointer_6 + 0x20);
}



