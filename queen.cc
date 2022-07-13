#include <iostream>
#include "chessPiece.h"
#include "queen.h"
#include "globalEnums.h"
#include "cboard.h"

using namespace std;

/*
Queen::Queen(int c)
{
    color = c;
}
*/

Queen::~Queen()
{
    //cerr << "Queen destroyed" << endl;
}
bool Queen::isValidMove(int sRow, int sCol, int dRow, int dCol)
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

    // check no pieces are there between s and d
    // Moving N-S

    if (sCol == dCol)
    {
        int offset = (dRow - sRow > 0) ? 1 : -1;
        for (int i = sRow + offset; i != dRow; i = i + offset)
        {
            if (cb->getChessPiece(i, sCol))
            {
                return false;
            }
        }
        return true;
    }

    // Moving E-W

    if (sRow == dRow)
    {
        int offset = (dCol - sCol > 0) ? 1 : -1;
        for (int i = sCol + offset; i != dCol; i = i + offset)
        {
            if (cb->getChessPiece(sRow, i))
            {
                return false;
            }
        }
        return true;
    }
    // Moving Right Diagonal

    // Moving Left Diagonal

    if ((dCol - sCol == dRow - sRow) || (dCol - sCol == sRow - dRow))
    {
        // Make sure that all invervening squares are empty
        int rowOffset = (dRow - sRow > 0) ? 1 : -1;
        int colOffset = (dCol - sCol > 0) ? 1 : -1;
        int iRow;
        int iCol;
        for (iRow = sRow + rowOffset, iCol = sCol + colOffset;
             iRow != dRow;
             iRow = iRow + rowOffset, iCol = iCol + colOffset)
        {
            if (cb->getChessPiece(iRow, iCol))
            {
                return false;
            }
        }
        return true;
    }
    return false;
}
/*
int Queen::getTypeOfChessPiece()
{
    return GlobalEnums::CPType::Queen;
}
*/
/*
char Queen::getChessPieceDisplayChar()
{
    if (GlobalEnums::ChessColors::White == color)
    {
        return 'Q';
    }
    else
    {
        return 'q';
    }
}
*/
