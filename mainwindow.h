/**
 * @class   MainWindow
 * @author  github.com/translee
 * @date    2022/04/19
 * @brief   程序主窗口
 * @note
 * @warning
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <string>
#include <windows.h>
#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class TopWidget;
class BottomWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addText(const QString& s);
    void updatePipe();
private:
    Ui::MainWindow *ui;
    TopWidget* m_topWidget;
    BottomWidget* m_bottomWidget;
    QTimer* m_timer;
    HANDLE h_pipe;
    char* m_rawBytes;
};

#endif // MAINWINDOW_H
