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
    using PlayerPtr = std::shared_ptr<Player>;
    static PlayerManager& getInstance();
    PlayerManager(const PlayerManager&)=delete;
    PlayerManager& operator=(const PlayerManager&)=delete;
    ~PlayerManager()=default;
    bool addPlayer(int uid);
    inline size_t aliveSize() const { return m_mpAllPlayer.size(); }
    bool ifPlayerExist(int uid) const;
    void drawAllPlayerImage(QPainter* painter) const;
    //PlayerPtr getPlayerByUid(int uid);
private:
    PlayerManager();
private:
    std::map<int, PlayerPtr> m_mpAllPlayer;
};

#endif // PLAYERMANAGER_H
