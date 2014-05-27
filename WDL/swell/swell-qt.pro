# QtCreator project file

TARGET   = Swell
TEMPLATE = lib
VERSION  = 1.0

# -----------------------------------------------------------------------

QT = core gui xml

CONFIG    = debug
CONFIG   += link_pkgconfig qt shared warn_on

DEFINES   = DEBUG
DEFINES  += SWELL_LICE_GDI
DEFINES  += SWELL_FREETYPE
DEFINES  += SWELL_TARGET_QT

PKGCONFIG = freetype2

# -----------------------------------------------------------------------

SOURCES = \
    swell.cpp

HEADERS = \
    swell.h \
    swell-types.h \
    swell-functions.h \
    swell-internal.h

INCLUDEPATH = . .. ../lice

# -----------------------------------------------------------------------

QMAKE_CFLAGS = -malign-double -fno-strict-aliasing -fno-math-errno
QMAKE_CXXFLAGS = -malign-double -fno-strict-aliasing -fno-math-errno

LIBS = -ldl -lpthread

# -----------------------------------------------------------------------
