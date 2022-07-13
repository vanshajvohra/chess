#include <iostream>
#include "chessPiece.h"
#include "pawn.h"
#include "globalEnums.h"
#include "cboard.h"

using namespace std;

/*
Pawn::Pawn(int c)
{
    color = c;
}
*/

Pawn::~Pawn()
{
    //cerr << "Pawn destroyed" << endl;
}
bool Pawn::isValidMove(int sRow, int sCol, int dRow, int dCol)
{

    //cout << "Pawn check from " << sRow << ":" << sCol " to " << dRow << ":" << dCol << endl;

    ChessPiece *cp1 = cb->getChessPiece(dRow, dCol);

    if (cp1 != nullptr)
    {
        // there is a piece, so this is valid if it
        // of different color and this is a diagnonal move
        int dcolor = cp1->getChessPieceColor();

        if (color == dcolor)
        {
            return false;
        }

        if (color == GlobalEnums::ChessColors::White)
        {
            if (sRow - dRow == 1 && std::abs(dCol - sCol) == 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (sRow - dRow == -1 && std::abs(dCol - sCol) == 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }

    // if destination has no piece, the Pawn can only move forward
    // 1 step or 2 steps if this is first move in same col
    if (dCol != sCol)
    {
        return false;
    }

    if (color == GlobalEnums::ChessColors::White)
    {
        if (sRow == 6)
        {
            if (sRow - dRow == 1 || sRow - dRow == 2)
            {
                if (sRow - dRow == 2)
                {
                    // check that there is no other piece in front as jump is not allowed
                    ChessPiece *cp = cb->getChessPiece(sRow - 1, sCol);
                    if (cp != nullptr)
                    {
                        return false;
                    }
                    else
                    {
                        cb->setEnpassant(sRow, sCol, dRow, dCol, GlobalEnums::ChessColors::White);
                        return true;
                    }
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (sRow - dRow != 1)
            {
                return false;
            }
        }
    }
    else
    {
        if (sRow == 1)
        {
            if (sRow - dRow == -1 || sRow - dRow == -2)
            {
                if (sRow - dRow == -2)
                {
                    ChessPiece *cp = cb->getChessPiece(sRow + 1, sCol);
                    if (cp != nullptr)
                    {
                        return false;
                    }
                    else
                    {
                        cb->setEnpassant(sRow, sCol, dRow, dCol, GlobalEnums::ChessColors::Black);
                        return true;
                    }
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (sRow - dRow != -1)
            {
                return false;
            }
        }
    }

    return true;
}
/*
int Pawn::getTypeOfChessPiece()
{
    return GlobalEnums::CPType::Pawn;
}
*/
/*
char Pawn::getChessPieceDisplayChar()
{
    if (GlobalEnums::ChessColors::White == color)
    {
        return 'P';
    }
    else
    {
        return 'p';
    }
}
*/
