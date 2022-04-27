#include "playermanager.h"
#include <memory>
#include <QPainter>
#include <QPixmap>
#include "gameutil.h"
#include "constdef.h"
using namespace constDef;

PlayerManager &PlayerManager::getInstance()
{
    static PlayerManager m_sPlayerManager;
    return m_sPlayerManager;
}

bool PlayerManager::addPlayer(int uid)
{
    int nSize = static_cast<int>(m_mpAllPlayer.size());
    if (m_mpAllPlayer.size() >= 10)
        return false;
    PlayerPtr pNewPl(new Player(uid));
    pNewPl->m_nNumber = nSize + 1;
    m_mpPosToUid[nSize + 1] = uid;
    m_mpAllPlayer.insert({uid, pNewPl});
    return true;
}

bool PlayerManager::addSkill(int uid, int skill)
{
    if (m_mpAllPlayer[uid]->m_deqSkills.size() < 5)
    {
        m_mpAllPlayer[uid]->m_deqSkills.emplace_back(skill);
        return true;
    }
    return false;
}

bool PlayerManager::ifPlayerExist(int uid) const
{
    return (m_mpAllPlayer.find(uid) != m_mpAllPlayer.end());
}

void PlayerManager::drawAllPlayerImage(QPainter *painter) const
{
    for (const auto& pl : m_mpAllPlayer)
    {
        QPoint basePt = GameUtil::getBasePtByNum(pl.second->m_nNumber);
        QPoint imagePos = GameUtil::getImagePtByBasePt(basePt);
        QPoint skillPos = GameUtil::getSkillPtByBasePt(basePt);
        painter->drawPixmap(imagePos, pl.second->getImage());
        painter->setPen(QPen(Qt::black));
        for (const auto& skill : pl.second->m_deqSkills)
        {
            QString str("#" + QString::number(skill));
            painter->drawText(skillPos, str);
            skillPos.rx() += SKILLRECTW;
        }
    }
}

std::set<int> PlayerManager::getAlivePos() const
{
    std::set<int> s;
    for (const auto& pl : m_mpAllPlayer)
    {
        if (!pl.second->m_bDead)
            s.insert(pl.second->m_nNumber);
    }
    return s;
}

void PlayerManager::killPlayer(int i)
{
    m_mpAllPlayer[m_mpPosToUid[i]]->m_bDead = true;
}
