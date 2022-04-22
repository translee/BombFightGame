#include "bottomwidget.h"
#include <QPainter>
#include "constDef.h"
using namespace constDef;

BottomWidget::BottomWidget(QWidget *parent)
    : QWidget{parent}
{

}

void BottomWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing);
    painter.setPen(QPen(BORDERRED, 2, Qt::SolidLine));
    painter.drawRect(SPACE, SPACE, BOTTOMRECTW, BOTTOMRECTH);
}
