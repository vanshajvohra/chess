#include <iostream>
#include "chessPiece.h"
#include "bishop.h"
#include "globalEnums.h"
#include "cboard.h"

using namespace std;

/*
Bishop::Bishop(int c)
{
    color = c;
}
*/

Bishop::~Bishop()
{
    //cerr << "Bishop destroyed" << endl;
}
bool Bishop::isValidMove(int sRow, int sCol, int dRow, int dCol)
{
    // cout << "Bishop Valid Move check " << endl;

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

    if ((dCol - sCol == dRow - sRow) || (dCol - sCol == sRow - dRow))
    {
        // Make sure that all invervening squares are empty
        int rowOffSet = (dRow - sRow > 0) ? 1 : -1;
        int colOffSet = (dCol - sCol > 0) ? 1 : -1;
        int iRow;
        int iCol;
        for (iRow = sRow + rowOffSet, iCol = sCol + colOffSet;
             iRow != dRow;
             iRow = iRow + rowOffSet, iCol = iCol + colOffSet)
        {
            if (cb->getChessPiece(iRow, iCol))
            {
                return false;
            }
        }
        return true;
    }

    // cout << "Bishop returning false " << endl;

    return false;
}
/*
int Bishop::getTypeOfChessPiece()
{
    return GlobalEnums::CPType::Bishop;
}
*/

char Bishop::getChessPieceDisplayChar()
{
    if (GlobalEnums::CPType::WBishop == this->cptype)

    {
        return 'B';
    }
    else
    {
        return 'b';
    }
}
