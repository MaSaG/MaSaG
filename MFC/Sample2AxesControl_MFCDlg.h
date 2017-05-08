
// Sample2AxesControl_MFCDlg.h : header file
//

#pragma once

#include"nex_type.h"
#include "Nexecm.h"
#include "NexCoeMotion.h"
#include "afxwin.h"
#include "User_Data.h"
#include "SystemParams.h"


// CSample2AxesControl_MFCDlg dialog
class CSample2AxesControl_MFCDlg : public CDialogEx
{
// Construction
public:
	CSample2AxesControl_MFCDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_SAMPLE2AXESCONTROL_MFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	UINT    TimerHandle;
	U16_T   misUpdate;
	afx_msg void OnBnClickedCancel();
	CEdit mActPosL0;
	CEdit mActPosL1;
	CEdit mActPosL2;
	CEdit mActPosL3;
	CEdit mActPosL4;
	CEdit mActPosL5;
	CEdit mActPosL6;
	CEdit mActPosR0;
	CEdit mActPosR1;
	CEdit mActPosR2;
	CEdit mActPosR3;
	CEdit mActPosR4;
	CEdit mActPosR5;
	CEdit mActPosR6;
	CEdit mTgtPosL0;
	CEdit mTgtPosR0;
	CEdit mFxL;
	CEdit mFxR;
	CEdit mFyR;
	CEdit mFzR;
	CEdit mTxR;
	CEdit mTyR;
	CEdit mTzR;
	CEdit mFyL;
	CEdit mFzL;
	CEdit mTxL;
	CEdit mTyL;
	CEdit mTzL;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	CButton mBn1;
	CButton mBn2;
	CButton mBn3;
	CButton mBn4;
	CButton mBn5;
	CButton mBn6;
	CButton mBn7;
	CButton mBn8;
	CButton mBn9;
	CButton mBn10;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton15();
	CEdit mTgtPosL1;
	CEdit mTgtPosL2;
	CEdit mTgtPosL3;
	CEdit mTgtPosL4;
	CEdit mTgtPosL5;
	CEdit mTgtPosL6;
	CEdit mTgtPosR1;
	CEdit mTgtPosR2;
	CEdit mTgtPosR3;
	CEdit mTgtPosR4;
	CEdit mTgtPosR5;
	CEdit mTgtPosR6;
	CEdit mErrPosL0;
	CEdit mErrPosL1;
	CEdit mErrPosL2;
	CEdit mErrPosL3;
	CEdit mErrPosL4;
	CEdit mErrPosL5;
	CEdit mErrPosL6;
	CEdit mErrPosR0;
	CEdit mErrPosR1;
	CEdit mErrPosR2;
	CEdit mErrPosR3;
	CEdit mErrPosR4;
	CEdit mErrPosR5;
	CEdit mErrPosR6;
	CEdit mActVelL0;
	CEdit mActVelL1;
	CEdit mActVelL2;
	CEdit mActVelL3;
	CEdit mActVelL4;
	CEdit mActVelL5;
	CEdit mActVelL6;
	CEdit mActVelR0;
	CEdit mActVelR1;
	CEdit mActVelR2;
	CEdit mActVelR3;
	CEdit mActVelR4;
	CEdit mActVelR5;
	CEdit mActVelR6;
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton18();
	afx_msg void OnBnClickedButton19();
	afx_msg void OnBnClickedButton20();
	afx_msg void OnBnClickedButton21();
	afx_msg void OnBnClickedButton22();
	CButton mBn11;
	CButton mBn12;
	CButton mBn13;
	CButton mBn14;
	CButton mBn15;
	CButton mBn16;
	CButton mBn17;
	CButton mBn18;
	CButton mBn19;
	CButton mBn20;
	CButton mBn21;
	CButton mBn22;
	CEdit mCMDState;
	CEdit mPlnPosL0;
	CEdit mPlnPosL1;
	CEdit mPlnPosL2;
	CEdit mPlnPosL3;
	CEdit mPlnPosL4;
	CEdit mPlnPosL5;
	CEdit mPlnPosL6;
	CEdit mPlnPosR0;
	CEdit mPlnPosR1;
	CEdit mPlnPosR2;
	CEdit mPlnPosR3;
	CEdit mPlnPosR4;
	CEdit mPlnPosR5;
	CEdit mPlnPosR6;
	CEdit mCurTCPLx;
	CEdit mCurTCPLy;
	CEdit mCurTCPLz;
	CEdit mCurTCPLa;
	CEdit mCurTCPLb;
	CEdit mCurTCPLc;
	CEdit mCurTCPRx;
	CEdit mCurTCPRy;
	CEdit mCurTCPRz;
	CEdit mCurTCPRa;
	CEdit mCurTCPRb;
	CEdit mCurTCPRc;
	CEdit mTarTCPLx;
	CEdit mTarTCPLy;
	CEdit mTarTCPLz;
	CEdit mTarTCPLa;
	CEdit mTarTCPLb;
	CEdit mTarTCPLc;

	CEdit mTarTCPRx;
	CEdit mTarTCPRy;
	CEdit mTarTCPRz;
	CEdit mTarTCPRa;
	CEdit mTarTCPRb;
	CEdit mTarTCPRc;
	CEdit mErrTCPLx;
	CEdit mErrTCPLy;
	CEdit mErrTCPLz;
	CEdit mErrTCPLa;
	CEdit mErrTCPLb;
	CEdit mErrTCPLc;
	CEdit mErrTCPRx;
	CEdit mErrTCPRy;
	CEdit mErrTCPRz;
	CEdit mErrTCPRa;
	CEdit mErrTCPRb;
	CEdit mErrTCPRc;
	CEdit mPlnTCPLx;
	CEdit mPlnTCPLy;
	CEdit mPlnTCPLz;
	CEdit mPlnTCPLa;
	CEdit mPlnTCPLb;
	CEdit mPlnTCPLc;
	CEdit mPlnTCPRx;
	CEdit mPlnTCPRy;
	CEdit mPlnTCPRz;
	CEdit mPlnTCPRa;
	CEdit mPlnTCPRb;
	CEdit mPlnTCPRc;
	CEdit mVelTCPLx;
	CEdit mVelTCPLy;
	CEdit mVelTCPLz;
	CEdit mVelTCPLa;
	CEdit mVelTCPLb;
	CEdit mVelTCPLc;
	CEdit mVelTCPRx;
	CEdit mVelTCPRy;
	CEdit mVelTCPRz;
	CEdit mVelTCPRa;
	CEdit mVelTCPRb;
	CEdit mVelTCPRc;
	CEdit mTimerCntLArm;
	CEdit mTimerCntRArm;
	CEdit mTarTorL0;
	CEdit mTarTorL1;
	CEdit mTarTorL2;
	CEdit mTarTorL3;
	CEdit mTarTorL4;
	CEdit mTarTorL5;
	CEdit mTarTorL6;
	CEdit mTarTorR0;
	CEdit mTarTorR1;
	CEdit mTarTorR2;
	CEdit mTarTorR3;
	CEdit mTarTorR4;
	CEdit mTarTorR5;
	CEdit mTarTorR6;
	CEdit mCurTorL0;
	CEdit mCurTorL1;
	CEdit mCurTorL2;
	CEdit mCurTorL3;
	CEdit mCurTorL4;
	CEdit mCurTorL5;
	CEdit mCurTorL6;
	CEdit mCurTorR0;
	CEdit mCurTorR1;
	CEdit mCurTorR2;
	CEdit mCurTorR3;
	CEdit mCurTorR4;
	CEdit mCurTorR5;
	CEdit mCurTorR6;
};
