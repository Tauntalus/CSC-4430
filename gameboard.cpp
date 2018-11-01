#include "gameboard.h"

//gameBoard - creates a gameboard with (size) discs
//The isCon flag determines if moves from peg1 to peg3 are allowed
gameBoard::gameBoard(int size, bool isCon)
{
    //for loop - push (size) discs in reverse order
    //eg - 5, 4, 3, 2, 1
    for(int i = size; i > 0 ; i--)
    {
        std::cout << "pushing " << i << "..." << std::endl;
        pegs[1].push(i);
    }

    m_size = size;
    m_isCon = isCon;

    return;
}

//getSize - returns the size variable
int gameBoard::getSize()
{
    return m_size;
}

//moveDisc - moves a disc from peg(start) to peg(end)
bool gameBoard::moveDisc(int start, int end)
{

    //first things first, check that the given inputs are in the appropriate range
    if(( (start < 1)||(start > 3) ) || ( (end < 1)||(end > 3) ))
    {
        std::cout << "You can't move discs to or from pegs that don't exist!" << std::endl;
        return false;
    }

    //first check if the game is constrained - does the game allow this?
    if(m_isCon && ((start + end == 4) && (start != end)))
    {
        std::cout << "This move is illegal - in constrained, you can only move discs to adjacent pegs!" << std::endl;
        return false;
    }

    //check that the move is legal - if not, quit here.
    if(pegs[start].top() > pegs[end].top())
    {
        std::cout << "This move is illegal - disc " << pegs[start].top() << " is bigger than disc " << pegs[end].top() << "." << std::endl;
        return false;
    }

    /*If we make it here, then:
    * A - the peg numbers are valid
    * B - the game type allows the move
    * C - the move is valid
    * Ergo, we allow the move.
    */

    std::cout << "Moving disc " << pegs[start].top() << "to peg " << end << "." << std::endl;
    pegs[end].push(pegs[start].top());
    pegs[start].pop();
    return true;
}

//gameIsWon - checks if peg 1 and peg 2 are empty - if this is true, then the tower has been moved entirely to peg 3 and the game has been won!
bool gameBoard::gameIsWon()
{
    return(pegs[1].empty() && pegs[2].empty());
}

//solveHanoi - the solve engine that solves the puzzle. This is the most efficient way to solve the Hanoi puzzle
void solveHanoi(int n, bool isCon)
{

}
