#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_freeButton_clicked()
{
    gamewindow currentGame;
    currentGame.initGame(ui->numDiscBox->value(), false);

    hide();
    currentGame.exec();
    show();
}

void MainWindow::on_conButton_clicked()
{
    gamewindow currentGame;
    currentGame.initGame(ui->numDiscBox->value(), true);

    hide();
    currentGame.exec();
    show();
}
