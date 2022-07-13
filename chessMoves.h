#ifndef _CHESS_MOVES_H
#define _CHESS_MOVES_H
#include "cboard.h"
#include "chessPiece.h"

class ChessMoves
{
    CBoard *cb;
    struct lastMove
    {
        int sr;
        int sc;
        int sChessPieceType;
        int dr;
        int dc;
        int dChessPieceType;
    };
    lastMove lm;

public:
    ChessMoves(CBoard *b = nullptr) : cb{b} {};
    void attachBoard(CBoard *);
    bool isValidMove(int sr, int sc, int dr, int dc);
    bool isKinginCheck(int color);
    bool isAnyMovePossible(int color);
    void storeMove(int sr, int sc, int dr, int dc);
    void undoLastMove();
};
#endif
