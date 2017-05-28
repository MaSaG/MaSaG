
// Sample2AxesControl_MFCDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Sample2AxesControl_MFC.h"
#include "Sample2AxesControl_MFCDlg.h"
#include "afxdialogex.h"
#include <windows.h>
#include <rtapi.h>

extern PVOID location;

#define EVN_NAME "Event"
#define SHM_NAME "Memory"

U16_T masterId ;

RTN_ERR ret;
I32_T   timeOut = 5000;
U8_T	StartCheck = 0;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSample2AxesControl_MFCDlg dialog




CSample2AxesControl_MFCDlg::CSample2AxesControl_MFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSample2AxesControl_MFCDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSample2AxesControl_MFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_REAL_POS, mActPosL0);
	DDX_Control(pDX, IDC_EDIT_REAL_POS2, mActPosL1);
	DDX_Control(pDX, IDC_EDIT_REAL_POS3, mActPosL2);
	DDX_Control(pDX, IDC_EDIT_REAL_POS4, mActPosL3);
	DDX_Control(pDX, IDC_EDIT_REAL_POS5, mActPosL4);
	DDX_Control(pDX, IDC_EDIT_REAL_POS6, mActPosL5);
	DDX_Control(pDX, IDC_EDIT_REAL_POS7, mActPosL6);
	DDX_Control(pDX, IDC_EDIT_REAL_POS8, mActPosR0);
	DDX_Control(pDX, IDC_EDIT_REAL_POS9, mActPosR1);
	DDX_Control(pDX, IDC_EDIT_REAL_POS10, mActPosR2);
	DDX_Control(pDX, IDC_EDIT_REAL_POS11, mActPosR3);
	DDX_Control(pDX, IDC_EDIT_REAL_POS12, mActPosR4);
	DDX_Control(pDX, IDC_EDIT_REAL_POS13, mActPosR5);
	DDX_Control(pDX, IDC_EDIT_REAL_POS14, mActPosR6);
	DDX_Control(pDX, IDC_EDIT_POS, mTgtPosL0);
	DDX_Control(pDX, IDC_EDIT_REAL_POS17, mTgtPosL1);
	DDX_Control(pDX, IDC_EDIT_REAL_POS18, mTgtPosL2);
	DDX_Control(pDX, IDC_EDIT_REAL_POS19, mTgtPosL3);
	DDX_Control(pDX, IDC_EDIT_REAL_POS20, mTgtPosL4);
	DDX_Control(pDX, IDC_EDIT_REAL_POS21, mTgtPosL5);
	DDX_Control(pDX, IDC_EDIT_REAL_POS22, mTgtPosL6);
	DDX_Control(pDX, IDC_EDIT_POS8, mTgtPosR0);
	DDX_Control(pDX, IDC_EDIT_REAL_POS23, mTgtPosR1);
	DDX_Control(pDX, IDC_EDIT_REAL_POS24, mTgtPosR2);
	DDX_Control(pDX, IDC_EDIT_REAL_POS25, mTgtPosR3);
	DDX_Control(pDX, IDC_EDIT_REAL_POS26, mTgtPosR4);
	DDX_Control(pDX, IDC_EDIT_REAL_POS27, mTgtPosR5);
	DDX_Control(pDX, IDC_EDIT_REAL_POS28, mTgtPosR6);
	DDX_Control(pDX, IDC_EDIT_REAL_POS15, mFxL);
	DDX_Control(pDX, IDC_EDIT_REAL_POS16, mFxR);
	DDX_Control(pDX, IDC_EDIT_POS16, mFyR);
	DDX_Control(pDX, IDC_EDIT_V16, mFzR);
	DDX_Control(pDX, IDC_EDIT_A16, mTxR);
	DDX_Control(pDX, IDC_EDIT_A19, mTyR);
	DDX_Control(pDX, IDC_EDIT_A20, mTzR);
	DDX_Control(pDX, IDC_EDIT_POS15, mFyL);
	DDX_Control(pDX, IDC_EDIT_V15, mFzL);
	DDX_Control(pDX, IDC_EDIT_A15, mTxL);
	DDX_Control(pDX, IDC_EDIT_A17, mTyL);
	DDX_Control(pDX, IDC_EDIT_A18, mTzL);
	DDX_Control(pDX, IDC_BUTTON1, mBn1);
	DDX_Control(pDX, IDC_BUTTON2, mBn2);
	DDX_Control(pDX, IDC_BUTTON3, mBn3);
	DDX_Control(pDX, IDC_BUTTON4, mBn4);
	DDX_Control(pDX, IDC_BUTTON5, mBn5);
	DDX_Control(pDX, IDC_BUTTON6, mBn6);
	DDX_Control(pDX, IDC_BUTTON7, mBn7);
	DDX_Control(pDX, IDC_BUTTON8, mBn8);
	DDX_Control(pDX, IDC_BUTTON9, mBn9);
	DDX_Control(pDX, IDC_BUTTON10, mBn10);


	DDX_Control(pDX, IDC_EDIT_POS17, mErrPosL0);
	DDX_Control(pDX, IDC_EDIT_REAL_POS29, mErrPosL1);
	DDX_Control(pDX, IDC_EDIT_REAL_POS31, mErrPosL2);
	DDX_Control(pDX, IDC_EDIT_REAL_POS33, mErrPosL3);
	DDX_Control(pDX, IDC_EDIT_REAL_POS35, mErrPosL4);
	DDX_Control(pDX, IDC_EDIT_REAL_POS37, mErrPosL5);
	DDX_Control(pDX, IDC_EDIT_REAL_POS49, mErrPosL6);
	DDX_Control(pDX, IDC_EDIT_POS18, mErrPosR0);
	DDX_Control(pDX, IDC_EDIT_REAL_POS30, mErrPosR1);
	DDX_Control(pDX, IDC_EDIT_REAL_POS32, mErrPosR2);
	DDX_Control(pDX, IDC_EDIT_REAL_POS34, mErrPosR3);
	DDX_Control(pDX, IDC_EDIT_REAL_POS36, mErrPosR4);
	DDX_Control(pDX, IDC_EDIT_REAL_POS38, mErrPosR5);
	DDX_Control(pDX, IDC_EDIT_REAL_POS51, mErrPosR6);
	DDX_Control(pDX, IDC_EDIT_POS19, mActVelL0);
	DDX_Control(pDX, IDC_EDIT_REAL_POS39, mActVelL1);
	DDX_Control(pDX, IDC_EDIT_REAL_POS41, mActVelL2);
	DDX_Control(pDX, IDC_EDIT_REAL_POS43, mActVelL3);
	DDX_Control(pDX, IDC_EDIT_REAL_POS45, mActVelL4);
	DDX_Control(pDX, IDC_EDIT_REAL_POS47, mActVelL5);
	DDX_Control(pDX, IDC_EDIT_REAL_POS50, mActVelL6);
	DDX_Control(pDX, IDC_EDIT_POS20, mActVelR0);
	DDX_Control(pDX, IDC_EDIT_REAL_POS40, mActVelR1);
	DDX_Control(pDX, IDC_EDIT_REAL_POS42, mActVelR2);
	DDX_Control(pDX, IDC_EDIT_REAL_POS44, mActVelR3);
	DDX_Control(pDX, IDC_EDIT_REAL_POS46, mActVelR4);
	DDX_Control(pDX, IDC_EDIT_REAL_POS48, mActVelR5);
	DDX_Control(pDX, IDC_EDIT_REAL_POS52, mActVelR6);
	DDX_Control(pDX, IDC_BUTTON11, mBn11);
	DDX_Control(pDX, IDC_BUTTON12, mBn12);
	DDX_Control(pDX, IDC_BUTTON13, mBn13);
	DDX_Control(pDX, IDC_BUTTON14, mBn14);
	DDX_Control(pDX, IDC_BUTTON15, mBn15);
	DDX_Control(pDX, IDC_BUTTON16, mBn16);
	DDX_Control(pDX, IDC_BUTTON17, mBn17);
	DDX_Control(pDX, IDC_BUTTON18, mBn18);
	DDX_Control(pDX, IDC_BUTTON19, mBn19);
	DDX_Control(pDX, IDC_BUTTON20, mBn20);
	DDX_Control(pDX, IDC_BUTTON21, mBn21);
	DDX_Control(pDX, IDC_BUTTON22, mBn22);
	DDX_Control(pDX, IDC_EDIT1, mCMDState);
	DDX_Control(pDX, IDC_EDIT_POS21, mPlnPosL0);
	DDX_Control(pDX, IDC_EDIT_REAL_POS101, mPlnPosL1);
	DDX_Control(pDX, IDC_EDIT_REAL_POS102, mPlnPosL2);
	DDX_Control(pDX, IDC_EDIT_REAL_POS103, mPlnPosL3);
	DDX_Control(pDX, IDC_EDIT_REAL_POS104, mPlnPosL4);
	DDX_Control(pDX, IDC_EDIT_REAL_POS105, mPlnPosL5);
	DDX_Control(pDX, IDC_EDIT_REAL_POS106, mPlnPosL6);
	DDX_Control(pDX, IDC_EDIT_POS22, mPlnPosR0);
	DDX_Control(pDX, IDC_EDIT_REAL_POS107, mPlnPosR1);
	DDX_Control(pDX, IDC_EDIT_REAL_POS108, mPlnPosR2);
	DDX_Control(pDX, IDC_EDIT_REAL_POS109, mPlnPosR3);
	DDX_Control(pDX, IDC_EDIT_REAL_POS110, mPlnPosR4);
	DDX_Control(pDX, IDC_EDIT_REAL_POS111, mPlnPosR5);
	DDX_Control(pDX, IDC_EDIT_REAL_POS112, mPlnPosR6);
	DDX_Control(pDX, IDC_EDIT_REAL_POS53, mCurTCPLx);
	DDX_Control(pDX, IDC_EDIT_REAL_POS54, mCurTCPLy);
	DDX_Control(pDX, IDC_EDIT_REAL_POS55, mCurTCPLz);
	DDX_Control(pDX, IDC_EDIT_REAL_POS56, mCurTCPLa);
	DDX_Control(pDX, IDC_EDIT_REAL_POS57, mCurTCPLb);
	DDX_Control(pDX, IDC_EDIT_REAL_POS58, mCurTCPLc);
	DDX_Control(pDX, IDC_EDIT_REAL_POS77, mCurTCPRx);
	DDX_Control(pDX, IDC_EDIT_REAL_POS78, mCurTCPRy);
	DDX_Control(pDX, IDC_EDIT_REAL_POS79, mCurTCPRz);
	DDX_Control(pDX, IDC_EDIT_REAL_POS80, mCurTCPRa);
	DDX_Control(pDX, IDC_EDIT_REAL_POS81, mCurTCPRb);
	DDX_Control(pDX, IDC_EDIT_REAL_POS82, mCurTCPRc);
	DDX_Control(pDX, IDC_EDIT_REAL_POS59, mTarTCPLx);
	DDX_Control(pDX, IDC_EDIT_REAL_POS60, mTarTCPLy);
	DDX_Control(pDX, IDC_EDIT_REAL_POS61, mTarTCPLz);
	DDX_Control(pDX, IDC_EDIT_REAL_POS62, mTarTCPLa);
	DDX_Control(pDX, IDC_EDIT_REAL_POS63, mTarTCPLb);
	DDX_Control(pDX, IDC_EDIT_REAL_POS64, mTarTCPLc);

	DDX_Control(pDX, IDC_EDIT_REAL_POS83, mTarTCPRx);
	DDX_Control(pDX, IDC_EDIT_REAL_POS84, mTarTCPRy);
	DDX_Control(pDX, IDC_EDIT_REAL_POS85, mTarTCPRz);
	DDX_Control(pDX, IDC_EDIT_REAL_POS86, mTarTCPRa);
	DDX_Control(pDX, IDC_EDIT_REAL_POS87, mTarTCPRb);
	DDX_Control(pDX, IDC_EDIT_REAL_POS88, mTarTCPRc);
	DDX_Control(pDX, IDC_EDIT_REAL_POS65, mErrTCPLx);
	DDX_Control(pDX, IDC_EDIT_REAL_POS66, mErrTCPLy);
	DDX_Control(pDX, IDC_EDIT_REAL_POS67, mErrTCPLz);
	DDX_Control(pDX, IDC_EDIT_REAL_POS68, mErrTCPLa);
	DDX_Control(pDX, IDC_EDIT_REAL_POS69, mErrTCPLb);
	DDX_Control(pDX, IDC_EDIT_REAL_POS70, mErrTCPLc);
	DDX_Control(pDX, IDC_EDIT_REAL_POS89, mErrTCPRx);
	DDX_Control(pDX, IDC_EDIT_REAL_POS90, mErrTCPRy);
	DDX_Control(pDX, IDC_EDIT_REAL_POS91, mErrTCPRz);
	DDX_Control(pDX, IDC_EDIT_REAL_POS92, mErrTCPRa);
	DDX_Control(pDX, IDC_EDIT_REAL_POS93, mErrTCPRb);
	DDX_Control(pDX, IDC_EDIT_REAL_POS94, mErrTCPRc);
	DDX_Control(pDX, IDC_EDIT_REAL_POS113, mPlnTCPLx);
	DDX_Control(pDX, IDC_EDIT_REAL_POS114, mPlnTCPLy);
	DDX_Control(pDX, IDC_EDIT_REAL_POS115, mPlnTCPLz);
	DDX_Control(pDX, IDC_EDIT_REAL_POS116, mPlnTCPLa);
	DDX_Control(pDX, IDC_EDIT_REAL_POS117, mPlnTCPLb);
	DDX_Control(pDX, IDC_EDIT_REAL_POS118, mPlnTCPLc);
	DDX_Control(pDX, IDC_EDIT_REAL_POS119, mPlnTCPRx);
	DDX_Control(pDX, IDC_EDIT_REAL_POS120, mPlnTCPRy);
	DDX_Control(pDX, IDC_EDIT_REAL_POS121, mPlnTCPRz);
	DDX_Control(pDX, IDC_EDIT_REAL_POS122, mPlnTCPRa);
	DDX_Control(pDX, IDC_EDIT_REAL_POS123, mPlnTCPRb);
	DDX_Control(pDX, IDC_EDIT_REAL_POS124, mPlnTCPRc);
	DDX_Control(pDX, IDC_EDIT_REAL_POS71, mVelTCPLx);
	DDX_Control(pDX, IDC_EDIT_REAL_POS72, mVelTCPLy);
	DDX_Control(pDX, IDC_EDIT_REAL_POS73, mVelTCPLz);
	DDX_Control(pDX, IDC_EDIT_REAL_POS74, mVelTCPLa);
	DDX_Control(pDX, IDC_EDIT_REAL_POS75, mVelTCPLb);
	DDX_Control(pDX, IDC_EDIT_REAL_POS76, mVelTCPLc);
	DDX_Control(pDX, IDC_EDIT_REAL_POS95, mVelTCPRx);
	DDX_Control(pDX, IDC_EDIT_REAL_POS96, mVelTCPRy);
	DDX_Control(pDX, IDC_EDIT_REAL_POS97, mVelTCPRz);
	DDX_Control(pDX, IDC_EDIT_REAL_POS98, mVelTCPRa);
	DDX_Control(pDX, IDC_EDIT_REAL_POS99, mVelTCPRb);
	DDX_Control(pDX, IDC_EDIT_REAL_POS100, mVelTCPRc);
	DDX_Control(pDX, IDC_EDIT2, mTimerCntLArm);
	DDX_Control(pDX, IDC_EDIT3, mTimerCntRArm);
	DDX_Control(pDX, IDC_EDIT_POS23, mTarTorL0);
	DDX_Control(pDX, IDC_EDIT_REAL_POS125, mTarTorL1);
	DDX_Control(pDX, IDC_EDIT_REAL_POS126, mTarTorL2);
	DDX_Control(pDX, IDC_EDIT_REAL_POS127, mTarTorL3);
	DDX_Control(pDX, IDC_EDIT_REAL_POS128, mTarTorL4);
	DDX_Control(pDX, IDC_EDIT_REAL_POS129, mTarTorL5);
	DDX_Control(pDX, IDC_EDIT_REAL_POS130, mTarTorL6);
	DDX_Control(pDX, IDC_EDIT_POS24, mTarTorR0);
	DDX_Control(pDX, IDC_EDIT_REAL_POS131, mTarTorR1);
	DDX_Control(pDX, IDC_EDIT_REAL_POS132, mTarTorR2);
	DDX_Control(pDX, IDC_EDIT_REAL_POS133, mTarTorR3);
	DDX_Control(pDX, IDC_EDIT_REAL_POS134, mTarTorR4);
	DDX_Control(pDX, IDC_EDIT_REAL_POS135, mTarTorR5);
	DDX_Control(pDX, IDC_EDIT_REAL_POS136, mTarTorR6);
	DDX_Control(pDX, IDC_EDIT_POS25, mCurTorL0);
	DDX_Control(pDX, IDC_EDIT_REAL_POS137, mCurTorL1);
	DDX_Control(pDX, IDC_EDIT_REAL_POS138, mCurTorL2);
	DDX_Control(pDX, IDC_EDIT_REAL_POS139, mCurTorL3);
	DDX_Control(pDX, IDC_EDIT_REAL_POS140, mCurTorL4);
	DDX_Control(pDX, IDC_EDIT_REAL_POS141, mCurTorL5);
	DDX_Control(pDX, IDC_EDIT_REAL_POS142, mCurTorL6);
	DDX_Control(pDX, IDC_EDIT_POS26, mCurTorR0);
	DDX_Control(pDX, IDC_EDIT_REAL_POS143, mCurTorR1);
	DDX_Control(pDX, IDC_EDIT_REAL_POS144, mCurTorR2);
	DDX_Control(pDX, IDC_EDIT_REAL_POS145, mCurTorR3);
	DDX_Control(pDX, IDC_EDIT_REAL_POS146, mCurTorR4);
	DDX_Control(pDX, IDC_EDIT_REAL_POS147, mCurTorR5);
	DDX_Control(pDX, IDC_EDIT_REAL_POS148, mCurTorR6);
}

BEGIN_MESSAGE_MAP(CSample2AxesControl_MFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_Start, &CSample2AxesControl_MFCDlg::OnBnClickedButtonStart)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDCANCEL, &CSample2AxesControl_MFCDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &CSample2AxesControl_MFCDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON5, &CSample2AxesControl_MFCDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CSample2AxesControl_MFCDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON2, &CSample2AxesControl_MFCDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CSample2AxesControl_MFCDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CSample2AxesControl_MFCDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON7, &CSample2AxesControl_MFCDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CSample2AxesControl_MFCDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CSample2AxesControl_MFCDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CSample2AxesControl_MFCDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON14, &CSample2AxesControl_MFCDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON11, &CSample2AxesControl_MFCDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CSample2AxesControl_MFCDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CSample2AxesControl_MFCDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON15, &CSample2AxesControl_MFCDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CSample2AxesControl_MFCDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &CSample2AxesControl_MFCDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CSample2AxesControl_MFCDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &CSample2AxesControl_MFCDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &CSample2AxesControl_MFCDlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON21, &CSample2AxesControl_MFCDlg::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON22, &CSample2AxesControl_MFCDlg::OnBnClickedButton22)

END_MESSAGE_MAP()


// CSample2AxesControl_MFCDlg message handlers

BOOL CSample2AxesControl_MFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	ret = NEC_LoadRtxApp( "C:\\Program Files\\NEXCOM\\NexECMRtx\\Lib\\NexECMRtx\\x32\\NexECMRtx.rtss" );
	if( ret != 0 ) { MessageBox("NEC_LoadRtxApp NexECMRtx.rtss failed!");}

	Sleep(2000);

	this->misUpdate = 0;
	this->TimerHandle = SetTimer( NULL, 100, NULL );

	mBn1.EnableWindow(false);
	mBn2.EnableWindow(false);
	mBn3.EnableWindow(false);
	mBn4.EnableWindow(false);
	mBn5.EnableWindow(false);
	mBn6.EnableWindow(false);
	mBn7.EnableWindow(false);
	mBn8.EnableWindow(false);
	mBn9.EnableWindow(false);
	mBn10.EnableWindow(false);
	mBn11.EnableWindow(false);
	mBn12.EnableWindow(false);
	mBn13.EnableWindow(false);
	mBn14.EnableWindow(false);
	mBn15.EnableWindow(false);
	mBn16.EnableWindow(false);
	mBn17.EnableWindow(false);
	mBn18.EnableWindow(false);
	mBn19.EnableWindow(false);
	mBn20.EnableWindow(false);
	mBn21.EnableWindow(false);
	mBn22.EnableWindow(false);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSample2AxesControl_MFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSample2AxesControl_MFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSample2AxesControl_MFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSample2AxesControl_MFCDlg::OnBnClickedButtonStart()
{
	HANDLE	sHServo_on = NULL;
	HANDLE	oBStart_Master = NULL;

	// Start EtherCAT Driver
	ret = NEC_StartDriver();
	if (ret != 0) { MessageBox("NEC_StarDriver failed!"); NEC_StopDriver(); return; }

	// Get EtherCAT Master ID
	ret = NEC_GetRtMasterId(&masterId);
	if (ret != 0) { MessageBox("NEC_GetRtMasterId failed!"); NEC_StopDriver(); return; }

	// Reset EtherCAT Master
	ret = NEC_ResetEcMaster(masterId);
	if (ret != 0) { MessageBox("NEC_ResetEcMaster failed!"); NEC_StopDriver(); return; }

	// Load ENI file
	ret = NEC_LoadNetworkConfig(masterId, "D:\\Massage\\MaSaG_16_Devices.xml", 1);
	if (ret != 0) { MessageBox("NEC_StartNetworkEx failed!"); NEC_StopDriver(); return; }

	// Stop EtherCAT Driver
	NEC_StopDriver();
		
	// RtOpenSharedMemory
	ret = NEC_LoadRtxApp("D:\\Massage\\Massage_MFC_20170105\\Sample_2Layer\\VS2015\\Sample2AxesControl_MFC\\RtssDebug\\MaSaG_RTX.rtss");
	if (ret != 0) { MessageBox("NEC_LoadRtxApp RTX_app failed!"); NEC_StopDriver(); return; }

	RtPrintf("mark\n");
	
	sHServo_on = RtOpenSharedMemory( SHM_MAP_ALL_ACCESS , 0 , SHM_NAME , &location );
	// Shared Memory Pointer Assignment
	USER_DAT *p;
	p = (USER_DAT *) location;
	p->_rtxCMD_ST.Command = READY_CMD;
			
	// RtOpenEvent
	oBStart_Master = RtOpenEvent( NULL, 0, EVN_NAME);
	if( oBStart_Master == NULL ) { return ; }
	// RtSetEvent
	RtSetEvent(oBStart_Master);

	this->misUpdate = 1;

	mBn1.EnableWindow(true);
	mBn2.EnableWindow(true);
	mBn3.EnableWindow(true);
	mBn4.EnableWindow(true);
	mBn5.EnableWindow(true);
	mBn6.EnableWindow(true);
	mBn7.EnableWindow(true);
	mBn8.EnableWindow(true);
	mBn9.EnableWindow(true);
	mBn10.EnableWindow(true);
	mBn11.EnableWindow(true);
	mBn12.EnableWindow(true);
	mBn13.EnableWindow(true);
	mBn14.EnableWindow(true);
	mBn15.EnableWindow(true);
	mBn16.EnableWindow(true);
	mBn17.EnableWindow(true);
	mBn18.EnableWindow(true);
	mBn19.EnableWindow(true);
	mBn20.EnableWindow(true);
	mBn21.EnableWindow(true);
	mBn22.EnableWindow(true);

}


void CSample2AxesControl_MFCDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	if( this->misUpdate )
	{
		USER_DAT *p;
		p = (USER_DAT *) location;

		CString t;

		// Command State
		switch (p->_rtxCMD_ST.Command)
		{
		case READY_CMD:
			mCMDState.SetWindowText(_T("READY_CMD"));
			break;
		case TEACH_CMD:
			mCMDState.SetWindowText(_T("TEACH_CMD"));
			break;
		case PLAY_CMD:
			mCMDState.SetWindowText(_T("PLAY_CMD"));
			break;
		case TEST3_CMD:
			mCMDState.SetWindowText(_T("TEST3_CMD"));
			break;
		case TEST4_CMD:
			mCMDState.SetWindowText(_T("TEST4_CMD"));
			break;
		case TEST5_CMD:
			mCMDState.SetWindowText(_T("TEST5_CMD"));
			break;
		case TEST6_CMD:
			mCMDState.SetWindowText(_T("TEST6_CMD"));
			break;
		case TEST7_CMD:
			mCMDState.SetWindowText(_T("TEST7_CMD"));
			break;
		case FREE_MODE_CMD:
			mCMDState.SetWindowText(_T("FREE_MODE_CMD"));
			break;
		case MIRROR_CMD:
			mCMDState.SetWindowText(_T("MIRROR_CMD"));
			break;
		case MIMMIC_CMD:
			mCMDState.SetWindowText(_T("MIMMIC_CMD"));
			break;
		case ALIGN_CMD:
			mCMDState.SetWindowText(_T("ALIGN_CMD"));
			break;
		case TEST12_CMD:
			mCMDState.SetWindowText(_T("TEST12_CMD"));
			break;
		case TEST13_CMD:
			mCMDState.SetWindowText(_T("TEST13_CMD"));
			break;
		case TEST14_CMD:
			mCMDState.SetWindowText(_T("TEST14_CMD"));
			break;
		case TEST15_CMD:
			mCMDState.SetWindowText(_T("TEST15_CMD"));
			break;
		case TEST16_CMD:
			mCMDState.SetWindowText(_T("TEST16_CMD"));
			break;
		case TEST17_CMD:
			mCMDState.SetWindowText(_T("TEST17_CMD"));
			break;
		case 18:
			mCMDState.SetWindowText(_T("Under Constructing"));
			break;
		case 19:
			mCMDState.SetWindowText(_T("Under Constructing"));
			break;
		case 20:
			mCMDState.SetWindowText(_T("Under Constructing"));
			break;
		case SERVOON_CMD:
			mCMDState.SetWindowText(_T("SERVOON_CMD"));
			break;
		case SERVOOFF_CMD:
			mCMDState.SetWindowText(_T("SERVOOFF_CMD"));
			break;
		case HOME_CMD:
			mCMDState.SetWindowText(_T("HOME_CMD"));
			break;
		case FAULTRESET_CMD:
			mCMDState.SetWindowText(_T("FAULTRESET_CMD"));
			break;
		case PRINT_CMD:
			mCMDState.SetWindowText(_T("PRINT_CMD"));
			break;
		case 26:
			mCMDState.SetWindowText(_T("Under Constructing"));
			break;
		case ESCAPE_CMD:
			mCMDState.SetWindowText(_T("ESCAPE_CMD"));
			break;
		default:
			mCMDState.SetWindowText(_T("Undefined"));
			break;
		
		}


		// Actual Position, Encoder Counts
		t.Format(_T("%f"), p->_rtxLArm.curPos[0]);		mActPosL0.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.curPos[1]);		mActPosL1.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.curPos[2]);		mActPosL2.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.curPos[3]);		mActPosL3.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.curPos[4]);		mActPosL4.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.curPos[5]);		mActPosL5.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.curPos[6]);		mActPosL6.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.curPos[0]);		mActPosR0.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.curPos[1]);		mActPosR1.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.curPos[2]);		mActPosR2.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.curPos[3]);		mActPosR3.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.curPos[4]);		mActPosR4.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.curPos[5]);		mActPosR5.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.curPos[6]);		mActPosR6.SetWindowText(t);
		
		// Target Position
		t.Format(_T("%f"), p->_rtxLArm.tarPos[0]);		mTgtPosL0.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.tarPos[1]);		mTgtPosL1.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.tarPos[2]);		mTgtPosL2.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.tarPos[3]);		mTgtPosL3.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.tarPos[4]);		mTgtPosL4.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.tarPos[5]);		mTgtPosL5.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.tarPos[6]);		mTgtPosL6.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.tarPos[0]);		mTgtPosR0.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.tarPos[1]);		mTgtPosR1.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.tarPos[2]);		mTgtPosR2.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.tarPos[3]);		mTgtPosR3.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.tarPos[4]);		mTgtPosR4.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.tarPos[5]);		mTgtPosR5.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.tarPos[6]);		mTgtPosR6.SetWindowText(t);

		// Error Position
		t.Format(_T("%f"), p->_rtxLArm.errPos[0]);		mErrPosL0.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.errPos[1]);		mErrPosL1.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.errPos[2]);		mErrPosL2.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.errPos[3]);		mErrPosL3.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.errPos[4]);		mErrPosL4.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.errPos[5]);		mErrPosL5.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.errPos[6]);		mErrPosL6.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.errPos[0]);		mErrPosR0.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.errPos[1]);		mErrPosR1.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.errPos[2]);		mErrPosR2.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.errPos[3]);		mErrPosR3.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.errPos[4]);		mErrPosR4.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.errPos[5]);		mErrPosR5.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.errPos[6]);		mErrPosR6.SetWindowText(t);

		// Planned Position of Joint
		t.Format(_T("%f"), p->_rtxLArm.plnPos[0]);		mPlnPosL0.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.plnPos[1]);		mPlnPosL1.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.plnPos[2]);		mPlnPosL2.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.plnPos[3]);		mPlnPosL3.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.plnPos[4]);		mPlnPosL4.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.plnPos[5]);		mPlnPosL5.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.plnPos[6]);		mPlnPosL6.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.plnPos[0]);		mPlnPosR0.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.plnPos[1]);		mPlnPosR1.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.plnPos[2]);		mPlnPosR2.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.plnPos[3]);		mPlnPosR3.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.plnPos[4]);		mPlnPosR4.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.plnPos[5]);		mPlnPosR5.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.plnPos[6]);		mPlnPosR6.SetWindowText(t);
		
		// Actual Velocity of Joint
		t.Format(_T("%f"), p->_rtxLArm.curVel[0]);		mActVelL0.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.curVel[1]);		mActVelL1.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.curVel[2]);		mActVelL2.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.curVel[3]);		mActVelL3.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.curVel[4]);		mActVelL4.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.curVel[5]);		mActVelL5.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.curVel[6]);		mActVelL6.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.curVel[0]);		mActVelR0.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.curVel[1]);		mActVelR1.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.curVel[2]);		mActVelR2.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.curVel[3]);		mActVelR3.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.curVel[4]);		mActVelR4.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.curVel[5]);		mActVelR5.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.curVel[6]);		mActVelR6.SetWindowText(t);
		
		// Actual Torque of Joint
		t.Format(_T("%f"), p->_rtxLArm.actTorque[0]);	mCurTorL0.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.actTorque[1]);	mCurTorL1.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.actTorque[2]);	mCurTorL2.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.actTorque[3]);	mCurTorL3.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.actTorque[4]);	mCurTorL4.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.actTorque[5]);	mCurTorL5.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.actTorque[6]);	mCurTorL6.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.actTorque[0]);	mCurTorR0.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.actTorque[1]);	mCurTorR1.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.actTorque[2]);	mCurTorR2.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.actTorque[3]);	mCurTorR3.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.actTorque[4]);	mCurTorR4.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.actTorque[5]);	mCurTorR5.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.actTorque[6]);	mCurTorR6.SetWindowText(t);		
		
		// Target Torque of Joint
		t.Format(_T("%f"), p->_rtxLArm.tarTorque[0]);	mTarTorL0.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.tarTorque[1]);	mTarTorL1.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.tarTorque[2]);	mTarTorL2.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.tarTorque[3]);	mTarTorL3.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.tarTorque[4]);	mTarTorL4.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.tarTorque[5]);	mTarTorL5.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.tarTorque[6]);	mTarTorL6.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.tarTorque[0]);	mTarTorR0.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.tarTorque[1]);	mTarTorR1.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.tarTorque[2]);	mTarTorR2.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.tarTorque[3]);	mTarTorR3.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.tarTorque[4]);	mTarTorR4.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.tarTorque[5]);	mTarTorR5.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.tarTorque[6]);	mTarTorR6.SetWindowText(t);

		// Force-Torque Sensor, Fx, Fy, Fz, Tx, Ty, Tz
		t.Format(_T("%f"), p->_rtxLArm.FTSensor[0]);	mFxL.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.FTSensor[1]);	mFyL.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.FTSensor[2]);	mFzL.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.FTSensor[3]);	mTxL.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.FTSensor[4]);	mTyL.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.FTSensor[5]);	mTzL.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.FTSensor[0]);	mFxR.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.FTSensor[1]);	mFyR.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.FTSensor[2]);	mFzR.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.FTSensor[3]);	mTxR.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.FTSensor[4]);	mTyR.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.FTSensor[5]);	mTzR.SetWindowText(t);

		// current TCP
		t.Format(_T("%f"), p->_rtxLArm.curTCP[0]);		mCurTCPLx.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.curTCP[1]);		mCurTCPLy.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.curTCP[2]);		mCurTCPLz.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.curTCP[3]);		mCurTCPLa.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.curTCP[4]);		mCurTCPLb.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.curTCP[5]);		mCurTCPLc.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.curTCP[0]);		mCurTCPRx.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.curTCP[1]);		mCurTCPRy.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.curTCP[2]);		mCurTCPRz.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.curTCP[3]);		mCurTCPRa.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.curTCP[4]);		mCurTCPRb.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.curTCP[5]);		mCurTCPRc.SetWindowText(t);

		// target TCP
		t.Format(_T("%f"), p->_rtxLArm.tarTCP[0]);		mTarTCPLx.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.tarTCP[1]);		mTarTCPLy.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.tarTCP[2]);		mTarTCPLz.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.tarTCP[3]);		mTarTCPLa.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.tarTCP[4]);		mTarTCPLb.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.tarTCP[5]);		mTarTCPLc.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.tarTCP[0]);		mTarTCPRx.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.tarTCP[1]);		mTarTCPRy.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.tarTCP[2]);		mTarTCPRz.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.tarTCP[3]);		mTarTCPRa.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.tarTCP[4]);		mTarTCPRb.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.tarTCP[5]);		mTarTCPRc.SetWindowText(t);

		// error TCP
		t.Format(_T("%f"), p->_rtxLArm.errTCP[0]);		mErrTCPLx.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.errTCP[1]);		mErrTCPLy.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.errTCP[2]);		mErrTCPLz.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.errTCP[3]);		mErrTCPLa.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.errTCP[4]);		mErrTCPLb.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.errTCP[5]);		mErrTCPLc.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.errTCP[0]);		mErrTCPRx.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.errTCP[1]);		mErrTCPRy.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.errTCP[2]);		mErrTCPRz.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.errTCP[3]);		mErrTCPRa.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.errTCP[4]);		mErrTCPRb.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.errTCP[5]);		mErrTCPRc.SetWindowText(t);

		// planned TCP
		t.Format(_T("%f"), p->_rtxLArm.plnTCP[0]);		mPlnTCPLx.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.plnTCP[1]);		mPlnTCPLy.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.plnTCP[2]);		mPlnTCPLz.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.plnTCP[3]);		mPlnTCPLa.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.plnTCP[4]);		mPlnTCPLb.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.plnTCP[5]);		mPlnTCPLc.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.plnTCP[0]);		mPlnTCPRx.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.plnTCP[1]);		mPlnTCPRy.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.plnTCP[2]);		mPlnTCPRz.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.plnTCP[3]);		mPlnTCPRa.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.plnTCP[4]);		mPlnTCPRb.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.plnTCP[5]);		mPlnTCPRc.SetWindowText(t);

		// TCP velocity
		t.Format(_T("%f"), p->_rtxLArm.velTCP[0]);		mVelTCPLx.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.velTCP[1]);		mVelTCPLy.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.velTCP[2]);		mVelTCPLz.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.velTCP[3]);		mVelTCPLa.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.velTCP[4]);		mVelTCPLb.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxLArm.velTCP[5]);		mVelTCPLc.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.velTCP[0]);		mVelTCPRx.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.velTCP[1]);		mVelTCPRy.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.velTCP[2]);		mVelTCPRz.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.velTCP[3]);		mVelTCPRa.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.velTCP[4]);		mVelTCPRb.SetWindowText(t);
		t.Format(_T("%f"), p->_rtxRArm.velTCP[5]);		mVelTCPRc.SetWindowText(t);

		// is_busy flag
		t.Format(_T("%d"), p->_rtxLArm.cntTimer);		mTimerCntLArm.SetWindowText(t);
		t.Format(_T("%d"), p->_rtxRArm.cntTimer);		mTimerCntRArm.SetWindowText(t);

	}
	CDialogEx::OnTimer(nIDEvent);

	
}


void CSample2AxesControl_MFCDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	USER_DAT *p;
	p = (USER_DAT *)location;
	p->_rtxCMD_ST.Command = ESCAPE_CMD;
	CDialogEx::OnCancel();
}


void CSample2AxesControl_MFCDlg::OnBnClickedButton1()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
	USER_DAT *p;
	p = (USER_DAT *)location;
	p->_rtxCMD_ST.Command = SERVOON_CMD;

}

void CSample2AxesControl_MFCDlg::OnBnClickedButton2()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
	USER_DAT *p;
	p = (USER_DAT *)location;
	p->_rtxCMD_ST.Command = SERVOOFF_CMD;
}


void CSample2AxesControl_MFCDlg::OnBnClickedButton3()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
	USER_DAT *p;
	p = (USER_DAT *)location;
	p->_rtxCMD_ST.Command = HOME_CMD;
}


void CSample2AxesControl_MFCDlg::OnBnClickedButton4()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
	USER_DAT *p;
	p = (USER_DAT *)location;
	p->_rtxCMD_ST.Command = FAULTRESET_CMD;
}


void CSample2AxesControl_MFCDlg::OnBnClickedButton5()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
	USER_DAT *p;
	p = (USER_DAT *)location;
	p->_rtxCMD_ST.Command = PRINT_CMD;
}


void CSample2AxesControl_MFCDlg::OnBnClickedButton6()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
	USER_DAT *p;
	p = (USER_DAT *)location;
	p->_rtxCMD_ST.Command = TEACH_CMD;
}


void CSample2AxesControl_MFCDlg::OnBnClickedButton7()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
	USER_DAT *p;
	p = (USER_DAT *)location;
	p->_rtxCMD_ST.Command = PLAY_CMD;
}


void CSample2AxesControl_MFCDlg::OnBnClickedButton8()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
	USER_DAT *p;
	p = (USER_DAT *)location;
	p->_rtxCMD_ST.Command = TEST3_CMD;
}


void CSample2AxesControl_MFCDlg::OnBnClickedButton9()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
	USER_DAT *p;
	p = (USER_DAT *)location;
	p->_rtxCMD_ST.Command = TEST4_CMD;
}


void CSample2AxesControl_MFCDlg::OnBnClickedButton10()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
	USER_DAT *p;
	p = (USER_DAT *)location;
	p->_rtxCMD_ST.Command = TEST5_CMD;
}


void CSample2AxesControl_MFCDlg::OnBnClickedButton11()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
	USER_DAT *p;
	p = (USER_DAT *)location;
	p->_rtxCMD_ST.Command = TEST6_CMD;
}


void CSample2AxesControl_MFCDlg::OnBnClickedButton12()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
	USER_DAT *p;
	p = (USER_DAT *)location;
	p->_rtxCMD_ST.Command = TEST7_CMD;
}


void CSample2AxesControl_MFCDlg::OnBnClickedButton13()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
	USER_DAT *p;
	p = (USER_DAT *)location;
	p->_rtxCMD_ST.Command = FREE_MODE_CMD;
}


void CSample2AxesControl_MFCDlg::OnBnClickedButton14()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
	USER_DAT *p;
	p = (USER_DAT *)location;
	p->_rtxCMD_ST.Command = MIRROR_CMD;
}



void CSample2AxesControl_MFCDlg::OnBnClickedButton15()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
	USER_DAT *p;
	p = (USER_DAT *)location;
	p->_rtxCMD_ST.Command = MIMMIC_CMD;
}



void CSample2AxesControl_MFCDlg::OnBnClickedButton16()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
	USER_DAT *p;
	p = (USER_DAT *)location;
	p->_rtxCMD_ST.Command = ALIGN_CMD;
}


void CSample2AxesControl_MFCDlg::OnBnClickedButton17()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
	USER_DAT *p;
	p = (USER_DAT *)location;
	p->_rtxCMD_ST.Command = TEST12_CMD;
}


void CSample2AxesControl_MFCDlg::OnBnClickedButton18()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
	USER_DAT *p;
	p = (USER_DAT *)location;
	p->_rtxCMD_ST.Command = TEST13_CMD;
}


void CSample2AxesControl_MFCDlg::OnBnClickedButton19()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
	USER_DAT *p;
	p = (USER_DAT *)location;
	p->_rtxCMD_ST.Command = TEST14_CMD;
}


void CSample2AxesControl_MFCDlg::OnBnClickedButton20()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
	USER_DAT *p;
	p = (USER_DAT *)location;
	p->_rtxCMD_ST.Command = TEST15_CMD;
}


void CSample2AxesControl_MFCDlg::OnBnClickedButton21()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
	USER_DAT *p;
	p = (USER_DAT *)location;
	p->_rtxCMD_ST.Command = TEST16_CMD;
}


void CSample2AxesControl_MFCDlg::OnBnClickedButton22()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
	USER_DAT *p;
	p = (USER_DAT *)location;
	p->_rtxCMD_ST.Command = TEST17_CMD;
}


