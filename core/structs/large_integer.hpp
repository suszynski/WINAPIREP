
// x64 23H2
#pragma once
#include "ntdefs.hpp"

using namespace own::ntdefs;

union _LARGE_INTEGER
{
    struct
    {
        ULONG LowPart;                                                      //0x0
        LONG HighPart;                                                      //0x4
    };
    struct
    {
        ULONG LowPart;                                                      //0x0
        LONG HighPart;                                                      //0x4
    } u;                                                                    //0x0
    LONGLONG QuadPart;                                                      //0x0
};

union _ULARGE_INTEGER
{
    struct
    {
        ULONG LowPart;                                                      //0x0
        ULONG HighPart;                                                     //0x4
    };
    struct
    {
        ULONG LowPart;                                                      //0x0
        ULONG HighPart;                                                     //0x4
    } u;                                                                    //0x0
    ULONGLONG QuadPart;                                                     //0x0
};
