#ifndef __TOYS_H
#define __TOYS_H
/***************************************************************************
*
* Copyright © 2019 Hytto. All rights reserved.
*
* This software is licensed as described in the file COPYING, which
* you should have received as part of this distribution. 
* You may opt to use, copy, modify, merge, publish, distribute and/or sell
* copies of the Software, and permit persons to whom the Software is
* furnished to do so, under the terms of the COPYING file.
*
* This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
* KIND, either express or implied.
*
***************************************************************************/

#include <string>
#include <vector>
#include "LovenseDef.h"
#include "LovenseToyInfo.h"

#ifdef  __cplusplus
extern "C" {
#endif



/**Abstract class*/
class LOVENSE_EXTERN ILovenseSDKNotify
{
	public:
		/*Call when toy search start*/
		virtual	void LovenseDidSearchStart() = 0;

		/*Call when toy searching toy*/
		virtual  void LovenseSearchingToys(lovense_toy_info_t *info) = 0;

		/*Call when Something went wrong*/
		virtual  void LovenseErrorOutPut(int errorCode,const char *errorMsg) = 0;

		/*Call when toy search end*/
		virtual  void LovenseDidSearchEnd() = 0;

		/*Call when send cmd start*/
		virtual	void LovenseDidSendCmdStart() = 0;

		/*Call when send cmd return*/
		virtual  void LovenseSendCmdResult(const char * szToyID, CLovenseToy::CmdType cmd,const char *result,CLovenseToy::Error errorCode) = 0;

		/*Call when send cmd end*/
		virtual	void LovenseDidSendCmdEnd() = 0;

		/*Call when toy connected, or disconnected*/
		virtual void LovenseToyConnectedStatus(const char *szToyID, bool isConnected) = 0;
};


class LOVENSE_EXTERN CLovenseToyManager
{
	public:
		/**
		Pass your token into Lovense framework
		*/
		virtual bool SetDeveloperToken(const char *szToken) = 0;

		/**
		 Subscription notification
		 */
		virtual void RegisterEventCallBack(ILovenseSDKNotify * lovenseNotify) = 0;

		/**
		Search for Lovense toys
		*/
		virtual int StartSearchToy() = 0;

		/**
		 Stop searching
		*/
		virtual int StopSearchToy() = 0;

		/**
		Send a command to the toy

		@param toyId toy ID
		@param commandType command
		@param paramDict command parameters
		*/
		virtual int SendCommand(const char * szToyID, CLovenseToy::CmdType cmd, int nParam) = 0;

		/**
		Connect a toy

		@param toyId toy ID
		If Successful connection successfully, will call LovenseToyConnectedStatus;
		*/
		virtual int ConnectToToy(const char * szToyID) = 0;

		/**
		DisConnect a toy

		@param toyId toy ID
		return Successfully disconnected, will call LovenseToyConnectedStatus;
		*/
		virtual int DisConnectedToy(const char *szToyID) = 0;


		/**
		Get toy battery

		@param toyId toy ID
		return 0
		*/
		virtual int GetToyBattery(const char* szToyID, int *battery_out) = 0;
};

/**
 * Get the class instance through this export interface!
 */
LOVENSE_EXTERN CLovenseToyManager * const GetLovenseToyManager();

/**
* Release worker context
*/
LOVENSE_EXTERN void ReleaseLovenseToyManager();

#ifdef  __cplusplus
}
#endif

#endif // !__TOYS_H

