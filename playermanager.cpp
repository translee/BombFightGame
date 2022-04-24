#include "playermanager.h"
#include <memory>
#include <QPainter>
#include <QPixmap>
#include "gameutil.h"

PlayerManager &PlayerManager::getInstance()
{
    static PlayerManager m_sPlayerManager;
    return m_sPlayerManager;
}

PlayerManager::PlayerManager()
{
}

bool PlayerManager::addPlayer(int uid)
{
    int nSize = static_cast<int>(m_mpAllPlayer.size());
    if (m_mpAllPlayer.size() >= 10)
        return false;
    PlayerPtr pNewPl(new Player(uid));
    pNewPl->setNumber(nSize + 1);
    m_mpAllPlayer.insert({uid, pNewPl});
}

bool PlayerManager::ifPlayerExist(int uid) const
{
    return (m_mpAllPlayer.find(uid) != m_mpAllPlayer.end());
}

void PlayerManager::drawAllPlayerImage(QPainter *painter) const
{
    for (const auto& pl : m_mpAllPlayer)
    {
        QPoint pos = GameUtil::getImagePointByNum(pl.second->getNumber());
        painter->drawPixmap(pos, pl.second->getImage());
    }
}
