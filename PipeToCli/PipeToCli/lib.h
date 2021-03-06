#pragma once

#include "stdafx.h"

// Prints last error and exits
inline void die(wchar_t *err) {
	DWORD err_num = GetLastError();
	DWORD err_sock = WSAGetLastError();
	LPVOID err_msg, sock_msg;

	MessageBox(NULL, err, TEXT("Error"), MB_OK);
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		err_num,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&err_msg, 0, NULL);
	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		err_sock,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&sock_msg, 0, NULL);
	MessageBox(NULL, (LPCTSTR)sock_msg, TEXT("Error"), MB_OK);
	MessageBox(NULL, (LPCTSTR)err_msg, TEXT("Error"), MB_OK);
	LocalFree(err_msg);
	exit(-1);
}