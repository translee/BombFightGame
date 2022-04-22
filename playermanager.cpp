#include "playermanager.h"

PlayerManager &PlayerManager::getInstance()
{
    static PlayerManager m_sPlayerManager;
    return m_sPlayerManager;
}

PlayerManager::PlayerManager()
{

}

void PlayerManager::addPlayer(const QString& s)
{
    // loadImage

}
