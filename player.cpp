#include "player.h"
#include <QPixmap>
#include <QPainter>
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
        return QPixmap();
    else
        return m_image;
}
