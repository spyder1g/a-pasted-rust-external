#pragma once
#include "common.hpp"

inline SOCKET socket_connect;
inline DWORD exe;
inline bool g_Locked;
inline uint64_t u_Base;
inline uint64_t g_Base;
inline uint64_t base_address;

inline std::uint32_t find_process_by_id(const std::string& name)
{
	const auto snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (snap == INVALID_HANDLE_VALUE) {
		return 0;
	}

	PROCESSENTRY32 proc_entry{};
	proc_entry.dwSize = sizeof proc_entry;

	auto found_process = false;
	if (!!Process32First(snap, &proc_entry)) {
		do {
			if (name == proc_entry.szExeFile) {
				found_process = true;
				break;
			}
		} while (!!Process32Next(snap, &proc_entry));
	}

	CloseHandle(snap);
	return found_process
		? proc_entry.th32ProcessID
		: 0;
}

void	initialize();
void	deinitialize();

SOCKET	connect();
void	disconnect(SOCKET connection);
uint32_t readbuffer(uint64_t address, PVOID buffer, size_t size);
uint32_t read_memory(SOCKET connection, uint32_t process_id, uintptr_t address, uintptr_t buffer, size_t size);
uint32_t write_memory(SOCKET connection, uint32_t process_id, uintptr_t address, uintptr_t buffer, size_t size);
uint64_t get_process_base_address(SOCKET connection, uint32_t exe_id);
uint64_t get_dll(SOCKET connection, uint32_t process_id, int module);
uint64_t clean_piddbcachetable(SOCKET connection);
uint64_t clean_mmunloadeddrivers(SOCKET connection);
uint64_t spoof_drives(SOCKET connection);

template <typename T>
T read(const uintptr_t address)
{
	T buffer{ };
	read_memory(socket_connect, exe, address, uint64_t(&buffer), sizeof(T));
	return buffer;
}
template <typename T>
void write(const uintptr_t address, const T& buffer)
{
	write_memory(socket_connect, exe, address, uint64_t(&buffer), sizeof(T));
}

template <typename Type>
Type readchain(uint64_t address, std::vector<uint64_t> chain) {
	uint64_t current = address;
	for (int i = 0; i < chain.size() - 1; i++) {
		current = read<uint64_t>(current + chain[i]);
	}
	return read<Type>(current + chain[chain.size() - 1]);
}
