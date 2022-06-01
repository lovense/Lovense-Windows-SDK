
#pragma once


#include "resource.h"		




class CSDKdemoApp : public CWinApp
{
public:
	CSDKdemoApp();


public:
	virtual BOOL InitInstance();



	DECLARE_MESSAGE_MAP()
};

extern CSDKdemoApp theApp;