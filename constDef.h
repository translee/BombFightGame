/**
 * @class
 * @author  github.com/translee
 * @date    2022/04/19
 * @brief   常量统一定义
 * @note
 * @warning
*/

#ifndef CONSTDEF_H
#define CONSTDEF_H
#include <QColor>
namespace constDef {

// 通用
constexpr int SPACE = 10;
constexpr int SMALLSPACE = 4;

// 玩家
constexpr int BOMBRECTW = 60;
constexpr int BOMBRECTH = BOMBRECTW;
constexpr int PLAYERIMAGERECTW = 80;
constexpr int PLAYERIMAGERECTH = 2 * BOMBRECTH;
constexpr int PLAYERIMAGECIRCLED = PLAYERIMAGERECTW - SMALLSPACE * 2;
constexpr int PLAYERIMAGECIRCLER = PLAYERIMAGECIRCLED / 2;
constexpr int PLAYERINFOW = PLAYERIMAGERECTW + BOMBRECTW;
constexpr int SKILLRECTW = PLAYERINFOW / 5;
constexpr int SKILLRECTH = SKILLRECTW;
constexpr int PLAYERINFOH = PLAYERIMAGERECTH + SKILLRECTH;
constexpr int PLAYERSPACE = 10;

// 编号
constexpr int NUMTEXTX = 30;
constexpr int NUMTEXTY = PLAYERIMAGERECTH - SPACE;

// 上部窗口
constexpr int LINENUM = 2;
constexpr int COLNUM = 5;
constexpr int TOPRECTW = SPACE * (COLNUM + 1) + COLNUM * PLAYERINFOW;
constexpr int TOPRECTH = SPACE * (LINENUM + 1) + LINENUM * PLAYERINFOH;

// 底部窗口
constexpr int BOTTOMRECTW = TOPRECTW;
constexpr int BOTTOMRECTH = 220;

// 进程通信
constexpr int BUF_SIZE = 1024;

// 颜色
constexpr QColor BORDERRED(217, 0, 27);
constexpr QColor SKILLGREEN(149, 242, 4);

}

#endif // CONSTDEF_H
