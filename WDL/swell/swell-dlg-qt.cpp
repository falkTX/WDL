#ifndef SWELL_PROVIDED_BY_APP

#include "swell.h"
#include "swell-dlggen.h"

HMENU SWELL_GetDefaultWindowMenu()
{
    return 0;
}

void SWELL_SetDefaultWindowMenu(HMENU menu)
{
}

HMENU SWELL_GetDefaultModalWindowMenu()
{ 
    return 0;
}

void SWELL_SetDefaultModalWindowMenu(HMENU menu)
{
}

int SWELL_DialogBox(SWELL_DialogResourceIndex *reshead, const char *resid, HWND parent,  DLGPROC dlgproc, LPARAM param)
{
    return 0;
}

HWND SWELL_CreateDialog(SWELL_DialogResourceIndex *reshead, const char *resid, HWND parent, DLGPROC dlgproc, LPARAM param)
{
    return 0;
}

void EndDialog(HWND wnd, int ret)
{
}

void SWELL_InitiateDragDrop(HWND hwnd, RECT* srcrect, const char* srcfn, void (*callback)(const char* dropfn))
{
}

void SWELL_InitiateDragDropOfFileList(HWND hwnd, RECT *srcrect, const char **srclist, int srccount, HICON icon)
{
}

void SWELL_FinishDragDrop()
{
}

#endif
