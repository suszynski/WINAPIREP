// x64 23H2
#pragma once
#include "ntdefs.hpp"

using namespace own::ntdefs;

//0x10 bytes (sizeof)
struct _UNICODE_STRING
{
    USHORT Length;                                                          //0x0
    USHORT MaximumLength;                                                   //0x2
    WCHAR* Buffer;                                                          //0x8
};
