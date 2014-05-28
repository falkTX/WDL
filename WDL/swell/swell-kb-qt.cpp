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
    
    
    This file provides basic key and mouse cursor querying, as well as a mac key to windows key translation function.
    
  */

#ifndef SWELL_PROVIDED_BY_APP

#include "swell.h"
#include "swell-dlggen.h"

SWELL_CursorResourceIndex* SWELL_curmodule_cursorresource_head;

int SWELL_KeyToASCII(int wParam, int lParam, int *newflags)
{
    return 0;
}

WORD GetAsyncKeyState(int key)
{
    return 0;
}

void GetCursorPos(POINT *pt)
{
}

DWORD GetMessagePos()
{  
    return 0;
}

HCURSOR SWELL_LoadCursor(const char *_idx)
{
    return 0;
}

void SWELL_SetCursor(HCURSOR curs)
{
}

HCURSOR SWELL_GetCursor()
{
    return 0;
}

HCURSOR SWELL_GetLastSetCursor()
{
    return 0;
}

bool SWELL_IsCursorVisible()
{
    return false;
}

int SWELL_ShowCursor(BOOL bShow)
{
    return 0;
}

BOOL SWELL_SetCursorPos(int X, int Y)
{
    return false;
}

HCURSOR SWELL_LoadCursorFromFile(const char *fn)
{
    return NULL;
}

#endif
