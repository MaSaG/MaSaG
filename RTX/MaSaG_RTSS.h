//////////////////////////////////////////////////////////////////
//
// MaSaG_RTSS.h - header file
//
// Last Modified: 2/8/2017  
// User: sychen
//
//////////////////////////////////////////////////////////////////

#pragma once

#include <SDKDDKVer.h>

#include <windows.h>
#include <tchar.h>
#include <rtapi.h>    // RTX APIs that can be used in real-time and Windows applications.
#include <wchar.h>

#include "nex_type.h"
#include "NexECMRtx.h"
#include "nex_type.h"
#include "EcErrors.h"
#include "NexCoeMotion.h"
#include "motorParam.h"
#include "math.h"

#include <Eigen/Dense>
#include <iostream>

#define EVN_NAME "Event"
#define SHM_NAME "Memory"

static  PVOID  location;