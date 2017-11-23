/**
* \file
* UWP w32file support for Mono.
*
* Copyright 2016 Microsoft
* Licensed under the MIT license. See LICENSE file in the project root for full license information.
*/

#if _XBOX_ONE

#define _WIN32_WINNT 0x0602
#include <windows.h>
#include "mono/metadata/w32file-win32-internals.h"

gpointer
mono_w32file_create(const gunichar2 *name, guint32 fileaccess, guint32 sharemode, guint32 createmode, guint32 attrs)
{
	gpointer res;
	CREATEFILE2_EXTENDED_PARAMETERS param = { 0 };

	param.dwSize = sizeof(CREATEFILE2_EXTENDED_PARAMETERS);
	param.dwFileAttributes = attrs;
	param.dwSecurityQosFlags = SECURITY_ANONYMOUS;

	MONO_ENTER_GC_SAFE;
	res = CreateFile2(name, fileaccess, sharemode, createmode, &param);
	MONO_EXIT_GC_SAFE;

	return res;
}

gboolean
mono_w32file_copy(gunichar2 *path, gunichar2 *dest, gboolean overwrite, gint32 *error)
{
	gboolean						result = FALSE;
	COPYFILE2_EXTENDED_PARAMETERS	copy_param = { 0 };

	copy_param.dwSize = sizeof(COPYFILE2_EXTENDED_PARAMETERS);
	copy_param.dwCopyFlags = (!overwrite) ? COPY_FILE_FAIL_IF_EXISTS : 0;

	MONO_ENTER_GC_SAFE;

	result = SUCCEEDED(CopyFile2(path, dest, &copy_param));
	if (result == FALSE) {
		*error = GetLastError();
	}

	MONO_EXIT_GC_SAFE;
	return result;
}

#else /* G_HAVE_API_SUPPORT(HAVE_UWP_WINAPI_SUPPORT) */

MONO_EMPTY_SOURCE_FILE(file_io_windows_uwp);
#endif /* G_HAVE_API_SUPPORT(HAVE_UWP_WINAPI_SUPPORT) */
