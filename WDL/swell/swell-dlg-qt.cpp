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
    
    // TODO: this is very very unfinished
    return 0;
    
    unsigned int forceStyles=0; // 1=resizable, 2=no minimize, 4=no close
    bool forceNonChild=false;
    if ((((INT_PTR)resid)&~0xf)==0x400000)
    {
        forceStyles = (int) (((INT_PTR)resid)&0xf);
        if (forceStyles) forceNonChild=true;
        resid=NULL;
    }
    SWELL_DialogResourceIndex *p=resById(reshead,resid);
    if (!p&&resid) return 0;
    
    RECT r={0,0,p?p->width : 300, p?p->height : 200};
    HWND owner=NULL;
    
    if (!forceNonChild && parent && (!p || (p->windowTypeFlags&SWELL_DLG_WS_CHILD)))
    {
    } 
    else 
    {
        owner = parent;
        parent = NULL; // top level window
    }
    
    HWND__ *h = new HWND__(parent,0,&r,NULL,false,NULL,NULL);
    if (forceNonChild || (p && !(p->windowTypeFlags&SWELL_DLG_WS_CHILD)))
    {
        if ((forceStyles&1) || (p && (p->windowTypeFlags&SWELL_DLG_WS_RESIZABLE))) 
            h->m_style |= WS_THICKFRAME|WS_CAPTION;
        else h->m_style |= WS_CAPTION;
    }
    else if (!p && !parent) h->m_style |= WS_CAPTION;
    else if (parent && (!p || (p->windowTypeFlags&SWELL_DLG_WS_CHILD))) h->m_style |= WS_CHILD;
    
    if (p)
    {
      p->createFunc(h,p->windowTypeFlags);
      if (p->title) SetWindowText(h,p->title);
  
      h->m_dlgproc = dlgproc;
      h->m_wndproc = SwellDialogDefaultWindowProc;
  
      //HWND hFoc=m_children;
  //    while (hFoc && !hFoc->m_wantfocus) hFoc=hFoc->m_next;
   //   if (!hFoc) hFoc=this;
    //  if (dlgproc(this,WM_INITDIALOG,(WPARAM)hFoc,0)&&hFoc) SetFocus(hFoc);
  
      h->m_dlgproc(h,WM_INITDIALOG,0,param);
    } 
    else
    {
      h->m_wndproc = (WNDPROC)dlgproc;
      h->m_wndproc(h,WM_CREATE,0,param);
    }
      
    return h;
}

// TODO - remove this
// TODO - use a QWidget as HWND

LRESULT SwellDialogDefaultWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    DLGPROC d=(DLGPROC)GetWindowLong(hwnd,DWL_DLGPROC);
    if (d) 
    {
        if (uMsg == WM_PAINT)
        {
            PAINTSTRUCT ps;
            if (BeginPaint(hwnd,&ps))
            {
                HBRUSH hbrush = (HBRUSH) d(hwnd,WM_CTLCOLORDLG,(WPARAM)ps.hdc,(LPARAM)hwnd);
                if (hbrush && hbrush != (HBRUSH)1)
                {
                    FillRect(ps.hdc,&ps.rcPaint,hbrush);
                }
                else if (1) 
                {
                    hbrush=CreateSolidBrush(GetSysColor(COLOR_WINDOW));
                    FillRect(ps.hdc,&ps.rcPaint,hbrush);
                    DeleteObject(hbrush);
                }
                else if (0) // todo only on top level windows?
                {
                    SWELL_FillDialogBackground(ps.hdc,&ps.rcPaint,3);
                }
                
                EndPaint(hwnd,&ps);
            }
        }
        
        LRESULT r=(LRESULT) d(hwnd,uMsg,wParam,lParam);
        
        
        if (r) return r; 
    }
    return DefWindowProc(hwnd,uMsg,wParam,lParam);
}

HWND__::HWND__(HWND par, int wID, RECT *wndr, const char *label, bool visible, WNDPROC wndproc, DLGPROC dlgproc)
{
    m_refcnt=1;
    m_private_data=0;
    
    m_classname = "unknown";
    m_wndproc=wndproc?wndproc:dlgproc?(WNDPROC)SwellDialogDefaultWindowProc:(WNDPROC)DefWindowProc;
    m_dlgproc=dlgproc;
    m_userdata=0;
    m_style=0;
    m_exstyle=0;
    m_id=wID;
    m_owned=m_owner=0;
    m_children=m_parent=m_next=m_prev=0; 
    if (wndr) m_position = *wndr;
    else memset(&m_position,0,sizeof(m_position));
    memset(&m_extra,0,sizeof(m_extra));
    m_visible=visible;
    m_hashaddestroy=false;
    m_enabled=true;
    m_wantfocus=true;
    m_menu=NULL;
    m_oswidget = 0;
    
#ifdef SWELL_LICE_GDI
    m_paintctx=0;
    m_invalidated=true;
    m_child_invalidated=true;
    m_backingstore=0;
#endif
    
    m_title=label ? strdup(label) : NULL;
    SetParent(this, par);
    
}

HWND__::~HWND__()
{
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
