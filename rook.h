#ifndef _ROOK_H_
#define _ROOK_H_

#include "chessPiece.h"

class Rook : public ChessPiece
{
public:
    Rook(int c, int row, int col, CBoard *cb) : ChessPiece(c, row, col, cb){};
    ~Rook();
    bool isValidMove(int SRow, int SCol, int DRow, int DCol);
    //int getTypeOfChessPiece();
    // char getChessPieceDisplayChar();
};

#endif
