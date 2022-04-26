#include "gamecontroller.h"
#include <QRegularExpression>
#include "playermanager.h"

GameController::GameController()
    : m_status(GameStatus::WAIT)
{
}

void GameController::solveDanmu(int uid, QString s)
{
    if (GameStatus::WAIT == m_status)
    {
        if (PlayerManager::getInstance().ifPlayerExist(uid))
        {
            QRegularExpression re("#(\\d{1,2})");
            QRegularExpressionMatch match = re.match(s);
            if (match.hasMatch())
            {
                PlayerManager::getInstance().addSkill(uid,
                               match.captured(1).toInt());
            }
        }
        else if ("加入" == s)
            PlayerManager::getInstance().addPlayer(uid);
    }
    else if (GameStatus::PLAYING == m_status)
    {

    }
    else if (GameStatus::END == m_status)
    {
        return;
    }
    return;
}
