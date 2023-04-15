#include "common.h"

#include "armfunc.h"

extern u8 const * const gMsgTable[];

static char EWRAM_DATA sMsgString[0x1000] = {};
static int EWRAM_DATA sActiveMsg = 0;

char * DecodeMsg(int id)
{
    if (id == sActiveMsg)
        return sMsgString;

    DecodeString(gMsgTable[id], sMsgString);
    sActiveMsg = id;

    return sMsgString;
}
