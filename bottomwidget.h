/**
 * @class   BottomWidget
 * @author  github.com/translee
 * @date    2022/04/24
 * @brief   信息显示区
 * @note
 * @warning
*/

#ifndef BOTTOMWIDGET_H
#define BOTTOMWIDGET_H
#include <QWidget>

class BottomWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BottomWidget(QWidget *parent = nullptr);
    virtual void paintEvent(QPaintEvent*) override;
};

#endif // BOTTOMWIDGET_H
