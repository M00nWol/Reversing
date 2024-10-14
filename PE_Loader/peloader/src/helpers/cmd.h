/*
 * Command string helpers defenition
 */

// 명령줄 문자열을 개별 인자로 분리하기 위한 헤더
#ifndef _CMD_HELPER_H_
#define _CMD_HELPER_H_

#include <Windows.h>

namespace Helpers
{

    LPWSTR* WINAPI CommandLineToArgvW(LPCWSTR lpCmdline, int* numargs);

}

#endif // _CMD_HELPER_H_
