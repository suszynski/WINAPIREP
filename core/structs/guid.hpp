// x64 23H2
#include "ntdefs.hpp"

using namespace own::ntdefs;


//0x10 bytes (sizeof)
struct _GUID
{
    ULONG Data1;                                                            //0x0
    USHORT Data2;                                                           //0x4
    USHORT Data3;                                                           //0x6
    UCHAR Data4[8];                                                         //0x8
};