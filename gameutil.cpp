#include "gameutil.h"
#include <QPainter>
#include <QPainterPath>
#include "constDef.h"
using namespace constDef;

QPoint GameUtil::__getPointByNum(int index)
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

QPoint GameUtil::getImagePointByNum(int index)
{
    QPoint pos = __getPointByNum(index);
    pos.rx() += SMALLSPACE;
    pos.ry() += SPACE;
    return pos;
}

QPixmap GameUtil::loadPixmap(const QString& path)
{
    QPixmap rawPixmap(path);
    if (rawPixmap.isNull())
        return QPixmap();

    QPixmap pixmap(PLAYERIMAGECIRCLED, PLAYERIMAGECIRCLED);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setRenderHints(QPainter::Antialiasing |
                           QPainter::SmoothPixmapTransform);
    QRect rect(0, 0, PLAYERIMAGECIRCLED, PLAYERIMAGECIRCLED);
    QPainterPath paintPath;
    paintPath.addEllipse(0, 0, PLAYERIMAGECIRCLED, PLAYERIMAGECIRCLED);
    painter.setClipPath(paintPath);
    painter.drawPixmap(rect, rawPixmap.scaled(PLAYERIMAGECIRCLED,
                       PLAYERIMAGECIRCLED, Qt::IgnoreAspectRatio,
                                       Qt::SmoothTransformation));
    return pixmap;
}
