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
#include <windows.h>
#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class TopWidget;
class TipWidget;
class BottomWidget;
class QButtonGroup;
class GameController;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();
    void addText(const QString& s);
    void updatePipe();
private slots:
    void __sendDanmu();
    void __startGame();
private:
    Ui::MainWindow *ui;
    TopWidget* m_topWidget;
    TipWidget* m_tipWidget;
    BottomWidget* m_bottomWidget;
    QButtonGroup* m_bg;
    QTimer* m_timer;
    HANDLE h_pipe;
    char* m_rawBytes;
    GameController* m_control;
};

#endif // MAINWINDOW_H
