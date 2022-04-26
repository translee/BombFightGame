#include "tipwidget.h"
#include <QPainter>
#include <QTimer>

TipWidget::TipWidget(QWidget *parent)
    : QWidget{parent}
    , m_tip("指令：#1 加速 可以使炸弹加速前进 | "
            "#2 减速 可以使炸弹减速前进 | "
            "#3 爆炸范围 增加方圆半径2个玩家范围 | "
            "#4 何时爆炸 5s后爆炸 | "
            "#5	无中生弹 (时效性技能，当炸弹数量达到2个时,此技能失效) "
            "玩家可以自己安塞炸弹进入游戏中传递 | "
            "#6	正向	回归正常传递顺序 | "
            "#7	逆向	逆时针顺序传递 | ")
    , m_font(new QFont("微软雅黑", 10))
    , m_timer(new QTimer(this))
    , m_nStrWidth(QFontMetrics(*m_font).boundingRect(m_tip).width())
    , m_nX(10)
    , m_nX2(m_nX + m_nStrWidth + 50)
{
    m_timer->start(100);
    connect(m_timer, &QTimer::timeout, this, [this]{ this->update();});
}

TipWidget::~TipWidget()
{
    delete m_font;
}

void TipWidget::paintEvent(QPaintEvent*)
{
    if (m_nX <= -(10 + m_nStrWidth))
        m_nX = m_nX2 + m_nStrWidth + 50;
    if (m_nX2 <= -(10 + m_nStrWidth))
        m_nX2 = m_nX + m_nStrWidth + 50;
    m_nX -= 2;
    m_nX2 -= 2;
    QPainter painter(this);
    painter.setFont(*m_font);
    painter.drawText(m_nX, 20, m_tip);
    painter.drawText(m_nX2, 20, m_tip);
}
