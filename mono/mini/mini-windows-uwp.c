/**
 * \file
 * UWP profiler stat support for Mono.
 *
 * Copyright 2016 Microsoft
 * Licensed under the MIT license. See LICENSE file in the project root for full license information.
 */
#include <config.h>
#include <signal.h>
#include <math.h>
#include <conio.h>

#include <mono/metadata/assembly.h>
#include <mono/metadata/profiler-private.h>
#include <mono/metadata/gc-internals.h>
#include <mono/utils/mono-counters.h>
#include <mono/utils/mono-logger-internals.h>
#include <mono/utils/mono-mmap.h>
#include <mono/utils/dtrace.h>

#include "mini.h"
#include "mini-windows.h"
#include <string.h>
#include <ctype.h>
#include "trace.h"
#include "version.h"

#include "jit-icalls.h"

#if G_HAVE_API_SUPPORT(HAVE_UWP_WINAPI_SUPPORT)
//#include <windows.h>

//#include <mono/utils/mono-counters.h>
//#include "mini.h"
#include "mini-windows.h"

void
mono_runtime_setup_stat_profiler (void)
{
	g_unsupported_api ("OpenThread, GetThreadContext");
	SetLastError (ERROR_NOT_SUPPORTED);
	return;
}

void
mono_runtime_shutdown_stat_profiler (void)
{
	g_unsupported_api ("OpenThread, GetThreadContext");
	SetLastError (ERROR_NOT_SUPPORTED);
	return;
}

gboolean
mono_setup_thread_context(DWORD thread_id, MonoContext *mono_context)
{
	memset (mono_context, 0, sizeof (MonoContext));
	return FALSE;
}

#else /* G_HAVE_API_SUPPORT(HAVE_UWP_WINAPI_SUPPORT) */

MONO_EMPTY_SOURCE_FILE (mini_windows_uwp);
#endif /* G_HAVE_API_SUPPORT(HAVE_UWP_WINAPI_SUPPORT) */

