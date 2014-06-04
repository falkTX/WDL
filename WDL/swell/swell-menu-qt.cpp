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
    
    
    This file provides basic windows menu API to interface an NSMenu
    
  */

#ifndef SWELL_PROVIDED_BY_APP

#include "swell.h"
#include "swell-menugen.h"
#include "swell-internal.h"

#define DBGFUNC printf("%s\n", __PRETTY_FUNCTION__);

HMENU CreatePopupMenu()
{
    DBGFUNC;
    return 0;
}

HMENU CreatePopupMenuEx(const char *title)
{
    DBGFUNC;
    return 0;
}

void DestroyMenu(HMENU hMenu)
{
    DBGFUNC;
}

int AddMenuItem(HMENU hMenu, int pos, const char *name, int tagid)
{
    DBGFUNC;
    return 0;
}

HMENU GetSubMenu(HMENU hMenu, int pos)
{
    DBGFUNC;
    return 0;
}

int GetMenuItemCount(HMENU hMenu)
{
    DBGFUNC;
    return 0;
}

int GetMenuItemID(HMENU hMenu, int pos)
{
    DBGFUNC;
    return -1;
}

bool SetMenuItemModifier(HMENU hMenu, int idx, int flag, int code, unsigned int mask)
{
    DBGFUNC;
    return false;
}

bool SetMenuItemText(HMENU hMenu, int idx, int flag, const char *text)
{
    DBGFUNC;
    return false;
}

bool EnableMenuItem(HMENU hMenu, int idx, int en)
{
    DBGFUNC;
    return false;
}

bool DeleteMenu(HMENU hMenu, int idx, int flag)
{
    DBGFUNC;
    return false;
}

bool CheckMenuItem(HMENU hMenu, int idx, int chk)
{
    DBGFUNC;
    return false;
}

void InsertMenuItem(HMENU hMenu, int pos, BOOL byPos, MENUITEMINFO *mi)
{
    DBGFUNC;
}

void SWELL_InsertMenu(HMENU menu, int pos, int flag, UINT_PTR idx, const char *str)
{
    DBGFUNC;
}

BOOL GetMenuItemInfo(HMENU hMenu, int pos, BOOL byPos, MENUITEMINFO *mi)
{
    DBGFUNC;
    return FALSE;
}

BOOL SetMenuItemInfo(HMENU hMenu, int pos, BOOL byPos, MENUITEMINFO *mi)
{
    DBGFUNC;
    return FALSE;
}

void DrawMenuBar(HWND hwnd)
{
    DBGFUNC;
}

//---------------------------------------------------------------------------------------------------------------------------
// copied from swell-menu.mm
// the same code is on swell-menu-generic.cpp

SWELL_MenuResourceIndex* SWELL_curmodule_menuresource_head = NULL; // todo: move to per-module thingy

static SWELL_MenuResourceIndex* resById(SWELL_MenuResourceIndex *head, const char *resid)
{
    SWELL_MenuResourceIndex *p=head;
    while (p)
    {
        if (p->resid == resid) return p;
        p=p->_next;
    }
    return 0;
}

HMENU SWELL_LoadMenu(SWELL_MenuResourceIndex *head, const char *resid)
{
    SWELL_MenuResourceIndex *p;
    
    if (!(p=resById(head,resid))) return 0;
    HMENU hMenu=CreatePopupMenu();
    if (hMenu) p->createFunc(hMenu);
    return hMenu;
}

//---------------------------------------------------------------------------------------------------------------------------

int TrackPopupMenu(HMENU hMenu, int flags, int xpos, int ypos, int resvd, HWND hwnd, const RECT *r)
{
    DBGFUNC;
    return 0;
}

void SWELL_SetMenuDestination(HMENU menu, HWND hwnd)
{
    DBGFUNC;
}

HMENU SWELL_DuplicateMenu(HMENU menu)
{
    DBGFUNC;
    return 0;
}

BOOL SetMenu(HWND hwnd, HMENU menu)
{
    DBGFUNC;
    return FALSE;
}

HMENU GetMenu(HWND hwnd)
{
    DBGFUNC;
    return 0;
}

HMENU SWELL_GetCurrentMenu()
{
    DBGFUNC;
    return NULL;
}

void SWELL_SetCurrentMenu(HMENU hmenu)
{
    DBGFUNC;
}

void SWELL_Menu_AddMenuItem(HMENU hMenu, const char *name, int idx, int flags)
{
    DBGFUNC;
}

int SWELL_GenerateMenuFromList(HMENU hMenu, const void *_list, int listsz)
{
    DBGFUNC;
    return 0;
}

#endif
