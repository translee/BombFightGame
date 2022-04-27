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
#include <set>
#include <QString>
#include "player.h"

class PlayerManager final
{
public:
    static PlayerManager& getInstance();
    PlayerManager(const PlayerManager&)=delete;
    PlayerManager& operator=(const PlayerManager&)=delete;
    ~PlayerManager()=default;
    bool addPlayer(int uid);
    bool addSkill(int uid, int skill);
    bool ifPlayerExist(int uid) const;
    void drawAllPlayerImage(QPainter* painter) const;
    std::set<int> getAlivePos() const;
    void killPlayer(int i);
private:
    PlayerManager()=default;
private:
    std::map<int, PlayerPtr> m_mpAllPlayer;
    std::map<int, int> m_mpPosToUid;
};

#endif // PLAYERMANAGER_H
