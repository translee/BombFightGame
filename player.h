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
class Player;
using PlayerPtr = std::shared_ptr<Player>;

class Player
{
    friend class PlayerManager;
public:
    explicit Player(int uid);
    QPixmap getImage() const;
private:
    int m_nNumber;
    int m_nUid;
    QPixmap m_image;
    std::deque<int> m_deqSkills;
    bool m_bDead;
};

#endif // PLAYER_H
