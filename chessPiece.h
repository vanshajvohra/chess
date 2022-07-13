#ifndef _CHESS_PIECE_H
#define _CHESS_PIECE_H

class CBoard;

class ChessPiece
{
protected:
    int cptype;
    int row;
    int col;
    bool alive;
    char dispChar = 'X';
    int color = 0;
    CBoard *cb;

public:
    ChessPiece(int t, int r, int c, CBoard *b);

    virtual ~ChessPiece() = default;

    virtual bool isValidMove(int SRow, int SCol, int DRow, int DCol) = 0;
    virtual void setLocation(int row, int col);
    int getTypeOfChessPiece();
    char getChessPieceDisplayChar();
    int getChessPieceColor();
};

#endif
