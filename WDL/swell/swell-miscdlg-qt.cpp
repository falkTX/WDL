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
    
    
    This file provides basic APIs for browsing for files, directories, and messageboxes.
    
    These APIs don't all match the Windows equivelents, but are close enough to make it not too much trouble.
    
  */


#ifndef SWELL_PROVIDED_BY_APP

#include "swell.h"

int MessageBox(HWND hwndParent, const char *text, const char *caption, int type)
{
    return 0;
}

char *BrowseForFiles(const char *text, const char *initialdir, 
                     const char *initialfile, bool allowmul, const char *extlist)
{
    return NULL;
}

bool BrowseForSaveFile(const char *text, const char *initialdir, const char *initialfile, const char *extlist,
                       char *fn, int fnsize)
{
    return false;
}

bool BrowseForDirectory(const char *text, const char *initialdir, char *fn, int fnsize)
{
    return false;
}

static const char* BFSF_Templ_dlgid;
static DLGPROC BFSF_Templ_dlgproc;
static struct SWELL_DialogResourceIndex* BFSF_Templ_reshead;
void BrowseFile_SetTemplate(const char* dlgid, DLGPROC dlgProc, struct SWELL_DialogResourceIndex* reshead)
{
    BFSF_Templ_dlgid=dlgid;
    BFSF_Templ_dlgproc=dlgProc;
    BFSF_Templ_reshead=reshead;
}

#endif
