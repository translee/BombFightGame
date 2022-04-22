/**
 * @class   PlayerManager
 * @author  github.com/translee
 * @date    2022/04/21
 * @brief   玩家管理类
 * @note
 * @warning 单例类
*/

#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H
#include <array>
#include <set>
#include <QString>
#include "player.h"

struct playerComp {
    bool operator() (const Player* lhs, const Player* rhs) const{
        return (*lhs).getNumber() < (*rhs).getNumber();
    }
};

class PlayerManager final
{
public:
    static PlayerManager& getInstance();
    PlayerManager(const PlayerManager&)=delete;
    PlayerManager& operator=(const PlayerManager&)=delete;
    //~PlayerManager();
    void addPlayer(const QString& s);
private:
    PlayerManager();
private:
    std::array<Player*, 10> m_arrAllPlayer;
    std::set<Player*, playerComp> m_setAlivePlayer;
};

#endif // PLAYERMANAGER_H
