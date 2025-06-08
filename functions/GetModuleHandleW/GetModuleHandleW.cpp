#include "ntdefs.hpp"
#include "utils.h"

using namespace own::ntdefs;


namespace own {

	HMODULE GetModuleHandleW(IN OPTIONAL WPCSTR moduleName) {

		const _PEB* const PEB = utils::GetPeb();

		if (!moduleName)
			return PEB->ImageBaseAddress;

		_LIST_ENTRY* currentEntry = PEB->Ldr->InLoadOrderModuleList.Flink;
		_LIST_ENTRY* finalEntry = &PEB->Ldr->InLoadOrderModuleList;



		while (currentEntry != finalEntry) {

			// In other version than 23H2 it may require decrementing some offset to get the base of DTE
			// Ignored for now because seems like Flink of InLoadModules structure is the first pointer in DTE
			_LDR_DATA_TABLE_ENTRY* currentModuleData = (_LDR_DATA_TABLE_ENTRY*)currentEntry;


			if (utils::wstrcmp(currentModuleData->BaseDllName.Buffer, moduleName)) // may require calling toLower first
				return currentModuleData->DllBase;

			currentEntry = currentEntry->Flink;

		}

		return NULL;
	}

}
