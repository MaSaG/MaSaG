
// Sample2AxesControl_MFC.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CSample2AxesControl_MFCApp:
// See Sample2AxesControl_MFC.cpp for the implementation of this class
//

class CSample2AxesControl_MFCApp : public CWinApp
{
public:
	CSample2AxesControl_MFCApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CSample2AxesControl_MFCApp theApp;