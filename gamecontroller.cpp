#include "gamecontroller.h"
#include <QRegularExpression>
#include <QTimer>
#include "playermanager.h"
#include "bombmanager.h"
#include "bomb.h"

GameController::GameController()
    : m_status(GameStatus::WAIT)
    , m_timer(new QTimer)
{
    m_timer->start(1000);
}

GameController::~GameController()
{
    delete m_timer;
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

void GameController::startGame()
{
    m_status = GameStatus::PLAYING;
    connect(m_timer, &QTimer::timeout, this, &GameController::__runGame);
    BombManager::getInstance().addBomb();
}

void GameController::__runGame()
{
    BombManager::getInstance().nextMoment();
}
