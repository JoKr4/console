// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#pragma once

#include <LMCONS.H>
#include <lmapibuf.h>
// that one defines _LMAPIBUF_

#include <UserEnv.h>
// that one defines _INC_USERENV

#include <MUILoad.h>
// that one defines _MUILOAD_H_INCLUDED_

#include <WinInet.h>
// that one defines _WININET_
#if _WIN32_WINNT >= 0x0600
#include <netlistmgr.h>
#endif

// clipboard etc
#include <winuser.h>