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

#include "../mutex.h"

#define DBGFUNC printf("%s\n", __PRETTY_FUNCTION__);

BOOL ShellExecute(HWND hwndDlg, const char *action,  const char *content1, const char *content2, const char *content3, int blah)
{
    DBGFUNC;
    return FALSE;
}

HWND GetDlgItem(HWND hwnd, int idx)
{
    DBGFUNC;
    return 0;
}

void ShowWindow(HWND hwnd, int cmd)
{
    DBGFUNC;
}

void DestroyWindow(HWND hwnd)
{
    DBGFUNC;
}

BOOL SWELL_GetGestureInfo(LPARAM lParam, GESTUREINFO* gi)
{
    DBGFUNC;
    return FALSE;
}

void SWELL_HideApp()
{
    DBGFUNC;
}

BOOL SetDlgItemText(HWND hwnd, int idx, const char *text)
{
    DBGFUNC;
    return FALSE;
}

BOOL SetDlgItemInt(HWND hwnd, int idx, int val, int issigned)
{
    DBGFUNC;
    return FALSE;
}

int GetDlgItemInt(HWND hwnd, int idx, BOOL *translated, int issigned)
{
    DBGFUNC;
    return 0;
}

BOOL GetDlgItemText(HWND hwnd, int idx, char *text, int textlen)
{
    DBGFUNC;
    return FALSE;
}

void CheckDlgButton(HWND hwnd, int idx, int check)
{
    DBGFUNC;
}

int IsDlgButtonChecked(HWND hwnd, int idx)
{
    DBGFUNC;
    return 0;
}

void EnableWindow(HWND hwnd, int enable)
{
    DBGFUNC;
}

void SetFocus(HWND hwnd)
{
    DBGFUNC;
}

HWND GetFocus()
{
    DBGFUNC;
    return 0;
}

void SetForegroundWindow(HWND hwnd)
{
    DBGFUNC;
}

HWND GetForegroundWindow()
{
    DBGFUNC;
    return 0;
}

HWND GetCapture()
{
    DBGFUNC;
    return 0;
}

HWND SetCapture(HWND hwnd)
{
    DBGFUNC;
    return 0;
}

void ReleaseCapture()
{
    DBGFUNC;
}

int IsChild(HWND hwndParent, HWND hwndChild)
{
    DBGFUNC;
    return 0;
}

HWND GetParent(HWND hwnd)
{
    DBGFUNC;
    return 0;
}

HWND SetParent(HWND hwnd, HWND newPar)
{
    DBGFUNC;
    return 0;
}

HWND GetWindow(HWND hwnd, int what)
{
    DBGFUNC;
    return 0;
}

HWND FindWindowEx(HWND par, HWND lastw, const char *classname, const char *title)
{
    DBGFUNC;
    return 0;
}

void ClientToScreen(HWND hwnd, POINT *p)
{
    DBGFUNC;
}

void ScreenToClient(HWND hwnd, POINT *p)
{
    DBGFUNC;
}

bool GetWindowRect(HWND hwnd, RECT *r)
{
    DBGFUNC;
    return false;
}

void GetWindowContentViewRect(HWND hwnd, RECT *r)
{
    DBGFUNC;
}

void GetClientRect(HWND hwnd, RECT *r)
{
    DBGFUNC;
}

HWND WindowFromPoint(POINT p)
{
    DBGFUNC;
    return 0;
}

void SetWindowPos(HWND hwnd, HWND zorder, int x, int y, int cx, int cy, int flags)
{
    DBGFUNC;
}

int SWELL_SetWindowLevel(HWND hwnd, int newlevel)
{
    DBGFUNC;
    return 0;
}

void InvalidateRect(HWND hwnd, RECT *r, int eraseBk)
{
    DBGFUNC;
}

void UpdateWindow(HWND hwnd)
{
    DBGFUNC;
}

LONG_PTR GetWindowLong(HWND hwnd, int idx)
{
    DBGFUNC;
    return 0;
}

LONG_PTR SetWindowLong(HWND hwnd, int idx, LONG_PTR val)
{
    DBGFUNC;
    return 0;
}

BOOL ScrollWindow(HWND hwnd, int xamt, int yamt, const RECT *lpRect, const RECT *lpClipRect)
{
    DBGFUNC;
    return FALSE;
}

int EnumPropsEx(HWND hwnd, PROPENUMPROCEX proc, LPARAM lParam)
{
    DBGFUNC;
    return -1;
}

HANDLE GetProp(HWND hwnd, const char *name)
{
    DBGFUNC;
    return 0;
}

BOOL SetProp(HWND hwnd, const char *name, HANDLE val)
{
    DBGFUNC;
    return FALSE;
}

HANDLE RemoveProp(HWND hwnd, const char *name)
{
    DBGFUNC;
    return 0;
}

bool IsWindowVisible(HWND hwnd)
{
    DBGFUNC;
    return false;
}

bool IsWindow(HWND hwnd)
{
    DBGFUNC;
    return false;
}

UINT_PTR SetTimer(HWND hwnd, UINT_PTR timerid, UINT rate, TIMERPROC tProc)
{
    DBGFUNC;
    return 0;
}

BOOL KillTimer(HWND hwnd, UINT_PTR timerid)
{
    DBGFUNC;
    return FALSE;
}

void ListView_SetExtendedListViewStyleEx(HWND h, int flag, int mask)
{
    DBGFUNC;
}

void ListView_InsertColumn(HWND h, int pos, const LVCOLUMN *lvc)
{
    DBGFUNC;
}

bool ListView_DeleteColumn(HWND h, int pos)
{
    DBGFUNC;
    return false;
}

void ListView_SetColumn(HWND h, int pos, const LVCOLUMN *lvc)
{
    DBGFUNC;
}

int ListView_GetColumnWidth(HWND h, int pos)
{
    DBGFUNC;
    return 0;
}

int ListView_InsertItem(HWND h, const LVITEM *item)
{
    DBGFUNC;
    return 0;
}

void ListView_SetItemText(HWND h, int ipos, int cpos, const char *txt)
{
    DBGFUNC;
}

bool ListView_SetItem(HWND h, LVITEM *item)
{
    DBGFUNC;
    return false;
}

int ListView_GetNextItem(HWND h, int istart, int flags)
{
    DBGFUNC;
    return -1;
}

bool ListView_GetItem(HWND h, LVITEM *item)
{
    DBGFUNC;
    return false;
}

int ListView_GetItemState(HWND h, int ipos, int mask)
{
    DBGFUNC;
    return 0;
}

void ListView_DeleteItem(HWND h, int ipos)
{
    DBGFUNC;
}

void ListView_DeleteAllItems(HWND h)
{
    DBGFUNC;
}

int ListView_GetSelectedCount(HWND h)
{
    DBGFUNC;
    return 0;
}

int ListView_GetItemCount(HWND h)
{
    DBGFUNC;
    return 0;
}

int ListView_GetSelectionMark(HWND h)
{
    DBGFUNC;
    return 0;
}

void ListView_SetColumnWidth(HWND h, int colpos, int wid)
{
    DBGFUNC;
}

bool ListView_SetItemState(HWND h, int ipos, int state, int statemask)
{
    DBGFUNC;
    return false;
}

void ListView_RedrawItems(HWND h, int startitem, int enditem)
{
    DBGFUNC;
}

void ListView_SetItemCount(HWND h, int cnt)
{
    DBGFUNC;
}

void ListView_EnsureVisible(HWND h, int i, BOOL pok)
{
    DBGFUNC;
}

bool ListView_GetSubItemRect(HWND h, int item, int subitem, int code, RECT *r)
{
    DBGFUNC;
    return false;
}

void ListView_SetImageList(HWND h, HIMAGELIST imagelist, int which)
{
    DBGFUNC;
}

int ListView_HitTest(HWND h, LVHITTESTINFO *pinf)
{
    DBGFUNC;
    return -1;
}

int ListView_SubItemHitTest(HWND h, LVHITTESTINFO *pinf)
{
    DBGFUNC;
    return -1;
}

void ListView_GetItemText(HWND hwnd, int item, int subitem, char *text, int textmax)
{
    DBGFUNC;
}

void ListView_SortItems(HWND hwnd, PFNLVCOMPARE compf, LPARAM parm)
{
    DBGFUNC;
}

bool ListView_GetItemRect(HWND h, int item, RECT *r, int code)
{
    DBGFUNC;
    return false;
}

bool ListView_Scroll(HWND h, int xscroll, int yscroll)
{
    DBGFUNC;
    return false;
}

int ListView_GetTopIndex(HWND h)
{
    DBGFUNC;
    return 0;
}

int ListView_GetCountPerPage(HWND h)
{
    DBGFUNC;
    return 0;
}

BOOL ListView_SetColumnOrderArray(HWND h, int cnt, int* arr)
{
    DBGFUNC;
    return FALSE;
}

BOOL ListView_GetColumnOrderArray(HWND h, int cnt, int* arr)
{
    DBGFUNC;
    return FALSE;
}

HWND ListView_GetHeader(HWND h)
{
    DBGFUNC;
    return 0;
}

int Header_GetItemCount(HWND h)
{
    DBGFUNC;
    return 0;
}

BOOL Header_GetItem(HWND h, int col, HDITEM* hi)
{
    DBGFUNC;
    return FALSE;
}

BOOL Header_SetItem(HWND h, int col, HDITEM* hi)
{
    DBGFUNC;
    return FALSE;
}

int SWELL_GetListViewHeaderHeight(HWND h)
{
    DBGFUNC;
    return 0;
}

int TabCtrl_GetItemCount(HWND hwnd)
{
    DBGFUNC;
    return 0;
}

BOOL TabCtrl_DeleteItem(HWND hwnd, int idx)
{
    DBGFUNC;
    return 0;
}

int TabCtrl_InsertItem(HWND hwnd, int idx, TCITEM *item)
{
    DBGFUNC;
    return 0;
}

int TabCtrl_SetCurSel(HWND hwnd, int idx)
{
    DBGFUNC;
    return 0;
}

int TabCtrl_GetCurSel(HWND hwnd)
{
    DBGFUNC;
    return 0;
}

BOOL TabCtrl_AdjustRect(HWND hwnd, BOOL fLarger, RECT *r)
{
    DBGFUNC;
    return FALSE;
}

HTREEITEM TreeView_InsertItem(HWND hwnd, TV_INSERTSTRUCT *ins)
{
    DBGFUNC;
    return NULL;
}

BOOL TreeView_Expand(HWND hwnd, HTREEITEM item, UINT flag)
{
    DBGFUNC;
    return TRUE;
}

HTREEITEM TreeView_GetSelection(HWND hwnd)
{ 
    DBGFUNC;
    return NULL;
}

void TreeView_DeleteItem(HWND hwnd, HTREEITEM item)
{
    DBGFUNC;
}

void TreeView_SelectItem(HWND hwnd, HTREEITEM item)
{
    DBGFUNC;
}

BOOL TreeView_GetItem(HWND hwnd, LPTVITEM pitem)
{
    DBGFUNC;
    return TRUE;
}

BOOL TreeView_SetItem(HWND hwnd, LPTVITEM pitem)
{
    DBGFUNC;
    return TRUE;
}

HTREEITEM TreeView_HitTest(HWND hwnd, TVHITTESTINFO *hti)
{
    DBGFUNC;
    return NULL;
}

BOOL TreeView_SetIndent(HWND hwnd, int indent)
{
    DBGFUNC;
    return FALSE;
}

HTREEITEM TreeView_GetChild(HWND hwnd, HTREEITEM item)
{
    DBGFUNC;
    return NULL;
}

HTREEITEM TreeView_GetNextSibling(HWND hwnd, HTREEITEM item)
{
    DBGFUNC;
    return NULL;
}

HTREEITEM TreeView_GetRoot(HWND hwnd)
{
    DBGFUNC;
    return NULL;
}

void TreeView_SetBkColor(HWND hwnd, int color)
{
    DBGFUNC;
}

void TreeView_SetTextColor(HWND hwnd, int color)
{
    DBGFUNC;
}

void ListView_SetBkColor(HWND hwnd, int color)
{
    DBGFUNC;
}

void ListView_SetTextBkColor(HWND hwnd, int color)
{
    DBGFUNC;
}

void ListView_SetTextColor(HWND hwnd, int color)
{
    DBGFUNC;
}

void ListView_SetGridColor(HWND hwnd, int color)
{
    DBGFUNC;
}

void ListView_SetSelColors(HWND hwnd, int *colors, int ncolors)
{
    DBGFUNC;
}

void* SWELL_ModalWindowStart(HWND hwnd)
{
    DBGFUNC;
    return 0;
}

bool SWELL_ModalWindowRun(void *ctx, int *ret) // returns false and puts retval in *ret when done
{
    DBGFUNC;
    return false;
}

void SWELL_ModalWindowEnd(void *ctx)
{
    DBGFUNC;
}

void SWELL_CloseWindow(HWND hwnd)
{
    DBGFUNC;
}

//---------------------------------------------------------------------------------------------------------------------------
// copied from swell-wnd.mm
// the same code is on swell-wnd-generic.cpp

typedef struct ccprocrec
{
    SWELL_ControlCreatorProc proc;
    int cnt;
    struct ccprocrec *next;
} ccprocrec;

static ccprocrec* m_ccprocs = NULL;

void SWELL_RegisterCustomControlCreator(SWELL_ControlCreatorProc proc)
{
    if (!proc) return;
    
    ccprocrec *p=m_ccprocs;
    while (p && p->next)
    {
        if (p->proc == proc)
        {
            p->cnt++;
            return;
        }
        p=p->next;
    }
    ccprocrec *ent = (ccprocrec*)malloc(sizeof(ccprocrec));
    ent->proc=proc;
    ent->cnt=1;
    ent->next=0;
    
    if (p) p->next=ent;
    else m_ccprocs=ent;
}

void SWELL_UnregisterCustomControlCreator(SWELL_ControlCreatorProc proc)
{
    if (!proc) return;
    
    ccprocrec *lp=NULL;
    ccprocrec *p=m_ccprocs;
    while (p)
    {
        if (p->proc == proc)
        {
            if (--p->cnt <= 0)
            {
                if (lp) lp->next=p->next;
                else m_ccprocs=p->next;
                free(p);
            }
            return;
        }
        lp=p;
        p=p->next;
    }
}

//---------------------------------------------------------------------------------------------------------------------------

LRESULT DefWindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    DBGFUNC;
    return 0;
}

int SWELL_GetDefaultButtonID(HWND hwndDlg, bool onlyIfEnabled)
{
    DBGFUNC;
    return 0;
}

LRESULT SendMessage(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    DBGFUNC;
    return 0;
}

void SWELL_BroadcastMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    DBGFUNC;
}

BOOL PostMessage(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    DBGFUNC;
    return 0;
}

void SWELL_MessageQueue_Flush()
{
    DBGFUNC;
}

void SWELL_MessageQueue_Clear(HWND h)
{
    DBGFUNC;
}

void SWELL_GetViewPort(RECT *r, const RECT *sourcerect, bool wantWork)
{
    DBGFUNC;
}

bool OpenClipboard(HWND hwndDlg)
{
    DBGFUNC;
    return false;
}

void CloseClipboard()
{
    DBGFUNC;
}

HANDLE GetClipboardData(UINT type)
{
    DBGFUNC;
    return 0;
}

void EmptyClipboard()
{
    DBGFUNC;
}

void SetClipboardData(UINT type, HANDLE h)
{
    DBGFUNC;
}

UINT RegisterClipboardFormat(const char *desc)
{
    DBGFUNC;
    return 0;
}

UINT EnumClipboardFormats(UINT lastfmt)
{
    DBGFUNC;
    return 0;
}

void SetOpaque(HWND h, bool opaque)
{
    DBGFUNC;
}

BOOL EndPaint(HWND hwnd, PAINTSTRUCT *ps)
{
    DBGFUNC;
    return TRUE;
}

int GetSystemMetrics(int p)
{
    DBGFUNC;
    return 0;
}

BOOL DragQueryPoint(HDROP hDrop,LPPOINT pt)
{
    DBGFUNC;
    return FALSE;
}

void DragFinish(HDROP hDrop)
{
    DBGFUNC;
}

UINT DragQueryFile(HDROP hDrop, UINT wf, char *buf, UINT bufsz)
{
    DBGFUNC;
    return 0;
}

void SWELL_DrawFocusRect(HWND hwndPar, RECT *rct, void **handle)
{
    DBGFUNC;
}

void SWELL_MakeSetCurParms(float xscale, float yscale, float xtrans, float ytrans, HWND parent, bool doauto, bool dosizetofit)
{
    DBGFUNC;
}

HWND SWELL_MakeButton(int def, const char *label, int idx, int x, int y, int w, int h, int flags)
{
    DBGFUNC;
    return 0;
}

HWND SWELL_MakeEditField(int idx, int x, int y, int w, int h, int flags)
{
    DBGFUNC;
    return 0;
}

HWND SWELL_MakeLabel( int align, const char *label, int idx, int x, int y, int w, int h, int flags)
{
    DBGFUNC;
    return 0;
}

HWND SWELL_MakeControl(const char *cname, int idx, const char *classname, int style, int x, int y, int w, int h, int exstyle)
{
    DBGFUNC;
    return 0;
}

HWND SWELL_MakeCombo(int idx, int x, int y, int w, int h, int flags)
{
    DBGFUNC;
    return 0;
}

HWND SWELL_MakeGroupBox(const char *name, int idx, int x, int y, int w, int h, int style)
{
    DBGFUNC;
    return 0;
}

HWND SWELL_MakeCheckBox(const char *name, int idx, int x, int y, int w, int h, int flags=0)
{
    DBGFUNC;
    return 0;
}

HWND SWELL_MakeListBox(int idx, int x, int y, int w, int h, int styles)
{
    DBGFUNC;
    return 0;
}

void SWELL_GenerateDialogFromList(const void *_list, int listsz)
{
    DBGFUNC;
}

//---------------------------------------------------------------------------------------------------------------------------
// copied from swell-wnd-generic.cpp
// swell-misc.mm has similar code

static pthread_t m_pmq_mainthread;
static WDL_Mutex* m_pmq_mutex = NULL;

void SWELL_Internal_PostMessage_Init()
{
    if (m_pmq_mutex) return;
    
    m_pmq_mainthread=pthread_self();
    m_pmq_mutex = new WDL_Mutex;
}

//---------------------------------------------------------------------------------------------------------------------------

void SWELL_SetWindowWantRaiseAmt(HWND h, int  amt)
{
    DBGFUNC;
}

void SWELL_SetListViewFastClickMask(HWND hList, int mask)
{
    DBGFUNC;
}

void SWELL_initargs(int* argc, char*** argv)
{
    DBGFUNC;
    
    if (qApp) return;

    new QApplication(*argc, *argv);
}

void SWELL_RunMessageLoop()
{
    DBGFUNC;
}

BOOL EnumChildWindows(HWND hwnd, BOOL (*cwEnumFunc)(HWND,LPARAM),LPARAM lParam)
{
    DBGFUNC;
    return FALSE;
}

BOOL SWELL_IsGroupBox(HWND hwnd)
{
    DBGFUNC;
    return FALSE;
}

BOOL SWELL_IsButton(HWND hwnd)
{
    DBGFUNC;
    return FALSE;
}

BOOL SWELL_IsStaticText(HWND hwnd)
{
    DBGFUNC;
    return FALSE;
}

void SWELL_GetDesiredControlSize(HWND hwnd, RECT *r)
{
    DBGFUNC;
}

#ifdef SWELL_LICE_GDI
void swell_OSupdateWindowToScreen(HWND hwnd, RECT *rect)
{
    DBGFUNC;
}
#endif

#endif
