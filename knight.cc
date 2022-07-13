#include <iostream>
#include "chessPiece.h"
#include "knight.h"
#include "globalEnums.h"
#include "cboard.h"
using namespace std;

/*
Knight::Knight(int c)
{
    color = c;
}
*/

Knight::~Knight()
{
    //cerr << "Knight destroyed" << endl;
}
bool Knight::isValidMove(int sRow, int sCol, int dRow, int dCol)
{
    // cout << "Knight valid move " << sRow << " " << sCol << " " << dRow << " " << dCol << endl;

    ChessPiece *cp1 = cb->getChessPiece(dRow, dCol);

    if (cp1 != nullptr)
    {
        // there is a piece, has to be of different color
        int dcolor = cp1->getChessPieceColor();

        if (color == dcolor)
        {
            return false;
        }
    }

    if ((sCol == dCol + 1) || (sCol == dCol - 1))
    {
        if ((sRow == dRow + 2) || (sRow == dRow - 2))
        {
            return true;
        }
    }
    if ((sCol == dCol + 2) || (sCol == dCol - 2))
    {
        if ((sRow == dRow + 1) || (sRow == dRow - 1))
        {
            return true;
        }
    }
    //cout << "here false kinght" << endl;
    return false;
}
