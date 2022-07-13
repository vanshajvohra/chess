#ifndef _BISHOP_H_
#define _BISHOP_H_

#include "chessPiece.h"

class Bishop : public ChessPiece
{
public:
    Bishop(int c, int r, int cl, CBoard *cb) : ChessPiece(c, r, cl,cb){};
    ~Bishop();
    bool isValidMove(int SRow, int SCol, int DRow, int DCol);
    //int getTypeOfChessPiece();
    char getChessPieceDisplayChar();
};

#endif
