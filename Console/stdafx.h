// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#pragma once

#include <windows.h>
#include <winver.h>

#include <atlbase.h>
#include <atlstr.h>
#include <wtl/atlapp.h>
#ifdef _USE_AERO
  #include <dwmapi.h>
  #include <gdiplus.h>
  #include "wtlaero.h"
  #pragma comment (lib, "gdiplus.lib")
#endif
#include "resource.h"
#include "multisplit.h"

// ###########################

#include <HtmlHelp.h>
#include <ShellApi.h>
#include <tlhelp32.h>
#include <Psapi.h>
#include <winuser.h>
#include <WinCred.h>

#if _MSC_VER >= 1900
/*
Muiload.lib(muiload.obj) : error LNK2019: unresolved external symbol _vsnwprintf referenced in function
"long __cdecl StringVPrintfWorkerW(unsigned short *,unsigned __int64,unsigned __int64 *,unsigned short const *,char *)" (?StringVPrintfWorkerW@@YAJPEAG_KPEA_KPEBGPEAD@Z)

The definitions of all of the printf and scanf functions have been moved inline into <stdio.h>, <conio.h>,
and other CRT headers.This is a breaking change that leads to a linker error(LNK2019, unresolved external
symbol) for any programs that declared these functions locally without including the appropriate CRT
headers.If possible, you should update the code to include the CRT headers(that is, add #include <stdio.h>)
and the inline functions, but if you do not want to modify your code to include these header files,
an alternative solution is to add an additional library to your linker input, legacy_stdio_definitions.lib.
*/
#pragma comment (lib, "legacy_stdio_definitions.lib")
#endif

#include <shobjidl.h>
#include <CommonControls.h>

#ifndef _USING_V110_SDK71_
#include <ShellScalingAPI.h>
#endif

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <stack>
#include <array>
#include <regex>
#include <chrono>
#include <filesystem>

#define BOOST_ALL_NO_LIB
#include <boost/bind/bind.hpp>
#include <boost/format.hpp>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/sequenced_index.hpp>
using namespace boost::multi_index;

#include "../shared/Win32Exception.h"
#include "../shared/SharedMemory.h"
#include "../shared/Structures.h"
#include "../shared/Cpp11Helpers.h"
#include "../shared/NamedPipe.h"

//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
#define EXTERNAL_COMMANDS_COUNT 10
#define SEARCH_MRU_COUNT        10

//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
#include "Helpers.h"
#include "XmlHelper.h"
#include "ImageHandler.h"
#include "SettingsHandler.h"
#include "ConsoleHandler.h"
#include "Snippet.h"

//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
// Version numbers

#include "../shared/version.h"

//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
// WinXP defines

#define SPI_GETFONTSMOOTHINGTYPE	0x200A
#define FE_FONTSMOOTHINGCLEARTYPE	0x0002

//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
// User-defined messages

#define UM_UPDATE_CONSOLE_VIEW WM_USER + 0x1000
#define UM_CONSOLE_RESIZED     WM_USER + 0x1001
#define UM_CONSOLE_CLOSED      WM_USER + 0x1002
#define UM_UPDATE_TITLES       WM_USER + 0x1003
#define UM_SHOW_POPUP_MENU     WM_USER + 0x1004
#define UM_START_MOUSE_DRAG    WM_USER + 0x1005
#define UM_TRAY_NOTIFY         WM_USER + 0x1006
#define UM_UPDATE_STATUS_BAR   WM_USER + 0x1007

#define UPDATE_CONSOLE_RESIZE           0x0001
#define UPDATE_CONSOLE_TEXT_CHANGED     0x0002
#define UPDATE_CONSOLE_TITLE_CHANGED    0x0004
#define UPDATE_CONSOLE_CSBI_CHANGED     0x0008
#define UPDATE_CONSOLE_PROGRESS_CHANGED 0x0010

#define IDC_TRAY_ICON		0x0001

//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
// Global hotkeys

#define IDC_GLOBAL_ACTIVATE	0xB000

//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
// Windows' console window menu commands

#define SC_CONSOLE_COPY       0xFFF0
#define SC_CONSOLE_PASTE      0xFFF1
#define SC_CONSOLE_MARK       0xFFF2
#define SC_CONSOLE_SCROLL     0xFFF3
#define SC_CONSOLE_FIND       0xFFF4
#define SC_CONSOLE_SELECT_ALL 0xFFF5
#define SC_CONSOLE_PROPERTIES 0xFFF7

//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
// Console limits
#define MIN_BUFFER_ROWS     0
#define MAX_BUFFER_ROWS     32766
#define MIN_BUFFER_COLUMNS  0
#define MAX_BUFFER_COLUMNS  9999
#define MIN_WINDOW_ROWS     10
#define MAX_WINDOW_ROWS     200
#define MIN_WINDOW_COLUMNS  10
#define MAX_WINDOW_COLUMNS  300

//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
// pseudo SCROLL constant
#define SB_WHEEL 99

//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////

typedef enum
{
  ADJUSTSIZE_NONE,
  ADJUSTSIZE_WINDOW,
  ADJUSTSIZE_FONT
}
ADJUSTSIZE;

//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////

#define TM_INMENUMODE     0x0001
#define TM_POSTCHARBREAKS 0x0002

typedef
BOOL
(WINAPI * _t_TranslateMessageEx)(
    __in CONST MSG *lpMsg,
    __in UINT flags);

extern _t_TranslateMessageEx TranslateMessageEx;

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
// Memory allocation tracking

#ifdef _DEBUG
#include <crtdbg.h>
void* __cdecl operator new(size_t nSize, LPCSTR lpszFileName, int nLine);
#define DEBUG_NEW new(__FILE__, __LINE__)

void __cdecl operator delete(void* p, LPCSTR lpszFileName, int nLine);
#endif

//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
// trace function and TRACE macro

#ifdef _DEBUG

void Trace(const wchar_t* pszFormat, ...);

#define TRACE		::Trace
#define TRACE_KEY	__noop
#define TRACE_PERF	__noop

//#define CONSOLEZ_CHRONOS

#else

#define TRACE		__noop
#define TRACE_KEY	__noop
#define TRACE_PERF	__noop

#endif // _DEBUG

//////////////////////////////////////////////////////////////////////////////

