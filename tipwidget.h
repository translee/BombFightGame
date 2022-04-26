/**
 * @class   TipWidget
 * @author  github.com/translee
 * @date    2022/04/25
 * @brief   提示条
 * @note
 * @warning
*/

#ifndef TIPWIDGET_H
#define TIPWIDGET_H
#include <QWidget>

class TipWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TipWidget(QWidget *parent = nullptr);
    ~TipWidget();
protected:
    virtual void paintEvent(QPaintEvent*) override;
private:
    const QString m_tip;
    QFont* m_font;
    QTimer* m_timer;
    int m_nStrWidth;
    int m_nX;
    int m_nX2;
};

#endif // TIPWIDGET_H
