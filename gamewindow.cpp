#include "gamewindow.h"
#include "ui_gamewindow.h"

gamewindow::gamewindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gamewindow)
{
    ui->setupUi(this);

}

gamewindow::~gamewindow()
{
    delete ui;
}

void gamewindow::initGameBoard(int size, bool isCon)
{
    game = gameBoard(size, isCon);
}


void gamewindow::selectPeg1()
{
    if(secondPhase)
    {
        if(!game.moveDisc(firstPeg,1))
        {
            ui->
        }
    }
    else
    {
        firstPeg = 1;
        secondPhase=true;
    }
}
