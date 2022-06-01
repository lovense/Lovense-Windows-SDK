#pragma once
#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H

/*Build with Static*/
#ifdef DEF_STATICLIB
	#define LOVENSE_EXTERN
#elif defined(LOVENSETOYS_EXPORTS)  /*Build with dynamic*/
	#define LOVENSE_EXTERN  __declspec(dllexport)
#else
	#define LOVENSE_EXTERN  __declspec(dllimport)
#endif 

/* Compatibility for non-Clang compilers */
#ifndef __has_declspec_attribute
	#define __has_declspec_attribute(x) 0
#endif

#define  DEF_SDK_VSERSION "1.0.0"

namespace CLovenseToy
{
	typedef enum {
		COMMAND_UNKNOWN = -1,

		COMMAND_CONNECT_TOY = 0,

		COMMAND_DISCONNECT_TOY = 1,

		/**
		-Power off!
		- param Key = no parameter
		*/
		COMMAND_POWER_OFF = 100,

		/**
		- Vibrate the toy .The parameter must be between 0 and 20!
		- Supported toys = all
		*/
		COMMAND_VIBRATE = 101,

		/**
		- Rotate the toy .The parameter must be between 0 and 20!
		- Supported toys = Nora
		*/
		COMMAND_ROTATE = 102,

		/**
		- Rotate clockwise .The parameter must be between 0 and 20!
		- Supported toys = Nora
		*/
		COMMAND_ROTATE_CLOCKWISE = 103,

		/**
		- Rotate anti-clockwise .The parameter must be between 0 and 20!
		- Supported toys = Nora
		*/
		COMMAND_ROTATE_ANTI_CLOCKWISE = 104,

		/**
		- Change the rotation direction
		- param Key = no parameter
		- Supported toys = Nora
		*/
		COMMAND_ROTATE_CHANGE = 105,

		/**
		- Activate the first vibrator at level n .The parameter must be between 0 and 20!
		- param Key = kSendCommandParamKey_VibrateLevel
		- Supported toys = Edge
		*/
		COMMAND_VIBRATE1 = 113,

		/**
		- Activate the second vibrator at level n .The parameter must be between 0 and 20!
		- param Key = kSendCommandParamKey_VibrateLevel
		- Supported toys = Edge
		*/
		COMMAND_VIBRATE2 = 114,

		/**
		- Vibrate the toy at level n, and flash the light at the same time .The parameter must be between 0 and 20!
		- param key = kSendCommandParamKey_VibrateLevel: vibration level (between 1~3)
		- param key = kSendCommandParamKey_FlashLevel: Flashing frequency (per second). Between 0~9
		- Supported toys = Ambi / Domi / Osci
		*/
		COMMAND_VIBRATE_FLASH = 120,

		/**
		- Flash the light 3 times
		- param Key = no parameter
		- Supported toys = all
		*/
		COMMAND_FLASH = 201,

		/**
		- Turn off the light (saved permanently)
		- param Key = no parameter
		- Supported toys = Lush / Hush / Edge
		*/
		COMMAND_LIGHT_OFF = 210,

		/**
		- Turn on the light (saved permanently)
		- param Key = no parameter
		- Supported toys = Lush / Hush / Edge
		*/
		COMMAND_LIGHT_ON = 211,

		/**
		Get the light status (1: on, 0:off)
		- param Key = no parameter
		* Supported toys = Lush  Hush  Edge
		*/
		COMMAND_GET_LIGHT_STATUS = 212,

		/**
		- Turn off the AID light (saved permanently)
		- param Key = no parameter
		- Supported toys = Domi
		*/
		COMMAND_ALIGHT_OFF = 220,

		/**
		- Turn on the AID light (saved permanently)
		- param Key = no parameter
		- Supported toys = Domi
		*/
		COMMAND_ALIGHT_ON = 221,

		/**
		Get the AID light status (1: on, 0:off)
		- param Key = no parameter
		* Supported toys = Domi
		*/
		COMMAND_GET_ALIGHT_STATUS = 222,

		/**
		- Get battery status,
		- param Key = no parameter
		* Supported toys = all
		*/
		COMMAND_GET_BATTERY = 300,

		/**
		Get device/toy information
		- param Key = no parameter
		* Supported toys = all
		*/
		COMMAND_GET_DEVICE_TYPE = 310,

		/**
		Inflatable n seconds. The parameter must be between (1-3)
		* Supported toys = Max
		*/
		COMMAND_AIR_IN						= 330,

		/**
		Deflation n seconds. The parameter must be between (1-3)
		* Supported toys = Max
		*/
		COMMAND_AIR_OUT					= 331,

		/**
		Cycle inflation for n seconds, deflation for n seconds, 0 for stop!
		The parameter must be between (0-3)
		* Supported toys = Max
		*/
		COMMAND_AIR_AUTO				= 332,
		
		/**
		Start tracking the toy movement (0-4)
		- param Key = no parameter
		* Supported toys = Max,Nora
		*/
		COMMAND_START_MOVE = 400,

		/*
		Stop tracking the toy movement
		- param Key = no parameter
		* Supported toys = Max,Nora
		*/
		COMMAND_STOP_MOVE = 401
	} CmdType;

	typedef enum
	{
		TOYERR_UNKNOWN			= -1,

		TOYERR_SUCCESS			= 0,

		TOYERR_ABORT			= 1001,

		//HID interface initialization failed!
		TOYERR_HID_INIT_FAILED	= 1002,

		//No HID USB Dongle found!
		TOYERR_HID_DONGLE_NOT_FOUND	= 1003,

		//Unable to get HID Dongle information!
		TOYERR_HID_GET_DONGLE_ID_ERROR	= 1004,
		
		//Toys are not connected to USB Dongle!
		TOYERR_TOY_NOT_CONNECTED	= 1005,		

		//Invalid argument
		TOYERR_PARAM_ERROR		= 1006,	

		//Unrecognized command
		TOYERR_INVALID_CMD	= 1007,			

		//Invalid token
		TOYERR_INVALIDTOKEN	= 1008,

		//COM READ ERROR
		TOYERR_COM_READ_ERROR = 1009,

		//COM WRITE ERROR
		TOYERR_COM_WRITE_ERROR = 1010,

		//COM NOT FOUND ERROR
		TOYERR_COM_NOT_FOUND_ERROR = 1011,
		//HID READ ERROR
		TOYERR_HID_READ_ERROR = 1012,

		//HID WRITE ERROR
		TOYERR_HID_WRITE_ERROR = 1013,

		//DEVICE NOT FOUND
		TOYERR_DONGLE_NO_FOUND_ERROR = 1014,

		//HID DEVICE OPEN FAILED
		TOYERR_HID_OPEN_FAILED_ERROR = 1015,

		//COM DEVICE OPEN FAILED
		TOYERR_COM_OPEN_FAILED_ERROR = 1016,

		//device can not be write
		TOYERR_DEVICE_WRITE_FAILED = 1017,

		//device can not be read
		TOYERR_DEVICE_READ_FAILED = 1018,

		//device is searching, You can't send any commands
		TOYERR_DEVICE_IS_SEARCHING = 1019,
	}Error;
};

/*USB Dongle Type*/
typedef enum { 

	//HID USB Dongle
	DONGLE_HID_TYPE = 0,

	//SERIAL COM USB Dongle
	DONGLE_BLE_TYPE	= 1,

}DongleType;

/*Lovense Toy Type*/
typedef enum {
	LVS_UNKNOWN = 0,
	LVS_MAX			= 0x01,
	LVS_NORA		= 0x02,
	LVS_HUSH		= 0x03,
	LVS_LUSH		= 0x04,
	LVS_AMBI		= 0x05,
	LVS_DOMI		= 0x06,
	LVS_SECRET		= 0x07,
	LVS_EDGE		= 0x08,
	LVS_OSCI		= 0x09,
	LVS_DONGLE	= 0x0A,
	LVS_DIAMO = 0x0B,
	LVS_MISSION = 0x0C,
	LVS_V01 = 0x0D,
}LVSToyType;

#endif