#pragma once
#ifndef TOYINFO_H
#define TOYINFO_H

#include <string>
#include "LovenseDef.h"

#ifdef  __cplusplus
extern "C" {
#endif

typedef struct st_lovense_toy_info {
	char* toy_id;
	char* toy_name;
	int toy_battery;
	int toy_type;
	bool toy_connected;
}lovense_toy_info_t;

class CToyInfo
{
public:
	CToyInfo();
	virtual	~CToyInfo();
	virtual  const std::string & GetToyID() const ;
	virtual  const std::string & GetToyName() const;
	virtual  const std::string & GetToyFullName() const;
	virtual  const std::string & GetToyVersion() const;
	virtual   int GetBettary() const;
	virtual   bool IsConnected() const;
	virtual  LVSToyType GetToyType() const;

	void SetToyID(const std::string & toyID);
	void SetToyName(const std::string & toyName);
	void SetToyFullName(const std::string & fullName);
	void SetToyVersion(const std::string & version);
	void SetToyConnected(bool connected);
	void SetToyBettary(int bettary);
	void SetToyType(LVSToyType type);

private:
	std::string  m_strToyID;
	std::string  m_strToyName;
	std::string  m_strFullName;
	std::string  m_strToyVersion;
	bool		 m_isConnected = false;
	int			 m_bettary = 0;
	LVSToyType	 m_toyType;
};
#ifdef  __cplusplus
}
#endif
#endif