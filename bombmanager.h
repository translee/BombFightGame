/**
 * @class   BombManager
 * @author  github.com/translee
 * @date    2022/04/26
 * @brief   炸弹管理类
 * @note
 * @warning 单例类
*/

#ifndef BOMBMANAGER_H
#define BOMBMANAGER_H
#include "bomb.h"
#include <set>

class BombManager
{
public:
    static BombManager& getInstance();
    BombManager(const BombManager&)=delete;
    BombManager& operator=(const BombManager&)=delete;
    ~BombManager()=default;
    bool addBomb();
    void drawAllBombImage(QPainter* painter);
    void drawAllBombTime(QPainter* painter);
    bool nextMoment();
private:
    BombManager()=default;
private:
    std::vector<BombPtr> m_vecBombs;
    std::set<int> m_setBombPos;
};

#endif // BOMBMANAGER_H
