/*
    This file comes from the source code of Red Viper:
    see https://github.com/skyfloogle/red-viper/blob/master/include/cpp.h
*/

#pragma once

#include <3ds/types.h>
#include "3ds/services/irrst.h"
//#include <3ds/services/hid.h>
#include "hid.h"
Result cppInit(void);
void cppExit(void);
bool cppGetConnected(void);
void cppCircleRead(circlePosition *pos);
u32 cppKeysHeld(void);
u8 cppBatteryLevel(void);
// Custom addition, not present in the original file from Red Viper
u32 cppKeysDown(void);
u32 cppKeysUp(void);
