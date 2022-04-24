#include "mainwindow.h"
#include <windows.h>
#include <QTimer>
#include <QButtonGroup>
#include <QPushButton>
#include "./ui_mainwindow.h"
#include "topwidget.h"
#include "bottomwidget.h"
#include "playermanager.h"
#include "gamecontroller.h"
#include "constDef.h"
using namespace constDef;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_topWidget(new TopWidget)
    , m_bottomWidget(new BottomWidget)
    , m_bg(new QButtonGroup)
    , m_timer(new QTimer)
    , m_rawBytes(new char[BUF_SIZE])
    , m_control(new GameController)
{
    ui->setupUi(this);
    ui->topLayout->addWidget(m_topWidget);
    ui->downLayout->addWidget(m_bottomWidget);
    m_bg->addButton(ui->radioButton_1, 0);
    m_bg->addButton(ui->radioButton_2, 1);
    m_bg->addButton(ui->radioButton_3, 2);
    m_bg->addButton(ui->radioButton_4, 3);
    ui->radioButton_1->setChecked(true);
    ui->textBrowser->moveCursor(QTextCursor::MoveOperation::End);
    this->setWindowTitle("炸弹大乱斗");
    this->setFixedSize(this->width(),this->height());
    // 创建命名管道,消息只能从客户端流向服务器,读写数据采用非阻塞模式,
    // 字节流形式,超时值置为0表示采用默认的50毫秒
    h_pipe = ::CreateNamedPipe(L"\\\\.\\pipe\\MyPipe", PIPE_ACCESS_INBOUND,
        PIPE_READMODE_BYTE | PIPE_NOWAIT, PIPE_UNLIMITED_INSTANCES,
                               BUF_SIZE, BUF_SIZE, 0, nullptr);
    //等待命名管道客户端连接
    ::ConnectNamedPipe(h_pipe, nullptr);
    m_timer->start(200);
    connect(m_timer, &QTimer::timeout, this, &MainWindow::updatePipe);
    connect(m_timer, &QTimer::timeout, this, [this]{
        update();
    });
    connect(ui->sendButton, &QPushButton::clicked, this,
            &MainWindow::__sendDanmu);
}

MainWindow::~MainWindow()
{
    delete ui;
    ::CloseHandle(h_pipe);
}

void MainWindow::addText(const QString &s)
{
    ui->textBrowser->append(s);
}

void MainWindow::updatePipe()
{
    DWORD num_rcv; //实际接收到的字节数
    if (::ReadFile(h_pipe, m_rawBytes, BUF_SIZE, &num_rcv, nullptr))
    {
        QString retStr = QString::fromUtf8(m_rawBytes);
        qDebug() << '\n' << retStr << '\n';
        this->addText(retStr);
        memset(m_rawBytes, 0, BUF_SIZE);
    }
}

void MainWindow::__sendDanmu()
{
    m_control->solveDanmu(m_bg->checkedId() + 123, ui->lineEdit->text());
}

