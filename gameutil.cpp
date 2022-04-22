#include "gameutil.h"
#include "constDef.h"
using namespace constDef;

QPoint GameUtil::getPointByNumber(int index)
{
    int x = SPACE * 2;
    int y = SPACE * 2;
    if (index <= 5)
    {
        x += (index - 1) * (SPACE + PLAYERINFOW);
    }
    else
    {
        y += PLAYERINFOH + SPACE;
        x += (10 - index) * (SPACE + PLAYERINFOW);
    }
    return QPoint(x, y);
}
