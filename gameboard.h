#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <iostream>
#include <stack>

class gameBoard
{
public:
    //constructor
    gameBoard() = delete; //no default constructor
    gameBoard(int size, bool isCon);

    int getSize();

    bool moveDisc(int start, int end);//move disc from peg(start) to peg(end). returns false if move is illegal - returns true if move is successful

    bool gameIsWon();

    void solveHanoi(int n, bool isCon); //not yet designed, will be implemented at a later date

private:
    int m_size;
    bool m_isCon; //boolean to tell if the game is in Free or Constrained mode

    //peg stacks
    std::stack <int> pegs[3];
};

#endif // GAMEBOARD_H
