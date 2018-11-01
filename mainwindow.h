#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <gamewindow.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_freeButton_clicked();

    void on_conButton_clicked();

private:
    Ui::MainWindow *ui;

    gamewindow currentGame;
};

#endif // MAINWINDOW_H
