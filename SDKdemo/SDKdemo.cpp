


#include "stdafx.h"
#include "SDKdemo.h"
#include "SDKdemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSDKdemoApp

BEGIN_MESSAGE_MAP(CSDKdemoApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()




CSDKdemoApp::CSDKdemoApp()
{

	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

}




CSDKdemoApp theApp;




BOOL CSDKdemoApp::InitInstance()
{
// TODO: 调用 AfxInitRichEdit2() 以初始化 richedit2 库。\n"
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);

	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);
	AfxInitRichEdit();

	AfxInitRichEdit2();
	CWinApp::InitInstance();


	AfxEnableControlContainer();


	CShellManager *pShellManager = new CShellManager;

	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));


	SetRegistryKey(_T("Init"));

	CSDKdemoDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{

	}
	else if (nResponse == IDCANCEL)
	{

	}
	else if (nResponse == -1)
	{

	}


	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

#ifndef _AFXDLL
	ControlBarCleanUp();
#endif

	return FALSE;
}

