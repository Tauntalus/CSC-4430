#include "gamewindow.h"
#include "ui_gamewindow.h"

gamewindow::gamewindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gamewindow)
{
    ui->setupUi(this);

    //data clearing
    secondPhase=false;
    firstPeg=0;
    moves=0;

    //text clearing
    ui->errorLabel->setVisible(false);
    ui->infoLabel->setText("Which disc would you like to move?");
    ui->moveCounter->setText(QString("Moves: %1").arg(moves)); //creates a string that is of the form "Moves: X"
}

gamewindow::~gamewindow()
{
    delete ui;
}

void gamewindow::initGameBoard(int size, bool isCon)
{
    game = gameBoard(size, isCon);
}

//pickPeg - checks the state of the game, and then either makes a move or stores the picked peg for future use.
void gamewindow::pickPeg(int peg)
{
    ui->errorLabel->setVisible(false);
    if(secondPhase)
    {
        if(!game.moveDisc(firstPeg,peg))
        {
            ui->errorLabel->setVisible(true);
        }

        moves++;
        ui->moveCounter->setText(QString("Moves: %1").arg(moves));

        secondPhase= false;
        ui->infoLabel->setText("Which disc would you like to move?");
    }
    else
    {
        firstPeg = peg;
        secondPhase=true;

        ui->infoLabel->setText("Which peg would you like to move the disc to?");
    }
}
void gamewindow::on_peg1Button_clicked()
{
    pickPeg(0); //start at 0 for the sake of less ugly code
}

void gamewindow::on_peg2Button_clicked()
{
    pickPeg(1);
}

void gamewindow::on_peg3Button_clicked()
{
    pickPeg(2);
}
