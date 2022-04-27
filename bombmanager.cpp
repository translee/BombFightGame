#include "bombmanager.h"
#include <QPainter>
#include "playermanager.h"
#include "gameutil.h"

BombManager &BombManager::getInstance()
{
    static BombManager s_bombManager;
    return s_bombManager;
}

bool BombManager::addBomb()
{
    if (m_vecBombs.size() == 4)
        return false;
    std::set<int> s = PlayerManager::getInstance().getAlivePos();
    BombPtr newBomb(new Bomb());
    newBomb->m_nPosNum = *s.begin();
    m_vecBombs.push_back(newBomb);
    return true;
}

void BombManager::drawAllBombImage(QPainter *painter)
{
    painter->setFont(QFont("微软雅黑", 10));
    for (size_t i = 0; i < m_vecBombs.size(); i++)
    {
        BombPtr bm = m_vecBombs[i];
        painter->drawPixmap(bm->getBombImagePoint(), bm->m_image);
        painter->drawText(bm->getBombTextPoint(), QString::number(i+1) + "号弹");
    }
}

void BombManager::drawAllBombTime(QPainter *painter)
{
    for (size_t i = 0; i < m_vecBombs.size(); i++)
    {
        BombPtr bm = m_vecBombs[i];
        painter->drawText(100, 100, "炸弹爆炸倒计时：" +
                          QString::number(bm->m_nExplode));
    }
}

void BombManager::nextMoment()
{
    for (const auto& bm : m_vecBombs)
    {
        bm->moveNext();
        if (0 == bm->m_nExplode)
        {
            PlayerManager::getInstance().killPlayer(bm->m_nPosNum);
            bm->m_nExplode = 10;
        }
    }
}
