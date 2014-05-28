# QtCreator project file

TARGET   = Swell
TEMPLATE = lib
VERSION  = 1.0

# -----------------------------------------------------------------------

QT = core gui widgets

CONFIG    = debug
CONFIG   += link_pkgconfig qt shared warn_on

DEFINES   = DEBUG
DEFINES  += SWELL_LICE_GDI
DEFINES  += SWELL_FREETYPE
DEFINES  += SWELL_TARGET_QT

PKGCONFIG = freetype2

# -----------------------------------------------------------------------

SOURCES = \
    swell.cpp \
    swell-ini.cpp \
    swell-appstub-qt.cpp \
    swell-dlg-qt.cpp \
    swell-gdi-lice.cpp \
    swell-gdi-qt.cpp \ # unused
    swell-kb-qt.cpp \
    swell-menu-qt.cpp \
    swell-misc-qt.cpp \
    swell-miscdlg-qt.cpp \
    swell-modstub-qt.cpp \ # unused
    swell-wnd-qt.cpp

# lice
SOURCES += \
    ../lice/lice.cpp \
    ../lice/lice_arc.cpp \
    ../lice/lice_colorspace.cpp \
    ../lice/lice_image.cpp \
    ../lice/lice_jpg.cpp \
    ../lice/lice_line.cpp \
    ../lice/lice_pcx.cpp \
    ../lice/lice_png.cpp \
    ../lice/lice_texgen.cpp \
    ../lice/lice_text.cpp \
    ../lice/lice_textnew.cpp \
    ../lice/lice_ico.cpp \
    ../lice/lice_bmp.cpp \
    ../lice/lice_lvg.cpp

# libpng
SOURCES += \
    ../libpng/png.c \
    ../libpng/pngerror.c \
    ../libpng/pngget.c \
    ../libpng/pngmem.c \
    ../libpng/pngpread.c \
    ../libpng/pngread.c \
    ../libpng/pngrio.c \
    ../libpng/pngrtran.c \
    ../libpng/pngrutil.c \
    ../libpng/pngset.c \
    ../libpng/pngtrans.c

# jpeglib
SOURCES += \
    ../jpeglib/jcomapi.c \
    ../jpeglib/jdapimin.c \
    ../jpeglib/jdapistd.c \
    ../jpeglib/jdatadst.c \
    ../jpeglib/jdatasrc.c \
    ../jpeglib/jdcoefct.c \
    ../jpeglib/jdcolor.c \
    ../jpeglib/jddctmgr.c \
    ../jpeglib/jdhuff.c \
    ../jpeglib/jdinput.c \
    ../jpeglib/jdmainct.c \
    ../jpeglib/jdmarker.c \
    ../jpeglib/jdmaster.c \
    ../jpeglib/jdmerge.c \
    ../jpeglib/jdphuff.c \
    ../jpeglib/jdpostct.c \
    ../jpeglib/jdsample.c \
    ../jpeglib/jerror.c \
    ../jpeglib/jfdctflt.c \
    ../jpeglib/jfdctfst.c \
    ../jpeglib/jfdctint.c \
    ../jpeglib/jidctflt.c \
    ../jpeglib/jidctfst.c \
    ../jpeglib/jidctint.c \
    ../jpeglib/jidctred.c \
    ../jpeglib/jmemmgr.c \
    ../jpeglib/jmemnobs.c \
    ../jpeglib/jquant1.c \
    ../jpeglib/jquant2.c \
    ../jpeglib/jutils.c

# zlib
SOURCES_NOT += \
    ../zlib/compress.c \
    ../zlib/adler32.c \
    ../zlib/crc32.c \
    ../zlib/deflate.c \
    ../zlib/infback.c \
    ../zlib/inffast.c \
    ../zlib/inflate.c \
    ../zlib/inftrees.c \
    ../zlib/trees.c \
    ../zlib/uncompr.c \
    ../zlib/zutil.c \
    ../zlib/unzip.c \
    ../zlib/ioapi.c \
    ../zlib/zip.c

HEADERS = \
    swell.h \
    swell-dlggen.h \
    swell-functions.h \
    swell-internal.h \
    swell-menugen.h \
    swell-types.h
#   swell-gdi-internalpool.h

INCLUDEPATH = . .. ../lice

# -----------------------------------------------------------------------

QMAKE_CFLAGS = -malign-double -fno-strict-aliasing -fno-math-errno
QMAKE_CXXFLAGS = -malign-double -fno-strict-aliasing -fno-math-errno -Wno-unused-parameter -Wno-sign-compare
#QMAKE_LDLAGS = -Wl,-no-undefined

LIBS = -ldl -lpthread -Wl,-no-undefined

# -----------------------------------------------------------------------
