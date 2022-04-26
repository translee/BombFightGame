/**
 * @class   Player
 * @author  github.com/translee
 * @date    2022/04/21
 * @brief   玩家类
 * @note
 * @warning
*/

#ifndef PLAYER_H
#define PLAYER_H
#include <QPixmap>
#include <deque>
class QPainter;

class Player
{
    friend class PlayerManager;
public:
    explicit Player(int uid);
private:
    int m_nNumber;
    int m_nUid;
    QPixmap m_image;
    std::deque<int> m_deqSkills;
};

#endif // PLAYER_H
