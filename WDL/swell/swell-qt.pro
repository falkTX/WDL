# QtCreator project file

TARGET   = CarlaPlugin
TEMPLATE = dll
VERSION  = 1.0

# -----------------------------------------------------------------------

QT = core gui xml

CONFIG    = debug
CONFIG   += link_pkgconfig qt shared warn_on

DEFINES   = DEBUG
DEFINES  += SWELL_LICE_GDI
DEFINES  += SWELL_FREETYPE
DEFINES  += SWELL_TARGET_QT

PKGCONFIG = freetype

# -----------------------------------------------------------------------

SOURCES = \
    swell.cpp

HEADERS = \
    swell.h

INCLUDEPATH = . .. ../lice

# -----------------------------------------------------------------------

QMAKE_CFLAGS := -malign-double -fno-strict-aliasing -fno-math-errno
QMAKE_CXXFLAGS := -malign-double -fno-strict-aliasing -fno-math-errno

LIBS = -ldl -lpthread

# -----------------------------------------------------------------------
