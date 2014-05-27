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
    swell-appstub-generic.cpp \
    swell-dlg-generic.cpp \
    swell-gdi-generic.cpp \
    swell-kb-generic.cpp \
    swell-menu-generic.cpp \
    swell-misc-generic.cpp \
    swell-miscdlg-generic.cpp \
    swell-wnd-generic.cpp \
    swell-ini.cpp

HEADERS = \
    swell.h \
    swell-types.h \
    swell-functions.h \
    swell-internal.h

INCLUDEPATH = . .. ../lice

# -----------------------------------------------------------------------

QMAKE_CFLAGS = -malign-double -fno-strict-aliasing -fno-math-errno
QMAKE_CXXFLAGS = -malign-double -fno-strict-aliasing -fno-math-errno -Wno-unused-parameter -Wno-sign-compare
#QMAKE_LINKFLAGS = -Wl,-no-unused

LIBS = -ldl -lpthread

# -----------------------------------------------------------------------
