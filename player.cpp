#include "player.h"
#include <QPixmap>
#include <QPainter>
#include "gameutil.h"
#include "constDef.h"
using namespace constDef;

Player::Player()
    : m_nNumber(1)
    , m_image(new QPixmap)
{
}
