#ifndef _BOX_H_
#define _BOX_H_

class ChessPiece;

class Box
{
    int x = 0;
    int y = 0;
    int bcolor;
    char dispChar;
    ChessPiece *cPiece = nullptr;
    // pointer to a piece
public:
    Box(int x = 0, int y = 0, char c = ' ');
    ~Box();
    int getXVal();
    int getYVal();
    void setXVal(int);
    void setYVal(int);
    int getColor();
    char getDisplayChar();
    void setDisplayChar(char);

    void addChessPiece(ChessPiece *);
    ChessPiece *getChessPiece();
    void removeChessPiece();
    enum boxColor
    {
        White = 0,
        Black = 1
    };
    // Piece &getPeice();
};

#endif