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
    
    
    This file provides basic win32 GDI-->Quartz translation. It uses features that require OS X 10.4+
    
*/

#ifndef SWELL_PROVIDED_BY_APP

#include "swell.h"
#include "swell-internal.h"

#include "../mutex.h"
#include "../assocarray.h"
#include "../wdlcstring.h"

#include "swell-gdi-internalpool.h"

//---------------------------------------------------------------------------------------------------------------------------
// copied from swell-gdi.mm
// the same code is on swell-gdi-generic.cpp and swell-gdi-lice.cpp

HIMAGELIST ImageList_CreateEx()
{
    return (HIMAGELIST)new WDL_PtrList<HGDIOBJ__>;
}

BOOL ImageList_Remove(HIMAGELIST list, int idx)
{
    WDL_PtrList<HGDIOBJ__>* imglist=(WDL_PtrList<HGDIOBJ__>*)list;
    if (imglist && idx < imglist->GetSize())
    {
        if (idx < 0) 
        {
            int x,n=imglist->GetSize();
            for (x=0;x<n;x++)
            {
                HGDIOBJ__ *a = imglist->Get(x);
                if (a) DeleteObject(a);
            }
            imglist->Empty();
        }
        else 
        {
            HGDIOBJ__ *a = imglist->Get(idx);
            imglist->Set(idx, NULL); 
            if (a) DeleteObject(a);
        }
        return TRUE;
    }
    
    return FALSE;
}

int ImageList_ReplaceIcon(HIMAGELIST list, int offset, HICON image)
{
    if (!image || !list) return -1;
    WDL_PtrList<HGDIOBJ__> *l=(WDL_PtrList<HGDIOBJ__> *)list;
    
    HGDIOBJ__ *imgsrc = (HGDIOBJ__*)image;
    if (!HGDIOBJ_VALID(imgsrc,TYPE_BITMAP)) return -1;
    
    HGDIOBJ__* icon=GDP_OBJECT_NEW();
    icon->type=TYPE_BITMAP;
    icon->wid=1;
    
    // TODO: copy underlying image
    // the same code is on osx but generic and lice don't copy image
    
    image = (HICON) icon;
    
    if (offset<0||offset>=l->GetSize()) 
    {
        l->Add(image);
        offset=l->GetSize()-1;
    }
    else
    {
        HICON old=l->Get(offset);
        l->Set(offset,image);
        if (old) DeleteObject(old);
    }
    return offset;
}

void ImageList_Destroy(HIMAGELIST list)
{
    if (!list) return;
    ImageList_Remove(list, -1);
    delete (WDL_PtrList<HGDIOBJ__>*)list;
}

//---------------------------------------------------------------------------------------------------------------------------

HDC SWELL_CreateMemContext(HDC hdc, int w, int h)
{
    return NULL;
}

void SWELL_DeleteGfxContext(HDC ctx)
{
}

void* SWELL_GetCtxGC(HDC ctx)
{
    return NULL;
}

void* SWELL_GetCtxFrameBuffer(HDC ctx)
{
    return NULL;
}


void SWELL_PushClipRegion(HDC ctx)
{
}

void SWELL_SetClipRegion(HDC ctx, RECT *r)
{
}

void SWELL_PopClipRegion(HDC ctx)
{
}

HFONT CreateFontIndirect(LOGFONT *lf)
{
    return NULL;
}

HFONT CreateFont(int lfHeight, int lfWidth, int lfEscapement, int lfOrientation, int lfWeight, char lfItalic, 
                 char lfUnderline, char lfStrikeOut, char lfCharSet, char lfOutPrecision, char lfClipPrecision, 
                 char lfQuality, char lfPitchAndFamily, const char *lfFaceName)
{
    return NULL;
}

HPEN CreatePen(int attr, int wid, int col)
{
    return NULL;
}

HBRUSH CreateSolidBrush(int col)
{
    return NULL;
}

HPEN CreatePenAlpha(int attr, int wid, int col, float alpha)
{
    return NULL;
}

HBRUSH CreateSolidBrushAlpha(int col, float alpha)
{
    return NULL;
}

HGDIOBJ SelectObject(HDC ctx, HGDIOBJ pen)
{
    return NULL;
}

HGDIOBJ GetStockObject(int wh)
{
    return NULL;
}

void DeleteObject(HGDIOBJ pen)
{
}

void SWELL_FillRect(HDC ctx, RECT *r, HBRUSH br)
{
}

void Rectangle(HDC ctx, int l, int t, int r, int b)
{
}

void Ellipse(HDC ctx, int l, int t, int r, int b)
{
}

void Polygon(HDC ctx, POINT *pts, int npts)
{
}

void MoveToEx(HDC ctx, int x, int y, POINT *op)
{
}

void SWELL_LineTo(HDC ctx, int x, int y)
{
}

void SWELL_SetPixel(HDC ctx, int x, int y, int c)
{
}

void PolyBezierTo(HDC ctx, POINT *pts, int np)
{
}

int DrawText(HDC ctx, const char *buf, int buflen, RECT *r, int align)
{
    return 0;
}

void SetTextColor(HDC ctx, int col)
{
}

int GetTextColor(HDC ctx)
{
    return 0;
}

void SetBkColor(HDC ctx, int col)
{
}

void SetBkMode(HDC ctx, int col)
{
}

void RoundRect(HDC ctx, int x, int y, int x2, int y2, int xrnd, int yrnd)
{
}

void PolyPolyline(HDC ctx, POINT *pts, DWORD *cnts, int nseg)
{
}

BOOL GetTextMetrics(HDC ctx, TEXTMETRIC *tm)
{
    return FALSE;
}

BOOL GetObject(HICON icon, int bmsz, void *_bm)
{
    return FALSE;
}

HICON CreateIconIndirect(ICONINFO* iconinfo)
{
    return NULL;
}

HICON LoadNamedImage(const char *name, bool alphaFromMask)
{
    return NULL;
}

void DrawImageInRect(HDC ctx, HICON img, RECT *r)
{
}

void BitBlt(HDC hdcOut, int x, int y, int w, int h, HDC hdcIn, int xin, int yin, int mode)
{
}

void StretchBlt(HDC hdcOut, int x, int y, int w, int h, HDC hdcIn, int xin, int yin, int srcw, int srch, int mode)
{
}

int GetSysColor(int idx)
{
    return 0;
}

HBITMAP CreateBitmap(int width, int height, int numplanes, int bitsperpixel, unsigned char* bits)
{
    return NULL;
}

HDC BeginPaint(HWND hwnd, PAINTSTRUCT *ps)
{
    return NULL;
}

HDC GetDC(HWND h)
{
    return NULL;
}

HDC GetWindowDC(HWND h)
{
    return NULL;
}

void ReleaseDC(HWND h, HDC hdc)
{
}

void SWELL_FillDialogBackground(HDC hdc, RECT *r, int level)
{
}

HGDIOBJ SWELL_CloneGDIObject(HGDIOBJ a)
{
    return NULL;
}

#endif
