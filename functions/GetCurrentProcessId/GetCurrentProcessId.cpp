#include "utils.h"
#include "GetCurrentProcessId.h"

namespace own {

	DWORD GetCurrentProcessId() {

		_TEB* TEB = utils::GetTeb();

		return (DWORD)(uintptr_t)TEB->ClientId.UniqueProcess;
	}


	// For some unknown for me reasons right now, the PID is stored as void*
	// even tho its not a pointer and it just holds the PID as the address the pointer holds



}
