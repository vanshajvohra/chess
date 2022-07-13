#include "chessPiece.h"
#include "globalEnums.h"
#include "cboard.h"

ChessPiece::ChessPiece(int t, int r, int c, CBoard *b)
{

    cptype = t;
    row = r;
    col = c;
    alive = true;
    cb = b;

    switch (t)
    {

    case GlobalEnums::CPType::WKing:
        color = GlobalEnums::ChessColors::White;
        dispChar = 'K';
        break;
    case GlobalEnums::CPType::WQueen:
        dispChar = 'Q';
        color = GlobalEnums::ChessColors::White;
        break;
    case GlobalEnums::CPType::WBishop:
        dispChar = 'B';
        color = GlobalEnums::ChessColors::White;
        break;
    case GlobalEnums::CPType::WRook:
        dispChar = 'R';
        color = GlobalEnums::ChessColors::White;
        break;
    case GlobalEnums::CPType::WKnight:
        dispChar = 'N';
        color = GlobalEnums::ChessColors::White;
        break;
    case GlobalEnums::CPType::WPawn:
        dispChar = 'P';
        color = GlobalEnums::ChessColors::White;
        break;
    case GlobalEnums::CPType::BKing:
        dispChar = 'k';
        color = GlobalEnums::ChessColors::Black;
        break;
    case GlobalEnums::CPType::BQueen:
        dispChar = 'q';
        color = GlobalEnums::ChessColors::Black;
        break;
    case GlobalEnums::CPType::BBishop:
        dispChar = 'b';
        color = GlobalEnums::ChessColors::Black;
        break;
    case GlobalEnums::CPType::BRook:
        dispChar = 'r';
        color = GlobalEnums::ChessColors::Black;
        break;
    case GlobalEnums::CPType::BKnight:
        dispChar = 'n';
        color = GlobalEnums::ChessColors::Black;
        break;
    case GlobalEnums::CPType::BPawn:
        dispChar = 'p';
        color = GlobalEnums::ChessColors::Black;
        break;
    default:
        dispChar = 'X';
        color = GlobalEnums::ChessColors::Black;
        break;
    }
}
void ChessPiece::setLocation(int r, int c)
{
    row = r;
    col = c;
}
int ChessPiece::getTypeOfChessPiece()
{
    return cptype;
}
char ChessPiece::getChessPieceDisplayChar()
{
    return dispChar;
}
int ChessPiece::getChessPieceColor()
{
    return color;
}