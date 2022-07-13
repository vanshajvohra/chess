#include <iostream>
#include "chessPiece.h"
#include "king.h"
#include "globalEnums.h"
#include "cboard.h"

using namespace std;

King::~King()
{
    //cerr << "King destroyed" << endl;
}
bool King::isValidMove(int sRow, int sCol, int dRow, int dCol)
{
    //cout << "Not implemented" << endl;

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
    int iRow = dRow - sRow;
    int iCol = dCol - sCol;
    if (((iRow >= -1) && (iRow <= 1)) &&
        ((iCol >= -1) && (iCol <= 1)))
    {
        return true;
    }
    return false;
}
