# GetCurrentProcessId

## Implementation Details

This function retrieves the current process ID by directly accessing the Thread Environment Block (TEB) of the running thread, bypassing the standard Windows API. The TEB contains a 'CLIENT_ID' structure, which holds the process and thread identifiers for the current thread.

Steps:
1. Access the current threads’s TEB.
2. Access the 'ClientId' field of the TEB..
3. Extract the 'UniqueProcess' member, which is a pointer-sized field representing the process ID.
4. Cast the 'void*' value to 'uintptr_t' and then to 'DWORD', since process IDs are 32-bit values on Windows.

## Limitations

- Only tested and guaranteed to work on Windows 11 version 23H2 (x64). Internal structures may differ in other builds or architectures.
- Assumes that 'ClientId.UniqueProcess' stores the process ID as a pointer-sized integer, which is true for modern Windows NT-based systems.

## References

- Microsoft documentation: [GetCurrentProcessId function](https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-getcurrentprocessid)
- Russinovich, M., Ionescu, A., Solomon, D. *Windows Internals, Part 1: System architecture, processes, threads, memory management, and more*
- VergiliusProject: https://www.vergiliusproject.com
