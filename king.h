#ifndef _KING_H_
#define _KING_H_

#include "chessPiece.h"

class King : public ChessPiece
{
public:
    King(int type, int row, int col, CBoard *cb) : ChessPiece(type, row, col,cb){};
    ~King();
    bool isValidMove(int SRow, int SCol, int DRow, int DCol);
    //int getTypeOfChessPiece();
    //char getChessPieceDisplayChar();
};

#endif
