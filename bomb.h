/**
 * @class   Bomb
 * @author  github.com/translee
 * @date    2022/04/26
 * @brief   炸弹
 * @note
 * @warning
*/

#ifndef BOMB_H
#define BOMB_H
#include <QPixmap>
class Bomb;
using BombPtr = std::shared_ptr<Bomb>;

class Bomb
{
    friend class BombManager;
public:
    Bomb();
    void moveNext();
    QPoint getBombImagePoint() const;
    QPoint getBombTextPoint() const;
private:
    QPixmap m_image;
    int m_nPosNum;
    // 几次刷新移动一次(与速度成反比)
    int m_nMoveOnceByTimes;
    // 刷新次数
    int m_nCurProcess;
    int m_nExplode;
};

#endif // BOMB_H
