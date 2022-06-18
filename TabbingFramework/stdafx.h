// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#pragma once

// Change these values to use different versions
/*
#define WINVER        0x0602
#define _WIN32_WINNT  0x0602
*/
#ifdef _USE_AERO
#define _WIN32_IE     0x0700
#else
#define _WIN32_IE     0x0600
#endif

#define _RICHEDIT_VER 0x0300

//////////////////////////////////////////////////////////////////////////////

#define _USE_MATH_DEFINES

#include <atlbase.h>
#include <atlcoll.h>
#include <atlstr.h>
#include <atltypes.h>

#define _WTL_NO_CSTRING
#define _WTL_NO_WTYPES

#pragma warning(push)
#pragma warning(disable: 4091)
#include <wtl/atlapp.h>

extern CAppModule _Module;

#include <atlwin.h>
#include <wtl/atlddx.h>
#include <wtl/atlmisc.h>

#include <wtl/atltheme.h>
#include <wtl/atlframe.h>
#include <wtl/atlctrls.h>
#include <wtl/atldlgs.h>
#include <wtl/atlctrlw.h>
#include <wtl/atlctrlx.h>

#include <userenv.h>
#include <Lm.h>

#pragma warning(push)
#pragma warning(disable: 4091 4189 4267 4458 4838)
#include <atlgdix.h>

#ifdef _USE_AERO
  #include <dwmapi.h>
  #include <gdiplus.h>
  #include "wtlaero.h"
  #pragma comment (lib, "gdiplus.lib")
#endif

#if defined _M_IX86
  #pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_IA64
  #pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
  #pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
  #pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif

#include "CustomTabCtrl.h"
#include "DotNetTabCtrl.h"
#ifdef _USE_AERO
  #include "AeroTabCtrl.h"
#endif
#include "TabbedFrame.h"

#pragma warning(pop)