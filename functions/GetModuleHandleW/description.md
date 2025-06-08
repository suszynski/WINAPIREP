# GetModuleHandleW

## Implementation Details

The function uses the Process Environment Block (PEB) to access the module list maintained by the system loader. Specifically, it walks the `InLoadOrderModuleList` linked list found in the `PEB_LDR_DATA` structure. Each node in the list is an `_LDR_DATA_TABLE_ENTRY`, which contains the base address and name of the loaded module.

Steps:
1. Access the current process’s PEB.
2. Traverse the linked list of loaded modules.
3. Compare the `BaseDllName.Buffer` of each `_LDR_DATA_TABLE_ENTRY` to the provided module name.
4. Return the `DllBase` if a match is found.
5. If the `moduleName` argument is `nullptr`, return the image base address of the current process.

## Limitations

- Only tested and guaranteed to work on Windows 11 version 23H2 (x64). Internal structures may differ in other builds or architectures.
- Case-sensitive string comparison is currently used; normalization (e.g. lowercase matching) may be necessary for robustness.
- This implementation assumes that the `Flink` pointer in `InLoadOrderModuleList` points directly to an `_LDR_DATA_TABLE_ENTRY`.

## References

- Microsoft documentation: [GetModuleHandleW function](https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulehandlew)
- Russinovich, M., Ionescu, A., Solomon, D. *Windows Internals, Part 1: System architecture, processes, threads, memory management, and more*
- VergiliusProject: https://www.vergiliusproject.com
