#include "newcodeinfo.h"
#include "3ds/types.h"

Result svcControlProcessMemory(Handle process, u32 addr0, u32 addr1, u32 size, u32 type, u32 perm);

Handle getCurrentProcessHandle(void)
    __attribute__((section (".loader")));
