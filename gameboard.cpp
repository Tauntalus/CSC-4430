#include "gameboard.h"

//gameBoard - creates a gameboard with (size) discs
//The isCon flag determines if moves between non-adjacent pegs are allowed
gameBoard::gameBoard(int size, bool isCon)
{
    //for loop - push (size) discs in reverse order
    //eg - 5, 4, 3, 2, 1
    for(int i = size; i > 0 ; i--)
    {
        std::cout << "pushing " << i << "..." << std::endl;
        pegs[0].push(i);
    }
    std::cout << "Done!" << std::endl;

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

    //start is end, shouldn't count as a move.
    if(start == end)
    {
        std::cout << "You can't move a disc to the same peg you put it on." << std::endl;
        return false;
    }

    //either start or end is not a valid peg number (0, 1, 2)
    if(( (start < 0) || (start > 2) ) || ( (end < 0) || (end > 2) ))
    {
        std::cout << "You can't move discs to or from pegs that don't exist!" << std::endl;
        return false;
    }

    //constrained check - cannot move between non-adjacent pegs
    if(m_isCon && (abs(end - start) > 1))
    {
        std::cout << "This move is illegal - in constrained, you can only move discs to adjacent pegs!" << std::endl;
        return false;
    }

    //existence check - cannot move a nonexistent disc
    if(pegs[start].empty())
    {
        std::cout << "This move is illegal - you can't move from an empty peg!" << std::endl;
        return false;
    }

    //shortcut the process, if end is empty then move and be done - causes errors otherwise
    if(pegs[end].empty())
    {
        std::cout << "Moving disc " << pegs[start].top() << " to peg " << end << "." << std::endl;
        pegs[end].push(pegs[start].top());
        pegs[start].pop();
        return true;
    }

    //verified that the move is not blocked by the base rules. Now to check validity.

    /*KNOWN FACTS BY HERE
     * start and end are different
     * start and end are valid peg numbers
     * constrained rules don't block the move
     * peg[start] and peg[end] are not empty
     */

    //size check - make sure start disc is not bigger than end disc
    if(pegs[start].top() > pegs[end].top())
    {
        std::cout << "This move is illegal - disc " << pegs[start].top() << " is bigger than disc " << pegs[end].top() << "." << std::endl;
        return false;
    }

    //valid move between two non-empty pegs
    std::cout << "Moving disc " << pegs[start].top() << " to peg " << end << "." << std::endl;
    pegs[end].push(pegs[start].top());
    pegs[start].pop();
    return true;
}

//gameIsWon - checks if peg 1 and peg 2 are empty - if this is true, then the tower has been moved entirely to peg 3 and the game has been won!
bool gameBoard::gameIsWon()
{
    return(pegs[0].empty() && pegs[1].empty());
}

//solveHanoi - the solve engine that solves the puzzle. This is the most efficient way to solve the Hanoi puzzle
void solveHanoi(int n, bool isCon)
{
    //TODO
}
