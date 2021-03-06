/**
 * \file
 * ConsoleDriver internal calls for Win32
 *
 * Author:
 *	Gonzalo Paniagua Javier (gonzalo@ximian.com)
 *
 * Copyright (C) 2005-2009 Novell, Inc. (http://www.novell.com)
 * Licensed under the MIT license. See LICENSE file in the project root for full license information.
 */

#include <config.h>
#include <glib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>

#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif

#include <mono/metadata/appdomain.h>
#include <mono/metadata/object-internals.h>
#include <mono/metadata/class-internals.h>
#include <mono/metadata/domain-internals.h>
#include <mono/metadata/gc-internals.h>
#include <mono/metadata/metadata.h>

#include <mono/metadata/console-io.h>
#include <mono/metadata/exception.h>

void
mono_console_init (void)
{
}

void
mono_console_handle_async_ops (void)
{
}

#if G_HAVE_API_SUPPORT(HAVE_CLASSIC_WINAPI_SUPPORT) && !_XBOX_ONE
MonoBoolean
ves_icall_System_ConsoleDriver_Isatty (HANDLE handle, MonoError* error)
{
	DWORD mode;
	return GetConsoleMode (handle, &mode) != 0;
}

MonoBoolean
ves_icall_System_ConsoleDriver_SetEcho (MonoBoolean want_echo, MonoError* error)
{
	return FALSE;
}

MonoBoolean
ves_icall_System_ConsoleDriver_SetBreak (MonoBoolean want_break, MonoError* error)
{
	return FALSE;
}

gint32
ves_icall_System_ConsoleDriver_InternalKeyAvailable (gint32 timeout, MonoError* error)
{
	return FALSE;
}

MonoBoolean
ves_icall_System_ConsoleDriver_TtySetup (MonoStringHandle keypad, MonoStringHandle teardown, MonoArrayHandleOut control_chars, int **size, MonoError* error)
{
	return FALSE;
}
#endif /* G_HAVE_API_SUPPORT(HAVE_CLASSIC_WINAPI_SUPPORT) */

// HACK: VS17 not building the included files for UWP
#include "console-win32-uwp.c"
