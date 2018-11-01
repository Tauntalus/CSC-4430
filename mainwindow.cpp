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
    currentGame.initGameBoard(ui->numDiscBox->value(), false);

    currentGame.show();
    hide();
}

void MainWindow::on_conButton_clicked()
{
    currentGame.initGameBoard(ui->numDiscBox->value(), true);

    currentGame.show();
    hide();
}
