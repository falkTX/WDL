#ifndef SWELL_PROVIDED_BY_APP

#include "swell.h"
#include "swell-dlggen.h"
#include "swell-internal.h"

#define DBGFUNC printf("%s\n", __PRETTY_FUNCTION__);

HMENU SWELL_GetDefaultWindowMenu()
{
    DBGFUNC;
    return 0;
}

void SWELL_SetDefaultWindowMenu(HMENU menu)
{
    DBGFUNC;
}

HMENU SWELL_GetDefaultModalWindowMenu()
{ 
    DBGFUNC;
    return 0;
}

void SWELL_SetDefaultModalWindowMenu(HMENU menu)
{
    DBGFUNC;
}

int SWELL_DialogBox(SWELL_DialogResourceIndex *reshead, const char *resid, HWND parent,  DLGPROC dlgproc, LPARAM param)
{
    DBGFUNC;
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------
// copied from swell-dlg-generic.cpp

static SWELL_DialogResourceIndex* resById(SWELL_DialogResourceIndex *head, const char *resid)
{
    SWELL_DialogResourceIndex *p=head;
    while (p)
    {
        if (p->resid == resid) return p;
        p=p->_next;
    }
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------
// adapted from existing code

HWND SWELL_CreateDialog(SWELL_DialogResourceIndex* reshead, const char* resid, HWND parent, DLGPROC dlgproc, LPARAM param)
{
    DBGFUNC;

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------

void EndDialog(HWND wnd, int ret)
{
    DBGFUNC;
}

void SWELL_InitiateDragDrop(HWND hwnd, RECT* srcrect, const char* srcfn, void (*callback)(const char* dropfn))
{
    DBGFUNC;
}

void SWELL_InitiateDragDropOfFileList(HWND hwnd, RECT *srcrect, const char **srclist, int srccount, HICON icon)
{
    DBGFUNC;
}

void SWELL_FinishDragDrop()
{
    DBGFUNC;
}

#endif
