#include <QPainter>
#include "gamewindow.h"
#include "ui_gamewindow.h"

gamewindow::gamewindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gamewindow)
{
    ui->setupUi(this);
    ui->errorLabel->setVisible(false); //manually set error message invisible - no way in Qt Creator proper
}

gamewindow::~gamewindow()
{
    delete ui;
}

//initGameBoard - initializes the gameboard with the passed parameters
void gamewindow::initGame(int size, bool isCon)
{
    game = gameBoard(size, isCon);
    locations = new int[size];

    //initialize array values
    for(int i = 0; i < size; i++)
        locations[i] = 0;

    update();
}

//drawGame - draws the gameboard on the widget
void gamewindow::paintEvent(QPaintEvent *e)
{
    //define drawing constants
    const int PEG_WIDTH = 20;
    const int PEG_HEIGHT = 275;
    const int PEG_X = 100;
    const int PEG_Y = 150;
    const int PEG_SPACER = 250;

    const int DISC_RADIUS = 80;
    const int DISC_HEIGHT = 25;
    const int DISC_X = PEG_X + (PEG_WIDTH / 2);
    const int DISC_Y = PEG_Y + PEG_HEIGHT - DISC_HEIGHT;

    int size = game.getSize();

    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    //setup default pen
    QPainter painter(this);
    painter.setPen(Qt::black);

    //draw pegs
    painter.setBrush(Qt::darkYellow);
    painter.drawRect(PEG_X, PEG_Y, PEG_WIDTH, PEG_HEIGHT);
    painter.drawRect(PEG_X + PEG_SPACER, PEG_Y, PEG_WIDTH, PEG_HEIGHT);
    painter.drawRect(PEG_X + 2 * PEG_SPACER, PEG_Y, PEG_WIDTH, PEG_HEIGHT);


    //draw loop for discs
    painter.setBrush(Qt::cyan);
    for(int i = size - 1; i >= 0; i--)
    {
        int newRadius = int(((double(i) + 1) / size) * DISC_RADIUS) + (PEG_WIDTH / 2); //calculate new radius based on disc size

        //switch that makes sure discs are drawn in the appropriate places, at the appropriate heights
        switch(locations[i])
        {
        case 0:
            painter.drawRect((DISC_X - newRadius) + (0 * PEG_SPACER), DISC_Y - (count0 * DISC_HEIGHT), 2 * newRadius, DISC_HEIGHT);
            count0++;
            break;

        case 1:
            painter.drawRect((DISC_X - newRadius) + (1 * PEG_SPACER), DISC_Y - (count1 * DISC_HEIGHT), 2 * newRadius, DISC_HEIGHT);
            count1++;
            break;

        case 2:
            painter.drawRect((DISC_X - newRadius) + (2 * PEG_SPACER), DISC_Y - (count2 * DISC_HEIGHT), 2 * newRadius, DISC_HEIGHT);
            count2++;
            break;

        default:
            break;
        }

    }

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

            secondPhase= false;
            ui->infoLabel->setText("Which disc would you like to move?");
            return;
        }

        locations[game.peekAtPeg(peg)] = peg; //update pegs locations
        moves++;

        ui->moveCounter->setText(QString("Moves: %1").arg(moves));
        update();

        //after move check if the game is won
        if(game.gameIsWon())
            {
                ui->infoLabel->setText(QString("Congratulations! You won in %1 moves!").arg(moves));

                //disable UI buttons for moving
                ui->peg1Button->setEnabled(false);
                ui->peg2Button->setEnabled(false);
                ui->peg3Button->setEnabled(false);

                return;
            }

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

//drawBoard -
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

void gamewindow::on_returnButton_clicked()
{
    delete [] locations; //deallocate dynamic memory
    close();
}
