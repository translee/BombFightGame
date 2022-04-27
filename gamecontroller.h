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
class QTimer;

class GameController : public QObject
{
    Q_OBJECT
public:
    enum class GameStatus { WAIT, PLAYING, END};
    GameController();
    virtual ~GameController();
    GameStatus getGameStatus() const { return m_status; };
    void solveDanmu(int uid, QString s);
    void startGame();
private slots:
    void __runGame();
private:
    GameStatus m_status;
    QTimer* m_timer;
};

#endif // GAMECONTROLLER_H
