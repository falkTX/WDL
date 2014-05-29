#ifndef SWELL_PROVIDED_BY_APP

#include "swell.h"
#include "swell-internal.h"

#define DBGFUNC printf("%s\n", __PRETTY_FUNCTION__);

static bool s_rightclickemulate = false;

bool IsRightClickEmulateEnabled()
{
    return s_rightclickemulate;
}

void SWELL_EnableRightClickEmulate(BOOL enable)
{
    s_rightclickemulate = enable;
}

HANDLE SWELL_CreateProcess(const char *exe, int nparams, const char **params)
{
    DBGFUNC;
    return 0;
}

#endif
