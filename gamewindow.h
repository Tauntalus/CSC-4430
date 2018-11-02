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

    void initGame(int size, bool isCon);

    void pickPeg(int peg);

protected:
    void paintEvent(QPaintEvent *e);

private slots:
    void on_peg1Button_clicked();

    void on_peg2Button_clicked();

    void on_peg3Button_clicked();

    void on_returnButton_clicked();

private:
    Ui::gamewindow *ui;
    gameBoard game = gameBoard(5,false);

    bool secondPhase = false;

    //stores user's choices of pegs
    int firstPeg = 0;

    //location array, used in drawing
    int *locations;

    //total move count
    int moves = 0;

};

#endif // GAMEWINDOW_H
