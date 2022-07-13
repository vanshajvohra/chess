#ifndef _QUEEN_H_
#define _QUEEN_H_

#include "chessPiece.h"

class Queen : public ChessPiece
{
public:
    Queen(int c, int row, int col, CBoard *cb) : ChessPiece(c, row, col, cb){};
    ~Queen();
    bool isValidMove(int SRow, int SCol, int DRow, int DCol);
    //int getTypeOfChessPiece();
    //char getChessPieceDisplayChar();
};

#endif
