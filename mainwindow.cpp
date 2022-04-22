#include "mainwindow.h"
#include <windows.h>
#include <QTimer>
#include "./ui_mainwindow.h"
#include "topwidget.h"
#include "bottomwidget.h"
#include "constDef.h"
using namespace constDef;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_topWidget(new TopWidget)
    , m_bottomWidget(new BottomWidget)
    , m_timer(new QTimer)
    , m_rawBytes(new char[BUF_SIZE])
{
    ui->setupUi(this);
    ui->mainLayout->addWidget(m_topWidget);
    ui->verticalLayout->addWidget(m_bottomWidget);
    ui->textBrowser->moveCursor(QTextCursor::MoveOperation::End);
    //创建命名管道,消息只能从客户端流向服务器,读写数据采用阻塞模式,字节流形式,超时值置为0表示采用默认的50毫秒
    h_pipe = ::CreateNamedPipe(L"\\\\.\\pipe\\MyPipe", PIPE_ACCESS_INBOUND,
        PIPE_READMODE_BYTE | PIPE_NOWAIT, PIPE_UNLIMITED_INSTANCES, BUF_SIZE, BUF_SIZE, 0, nullptr);
    //等待命名管道客户端连接
    ::ConnectNamedPipe(h_pipe, nullptr);
    m_timer->start(200);
    connect(m_timer, &QTimer::timeout, this, &MainWindow::updatePipe);
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

