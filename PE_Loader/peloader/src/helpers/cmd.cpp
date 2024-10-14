#include "../system/syscalls.h"
#include "cmd.h"
#include "strings.h"

namespace Helpers 
{
	LPWSTR* WINAPI CommandLineToArgvW(LPCWSTR lpCmdline, int* numargs)
	{
		DWORD argc;
		LPWSTR* argv;
		LPCWSTR s;
		LPWSTR d;
		LPWSTR cmdline;
		int qcount, bcount;

		// numargs 포인터가 유효하지 않으면 오류 반환
		if (!numargs)
		{
			SetLastError(ERROR_INVALID_PARAMETER);
			return NULL;
		}

		// 명령줄이 비어 있을 경우
		if (*lpCmdline == 0)
		{
			// 실행 파일의 경로를 반환한다
			DWORD len, deslen = MAX_PATH, size;

			size = sizeof(LPWSTR) + deslen * sizeof(WCHAR) + sizeof(LPWSTR);
			for (;;)
			{
				if (!(argv = (LPWSTR*)LocalAlloc(LMEM_FIXED, size))) 
					return NULL;

				// 현재 실행 파일의 경로를 가져온다
				len = GetModuleFileNameW(0, (LPWSTR)(argv + 1), deslen);

				if (!len)
				{
					LocalFree(argv);
					return NULL;
				}

				if (len < deslen) 
					break;

				deslen *= 2;
				size = sizeof(LPWSTR) + deslen * sizeof(WCHAR) + sizeof(LPWSTR);
				LocalFree(argv);
			}

			argv[0] = (LPWSTR)(argv + 1);
			*numargs = 1;

			return argv;

		}

	}

}