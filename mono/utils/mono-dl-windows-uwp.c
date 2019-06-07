/**
 * \file
 * UWP dl support for Mono.
 *
 * Copyright 2016 Microsoft
 * Licensed under the MIT license. See LICENSE file in the project root for full license information.
*/
#include <config.h>
#include <glib.h>
#include "mono/utils/mono-compiler.h"

#if G_HAVE_API_SUPPORT(HAVE_UWP_WINAPI_SUPPORT) || _XBOX_ONE
#include <windows.h>
#include "mono/utils/mono-dl-windows-internals.h"

#if _WIN64
// Hack
WINBASEAPI
_Ret_maybenull_
HMODULE
WINAPI
LoadLibraryW(
    _In_ LPCWSTR lpLibFileName
    );
#endif

void*
mono_dl_open_file (const char *file, int flags)
{
	gpointer hModule = NULL;
	if (file) {
		gunichar2* file_utf16 = g_utf8_to_utf16 (file, strlen (file), NULL, NULL, NULL);

        guint last_sem = GetLastError ();
		guint32 last_error = 0;

#if _WIN64
		hModule = LoadLibraryW (file_utf16);
#else
        hModule = LoadPackagedLibrary (file_utf16, NULL);
#endif
		if (!hModule)
			last_error = GetLastError ();

		SetErrorMode (last_sem);

		g_free (file_utf16);

		if (!hModule)
			SetLastError (last_error);
	} else {
		g_error("Not supported");
	}
	return hModule;
}

void*
mono_dl_lookup_symbol_in_process (const char *symbol_name)
{
	g_unsupported_api ("EnumProcessModules");
	SetLastError (ERROR_NOT_SUPPORTED);

	return NULL;
}

char*
mono_dl_current_error_string (void)
{
	char *ret = NULL;
	TCHAR buf [1024];
	DWORD code = GetLastError ();

	if (!FormatMessage (FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL,
		code, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), buf, G_N_ELEMENTS(buf) - 1, NULL))
		buf[0] = TEXT('\0');

	ret = u16to8 (buf);
	return ret;
}

#else /* G_HAVE_API_SUPPORT(HAVE_UWP_WINAPI_SUPPORT) */

MONO_EMPTY_SOURCE_FILE (mono_dl_windows_uwp);
#endif /* G_HAVE_API_SUPPORT(HAVE_UWP_WINAPI_SUPPORT) */
