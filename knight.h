#ifndef _KNIGHT_H_
#define _KNIGHT_H_

#include "chessPiece.h"

class Knight : public ChessPiece
{
public:
    Knight(int color, int row, int col, CBoard *cb) : ChessPiece(color, row, col,cb){};
    ~Knight();
    bool isValidMove(int SRow, int SCol, int DRow, int DCol);
    //int getTypeOfChessPiece();
    //char getChessPieceDisplayChar();
};

#endif
