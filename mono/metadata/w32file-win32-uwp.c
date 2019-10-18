/**
 * \file
 * UWP w32file support for Mono.
 *
 * Copyright 2016 Microsoft
 * Licensed under the MIT license. See LICENSE file in the project root for full license information.
*/
#include <config.h>
#include <glib.h>
#include "mono/utils/mono-compiler.h"

#if G_HAVE_API_SUPPORT(HAVE_UWP_WINAPI_SUPPORT)
#include <windows.h>
#include "mono/metadata/w32file-win32-internals.h"
#include "mono/metadata/w32subset.h"
#include "icall-decl.h"

gpointer
mono_w32file_create(const gunichar2 *name, guint32 fileaccess, guint32 sharemode, guint32 createmode, guint32 attrs)
{
	gpointer res;
	MONO_ENTER_GC_SAFE;
	CREATEFILE2_EXTENDED_PARAMETERS param = { 0 };
	param.dwSize = sizeof(CREATEFILE2_EXTENDED_PARAMETERS);
	param.dwFileAttributes = FILE_ATTRIBUTE_NORMAL;
	param.dwSecurityQosFlags = SECURITY_ANONYMOUS;
	res = CreateFile2(name, (DWORD)fileaccess, (DWORD)sharemode, (DWORD)createmode, &param);
	MONO_EXIT_GC_SAFE;
	return res;
}

gboolean
mono_w32file_move (const gunichar2 *path, const gunichar2 *dest, gint32 *error)
{
	gboolean result = FALSE;
	MONO_ENTER_GC_SAFE;

	result = MoveFileEx (path, dest, MOVEFILE_COPY_ALLOWED);
	if (result == FALSE) {
		*error=GetLastError ();
	}

	MONO_EXIT_GC_SAFE;
	return result;
}

HANDLE
mono_w32file_get_console_output (void)
{
	ERROR_DECL (error);

	g_unsupported_api ("GetStdHandle (STD_OUTPUT_HANDLE)");

	mono_error_set_not_supported (error, G_UNSUPPORTED_API, "GetStdHandle (STD_OUTPUT_HANDLE)");
	mono_error_set_pending_exception (error);

	SetLastError (ERROR_NOT_SUPPORTED);

	return INVALID_HANDLE_VALUE;
}

HANDLE
mono_w32file_get_console_input (void)
{
	ERROR_DECL (error);

	g_unsupported_api ("GetStdHandle (STD_INPUT_HANDLE)");

	mono_error_set_not_supported (error, G_UNSUPPORTED_API, "GetStdHandle (STD_INPUT_HANDLE)");
	mono_error_set_pending_exception (error);

	SetLastError (ERROR_NOT_SUPPORTED);

	return INVALID_HANDLE_VALUE;
}

HANDLE
mono_w32file_get_console_error (void)
{
	ERROR_DECL (error);

	g_unsupported_api ("GetStdHandle (STD_ERROR_HANDLE)");

	mono_error_set_not_supported (error, G_UNSUPPORTED_API, "GetStdHandle (STD_ERROR_HANDLE)");
	mono_error_set_pending_exception (error);

	SetLastError (ERROR_NOT_SUPPORTED);

	return INVALID_HANDLE_VALUE;
}

gint32
mono_w32file_get_logical_drive(guint32 len, gunichar2 *buf)
{
	MonoError mono_error;
	error_init(&mono_error);

	g_unsupported_api("GetLogicalDriveStrings (len, buf)");

	mono_error_set_not_supported(&mono_error, G_UNSUPPORTED_API, "GetLogicalDriveStrings (len, buf)");
	mono_error_set_pending_exception(&mono_error);

	SetLastError(ERROR_NOT_SUPPORTED);

	return (gint32)INVALID_HANDLE_VALUE;
}

#else /* G_HAVE_API_SUPPORT(HAVE_UWP_WINAPI_SUPPORT) */

MONO_EMPTY_SOURCE_FILE (file_io_windows_uwp);
#endif /* G_HAVE_API_SUPPORT(HAVE_UWP_WINAPI_SUPPORT) */
