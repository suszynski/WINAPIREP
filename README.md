# Windows Userland API Replication (x64, Windows 11 23H2)

This project reimplements selected Windows user-mode API functions by directly accessing internal process structures such as the **PEB** and **LDR** without invoking kernel-mode or standard WinAPI calls.  
It is intended as a **proof of concept** and **educational tool** to understand how these APIs function under the hood.

---

## Project Goals

- Manually replicate user-mode Windows API behavior
- Deepen understanding of Windows internal memory structures
- Learn reverse engineering and system-level programming techniques
- Build a self-contained, version-specific toolkit

---

## Architecture & Compatibility

| Property         | Value               |
|-----------------|---------------------|
| OS Version       | Windows 11 23H2     |
| Architecture     | x64 only            |
| Kernel Access    | ❌ Not required     |
| Execution Mode   | User mode only      |
| Language         | C++                 |

Due to structure layout differences between OS versions and architectures, this project **only guarantees correctness on x64 Windows 11 version 23H2**.

---

## Implemented Functions

Each API function is isolated in its own directory and includes:
- A technical description (`description.md`)
- Header and implementation files

### Completed
- [`GetModuleHandleW`](functions/GetModuleHandleW/description.md)
- [`GetCurrentProcessId`](functions/GetCurrentProcessId/description.md)

### In Progress
- `GetCurrentThreadId`
- `LoadLibraryW`
- `lstrlenW`

---

## License

This project is released under the [MIT License](LICENSE)

---

## Disclaimer

Structure definitions are version-specific and not guaranteed to be portable. This code takes advantage of MSVC intrinsic's in order to access GS/FS registers so modifying code may be required when using other compiler.  
