#ifndef GAMEBOARD_H
#define GAMEBOARD_H

class gameBoard
{
public:
    //constructor
    gameBoard(int size, bool isCon);

    int getSize();

    void moveDisc(int start, int end);//move disc from peg(start) to peg(end)

    bool gameIsWon();

private:
    int size;
    bool isCon; //boolean to tell if the game is in Free or Constrained mode

    //peg stacks
    stack <int> pegs [3];
};


//gameBoard - creates a gameboard with (size) discs
//The isCon flag determines if moves from peg1 to peg3 are allowed
gameBoard::gameBoard(int size, bool isCon)
{
    //for loop - push (size) discs in reverse order
    //eg - 5, 4, 3, 2, 1
    for(int i = size; i > 0 ; i--)
    {
        std::cout << "pushing " + i + "..." << endl;
        peg1.push(i);
    }

    this->isCon = isCon;

    return;
}

//getSize - returns the size variable
gameBoard::getSize()
{
    return size;
}

//moveDisc - moves a disc from peg(start) to peg(end)
gameBoard::moveDisc(int start, int end)
{

    //first things first, check that the given inputs are in the appropriate range
    if(( (start > 1)||(start < 3) ) || ( (end < 1)||(end > 3) ))
    {
        std::cout << "You can't move discs to or from pegs that don't exist!" << endl;
        return;
    }

    //first check if the game is constrained - does the game allow this?
    if(isCon && ((start + end == 4) && (start != end)))
    {
        std::cout << "This move is illegal - in constrained, you can only move discs to adjacent pegs!" << endl;
        return;
    }

    //check that the move is legal - if not, quit here.
    if(pegs[start].top() > pegs[end].top())
    {
        std::cout << "This move is illegal - disc " + pegs[start].top() + " is bigger than disc " + pegs[end].top() + "." << endl;
        return;
    }

    /*If we make it here, then:
    * A - the peg numbers are valid
    * B - the game type allows the move
    * C - the move is valid
    * Ergo, we allow the move.
    */

    cout << "Moving disc " + pegs[start].top() + "to peg " + end + "." << endl;
    pegs[end].push(pegs[start].top());
    pegs[start].pop();
}

//gameIsWon - checks if peg 1 and peg 2 are empty - if this is true, then the tower has been moved entirely to peg 3 and the game has been won!
gameBoard::gameIsWon()
{
    return(pegs[1].empty() && pegs[2].empty());
}
#endif // GAMEBOARD_H
