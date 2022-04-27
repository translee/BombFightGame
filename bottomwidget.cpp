#include "bottomwidget.h"
#include <QPainter>
#include <QTimer>
#include "bombmanager.h"
#include "constdef.h"
using namespace constDef;

BottomWidget::BottomWidget(QWidget *parent)
    : QWidget{parent}
    , m_timer(new QTimer(this))
{
    m_timer->start(200);
    connect(m_timer, &QTimer::timeout, this, [this]{ this->update();});
}

void BottomWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing);
    painter.setPen(QPen(BORDERRED, 2, Qt::SolidLine));
    painter.drawRect(SPACE, SPACE, BOTTOMRECTW, BOTTOMRECTH);
    BombManager::getInstance().drawAllBombTime(&painter);
}
