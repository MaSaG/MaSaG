#pragma once

#include "User_Data.h"

void __RtCyclicCallback(void *UserDataPtr);
void __RtEventCallback(void *UserDataPtr, U32_T EventCode);
void __RtErrorCallback(void *UserDataPtr, I32_T ErrorCode);