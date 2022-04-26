#include "topwidget.h"
#include <QPainter>
#include <QTimer>
#include "playermanager.h"
#include "gameutil.h"
#include "constDef.h"
using namespace constDef;

TopWidget::TopWidget(QWidget *parent)
    : QWidget{parent}
    , m_timer(new QTimer(this))
{
    m_timer->start(200);
    connect(m_timer, &QTimer::timeout, this, [this]{ this->update();});
}

void TopWidget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing);
    __drawStaticBorder(&painter);
    PlayerManager::getInstance().drawAllPlayerImage(&painter);
}

void TopWidget::__drawStaticBorder(QPainter *painter)
{
    painter->setPen(QPen(BORDERRED, 2, Qt::SolidLine));
    painter->drawRect(SPACE, SPACE, TOPRECTW, TOPRECTH);
    painter->setPen(QPen(BORDERRED, 1, Qt::SolidLine));
    QBrush greenBrush(SKILLGREEN);
    QBrush whiteBrush;
    int startX = SPACE * 2;
    int startY = SPACE * 2;
    for (int i = 0; i < LINENUM; i++)
    {
        int startNum = (i == 0) ? 1 : 10;
        int step = (i == 0) ? 1 : -1;
        for (int j = 0; j < COLNUM; j++)
        {
            painter->drawRect(startX, startY, PLAYERINFOW, PLAYERINFOH);
            painter->drawRect(startX, startY, PLAYERIMAGERECTW, PLAYERIMAGERECTH);
            painter->drawRect(startX + PLAYERIMAGERECTW, startY, BOMBRECTW,
                             BOMBRECTH);
            painter->drawRect(startX + PLAYERIMAGERECTW, startY + BOMBRECTH,
                             BOMBRECTW, BOMBRECTH);
            painter->drawEllipse(startX + SMALLSPACE, startY + SPACE,
                                PLAYERIMAGECIRCLED, PLAYERIMAGECIRCLED);
            QString str(QString::number(startNum + step * j) + "号");
            painter->drawText(startX + NUMTEXTX, startY + NUMTEXTY, str);
            int skillX = startX;
            int skillY = startY + PLAYERIMAGERECTH;
            painter->setBrush(greenBrush);
            for (int k = 0; k < 5; k++)
            {
                 painter->drawRect(skillX, skillY, SKILLRECTW, SKILLRECTH);
                 skillX += SKILLRECTW;
            }
            painter->setBrush(whiteBrush);
            startX += PLAYERINFOW + SPACE;
        }
        startX = SPACE * 2;
        startY += PLAYERINFOH + SPACE;
    }
}
