#include "utils.h"
#include "GetCurrentProcessId.h"

namespace own {

	DWORD GetCurrentProcessId() {

		_TEB* TEB = utils::GetTeb();

		return (DWORD)(uintptr_t)TEB->ClientId.UniqueProcess;
	}
}
