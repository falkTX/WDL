# QtCreator project file

TARGET   = Swell
TEMPLATE = lib
VERSION  = 1.0

# -----------------------------------------------------------------------

QT = core gui widgets

CONFIG    = debug
CONFIG   += link_pkgconfig qt shared warn_on

DEFINES   = DEBUG
#DEFINES  += SWELL_LICE_GDI
DEFINES  += SWELL_FREETYPE
DEFINES  += SWELL_TARGET_QT

PKGCONFIG = freetype2

# -----------------------------------------------------------------------

SOURCES = \
    swell.cpp \
    swell-ini.cpp \
    swell-appstub-qt.cpp \
    swell-dlg-qt.cpp \
    swell-gdi-qt.cpp \
    swell-kb-qt.cpp \
    swell-menu-qt.cpp \
    swell-misc-qt.cpp \
    swell-miscdlg-qt.cpp \
    swell-modstub-qt.cpp \ # unused
    swell-wnd-qt.cpp

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
