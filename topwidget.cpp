#include "topwidget.h"
#include <QPainter>
#include "constDef.h"
using namespace constDef;

TopWidget::TopWidget(QWidget *parent)
    : QWidget{parent}
{
}

void TopWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing);
    painter.setPen(QPen(BORDERRED, 2, Qt::SolidLine));
    painter.drawRect(SPACE, SPACE, TOPRECTW, TOPRECTH);
    painter.setPen(QPen(BORDERRED, 1, Qt::SolidLine));
    QBrush greenBrush(SKILLGREEN);
    QBrush whiteBrush;
    int startX = SPACE * 2;
    int startY = SPACE * 2;
    for (int i = 0; i < LINENUM; i++)
    {
        for (int j = 0; j < COLNUM; j++)
        {
            painter.drawRect(startX, startY, PLAYERINFOW, PLAYERINFOH);
            painter.drawRect(startX, startY, PLAYERIMAGERECTW, PLAYERIMAGERECTH);
            painter.drawRect(startX + PLAYERIMAGERECTW, startY, BOMBRECTW,
                             BOMBRECTH);
            painter.drawRect(startX + PLAYERIMAGERECTW, startY + BOMBRECTH,
                             BOMBRECTW, BOMBRECTH);
            painter.drawEllipse(startX + SMALLSPACE, startY + SPACE,
                                PLAYERIMAGECIRCLED, PLAYERIMAGECIRCLED);
            painter.drawText(startX + NUMTEXTX, startY + NUMTEXTY, "1号");
            int skillX = startX;
            int skillY = startY + PLAYERIMAGERECTH;
            painter.setBrush(greenBrush);
            for (int k = 0; k < 5; k++)
            {
                 painter.drawRect(skillX, skillY, SKILLRECTW, SKILLRECTH);
                 skillX += SKILLRECTW;
            }
            painter.setBrush(whiteBrush);
            startX += PLAYERINFOW + SPACE;
        }
        startX = SPACE * 2;
        startY += PLAYERINFOH + SPACE;
    }
}
