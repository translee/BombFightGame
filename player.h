/**
 * @class   Player
 * @author  github.com/translee
 * @date    2022/04/21
 * @brief   玩家基类
 * @note
 * @warning
*/

#ifndef PLAYER_H
#define PLAYER_H
class QPixmap;
class QPainter;

class Player
{
public:
    Player();
    int getNumber() const { return m_nNumber; }
private:
    int m_nNumber;
    QPixmap* m_image;
};

#endif // PLAYER_H
