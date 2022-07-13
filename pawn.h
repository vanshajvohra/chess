#ifndef _PAWN_H_
#define _PAWN_H_

#include "chessPiece.h"

class Pawn : public ChessPiece
{
public:
    Pawn(int c, int row, int col, CBoard *cb) : ChessPiece(c, row, col,cb){};
    ~Pawn();
    bool isValidMove(int SRow, int SCol, int DRow, int DCol);
    //int getTypeOfChessPiece();
    //char getChessPieceDisplayChar();
};

#endif
