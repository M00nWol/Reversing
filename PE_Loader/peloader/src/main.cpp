// Main function

#include "system/system.h"
#include "loader/loader.h"
#include "helpers/strings.h"
#include "helpers/opendialog.h"
#include "system/syscalls.h"

/*
	기능 : 이미지 파일을 실행하자!
	Arguments:
		plpFilename - valid pointer to unicode string
		argc - arguments count (cmd)
		argv - argument variables (cmd)
	Return Value:
		BOOL - 이미지 파일 네임이 포함되어 있다면 참, 아니라면 false
*/
