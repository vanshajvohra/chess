#include <iostream>

#include "chessMoves.h"
#include "cboard.h"
#include "globalEnums.h"

using namespace std;

void ChessMoves::attachBoard(CBoard *b)
{
    cb = b;
}

bool ChessMoves::isValidMove(int sr, int sc, int dr, int dc)
{

    // basic checks
    // check if source and destinations are within the board

    if (sr > 7 || dr > 7)
    {
        return false;
    }

    /*
    if ((sr == 0 && sc == 0) || (sr == 0 && sc == 1))
    {
        return false;
    }
    if ((dr == 0 && dc == 0) || (dr == 0 && dc == 1))
    {
        return false;
    }
*/

    if (sc == 0 || sc == 1 || dc == 0 || dc == 1)
    {
        return false;
    }

    // check that the source has a valid piece
    ChessPiece *cp1 = cb->getChessPiece(sr, sc);
    if (cp1 == nullptr)
        return false;
    // check if destination has same color as source
    ChessPiece *cp2 = cb->getChessPiece(dr, dc);

    if (cp2 != nullptr)
    { // castling is a special case
        if (cp1->getChessPieceColor() == cp2->getChessPieceColor())
        {
            return false;
        }
    }
    // cout << " here valid move " << endl;
    if (false == cp1->isValidMove(sr, sc, dr, dc))
    {
        return false;
    }

    return true;
}

bool ChessMoves::isKinginCheck(int color)
{

    int rows = 0;
    int cols = 0;
    int kRow = 0;
    int kCol = 0;

    rows = cb->getRows();
    cols = cb->getCols();

    for (int i = 0; i < rows - 3; ++i)
    {
        for (int j = 2; j < cols; ++j)
        {
            ChessPiece *cp = nullptr;
            cp = cb->getChessPiece(i, j);
            if (cp)
            {
                int type = cp->getTypeOfChessPiece();
                if (type == GlobalEnums::CPType::WKing || type == GlobalEnums::CPType::BKing)
                {
                    if (color == GlobalEnums::ChessColors::Black)
                    {
                        if (type == GlobalEnums::CPType::BKing)
                        {
                            // found the match
                            // cout << " Black King at " << i << " " << j << endl;
                            kRow = i;
                            kCol = j;
                            break;
                        }
                    }
                    else
                    {
                        if (type == GlobalEnums::CPType::WKing)
                        {
                            // cout << " White King at " << i << " " << j << endl;
                            kRow = i;
                            kCol = j;
                            break;
                        }
                    }
                }
            }
        }
    }
    // cout << " row and col for king  color  " << kRow << " " << kCol << " " << color << endl;

    // check pieces of other color and see if any can take the king
    for (int ii = 0; ii < rows - 3; ++ii)
    {
        for (int jj = 2; jj < cols; ++jj)
        {
            ChessPiece *cp = nullptr;
            cp = cb->getChessPiece(ii, jj);
            if (cp)
            {
                int clr = cp->getChessPieceColor();
                if (clr != color)
                {
                    if (isValidMove(ii, jj, kRow, kCol))
                    {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

bool ChessMoves::isAnyMovePossible(int color)
{
    // Iterate the chessboard, for each piece of "color"
    // check all move combinations

    int bRows = cb->getRows();
    int bCols = cb->getCols();
    ChessPiece *cp = nullptr;
    // cout << "Any move possible for color : " << color << " rows : col " << bRows << " " << bCols << endl;
    for (int i = 0; i < bRows - 3; ++i)
    {
        for (int j = 2; j < bCols; ++j)
        {
            cp = nullptr;
            cp = cb->getChessPiece(i, j);
            if (cp)
            {
                // cout << "Piece at i,j " << i << " " << j << endl;

                if (cp->getChessPieceColor() == color)
                {
                    // found a piece of required color, now check all its moves

                    for (int ii = 0; ii < bRows - 3; ++ii)
                    {
                        for (int jj = 2; jj < bCols; ++jj)
                        {
                            if (isValidMove(i, j, ii, jj))
                            {

                                // make the move
                                storeMove(i, j, ii, jj);
                                cb->removePieceFromBoard(ii, jj);
                                cb->movePieceOnBoard(i, j, ii, jj);

                                // TODO
                                // check that King is not in check if the move is made
                                // make the move and then check and undo the move

                                bool check = isKinginCheck(color);
                                // if (check)
                                //   cout << "King in check at " << i << " : " << j << endl;
                                undoLastMove();
                                if (!check)
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}
void ChessMoves::storeMove(int sr, int sc, int dr, int dc)
{
    lm.sr = sr;
    lm.sc = sc;
    lm.dr = dr;
    lm.dc = dc;
    lm.sChessPieceType = GlobalEnums::CPType::NoPiece;
    lm.dChessPieceType = GlobalEnums::CPType::NoPiece;

    ChessPiece *cp = nullptr;
    cp = cb->getChessPiece(sr, sc);
    if (cp)
    {
        lm.sChessPieceType = cp->getTypeOfChessPiece();
    }
    cp = nullptr;
    cp = cb->getChessPiece(dr, dc);
    if (cp)
    {
        lm.dChessPieceType = cp->getTypeOfChessPiece();
    }

    //cout << "Last move sr sc chesspiece dr dc chess piece " << sr << " " << sc << " " << lm.sChessPieceType << " " << dr << " " << dc << " " << lm.dChessPieceType << endl;
}
void ChessMoves::undoLastMove()
{

    if (lm.sChessPieceType == GlobalEnums::CPType::NoPiece)
    {
        // invalid last move
        //  cout << " invalid last move undo" << endl;
        return;
    }

    //cout << "Undo move restore " << lm.sr << " " << lm.sc << " " << lm.sChessPieceType << " and " << lm.dr << " " << lm.dc << " " << lm.dChessPieceType << endl;
    cb->removePieceFromBoard(lm.dr, lm.dc);
    cb->removePieceFromBoard(lm.sr, lm.sc);

    cb->addPieceToBoard(lm.sr, lm.sc, lm.sChessPieceType);

    if (lm.dChessPieceType != GlobalEnums::CPType::NoPiece)
    {
        cb->addPieceToBoard(lm.dr, lm.dc, lm.dChessPieceType);
    }

    // now invalidate the move by making the
    lm.sChessPieceType = GlobalEnums::CPType::NoPiece;
}