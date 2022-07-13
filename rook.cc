#include <iostream>
#include "chessPiece.h"
#include "rook.h"
#include "globalEnums.h"
#include "cboard.h"

using namespace std;
/*
Rook::Rook(int c)
{
    ChessPiece::color = c;
}
*/
Rook::~Rook()
{
    //cerr << "Rook destroyed" << endl;
}
bool Rook::isValidMove(int sRow, int sCol, int dRow, int dCol)
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

    if (sRow == dRow)
    {

        int colOffSet = (dCol - sCol > 0) ? 1 : -1;
        for (int iCol = sCol + colOffSet; iCol != dCol; iCol = iCol + colOffSet)
        {
            if (cb->getChessPiece(sRow, iCol))
            {
                return false;
            }
        }
        return true;
    }
    else if (dCol == sCol)
    {

        int rowOffSet = (dRow - sRow > 0) ? 1 : -1;
        for (int iRow = sRow + rowOffSet; iRow != dRow; iRow = iRow + rowOffSet)
        {
            if (cb->getChessPiece(iRow, sCol))
            {
                return false;
            }
        }
        return true;
    }

    return false;
}
/*
int Rook::getTypeOfChessPiece()
{
    return GlobalEnums::CPType::Rook;
}
*/

/*
char Rook::getChessPieceDisplayChar()
{
    if (GlobalEnums::ChessColors::White == color)
    {
        return 'R';
    }
    else
    {
        return 'r';
    }
}
*/
