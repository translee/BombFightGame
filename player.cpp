#include "player.h"
#include <QPixmap>
#include <QPainter>
#include <QPainterPath>
#include "gameutil.h"
#include "constdef.h"
using namespace constDef;

Player::Player(int uid)
    : m_nNumber(1)
    , m_nUid(uid)
    , m_image(GameUtil::loadPixmap(":Image/userImage/" + QString::number(uid) + ".png"))
    , m_deqSkills()
    , m_bDead(false)
{
}

QPixmap Player::getImage() const
{
    if (m_bDead)
    {
        QImage image = m_image.toImage().convertToFormat(
                    QImage::Format_Grayscale8, Qt::AutoColor);
        QImage grayImage(m_image.width(), m_image.height(), QImage::Format_RGB32);
        grayImage.fill(QColor(255, 240, 240).rgb());
        QPainter painter(&grayImage);
        QPainterPath paintPath;
        paintPath.addEllipse(0, 0, m_image.width(), m_image.height());
        painter.setClipPath(paintPath);
        painter.drawImage(0, 0, image);

        QPixmap pixmap;
        pixmap.convertFromImage(grayImage);
        return pixmap;
    }
    else
        return m_image;
}
