/**
 * @class   GameUtil
 * @author  github.com/translee
 * @date    2022/04/19
 * @brief   工具类
 * @note
 * @warning 静态成员方法
*/

#ifndef GAMEUTIL_H
#define GAMEUTIL_H
#include <QPoint>
#include <QPixmap>

class GameUtil
{
public:
    static QPoint getBasePtByNum(int index);
    static QPoint getImagePtByBasePt(const QPoint& base);
    static QPoint getSkillPtByBasePt(const QPoint& base);
    static QPixmap loadPixmap(const QString& path);
};

#endif // GAMEUTIL_H
