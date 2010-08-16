/*
    WDL - queue.h
    Copyright (C) 2005 and later, Cockos Incorporated

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
      
*/

/*

  This file provides a simple class for a FIFO queue of bytes. It uses a simple buffer,
  so should not generally be used for large quantities of data (it can advance the queue 
  pointer, but Compact() needs to be called regularly to keep memory usage down, and when
  it is called, there's a memcpy() penalty for the remaining data. oh well, is what it is).

  You may also wish to look at fastqueue.h or circbuf.h if these limitations aren't acceptable.

*/

#ifndef _WDL_QUEUE_H_
#define _WDL_QUEUE_H_

#include "heapbuf.h"


class WDL_Queue 
{
public:
  WDL_Queue() : m_pos(0), m_hb(4096 WDL_HEAPBUF_TRACEPARM("WDL_Queue")) { }
  ~WDL_Queue() { }

  template <class T> void* AddT(T* buf)
  {
    return Add(buf, sizeof(T));
  }

  void *Add(const void *buf, int len)
  {
    int olen=m_hb.GetSize();
    void *obuf=m_hb.Resize(olen+len,false);
    if (!obuf) return 0;
    char* newbuf = (char*) obuf + olen;
    if (buf) memcpy(newbuf,buf,len);
    return newbuf; 
  }

  int GetSize()
  {
    return m_hb.GetSize()-m_pos;
  }

  template <class T> T* GetT(T* val=0)
  {
    T* p = (T*) Get(sizeof(T));
    if (val && p) *val = *p;
    return p;
  }
  
  void* Get(int size)
  {
    void* p = Get();
    if (p) Advance(size);
    return p;
  }
    
  void *Get()
  {
    void *buf=m_hb.Get();
    if (buf && m_pos >= 0 && m_pos < m_hb.GetSize()) return (char *)buf+m_pos;
    return NULL;
  }
  
  void* Rewind()
  {
    m_pos = 0;
    return m_hb.Get();
  }

  int Available() { return m_hb.GetSize() - m_pos; }

  void Clear()
  {
    m_pos=0;
    m_hb.Resize(0,false);
  }

  void Advance(int bytecnt) { m_pos+=bytecnt; }

  void Compact(bool allocdown=false)
  {
    if (m_pos > 0)
    {
      int olen=m_hb.GetSize();
      if (m_pos < olen)
      {
        void *a=m_hb.Get();
        if (a) memmove(a,(char*)a+m_pos,olen-m_pos);
        m_hb.Resize(olen-m_pos,allocdown);
      }
      else m_hb.Resize(0,allocdown);
      m_pos=0;
    }
  }

  void SetGranul(int granul) { m_hb.SetGranul(granul); }

private:
  WDL_HeapBuf m_hb;
  int m_pos;
};

template <class T> class WDL_TypedQueue
{
public:
  WDL_TypedQueue() : m_pos(0), m_hb(4096 WDL_HEAPBUF_TRACEPARM("WDL_TypedQueue")) { }
  ~WDL_TypedQueue() { }

  T *Add(const T *buf, int len)
  {
    len *= sizeof(T);
    int olen=m_hb.GetSize();
    void *obuf=m_hb.Resize(olen+len,false);
    if (!obuf) return 0;
    if (buf) memcpy((char*)obuf+olen,buf,len);
    return (T*) ((char*)obuf+olen);
  }

  int GetSize()
  {
    return (m_hb.GetSize()-m_pos)/sizeof(T);
  }

  T *Get()
  {
    void *buf=m_hb.Get();
    if (buf && m_pos >= 0 && m_pos < m_hb.GetSize()) return (T*)((char *)buf+m_pos);
    return NULL;
  }

  int Available() { return (m_hb.GetSize() - m_pos)/sizeof(T); }

  void Clear()
  {
    m_pos=0;
    m_hb.Resize(0,false);
  }

  void Advance(int cnt) { m_pos+=cnt*sizeof(T); }

  void Compact(bool allocdown=false)
  {
    if (m_pos > 0)
    {
      int olen=m_hb.GetSize();
      if (m_pos < olen)
      {
        void *a=m_hb.Get();
        if (a) memmove(a,(char*)a+m_pos,olen-m_pos);
        m_hb.Resize(olen-m_pos,allocdown);
      }
      else m_hb.Resize(0,allocdown);
      m_pos=0;
    }
  }

  void SetGranul(int granul) { m_hb.SetGranul(granul); }

private:
  WDL_HeapBuf m_hb;
  int m_pos;
};

// endian-management stuff 

static void WDL_Queue__bswap_buffer(void *buf, int len)
{
#ifdef __ppc__
  char *p=(char *)buf;
  char *ep=p+len;
  while ((len-=2) >= 0)
  {
    char tmp=*p; *p++=*--ep; *ep=tmp;
  }
#endif
}

template<class T> static void WDL_Queue__AddToLE(WDL_Queue *q, T *val)
{
  WDL_Queue__bswap_buffer(q->AddT(val),sizeof(T));
}
static void WDL_Queue__AddDataToLE(WDL_Queue *q, void *data, int datasize, int unitsize)
{
  char *dout = (char *)q->Add(data,datasize);
  #ifdef __ppc__
  while (datasize >= unitsize)
  {
    WDL_Queue__bswap_buffer(dout,unitsize);
    dout+=unitsize;
    datasize-=unitsize;
  }
  #endif
}




// NOTE: these thrash the contents of the queue if on LE systems. So for example if you are going to rewind it later or use it elsewhere, 
// then get ready to get unhappy.
template<class T> static T *WDL_Queue__GetTFromLE(WDL_Queue *q, T* val=0)
{
  T *p = q->GetT(val);
  if (p) {
    WDL_Queue__bswap_buffer(p,sizeof(T));
    if (val) *val = *p;
  }
  return p;
}
static void *WDL_Queue__GetDataFromLE(WDL_Queue *q, int datasize, int unitsize)
{
  void *data=q->Get(datasize);
  #ifdef __ppc__
  char *dout=(char *)data;
  if (dout) while (datasize >= unitsize)
  {
    WDL_Queue__bswap_buffer(dout,unitsize);
    dout+=unitsize;
    datasize-=unitsize;
  }
  #endif
  return data;
}

#endif


