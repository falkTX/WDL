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
//#include "swell-dlggen.h"
//#include "swell-internal.h"

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

bool IsWindowVisible(HWND hwnd)
{
    return false;
}

bool IsWindow(HWND hwnd)
{
    return false;
}

UINT_PTR SetTimer(HWND hwnd, UINT_PTR timerid, UINT rate, TIMERPROC tProc)
{
    return 0;
}

BOOL KillTimer(HWND hwnd, UINT_PTR timerid)
{
    return FALSE;
}

void ListView_SetExtendedListViewStyleEx(HWND h, int flag, int mask)
{
}

void ListView_InsertColumn(HWND h, int pos, const LVCOLUMN *lvc)
{
}

bool ListView_DeleteColumn(HWND h, int pos)
{
    return false;
}

void ListView_SetColumn(HWND h, int pos, const LVCOLUMN *lvc)
{
}

int ListView_GetColumnWidth(HWND h, int pos)
{
    return 0;
}

int ListView_InsertItem(HWND h, const LVITEM *item)
{
    return 0;
}

void ListView_SetItemText(HWND h, int ipos, int cpos, const char *txt)
{
}

bool ListView_SetItem(HWND h, LVITEM *item)
{
    return false;
}

int ListView_GetNextItem(HWND h, int istart, int flags)
{
    return -1;
}

bool ListView_GetItem(HWND h, LVITEM *item)
{
    return false;
}

int ListView_GetItemState(HWND h, int ipos, int mask)
{
    return 0;
}

void ListView_DeleteItem(HWND h, int ipos)
{
}

void ListView_DeleteAllItems(HWND h)
{
}

int ListView_GetSelectedCount(HWND h)
{
    return 0;
}

int ListView_GetItemCount(HWND h)
{
    return 0;
}

int ListView_GetSelectionMark(HWND h)
{
    if (!h) return 0;
    return 0;
}

void ListView_SetColumnWidth(HWND h, int colpos, int wid)
{
}

bool ListView_SetItemState(HWND h, int ipos, int state, int statemask)
{
    return false;
}

void ListView_RedrawItems(HWND h, int startitem, int enditem)
{
}

void ListView_SetItemCount(HWND h, int cnt)
{
}

void ListView_EnsureVisible(HWND h, int i, BOOL pok)
{
}

bool ListView_GetSubItemRect(HWND h, int item, int subitem, int code, RECT *r)
{
    return false;
}

void ListView_SetImageList(HWND h, HIMAGELIST imagelist, int which)
{
}

int ListView_HitTest(HWND h, LVHITTESTINFO *pinf)
{
    return -1;
}

int ListView_SubItemHitTest(HWND h, LVHITTESTINFO *pinf)
{
    return -1;
}

void ListView_GetItemText(HWND hwnd, int item, int subitem, char *text, int textmax)
{
}

void ListView_SortItems(HWND hwnd, PFNLVCOMPARE compf, LPARAM parm)
{
}

bool ListView_GetItemRect(HWND h, int item, RECT *r, int code)
{
    return false;
}

bool ListView_Scroll(HWND h, int xscroll, int yscroll)
{
    return false;
}

int ListView_GetTopIndex(HWND h)
{
    return 0;
}

int ListView_GetCountPerPage(HWND h)
{
    return 0;
}

BOOL ListView_SetColumnOrderArray(HWND h, int cnt, int* arr)
{
    return FALSE;
}

BOOL ListView_GetColumnOrderArray(HWND h, int cnt, int* arr)
{
    return FALSE;
}

HWND ListView_GetHeader(HWND h)
{
    return 0;
}

int Header_GetItemCount(HWND h)
{
    return 0;
}

BOOL Header_GetItem(HWND h, int col, HDITEM* hi)
{
    return FALSE;
}

BOOL Header_SetItem(HWND h, int col, HDITEM* hi)
{
    return FALSE;
}

int SWELL_GetListViewHeaderHeight(HWND h)
{
    return 0;
}

int TabCtrl_GetItemCount(HWND hwnd)
{
    return 0;
}

BOOL TabCtrl_DeleteItem(HWND hwnd, int idx)
{
    return 0;
}

int TabCtrl_InsertItem(HWND hwnd, int idx, TCITEM *item)
{
    return 0;
}

int TabCtrl_SetCurSel(HWND hwnd, int idx)
{
    return 0;
}

int TabCtrl_GetCurSel(HWND hwnd)
{
    return 0;
}

BOOL TabCtrl_AdjustRect(HWND hwnd, BOOL fLarger, RECT *r)
{
    return FALSE;
}

HTREEITEM TreeView_InsertItem(HWND hwnd, TV_INSERTSTRUCT *ins)
{
    return NULL;
}

BOOL TreeView_Expand(HWND hwnd, HTREEITEM item, UINT flag)
{
    return TRUE;
}

HTREEITEM TreeView_GetSelection(HWND hwnd)
{ 
    return NULL;
}

void TreeView_DeleteItem(HWND hwnd, HTREEITEM item)
{
}

void TreeView_SelectItem(HWND hwnd, HTREEITEM item)
{
}

BOOL TreeView_GetItem(HWND hwnd, LPTVITEM pitem)
{
    return TRUE;
}

BOOL TreeView_SetItem(HWND hwnd, LPTVITEM pitem)
{
    return TRUE;
}

HTREEITEM TreeView_HitTest(HWND hwnd, TVHITTESTINFO *hti)
{
    return NULL;
}

BOOL TreeView_SetIndent(HWND hwnd, int indent)
{
    return FALSE;
}

HTREEITEM TreeView_GetChild(HWND hwnd, HTREEITEM item)
{
    return NULL;
}

HTREEITEM TreeView_GetNextSibling(HWND hwnd, HTREEITEM item)
{
    return NULL;
}

HTREEITEM TreeView_GetRoot(HWND hwnd)
{
    return NULL;
}

void TreeView_SetBkColor(HWND hwnd, int color)
{
}

void TreeView_SetTextColor(HWND hwnd, int color)
{
}

void ListView_SetBkColor(HWND hwnd, int color)
{
}

void ListView_SetTextBkColor(HWND hwnd, int color)
{
}

void ListView_SetTextColor(HWND hwnd, int color)
{
}

void ListView_SetGridColor(HWND hwnd, int color)
{
}

void ListView_SetSelColors(HWND hwnd, int *colors, int ncolors)
{
}

void* SWELL_ModalWindowStart(HWND hwnd)
{
    return 0;
}

bool SWELL_ModalWindowRun(void *ctx, int *ret) // returns false and puts retval in *ret when done
{
    return false;
}

void SWELL_ModalWindowEnd(void *ctx)
{
}

void SWELL_CloseWindow(HWND hwnd)
{
}

void SWELL_RegisterCustomControlCreator(SWELL_ControlCreatorProc proc)
{
}

void SWELL_UnregisterCustomControlCreator(SWELL_ControlCreatorProc proc)
{
}

LRESULT DefWindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    return 0;
}

int SWELL_GetDefaultButtonID(HWND hwndDlg, bool onlyIfEnabled)
{
    return 0;
}

LRESULT SendMessage(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    return 0;
}

void SWELL_BroadcastMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
}

BOOL PostMessage(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    return 0;
}

void SWELL_MessageQueue_Flush()
{
}

void SWELL_MessageQueue_Clear(HWND h)
{
}

void SWELL_GetViewPort(RECT *r, const RECT *sourcerect, bool wantWork)
{
}

bool OpenClipboard(HWND hwndDlg)
{
    return false;
}

void CloseClipboard()
{
}

HANDLE GetClipboardData(UINT type)
{
    return 0;
}

void EmptyClipboard()
{
}

void SetClipboardData(UINT type, HANDLE h)
{
}

UINT RegisterClipboardFormat(const char *desc)
{
    return 0;
}

UINT EnumClipboardFormats(UINT lastfmt)
{
    return 0;
}

void SetOpaque(HWND h, bool opaque)
{
}

BOOL EndPaint(HWND hwnd, PAINTSTRUCT *ps)
{
    return TRUE;
}

int GetSystemMetrics(int p)
{
    return 0;
}

BOOL DragQueryPoint(HDROP hDrop,LPPOINT pt)
{
    return FALSE;
}

void DragFinish(HDROP hDrop)
{
}

UINT DragQueryFile(HDROP hDrop, UINT wf, char *buf, UINT bufsz)
{
    return 0;
}

void SWELL_DrawFocusRect(HWND hwndPar, RECT *rct, void **handle)
{
}

void SWELL_MakeSetCurParms(float xscale, float yscale, float xtrans, float ytrans, HWND parent, bool doauto, bool dosizetofit)
{
}

HWND SWELL_MakeButton(int def, const char *label, int idx, int x, int y, int w, int h, int flags)
{
    return 0;
}

HWND SWELL_MakeEditField(int idx, int x, int y, int w, int h, int flags)
{
    return 0;
}

HWND SWELL_MakeLabel( int align, const char *label, int idx, int x, int y, int w, int h, int flags)
{
    return 0;
}

HWND SWELL_MakeControl(const char *cname, int idx, const char *classname, int style, int x, int y, int w, int h, int exstyle)
{
    return 0;
}

HWND SWELL_MakeCombo(int idx, int x, int y, int w, int h, int flags)
{
    return 0;
}

HWND SWELL_MakeGroupBox(const char *name, int idx, int x, int y, int w, int h, int style)
{
    return 0;
}

HWND SWELL_MakeCheckBox(const char *name, int idx, int x, int y, int w, int h, int flags=0)
{
    return 0;
}

HWND SWELL_MakeListBox(int idx, int x, int y, int w, int h, int styles)
{
    return 0;
}

void SWELL_GenerateDialogFromList(const void *_list, int listsz)
{
}

void SWELL_Internal_PostMessage_Init()
{
}

void SWELL_SetWindowWantRaiseAmt(HWND h, int  amt)
{
}

void SWELL_SetListViewFastClickMask(HWND hList, int mask)
{
}

void SWELL_initargs(int *argc, char ***argv) 
{
}

void SWELL_RunMessageLoop()
{
}

BOOL EnumChildWindows(HWND hwnd, BOOL (*cwEnumFunc)(HWND,LPARAM),LPARAM lParam)
{
    return FALSE;
}

BOOL SWELL_IsGroupBox(HWND hwnd)
{
    return FALSE;
}

BOOL SWELL_IsButton(HWND hwnd)
{
    return FALSE;
}

BOOL SWELL_IsStaticText(HWND hwnd)
{
    return FALSE;
}

void SWELL_GetDesiredControlSize(HWND hwnd, RECT *r)
{
}

#ifdef SWELL_LICE_GDI
void swell_OSupdateWindowToScreen(HWND hwnd, RECT *rect)
{
}
#endif

#endif
