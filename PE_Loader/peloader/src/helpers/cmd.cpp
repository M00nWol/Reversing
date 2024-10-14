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

		// numargs �����Ͱ� ��ȿ���� ������ ���� ��ȯ
		if (!numargs)
		{
			SetLastError(ERROR_INVALID_PARAMETER);
			return NULL;
		}

		// ������� ��� ���� ���
		if (*lpCmdline == 0)
		{
			// ���� ������ ��θ� ��ȯ�Ѵ�
			DWORD len, deslen = MAX_PATH, size;

			size = sizeof(LPWSTR) + deslen * sizeof(WCHAR) + sizeof(LPWSTR);
			for (;;)
			{
				if (!(argv = (LPWSTR*)LocalAlloc(LMEM_FIXED, size))) 
					return NULL;

				// ���� ���� ������ ��θ� �����´�
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