#pragma once
#include "ntdefs.hpp"
#include "peb.hpp"

namespace own::utils {


	bool wstrcmp(WPCSTR first, WPCSTR second); // Case sensitive wchar_t array compare
	_PEB* GetPeb();




}
