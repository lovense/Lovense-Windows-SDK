

//

#include "stdafx.h"
#include <iostream>
#include <lmshare.h>
#include <thread>

#include "SDKdemo.h"
#include "SDKdemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif




class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();


#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    


protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()






CSDKdemoDlg::CSDKdemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SDKDEMO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSDKdemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_toyListInfo);
	DDX_Control(pDX, IDC_COMBO2, m_cmdList);
	DDX_Control(pDX, IDC_COMBO3, m_paramList);
	DDX_Control(pDX, IDC_COMBO4, m_combToyName);
	DDX_Control(pDX, IDC_BUTTON1, m_btnSearch);
	DDX_Control(pDX, IDC_BUTTON2, m_btnStop);
	DDX_Control(pDX, IDC_EDIT1, m_editToken);
	DDX_Control(pDX, IDC_TEXT_BETTARY, m_txBetarry);
	DDX_Control(pDX, IDC_RICHEDIT_OUTPUT_APP_LOG, m_richedit_app_output);
}

BEGIN_MESSAGE_MAP(CSDKdemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CSDKdemoDlg::OnBnClickedsearchButton)
	ON_BN_CLICKED(IDC_BUTTON2, &CSDKdemoDlg::OnBnClickedStopSearchButton)
	ON_BN_CLICKED(IDC_SEND_BUTTON, &CSDKdemoDlg::OnBnClickedSendButton)
	ON_BN_CLICKED(IDC_LIGHT_OPEN_BUTTON, &CSDKdemoDlg::OnBnClickedLightOpenButton)
	ON_BN_CLICKED(IDC_LIGHT_CLOSE_BUTTON, &CSDKdemoDlg::OnBnClickedLightCloseButton)
	ON_BN_CLICKED(IDC_LIGHT_FLASH_BUTTON, &CSDKdemoDlg::OnBnClickedLightFlashButton)
	ON_BN_CLICKED(IDC_BUTTON_CONNECTED, &CSDKdemoDlg::OnBnClickedButtonConnected)
	ON_BN_CLICKED(IDC_BUTTON_DISCONNECTED, &CSDKdemoDlg::OnBnClickedButtonDisconnected)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CSDKdemoDlg::OnCbnSelchangeToyID)
	ON_EN_CHANGE(IDC_EDIT1, &CSDKdemoDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()




BOOL CSDKdemoDlg::OnInitDialog()
{

	CDialogEx::OnInitDialog();


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
	//AfxInitRichEdit2();

	SetIcon(m_hIcon, TRUE);			
	SetIcon(m_hIcon, FALSE);		
	const wchar_t* t = NULL;
	//wcscmp(t, _T("Lovense"));
	m_mapCmd[_T("Vibrate-(Suport All Toy)-Param(0~20)")] = CLovenseToy::CmdType::COMMAND_VIBRATE;
	m_mapCmd[_T("Rotate-(Suport Nora)-Param(0~20)")] = CLovenseToy::CmdType::COMMAND_ROTATE;
	m_mapCmd[_T("Clockwise Rotate-(Suport Nora)-Param(0~20)")] = CLovenseToy::CmdType::COMMAND_ROTATE_CLOCKWISE;
	m_mapCmd[_T("Anticlockwise Rotate-(Suport Nora)-Param(0~20)")] = CLovenseToy::CmdType::COMMAND_ROTATE_ANTI_CLOCKWISE;
	m_mapCmd[_T("Change Rotate-(Suport Nora)-No Param")] = CLovenseToy::CmdType::COMMAND_ROTATE_CHANGE;

	m_mapCmd[_T("Vibrate-Activate the first one(Suport Edge)-Param(0~20)")] = CLovenseToy::CmdType::COMMAND_VIBRATE1;
	m_mapCmd[_T("Vibrate-Activate the second one(Suport Edge)-Param(0~20)")] = CLovenseToy::CmdType::COMMAND_VIBRATE2;

	m_mapCmd[_T("Flash Light-Flashing Light(Suport All Toy)-No Param")] = CLovenseToy::CmdType::COMMAND_FLASH;
	m_mapCmd[_T("Light On-(Suport All Toy)-No Param")] = CLovenseToy::CmdType::COMMAND_LIGHT_ON;
	m_mapCmd[_T("Light Off-(Suport All Toy)-No Param")] = CLovenseToy::CmdType::COMMAND_LIGHT_OFF;
	m_mapCmd[_T("Light Off-(Suport Domi)-No Param")] = CLovenseToy::CmdType::COMMAND_ALIGHT_OFF;
	m_mapCmd[_T("Light On-(Suport Domi)-No Param")] = CLovenseToy::CmdType::COMMAND_ALIGHT_ON;
    m_mapCmd[_T("Air In-(Suport Max)-Param(1~3)")] = CLovenseToy::CmdType::COMMAND_AIR_IN;
	m_mapCmd[_T("Air Out-(Suport Max)-Param(1~3)")] = CLovenseToy::CmdType::COMMAND_AIR_OUT;
	m_mapCmd[_T("Air Auto-(Suport Max)-Param(0~3)")] = CLovenseToy::CmdType::COMMAND_AIR_AUTO;
	m_mapCmd[_T("Power Off-(Suport All Toy)-No Param")] = CLovenseToy::CmdType::COMMAND_POWER_OFF;
	m_mapCmd[_T("Start Move-(Suport Max,Nora)-10<=n<=99")] = CLovenseToy::CmdType::COMMAND_START_MOVE;
	m_mapCmd[_T("Stop Move-(Suport Max,Nora)-No Param")] = CLovenseToy::CmdType::COMMAND_STOP_MOVE;

	std::map<CString, int>::iterator iterMap = m_mapCmd.begin();
	while (iterMap != m_mapCmd.end())
	{
		m_cmdList.AddString(iterMap->first);
		++iterMap;
	}

	m_paramList.AddString(_T("0"));
	m_paramList.AddString(_T("1"));
	m_paramList.AddString(_T("2"));
	m_paramList.AddString(_T("3"));

	m_paramList.AddString(_T("4"));
	m_paramList.AddString(_T("5"));
	m_paramList.AddString(_T("6"));
	m_paramList.AddString(_T("7"));
	m_paramList.AddString(_T("8"));
	m_paramList.AddString(_T("9"));
	m_paramList.AddString(_T("10"));
	m_paramList.AddString(_T("11"));
	m_paramList.AddString(_T("12"));
	m_paramList.AddString(_T("13"));
	m_paramList.AddString(_T("14"));
	m_paramList.AddString(_T("15"));
	m_paramList.AddString(_T("16"));
	m_paramList.AddString(_T("17"));
	m_paramList.AddString(_T("18"));
	m_paramList.AddString(_T("19"));
	m_paramList.AddString(_T("20"));
	m_cmdList.SetCurSel(0);
	m_paramList.SetCurSel(4);

	m_editToken.SetWindowTextW(_T(""));

	return TRUE;  // 
}

void CSDKdemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		if (nID == SC_CLOSE)
		{
			ReleaseLovenseToyManager();
		}
		CDialogEx::OnSysCommand(nID, lParam);
	}
}



void CSDKdemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); //

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		//
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}


HCURSOR CSDKdemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CSDKdemoDlg::OnBnClickedsearchButton()
{
	this->OutPutAppLog(L"[App] OnClick Start Search!");

	TCHAR path[MAX_PATH];
	GetModuleFileName(NULL,path,MAX_PATH);
	m_toyListInfo.ResetContent();
	m_combToyName.ResetContent();
	m_search_toy.clear();
	//m_mapToyInfo.clear();
	CLovenseToyManager *manager = GetLovenseToyManager();
	
	CString token;
	m_editToken.GetWindowText(token);
	token = token.TrimLeft();
	token = token.TrimRight();
	std::string strToken = CW2A(token.GetString());
	if (manager->SetDeveloperToken(strToken.c_str()))
	{
		
		manager->RegisterEventCallBack(this);
		int ret = manager->StartSearchToy();
		if (ret == CLovenseToy::Error::TOYERR_SUCCESS)
		{
			m_btnSearch.EnableWindow(FALSE);
			m_btnStop.EnableWindow(TRUE);
		}
		else if (ret == CLovenseToy::Error::TOYERR_DEVICE_IS_SEARCHING)
		{
			this->OutPutAppLog(_T("Device is searching..."));
		}
	}
	else
		this->OutPutAppLog(_T("Invalid token"));


}


void CSDKdemoDlg::OnBnClickedStopSearchButton()
{
	this->OutPutAppLog(L"[App] OnClick Stop Search");
	CLovenseToyManager *manager = GetLovenseToyManager();
	manager->StopSearchToy();
}

void CSDKdemoDlg::AddToyInfo(LPCTSTR toyID, LPCTSTR toyName)
{

	std::wstring info = toyID;
	m_toyListInfo.AddString(info.c_str());
	m_toyListInfo.SetCurSel(0);
}

//send command to toy
void CSDKdemoDlg::OnBnClickedSendButton()
{
	CString strID;
	m_toyListInfo.GetLBText(m_toyListInfo.GetCurSel(), strID);

	CString strCmd;
	m_cmdList.GetLBText(m_cmdList.GetCurSel(), strCmd);

	CString strParam;
	m_paramList.GetLBText(m_paramList.GetCurSel(), strParam);
	CLovenseToyManager *manager = GetLovenseToyManager();

	std::string toyID;
	toyID = CW2A(strID.GetString());
	std::string param = CW2A(strParam.GetString());
	
	CLovenseToy::CmdType cmdType = CLovenseToy::CmdType::COMMAND_VIBRATE;
	int curlCmd = m_cmdList.GetCurSel();
	m_cmdList.GetLBText(m_cmdList.GetCurSel(), strCmd);
	cmdType = (CLovenseToy::CmdType)m_mapCmd[strCmd];

	CString log;
	log.Format(_T("[App] OnClick Send Cmd: id=%s type=%d param=%s"), strID, cmdType, strParam);
	this->OutPutAppLog(log);
	clock_t startTime = clock();
	int error = manager->SendCommand(toyID.c_str(), cmdType, atoi(param.c_str()));
	clock_t endTime = clock();
	log.Format(_T("[App] Result: ret = %d (time = %dms)"), error, endTime-startTime);
	this->OutPutAppLog(log);
}

void CSDKdemoDlg::LovenseErrorOutPut(int errorCode, const char *errorMsg)
{
	if (errorCode == CLovenseToy::Error::TOYERR_INVALIDTOKEN)
	{
		MessageBox(_T("Invalid token!"), _T("Error"), MB_OK);
	}

	CString log;
	log.Format(_T("[App Callback] errorcode=%d"), errorCode, errorMsg?CString(errorMsg):_T(""));
	this->OutPutAppLog(log);
}


void CSDKdemoDlg::LovenseDidSearchStart()
{
	std::cout << "LovenseDidSearchStart"<< std::endl;
	m_btnSearch.EnableWindow(FALSE);
	m_btnStop.EnableWindow(TRUE);
	this->OutPutAppLog(_T("[App Callback] SDK Did Search Start"));
}

void CSDKdemoDlg::LovenseDidSearchEnd()
{
	std::cout << "LovenseDidSearchEnd" << std::endl;
	m_btnSearch.EnableWindow(TRUE);
	m_btnStop.EnableWindow(FALSE);
	this->OutPutAppLog(_T("[App Callback] SDK Did Search End"));
}

void CSDKdemoDlg::LovenseSearchingToys(lovense_toy_info_t* info)
{
	if (info) {

		CString log;
		log.Format(_T("[App Callback] found toy:name=%s id=%s"), CString(info->toy_name), CString(info->toy_id));
		this->OutPutAppLog(log);

		if (info->toy_id)
		{
			TMap_Iterator iter = m_search_toy.find(CString(info->toy_id));
			if (iter == m_search_toy.end())
			{
				std::shared_ptr<MyToyInfo> pMyToy = std::make_shared<MyToyInfo>();
				pMyToy->toy_id = info->toy_id;
				if (info->toy_name)
				{
					pMyToy->toy_name = info->toy_name;
				}
				pMyToy->toy_type = info->toy_type;
				pMyToy->toy_battery = info->toy_battery;
				pMyToy->toy_connected = info->toy_connected;

				m_search_toy.insert(std::make_pair(pMyToy->toy_id, pMyToy));
				m_toyListInfo.AddString(pMyToy->toy_id);
				m_toyListInfo.SetCurSel(0);

				m_combToyName.AddString(pMyToy->toy_name);
				m_combToyName.SetCurSel(0);
			}
			else
			{
				if (info->toy_name)
					iter->second->toy_name = info->toy_name;
				iter->second->toy_battery = info->toy_battery;
				iter->second->toy_connected = info->toy_connected;
				iter->second->toy_type = info->toy_type;
			}
		}
	}
}

void CSDKdemoDlg::LovenseSendCmdResult(const char * szToyID, CLovenseToy::CmdType cmd, const char *result, CLovenseToy::Error errorCode)
{
	if (szToyID)
	{
		CString log;
		log.Format(_T("[App Callback] Send Cmd Result:toyId=%s cmd=%d result=%s erorcode=%d" ), CString(szToyID), cmd, result?CString(result):_T(""),errorCode);
		this->OutPutAppLog(log);
	}
}

void CSDKdemoDlg::LovenseDidSendCmdStart()
{
	this->OutPutAppLog(_T("[App Callback] SDK Did Send Cmd Start!"));
}

void CSDKdemoDlg::LovenseDidSendCmdEnd()
{
	this->OutPutAppLog(_T("[App Callback] SDK Did Send Cmd End!"));
}


void CSDKdemoDlg::LovenseToyConnectedStatus(const char *szToyID, bool isConnected)
{
	if(isConnected)
		std::cout << "Toy:" << szToyID << " is connected!"<<std::endl;
	else
		std::cout << "Toy:" << szToyID << " is disConnected!" << std::endl;
	CString log;
	log.Format(_T("[App Callback] Toy Connected Update:toyId=%s connected=%d"),CString("szToyID"),isConnected);
	this->OutPutAppLog(log);
}

void CSDKdemoDlg::OnBnClickedLightOpenButton()
{
	CString strID;
	m_toyListInfo.GetLBText(m_toyListInfo.GetCurSel(), strID);
	this->OutPutAppLog(_T("[App] OnClick Did Send Light On Cmd"));

	CLovenseToyManager *manager = GetLovenseToyManager();
	std::string toyID;
	toyID = CW2A(strID.GetString());
	clock_t startTime = clock();
	int error = manager->SendCommand(toyID.c_str(), CLovenseToy::CmdType::COMMAND_LIGHT_ON, 0);
	clock_t endTime = clock();
	CString log;
	log.Format(_T("[App] Result: ret = %d (time = %dms)"), error, endTime - startTime);
	this->OutPutAppLog(log);
}


void CSDKdemoDlg::OnBnClickedLightCloseButton()
{

	CString strID;
	m_toyListInfo.GetLBText(m_toyListInfo.GetCurSel(), strID);
	this->OutPutAppLog(_T("[App] OnClick Did Send Light Off Cmd"));

	CLovenseToyManager *manager = GetLovenseToyManager();
	std::string toyID;
	toyID = CW2A(strID.GetString());
	clock_t startTime = clock();
	int error = manager->SendCommand(toyID.c_str(), CLovenseToy::CmdType::COMMAND_LIGHT_OFF, 0);
	clock_t endTime = clock();
	CString log;
	log.Format(_T("[App] Result: ret = %d (time = %dms)"), error, endTime - startTime);
	this->OutPutAppLog(log);
}

void CSDKdemoDlg::OnBnClickedLightFlashButton()
{
	CString strID;
	m_toyListInfo.GetLBText(m_toyListInfo.GetCurSel(), strID);
	this->OutPutAppLog(_T("[App] OnClick Did Send Get Battery Cmd"));

	std::string toyID;
	toyID = CW2A(strID.GetString());

	CLovenseToyManager *manager = GetLovenseToyManager();
	int battery = 0;
	int ret = manager->GetToyBattery(toyID.c_str(), &battery);
	if (ret == CLovenseToy::Error::TOYERR_SUCCESS)
	{
		CString log;
		log.Format(_T("[App Callback] Toy Battery:toyId=%s Battery=%d"), CString("szToyID"), battery);
		this->OutPutAppLog(log);
	}
	static bool run_one = false;
	if (!run_one)
	{
		run_one = true;
		
		std::thread thread1 = std::thread([&]() {
			CString strID;
			m_toyListInfo.GetLBText(m_toyListInfo.GetCurSel(), strID);
			this->OutPutAppLog(_T("[App] OnClick Did Send Get Battery Cmd"));
			std::string toyID;
			toyID = CW2A(strID.GetString());

			while (1)
			{
				Sleep(5000);
				int battery = 0;
				CLovenseToyManager* manager = GetLovenseToyManager();
				CString log;
				log.Format(_T("[App] Send Get Battery Cmd: id = %s"), strID);
				this->OutPutAppLog(log);
				int ret = manager->GetToyBattery(toyID.c_str(), &battery);
				log.Format(_T("[App] ret:%d id:%s battery:%d"), ret, strID, battery);
				this->OutPutAppLog(log);
			}
		});
		thread1.detach();
	}
}


void CSDKdemoDlg::OnBnClickedButtonConnected()
{
	CString strID;
	m_toyListInfo.GetLBText(m_toyListInfo.GetCurSel(), strID);
	CString log;
	log.Format(_T("[App] OnClick Connect: toy=%s"), strID);
	this->OutPutAppLog(log);

	std::string toyID;
	toyID = CW2A(strID.GetString());
	CLovenseToyManager *manager = GetLovenseToyManager();
	clock_t startTime = clock();
	int error = manager->ConnectToToy(toyID.c_str());
	clock_t endTime = clock();
	log.Format(_T("[App] Result: ret = %d (time = %dms)"), error, endTime - startTime);
	this->OutPutAppLog(log);
}


void CSDKdemoDlg::OnBnClickedButtonDisconnected()
{
	CString strID;
	m_toyListInfo.GetLBText(m_toyListInfo.GetCurSel(), strID);
	std::string toyID;
	toyID = CW2A(strID.GetString());
	CString log;
	log.Format(_T("[App] OnClick DisConnect: toy=%s"), strID);
	this->OutPutAppLog(log);

	clock_t startTime = clock();
	CLovenseToyManager *manager = GetLovenseToyManager();
	int error = manager->DisConnectedToy(toyID.c_str());
	clock_t endTime = clock();
	log.Format(_T("[App] Result: ret = %d (time = %dms)"), error, endTime - startTime);
	this->OutPutAppLog(log);
}


void CSDKdemoDlg::OnCbnSelchangeToyID()
{
	m_combToyName.SetCurSel(m_toyListInfo.GetCurSel());
	CString strID;
	m_toyListInfo.GetLBText(m_toyListInfo.GetCurSel(),strID);

	if (m_search_toy.find(strID) != m_search_toy.end())
	{
		auto info = m_search_toy[strID];
		CString battery;
		battery.Format(_T("%d"), info->toy_battery);
		m_txBetarry.SetWindowTextW(battery);
	}
}


void CSDKdemoDlg::OnEnChangeEdit1()
{

}

void CSDKdemoDlg::OutPutAppLog(CString log)
{
	log += _T("\r\n");
	this->m_richedit_app_output.ReplaceSel(log);
	this->m_richedit_app_output.PostMessage(WM_VSCROLL, SB_BOTTOM, 0);
}

