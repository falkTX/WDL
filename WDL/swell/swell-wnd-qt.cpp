/* Cockos SWELL (Simple/Small Win32 Emulation Layer for Losers (who use OS X))
   Copyright (C) 2006-2007, Cockos, Inc.
   
    This software is provided 'as-is', without any express or implied
    warranty.  In no event will the authors be held liable for any damages
    arising from the use of this software.
    
    Permission is granted to anyone to use this software for any purpose,
    including commercial applications, and to alter it and redistribute it
    freely, subject to the following restrictions:
    
    1. The origin of this software must not be misrepresented; you must not
       claim that you wrote the original software. If you use this software
       in a product, an acknowledgment in the product documentation would be
       appreciated but is not required.
    2. Altered source versions must be plainly marked as such, and must not be
       misrepresented as being the original software.
    3. This notice may not be removed or altered from any source distribution.
    
    
    This file provides basic windows APIs for handling windows, as well as the stubs to enable swell-dlggen to work.
    
  */


#ifndef SWELL_PROVIDED_BY_APP

#include "swell.h"
#include "swell-dlggen.h"
#include "swell-internal.h"

BOOL ShellExecute(HWND hwndDlg, const char *action,  const char *content1, const char *content2, const char *content3, int blah)
{
    return FALSE;
}

HWND GetDlgItem(HWND hwnd, int idx)
{
    return 0;
}

void ShowWindow(HWND hwnd, int cmd)
{
    
}

void DestroyWindow(HWND hwnd)
{
    
}

BOOL SWELL_GetGestureInfo(LPARAM lParam, GESTUREINFO* gi)
{
    return FALSE;
}

void SWELL_HideApp()
{
    
}

BOOL SetDlgItemText(HWND hwnd, int idx, const char *text)
{
    return FALSE;
}

BOOL SetDlgItemInt(HWND hwnd, int idx, int val, int issigned)
{
    return FALSE;
}

int GetDlgItemInt(HWND hwnd, int idx, BOOL *translated, int issigned)
{
    return 0;
}

BOOL GetDlgItemText(HWND hwnd, int idx, char *text, int textlen)
{
    return FALSE;
}

void CheckDlgButton(HWND hwnd, int idx, int check)
{
    
}

int IsDlgButtonChecked(HWND hwnd, int idx)
{
    return 0;
}

void EnableWindow(HWND hwnd, int enable)
{
    
}

void SetFocus(HWND hwnd)
{
    
}

HWND GetFocus()
{
    return 0;
}

void SetForegroundWindow(HWND hwnd)
{
    
}

HWND GetForegroundWindow()
{
    return 0;
}

HWND GetCapture()
{
    
    return 0;
}

HWND SetCapture(HWND hwnd)
{
    return 0;
}

void ReleaseCapture()
{
    
}

int IsChild(HWND hwndParent, HWND hwndChild)
{
    return 0;
}

HWND GetParent(HWND hwnd)
{
    return 0;
}

HWND SetParent(HWND hwnd, HWND newPar)
{
    return 0;
}

HWND GetWindow(HWND hwnd, int what)
{
    return 0;
}

HWND FindWindowEx(HWND par, HWND lastw, const char *classname, const char *title)
{
    return 0;
}

void ClientToScreen(HWND hwnd, POINT *p)
{
    
}

void ScreenToClient(HWND hwnd, POINT *p)
{
    
}

bool GetWindowRect(HWND hwnd, RECT *r)
{
    return false;
}

void GetWindowContentViewRect(HWND hwnd, RECT *r)
{
    
}

void GetClientRect(HWND hwnd, RECT *r)
{
    
}

HWND WindowFromPoint(POINT p)
{
    return 0;
}

// WinOffsetRect missing
// WinSetRect missing
// WinUnionRect missing
// WinIntersectRect missing

void SetWindowPos(HWND hwnd, HWND zorder, int x, int y, int cx, int cy, int flags)
{
    
}

int SWELL_SetWindowLevel(HWND hwnd, int newlevel)
{
    return 0;
}

void InvalidateRect(HWND hwnd, RECT *r, int eraseBk)
{
}

void UpdateWindow(HWND hwnd)
{
    
}

LONG_PTR GetWindowLong(HWND hwnd, int idx)
{
    return 0;
}

LONG_PTR SetWindowLong(HWND hwnd, int idx, LONG_PTR val)
{
    return 0;
}

BOOL ScrollWindow(HWND hwnd, int xamt, int yamt, const RECT *lpRect, const RECT *lpClipRect)
{
    return FALSE;
}

int EnumPropsEx(HWND hwnd, PROPENUMPROCEX proc, LPARAM lParam)
{
    return -1;
}

HANDLE GetProp(HWND hwnd, const char *name)
{
    return 0;
}

BOOL SetProp(HWND hwnd, const char *name, HANDLE val)
{
    return FALSE;
}

HANDLE RemoveProp(HWND hwnd, const char *name)
{
    return 0;
}

#endif
