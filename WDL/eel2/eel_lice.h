#ifndef _EEL_LICE_H_
#define _EEL_LICE_H_

void eel_lice_register();

#ifdef DYNAMIC_LICE
  #define LICE_IBitmap LICE_IBitmap_disabledAPI
    #include "../lice/lice.h"

  #undef LICE_IBitmap
  typedef void LICE_IBitmap; // prevent us from using LICE api directly, in case it ever changes

class LICE_IFont;

#ifdef EEL_LICE_API_ONLY
#define EEL_LICE_FUNCDEF extern
#else
#define EEL_LICE_FUNCDEF
#endif

#define LICE_FUNCTION_VALID(x) (x)

EEL_LICE_FUNCDEF LICE_IBitmap *(*__LICE_CreateBitmap)(int, int, int);
EEL_LICE_FUNCDEF void (*__LICE_Clear)(LICE_IBitmap *dest, LICE_pixel color);
EEL_LICE_FUNCDEF void (*__LICE_Line)(LICE_IBitmap *dest, int x1, int y1, int x2, int y2, LICE_pixel color, float alpha, int mode, bool aa);
EEL_LICE_FUNCDEF bool (*__LICE_ClipLine)(int* pX1, int* pY1, int* pX2, int* pY2, int xLo, int yLo, int xHi, int yHi);
EEL_LICE_FUNCDEF void (*__LICE_DrawText)(LICE_IBitmap *bm, int x, int y, const char *string, 
                   LICE_pixel color, float alpha, int mode);
EEL_LICE_FUNCDEF void (*__LICE_DrawChar)(LICE_IBitmap *bm, int x, int y, char c, 
                   LICE_pixel color, float alpha, int mode);
EEL_LICE_FUNCDEF void (*__LICE_MeasureText)(const char *string, int *w, int *h);
EEL_LICE_FUNCDEF void (*__LICE_PutPixel)(LICE_IBitmap *bm, int x, int y, LICE_pixel color, float alpha, int mode);
EEL_LICE_FUNCDEF LICE_pixel (*__LICE_GetPixel)(LICE_IBitmap *bm, int x, int y);
EEL_LICE_FUNCDEF void (*__LICE_FillRect)(LICE_IBitmap *dest, int x, int y, int w, int h, LICE_pixel color, float alpha, int mode);
EEL_LICE_FUNCDEF LICE_IBitmap *(*__LICE_LoadPNG)(const char *filename, LICE_IBitmap *bmp);
EEL_LICE_FUNCDEF void (*__LICE_Blur)(LICE_IBitmap *dest, LICE_IBitmap *src, int dstx, int dsty, int srcx, int srcy, int srcw, int srch); // src and dest can overlap, however it may look fudgy if they do
EEL_LICE_FUNCDEF void (*__LICE_ScaledBlit)(LICE_IBitmap *dest, LICE_IBitmap *src, int dstx, int dsty, int dstw, int dsth, 
                     float srcx, float srcy, float srcw, float srch, float alpha, int mode);


// if cliptosourcerect is false, then areas outside the source rect can get in (otherwise they are not drawn)
EEL_LICE_FUNCDEF void (*__LICE_RotatedBlit)(LICE_IBitmap *dest, LICE_IBitmap *src, 
                      int dstx, int dsty, int dstw, int dsth, 
                      float srcx, float srcy, float srcw, float srch, 
                      float angle, 
                      bool cliptosourcerect, float alpha, int mode,
                      float rotxcent, float rotycent); // these coordinates are offset from the center of the image, in source pixel coordinates


EEL_LICE_FUNCDEF void (*__LICE_MultiplyAddRect)(LICE_IBitmap *dest, int x, int y, int w, int h, 
                          float rsc, float gsc, float bsc, float asc, // 0-1, or -100 .. +100 if you really are insane
                          float radd, float gadd, float badd, float aadd); // 0-255 is the normal range on these.. of course its clamped

EEL_LICE_FUNCDEF void (*__LICE_GradRect)(LICE_IBitmap *dest, int dstx, int dsty, int dstw, int dsth, 
                      float ir, float ig, float ib, float ia,
                      float drdx, float dgdx, float dbdx, float dadx,
                      float drdy, float dgdy, float dbdy, float dady,
                      int mode);

EEL_LICE_FUNCDEF void (*__LICE_TransformBlit2)(LICE_IBitmap *dest, LICE_IBitmap *src,  
                    int dstx, int dsty, int dstw, int dsth,
                    double *srcpoints, int div_w, int div_h, // srcpoints coords should be div_w*div_h*2 long, and be in source image coordinates
                    float alpha, int mode);

EEL_LICE_FUNCDEF void (*__LICE_DeltaBlit)(LICE_IBitmap *dest, LICE_IBitmap *src, 
                    int dstx, int dsty, int dstw, int dsth,                     
                    float srcx, float srcy, float srcw, float srch, 
                    double dsdx, double dtdx, double dsdy, double dtdy,         
                    double dsdxdy, double dtdxdy,
                    bool cliptosourcerect, float alpha, int mode);


#define LICE_Blur __LICE_Blur
#define LICE_Clear __LICE_Clear
#define LICE_Line __LICE_Line
#define LICE_ClipLine __LICE_ClipLine
#define LICE_FillRect __LICE_FillRect
#define LICE_PutPixel __LICE_PutPixel
#define LICE_GetPixel __LICE_GetPixel
#define LICE_DrawText __LICE_DrawText
#define LICE_DrawChar __LICE_DrawChar
#define LICE_MeasureText __LICE_MeasureText
#define LICE_LoadPNG __LICE_LoadPNG
#define LICE_RotatedBlit __LICE_RotatedBlit
#define LICE_ScaledBlit __LICE_ScaledBlit
#define LICE_MultiplyAddRect __LICE_MultiplyAddRect
#define LICE_GradRect __LICE_GradRect
#define LICE_TransformBlit2 __LICE_TransformBlit2
#define LICE_DeltaBlit __LICE_DeltaBlit

EEL_LICE_FUNCDEF HDC (*LICE__GetDC)(LICE_IBitmap *bm);
EEL_LICE_FUNCDEF int (*LICE__GetWidth)(LICE_IBitmap *bm);
EEL_LICE_FUNCDEF int (*LICE__GetHeight)(LICE_IBitmap *bm);
EEL_LICE_FUNCDEF void (*LICE__Destroy)(LICE_IBitmap *bm);
EEL_LICE_FUNCDEF bool (*LICE__resize)(LICE_IBitmap *bm, int w, int h);

EEL_LICE_FUNCDEF void (*LICE__DestroyFont)(LICE_IFont* font);
EEL_LICE_FUNCDEF LICE_IFont *(*LICE_CreateFont)();
EEL_LICE_FUNCDEF void (*LICE__SetFromHFont)(LICE_IFont* ifont, HFONT font, int flags);
EEL_LICE_FUNCDEF LICE_pixel (*LICE__SetTextColor)(LICE_IFont* ifont, LICE_pixel color);
EEL_LICE_FUNCDEF LICE_pixel (*LICE__SetBkColor)(LICE_IFont* ifont, LICE_pixel color);
EEL_LICE_FUNCDEF void (*LICE__SetTextCombineMode)(LICE_IFont* ifont, int mode, float alpha);
EEL_LICE_FUNCDEF int (*LICE__DrawText)(LICE_IFont* ifont, LICE_IBitmap *bm, const char *str, int strcnt, RECT *rect, UINT dtFlags);

#else

#include "../lice/lice.h"
#include "../lice/lice_text.h"
#define LICE_FUNCTION_VALID(x) (1)

static HDC LICE__GetDC(LICE_IBitmap *bm)
{
  return bm->getDC();
}
static int LICE__GetWidth(LICE_IBitmap *bm)
{
  return bm->getWidth();
}
static int LICE__GetHeight(LICE_IBitmap *bm)
{
  return bm->getHeight();
}
static void LICE__Destroy(LICE_IBitmap *bm)
{
  delete bm;
}
static void LICE__SetFromHFont(LICE_IFont * ifont, HFONT font, int flags)
{
  if (ifont) ifont->SetFromHFont(font,flags);
}
static LICE_pixel LICE__SetTextColor(LICE_IFont* ifont, LICE_pixel color)
{
  if (ifont) return ifont->SetTextColor(color);
  return 0;
}
static LICE_pixel LICE__SetBkColor(LICE_IFont* ifont, LICE_pixel color)
{
  if (ifont) return ifont->SetBkColor(color);
  return 0;
}
static void LICE__SetTextCombineMode(LICE_IFont* ifont, int mode, float alpha)
{
  if (ifont) ifont->SetCombineMode(mode, alpha);
}
static int LICE__DrawText(LICE_IFont* ifont, LICE_IBitmap *bm, const char *str, int strcnt, RECT *rect, UINT dtFlags)
{
  if (ifont) return ifont->DrawText(bm, str, strcnt, rect, dtFlags);
  return 0;
}


static LICE_IFont *LICE_CreateFont()
{
  return new LICE_CachedFont();
}
static void LICE__DestroyFont(LICE_IFont *bm)
{
  delete bm;
}
static bool LICE__resize(LICE_IBitmap *bm, int w, int h)
{
  return bm->resize(w,h);
}

static LICE_IBitmap *__LICE_CreateBitmap(int mode, int w, int h)
{
  if (mode==1) return new LICE_SysBitmap(w,h);
  return new LICE_MemBitmap(w,h);
}


#endif




class eel_lice_state
{
public:

  eel_lice_state(NSEEL_VMCTX vm, void *ctx, int image_slots, int font_slots);
  ~eel_lice_state();

  void resetVarsToStock()
  {
    if (m_gfx_a&&m_gfx_r&&m_gfx_g&&m_gfx_b) *m_gfx_r=*m_gfx_g=*m_gfx_b=*m_gfx_a=1.0;
    if (m_gfx_dest) *m_gfx_dest=-1.0;
    // todo: reset others?
  }

  LICE_IBitmap *m_framebuffer, *m_framebuffer_extra;
  int m_framebuffer_refstate;
  WDL_TypedBuf<LICE_IBitmap *> m_gfx_images;
  struct gfxFontStruct {
    LICE_IFont *font;
    char last_fontname[128];
    int last_fontsize;
    int last_fontflag;

    int use_fonth;
  }; 
  WDL_TypedBuf<gfxFontStruct> m_gfx_fonts;
  int m_gfx_font_active; // -1 for default, otherwise index into gfx_fonts (NOTE: this differs from the exposed API, which defines 0 as default, 1-n)
  LICE_IFont *GetActiveFont() { return m_gfx_font_active>=0&&m_gfx_font_active<m_gfx_fonts.GetSize() && m_gfx_fonts.Get()[m_gfx_font_active].use_fonth ? m_gfx_fonts.Get()[m_gfx_font_active].font : NULL; }

  LICE_IBitmap *GetImageForIndex(EEL_F idx) 
  { 
    if (idx>-2.0)
    {
      if (idx < 0.0) return m_framebuffer;

      const int a = (int)idx;
      if (a >= 0 && a < m_gfx_images.GetSize()) return m_gfx_images.Get()[a];
    }
    return NULL;
  };

  void SetImageDirty(LICE_IBitmap *bm)
  {
    if (bm == m_framebuffer) m_framebuffer_refstate=1;
  }

  // R, G, B, A, w, h, x, y, mode(1=add,0=copy)
  EEL_F *m_gfx_r, *m_gfx_g, *m_gfx_b, *m_gfx_w, *m_gfx_h, *m_gfx_a, *m_gfx_x, *m_gfx_y, *m_gfx_mode, *m_gfx_clear, *m_gfx_texth,*m_gfx_dest;
  EEL_F *m_mouse_x, *m_mouse_y, *m_mouse_cap;

  NSEEL_VMCTX m_vmref;
  void *m_user_ctx;

  int setup_frame(HWND hwnd, RECT r);

  void gfx_lineto(EEL_F xpos, EEL_F ypos, EEL_F aaflag);
  void gfx_rectto(EEL_F xpos, EEL_F ypos);
  void gfx_line(int np, EEL_F **parms);
  void gfx_rect(int np, EEL_F **parms);
  void gfx_grad_or_muladd_rect(int mode, int np, EEL_F **parms);
  void gfx_setpixel(EEL_F r, EEL_F g, EEL_F b);
  void gfx_getpixel(EEL_F *r, EEL_F *g, EEL_F *b);
  void gfx_drawnumber(EEL_F n, EEL_F ndigits);
  void gfx_drawchar(EEL_F ch);
  void gfx_getimgdim(EEL_F img, EEL_F *w, EEL_F *h);
  EEL_F gfx_setimgdim(int img, EEL_F *w, EEL_F *h);
  void gfx_blurto(EEL_F x, EEL_F y);
  void gfx_blit(EEL_F img, EEL_F scale, EEL_F rotate);
  void gfx_blitext(EEL_F img, EEL_F *coords, EEL_F angle);
  void gfx_blitext2(int np, EEL_F **parms, int mode); // 0=blit, 1=deltablit
  void gfx_transformblit(EEL_F **parms, int div_w, int div_h, EEL_F *tab); // parms[0]=src, 1-4=x,y,w,h

  void gfx_drawstr(void *opaque, EEL_F str, int formatmode, int nfmtparms, EEL_F **fmtparms); // formatmode=1 for format, 2 for purely measure no format
  EEL_F gfx_loadimg(void *opaque, int img, EEL_F loadFrom);
  EEL_F gfx_setfont(void *opaque, int np, EEL_F **parms);

  LICE_pixel getCurColor();
  int getCurMode();
  int getCurModeForBlit(bool isFBsrc);
};

#ifndef EEL_LICE_API_ONLY

eel_lice_state::eel_lice_state(NSEEL_VMCTX vm, void *ctx, int image_slots, int font_slots)
{
  m_user_ctx=ctx;
  m_vmref= vm;
  m_gfx_font_active=-1;
  m_gfx_fonts.Resize(font_slots);
  memset(m_gfx_fonts.Get(),0,m_gfx_fonts.GetSize()*sizeof(m_gfx_fonts.Get()[0]));

  m_gfx_images.Resize(image_slots);
  memset(m_gfx_images.Get(),0,m_gfx_images.GetSize()*sizeof(m_gfx_images.Get()[0]));
  m_framebuffer=m_framebuffer_extra=0;
  m_framebuffer_refstate=0;

  m_gfx_r = NSEEL_VM_regvar(vm,"gfx_r");
  m_gfx_g = NSEEL_VM_regvar(vm,"gfx_g");
  m_gfx_b = NSEEL_VM_regvar(vm,"gfx_b");
  m_gfx_a = NSEEL_VM_regvar(vm,"gfx_a");

  m_gfx_w = NSEEL_VM_regvar(vm,"gfx_w");
  m_gfx_h = NSEEL_VM_regvar(vm,"gfx_h");
  m_gfx_x = NSEEL_VM_regvar(vm,"gfx_x");
  m_gfx_y = NSEEL_VM_regvar(vm,"gfx_y");
  m_gfx_mode = NSEEL_VM_regvar(vm,"gfx_mode");
  m_gfx_clear = NSEEL_VM_regvar(vm,"gfx_clear");
  m_gfx_texth = NSEEL_VM_regvar(vm,"gfx_texth");
  m_gfx_dest = NSEEL_VM_regvar(vm,"gfx_dest");

  m_mouse_x = NSEEL_VM_regvar(vm,"mouse_x");
  m_mouse_y = NSEEL_VM_regvar(vm,"mouse_y");
  m_mouse_cap = NSEEL_VM_regvar(vm,"mouse_cap");

  if (m_gfx_texth) *m_gfx_texth=8;

}
eel_lice_state::~eel_lice_state()
{
  if (LICE_FUNCTION_VALID(LICE__Destroy)) 
  {
    LICE__Destroy(m_framebuffer_extra);
    LICE__Destroy(m_framebuffer);
    int x;
    for (x=0;x<m_gfx_images.GetSize();x++)
    {
      LICE__Destroy(m_gfx_images.Get()[x]);
    }
  }
  if (LICE_FUNCTION_VALID(LICE__DestroyFont))
  {
    int x;
    for (x=0;x<m_gfx_fonts.GetSize();x++)
    {
      if (m_gfx_fonts.Get()[x].font) LICE__DestroyFont(m_gfx_fonts.Get()[x].font);
    }
  }
}

int eel_lice_state::getCurMode()
{
  const int gmode = (int) (*m_gfx_mode);
  const int sm=(gmode>>4)&0xf;
  if (sm > LICE_BLIT_MODE_COPY && sm <= LICE_BLIT_MODE_HSVADJ) return sm;

  return (gmode&1) ? LICE_BLIT_MODE_ADD : LICE_BLIT_MODE_COPY;
}
int eel_lice_state::getCurModeForBlit(bool isFBsrc)
{
  const int gmode = (int) (*m_gfx_mode);
 
  const int sm=(gmode>>4)&0xf;

  int mode;
  if (sm > LICE_BLIT_MODE_COPY && sm <= LICE_BLIT_MODE_HSVADJ) mode=sm;
  else mode=((gmode&1) ? LICE_BLIT_MODE_ADD : LICE_BLIT_MODE_COPY);


  if (!isFBsrc && !(gmode&2)) mode|=LICE_BLIT_USE_ALPHA;
  if (!(gmode&4)) mode|=LICE_BLIT_FILTER_BILINEAR;
 
  return mode;
}
LICE_pixel eel_lice_state::getCurColor()
{
  int red=(int) (*m_gfx_r*255.0);
  int green=(int) (*m_gfx_g*255.0);
  int blue=(int) (*m_gfx_b*255.0);
  if (red<0) red=0;else if (red>255)red=255;
  if (green<0) green=0;else if (green>255)green=255;
  if (blue<0) blue=0; else if (blue>255) blue=255;
  return LICE_RGBA(red,green,blue,255);
}


static EEL_F * NSEEL_CGEN_CALL _gfx_lineto(void *opaque, EEL_F *xpos, EEL_F *ypos, EEL_F *useaa)
{
  eel_lice_state *ctx=EEL_LICE_GET_CONTEXT(opaque);
  if (ctx) ctx->gfx_lineto(*xpos, *ypos, *useaa);
  return xpos;
}
static EEL_F * NSEEL_CGEN_CALL _gfx_lineto2(void *opaque, EEL_F *xpos, EEL_F *ypos)
{
  eel_lice_state *ctx=EEL_LICE_GET_CONTEXT(opaque);
  if (ctx) ctx->gfx_lineto(*xpos, *ypos, 1.0f);
  return xpos;
}

static EEL_F * NSEEL_CGEN_CALL _gfx_rectto(void *opaque, EEL_F *xpos, EEL_F *ypos)
{
  eel_lice_state *ctx=EEL_LICE_GET_CONTEXT(opaque);
  if (ctx) ctx->gfx_rectto(*xpos, *ypos);
  return xpos;
}

static EEL_F NSEEL_CGEN_CALL _gfx_line(void *opaque, INT_PTR np, EEL_F **parms)
{
  eel_lice_state *ctx=EEL_LICE_GET_CONTEXT(opaque);
  if (ctx) ctx->gfx_line((int)np,parms);
  return 0.0;
}

static EEL_F NSEEL_CGEN_CALL _gfx_rect(void *opaque, INT_PTR np, EEL_F **parms)
{
  eel_lice_state *ctx=EEL_LICE_GET_CONTEXT(opaque);
  if (ctx) ctx->gfx_rect((int)np,parms);
  return 0.0;
}
static EEL_F NSEEL_CGEN_CALL _gfx_gradrect(void *opaque, INT_PTR np, EEL_F **parms)
{
  eel_lice_state *ctx=EEL_LICE_GET_CONTEXT(opaque);
  if (ctx) ctx->gfx_grad_or_muladd_rect(0,(int)np,parms);
  return 0.0;
}

static EEL_F NSEEL_CGEN_CALL _gfx_muladdrect(void *opaque, INT_PTR np, EEL_F **parms)
{
  eel_lice_state *ctx=EEL_LICE_GET_CONTEXT(opaque);
  if (ctx) ctx->gfx_grad_or_muladd_rect(1,(int)np,parms);
  return 0.0;
}

static EEL_F NSEEL_CGEN_CALL _gfx_deltablit(void *opaque, INT_PTR np, EEL_F **parms)
{
  eel_lice_state *ctx=EEL_LICE_GET_CONTEXT(opaque);
  if (ctx) ctx->gfx_blitext2((int)np,parms,1);
  return 0.0;
}

static EEL_F NSEEL_CGEN_CALL _gfx_transformblit(void *opaque, INT_PTR np, EEL_F **parms)
{
  eel_lice_state *ctx=EEL_LICE_GET_CONTEXT(opaque);
  if (ctx) 
  {
    EEL_F **blocks = ctx->m_vmref  ? ((compileContext*)ctx->m_vmref)->ram_state.blocks : 0;
    if (!blocks || np < 8) return 0.0;

    const int divw = (int) (parms[5][0]+0.5);
    const int divh = (int) (parms[6][0]+0.5);
    if (divw < 1 || divh < 1) return 0.0;

    const int addr1= (int) (parms[7][0]+0.5);
    const int sz = divw*divh*2;
    EEL_F *d=__NSEEL_RAMAlloc(blocks,addr1);
    if (sz>NSEEL_RAM_ITEMSPERBLOCK)
    {
      int x;
      for(x=NSEEL_RAM_ITEMSPERBLOCK;x<sz-1;x+=NSEEL_RAM_ITEMSPERBLOCK)
        if (__NSEEL_RAMAlloc(blocks,addr1+x) != d+x) return 0.0;
    }
    EEL_F *end=__NSEEL_RAMAlloc(blocks,addr1+sz-1);
    if (end != d+sz-1) return 0.0; // buffer not contiguous

    ctx->gfx_transformblit(parms,divw,divh,d);
  }
  return 0.0;
}


static EEL_F * NSEEL_CGEN_CALL _gfx_drawnumber(void *opaque, EEL_F *n, EEL_F *nd)
{
  eel_lice_state *ctx=EEL_LICE_GET_CONTEXT(opaque);
  if (ctx) ctx->gfx_drawnumber(*n, *nd);
  return n;
}

static EEL_F * NSEEL_CGEN_CALL _gfx_drawchar(void *opaque, EEL_F *n)
{
  eel_lice_state *ctx=EEL_LICE_GET_CONTEXT(opaque);
  if (ctx) ctx->gfx_drawchar(*n);
  return n;
}

static EEL_F * NSEEL_CGEN_CALL _gfx_measurestr(void *opaque, EEL_F *str, EEL_F *xOut, EEL_F *yOut)
{
  eel_lice_state *ctx=EEL_LICE_GET_CONTEXT(opaque);
  if (ctx) 
  {
    EEL_F *p[2]={xOut,yOut};
    ctx->gfx_drawstr(opaque,*str,2,2,p);
  }
  return str;
}

static EEL_F * NSEEL_CGEN_CALL _gfx_drawstr(void *opaque, EEL_F *n)
{
  eel_lice_state *ctx=EEL_LICE_GET_CONTEXT(opaque);
  if (ctx) ctx->gfx_drawstr(opaque,*n,0,0,NULL);
  return n;
}
static EEL_F NSEEL_CGEN_CALL _gfx_printf(void *opaque, INT_PTR nparms, EEL_F **parms)
{
  eel_lice_state *ctx=EEL_LICE_GET_CONTEXT(opaque);
  if (ctx && nparms>0) 
  {
    EEL_F v= **parms;
    ctx->gfx_drawstr(opaque,v,1,nparms-1,parms+1);
    return v;
  }
  return 0.0;
}
static EEL_F * NSEEL_CGEN_CALL _gfx_setpixel(void *opaque, EEL_F *r, EEL_F *g, EEL_F *b)
{
  eel_lice_state *ctx=EEL_LICE_GET_CONTEXT(opaque);
  if (ctx) ctx->gfx_setpixel(*r, *g, *b);
  return r;
}

static EEL_F * NSEEL_CGEN_CALL _gfx_getpixel(void *opaque, EEL_F *r, EEL_F *g, EEL_F *b)
{
  eel_lice_state *ctx=EEL_LICE_GET_CONTEXT(opaque);
  if (ctx) ctx->gfx_getpixel(r, g, b);
  return r;
}

static EEL_F * NSEEL_CGEN_CALL _gfx_blit(void *opaque, EEL_F *img, EEL_F *scale, EEL_F *rotate)
{
  eel_lice_state *ctx=EEL_LICE_GET_CONTEXT(opaque);
  if (ctx) ctx->gfx_blit(*img,*scale,*rotate);
  return img;
}

static EEL_F NSEEL_CGEN_CALL _gfx_setfont(void *opaque, INT_PTR np, EEL_F **parms)
{
  eel_lice_state *ctx=EEL_LICE_GET_CONTEXT(opaque);
  if (ctx) return ctx->gfx_setfont(opaque,np,parms);
  return 0.0;
}

static EEL_F NSEEL_CGEN_CALL _gfx_blit2(void *opaque, INT_PTR np, EEL_F **parms)
{
  eel_lice_state *ctx=EEL_LICE_GET_CONTEXT(opaque);
  if (ctx && np>=3) 
  {
    ctx->gfx_blitext2(np,parms,0);
    return *(parms[0]);
  }
  return 0.0;
}

static EEL_F * NSEEL_CGEN_CALL _gfx_blitext(void *opaque, EEL_F *img, EEL_F *coordidx, EEL_F *rotate)
{
  eel_lice_state *ctx=EEL_LICE_GET_CONTEXT(opaque);
  if (ctx) 
  {
    EEL_F fc = *coordidx;
    if (fc < -0.5 || fc >= NSEEL_RAM_BLOCKS*NSEEL_RAM_ITEMSPERBLOCK) return img;
    int a=(int)fc;
    if (a<0) return img;
        
    EEL_F buf[10];
    int x;
    EEL_F **blocks = ctx->m_vmref  ? ((compileContext*)ctx->m_vmref)->ram_state.blocks : 0;
    if (!blocks) return img;
    for (x = 0;x < 10; x ++)
    {
      EEL_F *d=__NSEEL_RAMAlloc(blocks,a++);
      if (!d || d==&nseel_ramalloc_onfail) return img;
      buf[x]=*d;
    }
    // read megabuf
    ctx->gfx_blitext(*img,buf,*rotate);
  }
  return img;
}


static EEL_F * NSEEL_CGEN_CALL _gfx_blurto(void *opaque, EEL_F *x, EEL_F *y)
{
  eel_lice_state *ctx=EEL_LICE_GET_CONTEXT(opaque);
  if (ctx) ctx->gfx_blurto(*x,*y);
  return x;
}

static EEL_F * NSEEL_CGEN_CALL _gfx_getimgdim(void *opaque, EEL_F *img, EEL_F *w, EEL_F *h)
{
  eel_lice_state *ctx=EEL_LICE_GET_CONTEXT(opaque);
  if (ctx) ctx->gfx_getimgdim(*img,w,h);
  return img;
}

static EEL_F NSEEL_CGEN_CALL _gfx_loadimg(void *opaque, EEL_F *img, EEL_F *fr)
{
  eel_lice_state *ctx=EEL_LICE_GET_CONTEXT(opaque);
  if (ctx) return ctx->gfx_loadimg(opaque,(int)*img,*fr);
  return 0.0;
}

static EEL_F NSEEL_CGEN_CALL _gfx_setimgdim(void *opaque, EEL_F *img, EEL_F *w, EEL_F *h)
{
  eel_lice_state *ctx=EEL_LICE_GET_CONTEXT(opaque);
  if (ctx) return ctx->gfx_setimgdim((int)*img,w,h);
  return 0.0;
}




void eel_lice_state::gfx_lineto(EEL_F xpos, EEL_F ypos, EEL_F aaflag)
{
  LICE_IBitmap *dest = GetImageForIndex(*m_gfx_dest);
  if (!dest) return;

  int x1=(int)floor(xpos),y1=(int)floor(ypos),x2=(int)floor(*m_gfx_x), y2=(int)floor(*m_gfx_y);
  if (LICE_FUNCTION_VALID(LICE__GetWidth) && LICE_FUNCTION_VALID(LICE__GetHeight) && LICE_FUNCTION_VALID(LICE_Line) && 
      LICE_FUNCTION_VALID(LICE_ClipLine) && 
      LICE_ClipLine(&x1,&y1,&x2,&y2,0,0,LICE__GetWidth(dest),LICE__GetHeight(dest))) 
  {
    LICE_Line(dest,x1,y1,x2,y2,getCurColor(),*m_gfx_a,getCurMode(),aaflag > 0.5);
    SetImageDirty(dest);
  }
  *m_gfx_x = xpos;
  *m_gfx_y = ypos;
  
}

void eel_lice_state::gfx_rectto(EEL_F xpos, EEL_F ypos)
{
  LICE_IBitmap *dest = GetImageForIndex(*m_gfx_dest);
  if (!dest) return;

  float x1=xpos,y1=ypos,x2=*m_gfx_x, y2=*m_gfx_y;
  if (x2<x1) { x1=x2; x2=xpos; }
  if (y2<y1) { y1=y2; y2=ypos; }

  if (LICE_FUNCTION_VALID(LICE_FillRect) && x2-x1 > 0.5 && y2-y1 > 0.5)
  {
    LICE_FillRect(dest,(int)x1,(int)y1,(int)(x2-x1),(int)(y2-y1),getCurColor(),*m_gfx_a,getCurMode());

    SetImageDirty(dest);
  }
  *m_gfx_x = xpos;
  *m_gfx_y = ypos;
}


void eel_lice_state::gfx_line(int np, EEL_F **parms)
{
  LICE_IBitmap *dest = GetImageForIndex(*m_gfx_dest);
  if (!dest) return;

  int x1=(int)floor(parms[0][0]),y1=(int)floor(parms[1][0]),x2=(int)floor(parms[2][0]), y2=(int)floor(parms[3][0]);
  if (LICE_FUNCTION_VALID(LICE__GetWidth) && 
      LICE_FUNCTION_VALID(LICE__GetHeight) && 
      LICE_FUNCTION_VALID(LICE_Line) && 
      LICE_FUNCTION_VALID(LICE_ClipLine) && LICE_ClipLine(&x1,&y1,&x2,&y2,0,0,LICE__GetWidth(dest),LICE__GetHeight(dest))) 
  {
    LICE_Line(dest,x1,y1,x2,y2,getCurColor(),*m_gfx_a,getCurMode(),np< 5 || parms[4][0] > 0.5);
    SetImageDirty(dest);
  } 
}

void eel_lice_state::gfx_rect(int np, EEL_F **parms)
{
  LICE_IBitmap *dest = GetImageForIndex(*m_gfx_dest);
  if (!dest) return;

  int x1=(int)floor(parms[0][0]),y1=(int)floor(parms[1][0]),w=(int)floor(parms[2][0]), h=(int)floor(parms[3][0]);

  if (LICE_FUNCTION_VALID(LICE_FillRect) && w>0 && h>0)
  {
    LICE_FillRect(dest,x1,y1,w,h,getCurColor(),*m_gfx_a,getCurMode());

    SetImageDirty(dest);
  }
}

void eel_lice_state::gfx_grad_or_muladd_rect(int whichmode, int np, EEL_F **parms)
{
  LICE_IBitmap *dest = GetImageForIndex(*m_gfx_dest);
  if (!dest) return;

  const int x1=(int)floor(parms[0][0]),y1=(int)floor(parms[1][0]),w=(int)floor(parms[2][0]), h=(int)floor(parms[3][0]);

  if (w>0 && h>0)
  {
    if (whichmode==0 && LICE_FUNCTION_VALID(LICE_GradRect) && np > 7)
    {
      LICE_GradRect(dest,x1,y1,w,h,parms[4][0],parms[5][0],parms[6][0],parms[7][0],
                                   np > 8 ? parms[8][0]:0.0, np > 9 ? parms[9][0]:0.0,  np > 10 ? parms[10][0]:0.0, np > 11 ? parms[11][0]:0.0,  
                                   np > 12 ? parms[12][0]:0.0, np > 13 ? parms[13][0]:0.0,  np > 14 ? parms[14][0]:0.0, np > 15 ? parms[15][0]:0.0,  
                                   getCurMode());

      SetImageDirty(dest);
    }
    else if (whichmode==1 && LICE_FUNCTION_VALID(LICE_MultiplyAddRect) && np > 6)
    {
      const double sc = 255.0;
      LICE_MultiplyAddRect(dest,x1,y1,w,h,parms[4][0],parms[5][0],parms[6][0],np>7 ? parms[7][0]:1.0,
        np > 8 ? sc*parms[8][0]:0.0, np > 9 ? sc*parms[9][0]:0.0,  np > 10 ? sc*parms[10][0]:0.0, np > 11 ? sc*parms[11][0]:0.0);
      SetImageDirty(dest);
    }
  }
}



void eel_lice_state::gfx_setpixel(EEL_F r, EEL_F g, EEL_F b)
{
  LICE_IBitmap *dest = GetImageForIndex(*m_gfx_dest);
  if (!dest) return;

  int red=(int) (r*255.0);
  int green=(int) (g*255.0);
  int blue=(int) (b*255.0);
  if (red<0) red=0;else if (red>255)red=255;
  if (green<0) green=0;else if (green>255)green=255;
  if (blue<0) blue=0; else if (blue>255) blue=255;

  if (LICE_FUNCTION_VALID(LICE_PutPixel)) 
  {
    LICE_PutPixel(dest,(int)*m_gfx_x, (int)*m_gfx_y,LICE_RGBA(red,green,blue,255),*m_gfx_a,getCurMode());
    SetImageDirty(dest);
  }
}

void eel_lice_state::gfx_getimgdim(EEL_F img, EEL_F *w, EEL_F *h)
{
  *w=*h=0;
  if (!this
#ifdef DYNAMIC_LICE
    ||!LICE__GetWidth || !LICE__GetHeight
#endif
    ) return;

  LICE_IBitmap *bm=GetImageForIndex(img); 
  if (bm)
  {
    *w=LICE__GetWidth(bm);
    *h=LICE__GetHeight(bm);
  }
}


EEL_F eel_lice_state::gfx_loadimg(void *opaque, int img, EEL_F loadFrom)
{
  if (!this
#ifdef DYNAMIC_LICE
    ||!__LICE_LoadPNG || !LICE__Destroy
#endif
    ) return 0.0;

  if (img >= 0 && img < m_gfx_images.GetSize()) 
  {
    WDL_FastString fs;
    bool ok = EEL_LICE_GET_FILENAME_FOR_STRING(loadFrom,&fs,0);

    if (ok)
    {
      LICE_IBitmap *bm = NULL;

      if (fs.GetLength()>4 && !stricmp(fs.Get()+fs.GetLength()-4,".png"))
        bm = LICE_LoadPNG(fs.Get(),NULL);
      
      if (bm)
      {
        LICE__Destroy(m_gfx_images.Get()[img]);
        m_gfx_images.Get()[img]=bm;
        return img;
      }
    }
  }
  return -1.0;

}

EEL_F eel_lice_state::gfx_setimgdim(int img, EEL_F *w, EEL_F *h)
{
  int rv=0;
  if (!this
#ifdef DYNAMIC_LICE
    ||!LICE__resize ||!LICE__GetWidth || !LICE__GetHeight||!__LICE_CreateBitmap
#endif
    ) return 0.0;

  int use_w = (int)*w;
  int use_h = (int)*h;
  if (use_w<1 || use_h < 1) use_w=use_h=0;
  if (use_w > 2048) use_w=2048;
  if (use_h > 2048) use_h=2048;
  
  LICE_IBitmap *bm=NULL;
  if (img >= 0 && img < m_gfx_images.GetSize()) 
  {
    bm=m_gfx_images.Get()[img];  
    if (!bm) 
    {
      m_gfx_images.Get()[img] = bm = __LICE_CreateBitmap(1,use_w,use_h);
      rv=!!bm;
    }
    else 
    {
      rv=LICE__resize(bm,use_w,use_h);
    }
  }

  return rv?1.0:0.0;
}

void eel_lice_state::gfx_blurto(EEL_F x, EEL_F y)
{
  LICE_IBitmap *dest = GetImageForIndex(*m_gfx_dest);
  if (!dest
#ifdef DYNAMIC_LICE
    ||!LICE_Blur
#endif
    ) return;
  
  int srcx = (int)x;
  int srcy = (int)y;
  int srcw=(int) (*m_gfx_x-x);
  int srch=(int) (*m_gfx_y-y);
  if (srch < 0) { srch=-srch; srcy = (int)*m_gfx_y; }
  if (srcw < 0) { srcw=-srcw; srcx = (int)*m_gfx_x; }
  LICE_Blur(dest,dest,srcx,srcy,srcx,srcy,srcw,srch);
  *m_gfx_x = x;
  *m_gfx_y = y;
  SetImageDirty(dest);
}

static bool CoordsSrcDestOverlap(EEL_F *coords)
{
  if (coords[0]+coords[2] < coords[4]) return false;
  if (coords[0] > coords[4] + coords[6]) return false;
  if (coords[1]+coords[3] < coords[5]) return false;
  if (coords[1] > coords[5] + coords[7]) return false;
  return true;
}

void eel_lice_state::gfx_transformblit(EEL_F **parms, int div_w, int div_h, EEL_F *tab)
{
  LICE_IBitmap *dest = GetImageForIndex(*m_gfx_dest);

  if (!dest
#ifdef DYNAMIC_LICE
    ||!LICE_ScaledBlit || !LICE_TransformBlit2 ||!LICE__GetWidth||!LICE__GetHeight
#endif 
    ) return;

  LICE_IBitmap *bm=GetImageForIndex(parms[0][0]); 
  if (!bm) return;

  const int bmw=LICE__GetWidth(bm);
  const int bmh=LICE__GetHeight(bm);
 
  const bool isFromFB = bm==m_framebuffer;

  if (bm == dest)
  {
    if (!m_framebuffer_extra && LICE_FUNCTION_VALID(__LICE_CreateBitmap)) m_framebuffer_extra=__LICE_CreateBitmap(0,bmw,bmh);
    if (m_framebuffer_extra)
    {
    
      LICE__resize(bm=m_framebuffer_extra,bmw,bmh);
      LICE_ScaledBlit(bm,dest, // copy the entire image
        0,0,bmw,bmh,
        0,0,bmw,bmh,
        1.0f,LICE_BLIT_MODE_COPY);      
    }
  }
  LICE_TransformBlit2(dest,bm,(int)floor(parms[1][0]),(int)floor(parms[2][0]),(int)floor(parms[3][0]),(int)floor(parms[4][0]),tab,div_w,div_h,*m_gfx_a,getCurModeForBlit(isFromFB));

  SetImageDirty(dest);
}

EEL_F eel_lice_state::gfx_setfont(void *opaque, int np, EEL_F **parms)
{
  int a = np>0 ? ((int)floor(parms[0][0]))-1 : -1;

  if (a>=0 && a < m_gfx_fonts.GetSize())
  {
    gfxFontStruct *s = m_gfx_fonts.Get()+a;
    if (np>1 && LICE_FUNCTION_VALID(LICE_CreateFont) && LICE_FUNCTION_VALID(LICE__SetFromHFont))
    {
      const int sz=np>2 ? (int)parms[2][0] : 10.0;
      
      bool doCreate=false;
      int fontflag=0;

      {
        EEL_STRING_MUTEXLOCK_SCOPE
      
        const char *face=EEL_STRING_GET_FOR_INDEX(parms[1][0],NULL);
        if (!face || !*face) face="Arial";

        {
          unsigned int c = np > 3 ? (unsigned int) parms[3][0] : 0;
          while (c)
          {
            if (toupper(c&0xff)=='B') fontflag|=1;
            else if (toupper(c&0xff)=='I') fontflag|=2;
            else if (toupper(c&0xff)=='U') fontflag|=4;
            c>>=8;
          }
        }
      

        if (fontflag != s->last_fontflag || sz!=s->last_fontsize || strncmp(s->last_fontname,face,sizeof(s->last_fontname)-1))
        {
          lstrcpyn_safe(s->last_fontname,face,sizeof(s->last_fontname));
          s->last_fontsize=sz;
          s->last_fontflag=fontflag;
          doCreate=1;
        }
      }

      if (doCreate)
      {
        if (!s->font) s->font=LICE_CreateFont();
        if (s->font)
        {
          HFONT hf=CreateFont(sz,0,0,0,(fontflag&1) ? FW_BOLD : FW_NORMAL,!!(fontflag&2),!!(fontflag&4),FALSE,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH,s->last_fontname);
          if (!hf)
          {
            s->use_fonth=0; // disable this font
          }
          else
          {
            TEXTMETRIC tm;
            tm.tmHeight = sz;

            if (!m_framebuffer && LICE_FUNCTION_VALID(__LICE_CreateBitmap)) m_framebuffer=__LICE_CreateBitmap(0,64,64);

            if (m_framebuffer && LICE_FUNCTION_VALID(LICE__GetDC))
            {
              HGDIOBJ oldFont = 0;
              HDC hdc=LICE__GetDC(m_framebuffer);
              if (hdc)
              {
                oldFont = SelectObject(hdc,hf);
                GetTextMetrics(hdc,&tm);
                SelectObject(hdc,oldFont);
              }
            }

            s->use_fonth=max(tm.tmHeight,1);
            LICE__SetFromHFont(s->font,hf,512);//LICE_FONT_FLAG_OWNS_HFONT);
          }
        }
      }
    }

    
    if (s->font && s->use_fonth)
    {
      m_gfx_font_active=a;
      if (m_gfx_texth) *m_gfx_texth=s->use_fonth;
      return 1.0;
    }
    // try to init this font
  }

  if (a<0||a>=m_gfx_fonts.GetSize()||!m_gfx_fonts.Get()[a].font)
  {
    m_gfx_font_active=-1;
    if (m_gfx_texth) *m_gfx_texth=8;
    return 1.0;
  }
  return 0.0;
}

void eel_lice_state::gfx_blitext2(int np, EEL_F **parms, int blitmode)
{
  LICE_IBitmap *dest = GetImageForIndex(*m_gfx_dest);

  if (!dest
#ifdef DYNAMIC_LICE
    ||!LICE_ScaledBlit || !LICE_RotatedBlit||!LICE__GetWidth||!LICE__GetHeight
#endif 
    ) return;

  LICE_IBitmap *bm=GetImageForIndex(parms[0][0]); 
  if (!bm) return;

  const int bmw=LICE__GetWidth(bm);
  const int bmh=LICE__GetHeight(bm);
  
  // 0=img, 1=scale, 2=rotate
  double coords[8];
  const double sc = blitmode==0 ? parms[1][0] : 1.0,
            angle = blitmode==0 ? parms[2][0] : 0.0;
  if (blitmode==0)
  {
    parms+=2;
    np -= 2;
  }

  coords[0]=np > 1 ? parms[1][0] : 0.0f;
  coords[1]=np > 2 ? parms[2][0] : 0.0f;
  coords[2]=np > 3 ? parms[3][0] : bmw;
  coords[3]=np > 4 ? parms[4][0] : bmh;
  coords[4]=np > 5 ? parms[5][0] : *m_gfx_x;
  coords[5]=np > 6 ? parms[6][0] : *m_gfx_y;
  coords[6]=np > 7 ? parms[7][0] : coords[2]*sc;
  coords[7]=np > 8 ? parms[8][0] : coords[3]*sc;
 
  const bool isFromFB = bm == m_framebuffer;
 
  if (bm == dest && CoordsSrcDestOverlap(coords))
  {
    if (!m_framebuffer_extra && LICE_FUNCTION_VALID(__LICE_CreateBitmap)) m_framebuffer_extra=__LICE_CreateBitmap(0,bmw,bmh);
    if (m_framebuffer_extra)
    {
    
      LICE__resize(bm=m_framebuffer_extra,bmw,bmh);
      LICE_ScaledBlit(bm,dest, // copy the source portion
        coords[0],coords[1],coords[2],coords[3],
        coords[0],coords[1],coords[2],coords[3],
        1.0f,LICE_BLIT_MODE_COPY);      
    }
  }
  
  if (blitmode==1)
  {
    if (LICE_FUNCTION_VALID(LICE_DeltaBlit))
      LICE_DeltaBlit(dest,bm,coords[4],coords[5],coords[6],coords[7],coords[0],coords[1],coords[2],coords[3],
                np > 9 ? parms[9][0]:1.0, // dsdx
                np > 10 ? parms[10][0]:0.0, // dtdx
                np > 11 ? parms[11][0]:0.0, // dsdy
                np > 12 ? parms[12][0]:1.0, // dtdy
                np > 13 ? parms[13][0]:0.0, // dsdxdy
                np > 14 ? parms[14][0]:0.0, // dtdxdy
                true,*m_gfx_a,getCurModeForBlit(isFromFB));
  }
  else if (fabs(angle)>0.000000001)
  {
    LICE_RotatedBlit(dest,bm,coords[4],coords[5],coords[6],coords[7],coords[0],coords[1],coords[2],coords[3],
        angle,true,*m_gfx_a,getCurModeForBlit(isFromFB),
       np > 9 ? parms[9][0] : 0.0,
       np > 10 ? parms[10][0] : 0.0);
  }
  else
  {
    LICE_ScaledBlit(dest,bm,coords[4],coords[5],coords[6],coords[7],coords[0],coords[1],coords[2],coords[3],*m_gfx_a,getCurModeForBlit(isFromFB));
  }
  SetImageDirty(dest);
}

void eel_lice_state::gfx_blitext(EEL_F img, EEL_F *coords, EEL_F angle)
{
  LICE_IBitmap *dest = GetImageForIndex(*m_gfx_dest);

  if (!dest
#ifdef DYNAMIC_LICE
    ||!LICE_ScaledBlit || !LICE_RotatedBlit||!LICE__GetWidth||!LICE__GetHeight
#endif 
    ) return;

  LICE_IBitmap *bm=GetImageForIndex(img); 
  if (!bm) return;
  
  const bool isFromFB = bm == m_framebuffer;
 
  int bmw=LICE__GetWidth(bm);
  int bmh=LICE__GetHeight(bm);
  
  if (bm == dest && CoordsSrcDestOverlap(coords))
  {
    if (!m_framebuffer_extra && LICE_FUNCTION_VALID(__LICE_CreateBitmap)) m_framebuffer_extra=__LICE_CreateBitmap(0,bmw,bmh);
    if ( m_framebuffer_extra)
    {
    
      LICE__resize(bm=m_framebuffer_extra,bmw,bmh);
      LICE_ScaledBlit(bm,dest, // copy the source portion
        coords[0],coords[1],coords[2],coords[3],
        coords[0],coords[1],coords[2],coords[3],
        1.0f,LICE_BLIT_MODE_COPY);      
    }
  }
  
  if (fabs(angle)>0.000000001)
  {
    LICE_RotatedBlit(dest,bm,coords[4],coords[5],coords[6],coords[7],coords[0],coords[1],coords[2],coords[3],angle,true,*m_gfx_a,getCurModeForBlit(isFromFB),
        coords[8],coords[9]);
  }
  else
  {
    LICE_ScaledBlit(dest,bm,coords[4],coords[5],coords[6],coords[7],coords[0],coords[1],coords[2],coords[3],*m_gfx_a,getCurModeForBlit(isFromFB));
  }
  SetImageDirty(dest);
}

void eel_lice_state::gfx_blit(EEL_F img, EEL_F scale, EEL_F rotate)
{
  LICE_IBitmap *dest = GetImageForIndex(*m_gfx_dest);
  if (!dest
#ifdef DYNAMIC_LICE
    ||!LICE_ScaledBlit || !LICE_RotatedBlit||!LICE__GetWidth||!LICE__GetHeight
#endif
    ) return;

  LICE_IBitmap *bm=GetImageForIndex(img);
  
  if (!bm) return;
  
  const bool isFromFB = bm == m_framebuffer;
  
  int bmw=LICE__GetWidth(bm);
  int bmh=LICE__GetHeight(bm);
  if (fabs(rotate)>0.000000001)
  {
    LICE_RotatedBlit(dest,bm,*m_gfx_x,*m_gfx_y,bmw*scale,bmh*scale,0,0,bmw,bmh,rotate,true,*m_gfx_a,getCurModeForBlit(isFromFB),
        0,0);
  }
  else
  {
    LICE_ScaledBlit(dest,bm,*m_gfx_x,*m_gfx_y,bmw*scale,bmh*scale,0,0,bmw,bmh,*m_gfx_a,getCurModeForBlit(isFromFB));
  }
  SetImageDirty(dest);
}


void eel_lice_state::gfx_getpixel(EEL_F *r, EEL_F *g, EEL_F *b)
{
  LICE_IBitmap *dest = GetImageForIndex(*m_gfx_dest);
  if (!dest) return;

  int ret=LICE_GetPixel?LICE_GetPixel(dest,(int)*m_gfx_x, (int)*m_gfx_y):0;

  *r=LICE_GETR(ret)/255.0;
  *g=LICE_GETG(ret)/255.0;
  *b=LICE_GETB(ret)/255.0;

}


static int __drawTextWithFont(LICE_IBitmap *dest, int xpos, int ypos, LICE_IFont *font, const char *buf, int buflen, int fg, int mode, float alpha, EEL_F *wantYoutput, EEL_F **measureOnly)
{
  if (font && LICE_FUNCTION_VALID(LICE__DrawText))
  {
    LICE__SetTextColor(font,fg);
    LICE__SetTextCombineMode(font,mode,alpha);

    int maxx=0;
    RECT r={0,0,xpos,0};
    while (buflen>0)
    {
      int thislen = 0;
      while (thislen < buflen && buf[thislen] != '\n') thislen++;
      memset(&r,0,sizeof(r));
      int lineh = LICE__DrawText(font,dest,buf,thislen?thislen:1,&r,DT_SINGLELINE|DT_NOPREFIX|DT_CALCRECT);
      if (!measureOnly)
      {
        r.left = xpos;
        r.top = ypos;
        r.right += xpos;
        r.bottom += ypos;
        lineh = LICE__DrawText(font,dest,buf,thislen?thislen:1,&r,DT_SINGLELINE|DT_NOPREFIX|DT_LEFT|DT_TOP);

        if (wantYoutput) *wantYoutput = ypos;
      }
      else
      {
        if (r.right > maxx) maxx=r.right;
      }
      ypos += lineh;

      buflen -= thislen+1;
      buf += thislen+1;      
    }
    if (measureOnly) 
    {
      measureOnly[0][0] = maxx;
      measureOnly[1][0] = ypos;
    }
    return r.right;
  }
  else
  { 
    int x;
    const int sxpos = xpos;
    int maxx=0,maxy=0;
    if (LICE_FUNCTION_VALID(LICE_DrawChar)) for(x=0;x<buflen;x++)
    {
      switch (buf[x])
      {
        case '\n': 
          ypos += 8; 
        case '\r': 
          xpos = sxpos; 
        break;
        case ' ': xpos += 8; break;
        case '\t': xpos += 8*5; break;
        default:
          if (!measureOnly) LICE_DrawChar(dest,xpos,ypos,buf[x], fg,alpha,mode);
          xpos += 8;
          if (xpos > maxx) maxx=xpos;
          maxy = ypos + 8;
        break;
      }
    }
    if (measureOnly)
    {
      measureOnly[0][0]=maxx;
      measureOnly[1][0]=maxy;
    }
    else
    {
      if (wantYoutput) *wantYoutput=ypos;
    }
    return xpos;
  }
}

void eel_lice_state::gfx_drawstr(void *opaque, EEL_F ch, int formatmode, int nfmtparms, EEL_F **fmtparms)// formatmode=1 for format, 2 for purely measure no format
{
  LICE_IBitmap *dest = GetImageForIndex(*m_gfx_dest);
  if (!dest) return;

#ifdef DYNAMIC_LICE
  if (!LICE__GetWidth || !LICE__GetHeight) return;
#endif

  EEL_STRING_MUTEXLOCK_SCOPE

  WDL_FastString *fs=NULL;
  const char *s=EEL_STRING_GET_FOR_INDEX(ch,&fs);
  char buf[4096];
  int s_len=0;
  if (!s) 
  {
    s="<bad string>";
    s_len = 12;
  }
  else if (formatmode==1)
  {
    extern int eel_format_strings(void *, const char *s, const char *ep, char *, int, int, EEL_F **);
    s_len = eel_format_strings(this,s,fs?(s+fs->GetLength()):NULL,buf,sizeof(buf),nfmtparms,fmtparms);
    if (s_len<1) return;
    s=buf;
  }
  else
  {
    s_len = fs?fs->GetLength():(int)strlen(s);
  }

  if (s_len)
  {
    if (formatmode==2)
    {
      if (nfmtparms==2)
        __drawTextWithFont(dest,0,0,GetActiveFont(),s,s_len,getCurColor(),getCurMode(),(float) *m_gfx_a,NULL, fmtparms);
    }
    else
    {
      *m_gfx_x = __drawTextWithFont(dest,(int)floor(*m_gfx_x),(int)floor(*m_gfx_y),GetActiveFont(),s,s_len,getCurColor(),getCurMode(),(float) *m_gfx_a,m_gfx_y,NULL);
    }

    SetImageDirty(dest);
  }
}

void eel_lice_state::gfx_drawchar(EEL_F ch)
{
  LICE_IBitmap *dest = GetImageForIndex(*m_gfx_dest);
  if (!dest) return;

  int a=(int)(ch+0.5);
  if (a == '\r' || a=='\n') a=' ';

  char buf[2]={a,0};
  *m_gfx_x = __drawTextWithFont(dest,(int)floor(*m_gfx_x),(int)floor(*m_gfx_y),
                         GetActiveFont(),buf,1,
                         getCurColor(),getCurMode(),(float)*m_gfx_a, NULL,NULL);

  SetImageDirty(dest);
}


void eel_lice_state::gfx_drawnumber(EEL_F n, EEL_F ndigits)
{
  LICE_IBitmap *dest = GetImageForIndex(*m_gfx_dest);
  if (!dest) return;

  char buf[512];
  int a=(int)(ndigits+0.5);
  if (a <0)a=0;
  else if (a > 16) a=16;
  snprintf(buf,sizeof(buf),"%.*f",a,n);

  *m_gfx_x = __drawTextWithFont(dest,(int)floor(*m_gfx_x),(int)floor(*m_gfx_y),
                           GetActiveFont(),buf,strlen(buf),
                           getCurColor(),getCurMode(),(float)*m_gfx_a, NULL,NULL);

  SetImageDirty(dest);
}

int eel_lice_state::setup_frame(HWND hwnd, RECT r)
{
  int dr=0;
  if (!m_framebuffer && LICE_FUNCTION_VALID(__LICE_CreateBitmap)) 
  {
    m_framebuffer=__LICE_CreateBitmap(1,r.right-r.left,r.bottom-r.top);
    dr=1;
  }

  if (!m_framebuffer || !LICE_FUNCTION_VALID(LICE__GetHeight) || !LICE_FUNCTION_VALID(LICE__GetWidth)) return -1;

  if (r.right-r.left != LICE__GetWidth(m_framebuffer) ||
      r.bottom-r.top != LICE__GetHeight(m_framebuffer))
  {
    LICE__resize(m_framebuffer,r.right-r.left,r.bottom-r.top);
    dr=1;
  }
  *m_gfx_w = r.right-r.left;
  *m_gfx_h = r.bottom-r.top;
  
  if (*m_gfx_clear > -1.0)
  {
    int a=*m_gfx_clear;
    int r=a&0xff;
    int g=(a>>8)&0xff;
    int b=(a>>16)&0xff;
    if (LICE_FUNCTION_VALID(LICE_Clear)) LICE_Clear(m_framebuffer,LICE_RGBA(r,g,b,0));
  }

  POINT pt;
  GetCursorPos(&pt);
  ScreenToClient(hwnd,&pt);
  *m_mouse_x=pt.x-r.left;
  *m_mouse_y=pt.y-r.top;
  int vflags=0;
  if (GetCapture()==hwnd)
  {
    if (GetAsyncKeyState(VK_LBUTTON)&0x8000) vflags|=1;
    if (GetAsyncKeyState(VK_RBUTTON)&0x8000) vflags|=2;
    if (vflags)
    {
      if (GetAsyncKeyState(VK_CONTROL)&0x8000) vflags|=4;
      if (GetAsyncKeyState(VK_SHIFT)&0x8000) vflags|=8;
      if (GetAsyncKeyState(VK_MENU)&0x8000) vflags|=16;
    }
  }
  *m_mouse_cap=(EEL_F)vflags;

  *m_gfx_dest = -1.0; // m_framebuffer
  *m_gfx_a= 1.0; // default to full alpha every call
  return dr;

}


void eel_lice_register()
{
  NSEEL_addfunctionex("gfx_lineto",3,(char *)_asm_generic3parm,(char *)_asm_generic3parm_end-(char *)_asm_generic3parm,NSEEL_PProc_THIS,(void *)&_gfx_lineto);
  NSEEL_addfunctionex("gfx_lineto",2,(char *)_asm_generic2parm,(char *)_asm_generic2parm_end-(char *)_asm_generic2parm,NSEEL_PProc_THIS,(void *)&_gfx_lineto2);
  NSEEL_addfunctionex("gfx_rectto",2,(char *)_asm_generic2parm,(char *)_asm_generic2parm_end-(char *)_asm_generic2parm,NSEEL_PProc_THIS,(void *)&_gfx_rectto);
  NSEEL_addfunc_exparms("gfx_rect",4,NSEEL_PProc_THIS,(void *)&_gfx_rect);
  NSEEL_addfunc_varparm("gfx_line",4,NSEEL_PProc_THIS,(void *)&_gfx_line); // 5th param is optionally AA
  NSEEL_addfunc_varparm("gfx_gradrect",8,NSEEL_PProc_THIS,(void *)&_gfx_gradrect); 
  NSEEL_addfunc_varparm("gfx_muladdrect",7,NSEEL_PProc_THIS,(void *)&_gfx_muladdrect);  
  NSEEL_addfunc_varparm("gfx_deltablit",9,NSEEL_PProc_THIS,(void *)&_gfx_deltablit);  
  NSEEL_addfunc_exparms("gfx_transformblit",8,NSEEL_PProc_THIS,(void *)&_gfx_transformblit);
  NSEEL_addfunctionex("gfx_blurto",2,(char *)_asm_generic2parm,(char *)_asm_generic2parm_end-(char *)_asm_generic2parm,NSEEL_PProc_THIS,(void *)&_gfx_blurto);
  NSEEL_addfunctionex("gfx_drawnumber",2,(char *)_asm_generic2parm,(char *)_asm_generic2parm_end-(char *)_asm_generic2parm,NSEEL_PProc_THIS,(void *)&_gfx_drawnumber);
  NSEEL_addfunctionex("gfx_drawchar",1,(char *)_asm_generic1parm,(char *)_asm_generic1parm_end-(char *)_asm_generic1parm,NSEEL_PProc_THIS,(void *)&_gfx_drawchar);
  NSEEL_addfunctionex("gfx_drawstr",1,(char *)_asm_generic1parm,(char *)_asm_generic1parm_end-(char *)_asm_generic1parm,NSEEL_PProc_THIS,(void *)&_gfx_drawstr);
  NSEEL_addfunctionex("gfx_measurestr",3,(char *)_asm_generic3parm,(char *)_asm_generic3parm_end-(char *)_asm_generic3parm,NSEEL_PProc_THIS,(void *)&_gfx_measurestr);
  NSEEL_addfunc_varparm("gfx_printf",1,NSEEL_PProc_THIS,(void *)&_gfx_printf);
  NSEEL_addfunctionex("gfx_setpixel",3,(char *)_asm_generic3parm,(char *)_asm_generic3parm_end-(char *)_asm_generic3parm,NSEEL_PProc_THIS,(void *)&_gfx_setpixel);
  NSEEL_addfunctionex("gfx_getpixel",3,(char *)_asm_generic3parm,(char *)_asm_generic3parm_end-(char *)_asm_generic3parm,NSEEL_PProc_THIS,(void *)&_gfx_getpixel);
  NSEEL_addfunctionex("gfx_getimgdim",3,(char *)_asm_generic3parm,(char *)_asm_generic3parm_end-(char *)_asm_generic3parm,NSEEL_PProc_THIS,(void *)&_gfx_getimgdim);
  NSEEL_addfunctionex("gfx_setimgdim",3,(char *)_asm_generic3parm_retd,(char *)_asm_generic3parm_retd_end-(char *)_asm_generic3parm_retd,NSEEL_PProc_THIS,(void *)&_gfx_setimgdim);
  NSEEL_addfunctionex("gfx_loadimg",2,(char *)_asm_generic2parm_retd,(char *)_asm_generic2parm_retd_end-(char *)_asm_generic2parm_retd,NSEEL_PProc_THIS,(void *)&_gfx_loadimg);
  NSEEL_addfunctionex("gfx_blit",3,(char *)_asm_generic3parm,(char *)_asm_generic3parm_end-(char *)_asm_generic3parm,NSEEL_PProc_THIS,(void *)&_gfx_blit);
  NSEEL_addfunctionex("gfx_blitext",3,(char *)_asm_generic3parm,(char *)_asm_generic3parm_end-(char *)_asm_generic3parm,NSEEL_PProc_THIS,(void *)&_gfx_blitext);
  NSEEL_addfunc_varparm("gfx_blit",4,NSEEL_PProc_THIS,(void *)&_gfx_blit2);
  NSEEL_addfunc_varparm("gfx_setfont",1,NSEEL_PProc_THIS,(void *)&_gfx_setfont);
}

#endif//!EEL_LICE_API_ONLY




#ifdef DYNAMIC_LICE
static void eel_lice_initfuncs(void *(*getFunc)(const char *name))
{
  if (!getFunc) return;

  *(void **)&__LICE_CreateBitmap = getFunc("LICE_CreateBitmap");
  *(void **)&LICE_Clear = getFunc("LICE_Clear");
  *(void **)&LICE_Line = getFunc("LICE_LineInt");
  *(void **)&LICE_ClipLine = getFunc("LICE_ClipLine");
  *(void **)&LICE_FillRect = getFunc("LICE_FillRect");
  *(void **)&LICE_PutPixel = getFunc("LICE_PutPixel");
  *(void **)&LICE_GetPixel = getFunc("LICE_GetPixel");
  *(void **)&LICE_DrawText = getFunc("LICE_DrawText");
  *(void **)&LICE_DrawChar = getFunc("LICE_DrawChar");
  *(void **)&LICE_MeasureText = getFunc("LICE_MeasureText");
  *(void **)&LICE_LoadPNG = getFunc("LICE_LoadPNG");
  *(void **)&LICE__GetDC = getFunc("LICE__GetDC");
  *(void **)&LICE__Destroy = getFunc("LICE__Destroy");
  *(void **)&LICE__GetWidth = getFunc("LICE__GetWidth");
  *(void **)&LICE__GetHeight = getFunc("LICE__GetHeight");
  *(void **)&LICE__resize = getFunc("LICE__resize");
  *(void **)&LICE_Blur = getFunc("LICE_Blur");
  *(void **)&LICE_RotatedBlit = getFunc("LICE_RotatedBlit");
  *(void **)&LICE_ScaledBlit = getFunc("LICE_ScaledBlit");

  *(void **)&LICE_MultiplyAddRect  = getFunc("LICE_MultiplyAddRect");
  *(void **)&LICE_GradRect  = getFunc("LICE_GradRect");
  *(void **)&LICE_TransformBlit2  = getFunc("LICE_TransformBlit2");
  *(void **)&LICE_DeltaBlit  = getFunc("LICE_DeltaBlit");

  *(void **)&LICE__DestroyFont = getFunc("LICE__DestroyFont");    
  *(void **)&LICE_CreateFont = getFunc("LICE_CreateFont");    
  *(void **)&LICE__SetFromHFont = getFunc("LICE__SetFromHFont2");

  *(void **)&LICE__SetTextColor = getFunc("LICE__SetTextColor");    
  *(void **)&LICE__SetBkColor = getFunc("LICE__SetBkColor");    
  *(void **)&LICE__SetTextCombineMode = getFunc("LICE__SetTextCombineMode");    
  *(void **)&LICE__DrawText = getFunc("LICE__DrawText");    
}
#endif


#endif//_EEL_LICE_H_