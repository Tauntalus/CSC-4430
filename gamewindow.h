#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QDialog>
#include "gameboard.h"

namespace Ui {
class gamewindow;
}

class gamewindow : public QDialog
{
    Q_OBJECT

public:
    explicit gamewindow(QWidget *parent = nullptr);
    ~gamewindow();

    void initGameBoard(int size, bool isCon);
    void pickPeg(int peg, bool secondPhase);

private slots:
    void selectPeg1();

private:
    Ui::gamewindow *ui;
    gameBoard game = gameBoard(5,false);

    bool secondPhase = false;
    int locations[10]; //used for drawing pegs accurately

    //stores user's choices of pegs
    int firstPeg;
};

#endif // GAMEWINDOW_H
