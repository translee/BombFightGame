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
#include <queue>
class QPainter;

class Player
{
public:
    explicit Player(int uid);
    inline int getNumber() const { return m_nNumber; }
    inline void setNumber(int n) { m_nNumber = n; }
    inline QPixmap getImage() const { return m_image; }
private:
    int m_nNumber;
    int m_nUid;
    QPixmap m_image;
    std::queue<int> m_qSkills;
};

#endif // PLAYER_H
