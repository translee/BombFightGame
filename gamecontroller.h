/**
 * @class   GameController
 * @author  github.com/translee
 * @date    2022/04/24
 * @brief   游戏控制器类
 * @note
 * @warning
*/

#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include <QObject>

class GameController
{
public:
    enum class GameStatus { WAIT, PLAYING, END};
    GameController();
    GameStatus getGameStatus() const { return m_status; };
    void solveDanmu(int uid, QString s);
private:
    GameStatus m_status;
};

#endif // GAMECONTROLLER_H
