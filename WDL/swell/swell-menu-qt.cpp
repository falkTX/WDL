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

HMENU CreatePopupMenu()
{
    return 0;
}

HMENU CreatePopupMenuEx(const char *title)
{
    return 0;
}

void DestroyMenu(HMENU hMenu)
{
    delete hMenu;
}

int AddMenuItem(HMENU hMenu, int pos, const char *name, int tagid)
{
    if (!hMenu) return -1;
    MENUITEMINFO *inf = (MENUITEMINFO*)calloc(1,sizeof(MENUITEMINFO));
    inf->wID = tagid;
    inf->dwTypeData = strdup(name?name:"");
    hMenu->items.Insert(pos,inf);
    return 0;
}

HMENU GetSubMenu(HMENU hMenu, int pos)
{
    MENUITEMINFO *item = hMenu ? hMenu->items.Get(pos) : NULL;
    if (item) return item->hSubMenu;
    return 0;
}

int GetMenuItemCount(HMENU hMenu)
{
    if (hMenu) return hMenu->items.GetSize();
    return 0;
}

int GetMenuItemID(HMENU hMenu, int pos)
{
    MENUITEMINFO *item = hMenu ? hMenu->items.Get(pos) : NULL;
    if (!item || item->hSubMenu) return -1;
    return item->wID;
}

bool SetMenuItemModifier(HMENU hMenu, int idx, int flag, int code, unsigned int mask)
{
    return false;
}

bool SetMenuItemText(HMENU hMenu, int idx, int flag, const char *text)
{
    return false;
}

bool EnableMenuItem(HMENU hMenu, int idx, int en)
{
    return false;
}

bool DeleteMenu(HMENU hMenu, int idx, int flag)
{
    return false;
}

bool CheckMenuItem(HMENU hMenu, int idx, int chk)
{
    return false;
}

void InsertMenuItem(HMENU hMenu, int pos, BOOL byPos, MENUITEMINFO *mi)
{
    
}

void SWELL_InsertMenu(HMENU menu, int pos, int flag, UINT_PTR idx, const char *str)
{
    
}

BOOL GetMenuItemInfo(HMENU hMenu, int pos, BOOL byPos, MENUITEMINFO *mi)
{
    return FALSE;
}

BOOL SetMenuItemInfo(HMENU hMenu, int pos, BOOL byPos, MENUITEMINFO *mi)
{
    return FALSE;
}

void DrawMenuBar(HWND hwnd)
{
}

HMENU SWELL_LoadMenu(SWELL_MenuResourceIndex *head, const char *resid)
{
    return 0;
}

int TrackPopupMenu(HMENU hMenu, int flags, int xpos, int ypos, int resvd, HWND hwnd, const RECT *r)
{
    return 0;
}

void SWELL_SetMenuDestination(HMENU menu, HWND hwnd)
{
    // only needed for Cocoa
}

HMENU SWELL_DuplicateMenu(HMENU menu)
{
    return 0;
}

BOOL SetMenu(HWND hwnd, HMENU menu)
{
    if (!hwnd) return 0;
    hwnd->m_menu = menu;
    
    return TRUE;
}

HMENU GetMenu(HWND hwnd)
{
    if (!hwnd) return 0;
    return hwnd->m_menu;
}

HMENU SWELL_GetCurrentMenu()
{
    return NULL; // not osx
}
void SWELL_SetCurrentMenu(HMENU hmenu)
{
}

#endif
