Lovense SDK for Windows
========================

The Windows SDK is a library provided for Windows that allows you to directly access Lovense toys. You usually choose this option if you are making your own Windows application.


TRY IT OUT
----------

In order to be able to use the API you must create a free account on the Lovense Official website in order to get your token
1. Create a new account at https://www.lovense.com/sextoys/developer/join/.
2. Go to https://www.lovense.com/user/developer/info and get your developer token.
3. Start coding! Visit https://developer.lovense.com/lovense-win-sdk-demo-2.0.1.zip to download the demo app.
4. Check out `LovenseDef.h` for a list of supported commands.
5. You can also download the demo app from this repo.


INSTALLATION
------------

- Create a new account at https://www.lovense.com/sextoys/developer/join/

- Go to https://www.lovense.com/user/developer/info and get your developer token

- Download and extract the Lovense SDK at https://developer.lovense.com/lovense-win-sdk-2.0.1.zip

- Configure the SDK in your application. Visual Studio 2019 example:
1. Set the path of the SDK header file
![Alt text](https://github.com/lovense/Lovense-Windows-SDK/blob/main/windows-sdk-configure-head.52e96ef6.png "SDK Header file")
2. Set the path of SDK lib file
![Alt text](https://github.com/lovense/Lovense-Windows-SDK/blob/main/windows-sdk-configure-lib.0d4eed86.png "SDK lib file")


- Connect Lovense toys

```
#include <Lovense.h>
...
class CEventCallBack: public ILovenseSDKNotify
{
	public:
		/*Call when toy search start*/
		virtual	void LovenseDidSearchStart();

		/*Call when toy searching toy*/
		virtual  void LovenseSearchingToys(lovense_toy_info_t *info) = 0;

		/*Call when something went wrong*/
		virtual  void LovenseErrorOutPut(int errorCode,const char *errorMsg) = 0;


		/*Call when toy search end*/
		virtual  void LovenseDidSearchEnd();

		/*Call when send cmd start*/
		virtual	void LovenseDidSendCmdStart();

		/*Call when send cmd return*/
		virtual  void LovenseSendCmdResult(const char * szToyID, CLovenseToy::CmdType cmd,const char *result,CLovenseToy::Error errorCode);

		/*Call when send cmd end*/
		virtual	void LovenseDidSendCmdEnd();

		/*Call when toy connected, or disconnected*/
		virtual void LovenseToyConnectedStatus(const char *szToyID, bool isConnected) ;
};

...
	//TODO:This is a simple process
	CEventCallBack *callBack = new CEventCallBack();
	CLovenseToyManager *manager = GetLovenseToyManager();
	manager->SetDeveloperToken(...);
	manager->RegisterEventCallBack(callBack);
	manager->StartSearchToy();//Search for the toys via USB Dongle
```

- Send commands

```
	CLovenseToyManager *manager = GetLovenseToyManager();
	//Send a vibration command
	manager->SendCommand(toyID,CLovenseToy::CmdType::COMMAND_VIBRATE,10);
```

- For a list of supported commands, please check `LovenseDef.h`. As an example:

```
namespace CLovenseToy
{
	typedef enum {

		/**
		-Power off!
		- param Key = no parameter
		*/
		COMMAND_POWER_OFF = 100,

		/**
		- Vibrate the toy. The parameter must be between 0 and 20!
		- Supported toys = all
		*/
		COMMAND_VIBRATE = 101,

		/**
		- Rotate the toy. The parameter must be between 0 and 20!
		- Supported toys = Nora
		*/
		COMMAND_ROTATE = 102,
		.
		.
		.
	}
}
```

- To view the log output, use the editbin command.
![Alt text](https://github.com/lovense/Lovense-Windows-SDK/blob/main/editbin.png "Editbin")


SETUP 
-----
1. Insert the Lovense USB Bluetooth Adapter into the PC.
2. Turn on the toy. The light will begin flashing.
3. Open your application and search for the toy to establish a connection.


TIPS
----

1. When searching for toys, do not send other commands to toys.
2. If you need to get the toy's battery level frequently, start a thread loop.
3. For best results, don't sent toy commands more than once per second.
4. First time users, refer to our SDK Demo linked above.


GIVE FEEDBACK
-------------
Please report bugs or issues to [Lovense Support](mailto:developer@mail.lovense.com).

You can also join our [Lovense Developer Community Discord](https://discord.gg/dW9f54BwqR), visit the [Lovense Developers Website](https://developer.lovense.com/#introduction), or open an issue in this repository.
