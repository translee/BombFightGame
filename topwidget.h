/**
 * @class   TopWidget
 * @author  github.com/translee
 * @date    2022/04/19
 * @brief   游戏显示区
 * @note
 * @warning
*/

#ifndef DISPLAYWIDGET_H
#define DISPLAYWIDGET_H
#include <QWidget>
class QPainter;

class TopWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TopWidget(QWidget *parent = nullptr);
    virtual void paintEvent(QPaintEvent*) override;
private:
    void __drawStaticBorder(QPainter* painter);
};

#endif // DISPLAYWIDGET_H
