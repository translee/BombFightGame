#include "bomb.h"
#include "gameutil.h"
#include "constdef.h"
#include "playermanager.h"
using namespace constDef;

Bomb::Bomb()
    : m_image(GameUtil::loadBombPixmap())
    , m_nPosNum(1)
    , m_nMoveOnceByTimes(1)
    , m_nCurProcess(0)
    , m_nExplode(3)
{
}

void Bomb::moveNext()
{
    m_nCurProcess++;
    if (m_nCurProcess == m_nMoveOnceByTimes)
    {
        m_nCurProcess = 0;
        std::set<int> pos = PlayerManager::getInstance().getAlivePos();
        if (1 == pos.size())
            return;
        auto it = pos.find(m_nPosNum);
        it++;
        if (it == pos.end())
            it = pos.begin();
        m_nPosNum = *it;
    }
    m_nExplode--;
    return;
}

QPoint Bomb::getBombImagePoint() const
{
    QPoint pos = GameUtil::getBasePtByNum(m_nPosNum);
    pos.rx() += PLAYERIMAGERECTW;
    return pos;
}

QPoint Bomb::getBombTextPoint() const
{
    QPoint pos = getBombImagePoint();
    pos.rx() += 10;
    pos.ry() += BOMBRECTH + 35;
    return pos;
}
