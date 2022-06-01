
#pragma once
#include "afxwin.h"
#include <Lovense.h>
#include <LovenseDef.h>
#include <map>
#include <LovenseToyInfo.h>
#include <memory>
using namespace std;

class MyToyInfo {
public:
	CString toy_id;
	CString toy_name;
	uint32_t toy_battery;
	uint32_t toy_type;
	bool toy_connected;
};

typedef std::map < CString/*toy id*/, std::shared_ptr<MyToyInfo>> TMap;
typedef std::map < CString/*toy id*/, std::shared_ptr<MyToyInfo>>::iterator TMap_Iterator;

class CSDKdemoDlg : public CDialogEx , ILovenseSDKNotify
{
public:
	CSDKdemoDlg(CWnd* pParent = NULL);	


#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SDKDEMO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	



protected:
	HICON m_hIcon;


	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedsearchButton();
	afx_msg void OnBnClickedStopSearchButton();
	void AddToyInfo(LPCTSTR toyID,LPCTSTR toyName);
	CComboBox m_toyListInfo;
	CComboBox m_cmdList;
	CComboBox m_paramList;
	afx_msg void OnBnClickedSendButton();

public:
	virtual	void LovenseDidSearchStart() ;
	virtual void LovenseDidSearchEnd() ;

	virtual void LovenseSearchingToys(lovense_toy_info_t *info);

	virtual void LovenseSendCmdResult(const char * szToyID, CLovenseToy::CmdType cmd, const char *result, CLovenseToy::Error errorCode) ;
	virtual void LovenseDidSendCmdStart();
	virtual void LovenseDidSendCmdEnd();
	virtual void LovenseToyConnectedStatus(const char *szToyID, bool isConnected);
	virtual void LovenseErrorOutPut(int errorCode, const char *errorMsg);

	afx_msg void OnBnClickedLightOpenButton();
	afx_msg void OnBnClickedLightCloseButton();
	afx_msg void OnBnClickedLightFlashButton();
	afx_msg void OnBnClickedButtonConnected();
	afx_msg void OnBnClickedButtonDisconnected();
	afx_msg void OnEnChangeEdit1();

	void OutPutAppLog(CString log);

	CComboBox m_combToyName;
	afx_msg void OnCbnSelchangeToyID();
	CButton m_btnSearch;
	CButton m_btnStop;
	CStatic m_txBetarry;
	map<CString, int> m_mapCmd;
	//map<CString, CToyInfo> m_mapToyInfo;
	CEdit m_editToken;

	CRichEditCtrl m_richedit_app_output;
	TMap m_search_toy;
};
