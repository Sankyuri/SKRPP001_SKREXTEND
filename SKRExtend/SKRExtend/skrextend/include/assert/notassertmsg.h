#pragma once
#include "assertmsg.h"


#define notassertmsg(expr, msg)    assertmsg(!(expr), (msg))

#define NOTASSERTMSG    notassertmsg


#define notassertmsg_dbgprt(expr, msg)    assertmsg_dbgprt(!(expr), (msg))

#define NOTASSERTMSG_DBGPRT    notassertmsg_dbgprt



