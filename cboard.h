#ifndef _CBOARD_H_
#define _CBOARD_H_
#include <vector>
#include "board.h"
#include "subject.h"

class Box;
class Subject;
class ChessPiece;
class Board;

class CBoard : public Board

{

    int row = 11;
    int col = 10;

    struct Enpassant
    {
        int sr;
        int sc;
        int dr;
        int dc;
        int color;
        bool valid;
    };

    Enpassant enpass;
    //    std::vector<ChessPiece *> cpListW;
    // std::vector<ChessPiece *> cpListB;

    Box *grid[11][10];

public:
    CBoard();
    int getRows() override;
    int getCols() override;
    Box *getBox(int row, int col) override;
    char getState(int row, int col) const override;
    //void render();
    void resetBoard() override;
    bool validateBoard() override;
    void clearAllPieces() override;
    bool addPieceToBoard(int row, int col, int chessPieceType) override;
    void removePieceFromBoard(int row, int col) override;
    void setInitialBoardPieces();
    void convertLocation(char c, int r, int *col, int *row);
    bool movePieceOnBoard(int srow, int scol, int drow, int dcol);
    ChessPiece *getChessPiece(int srow, int scol);
    void setEnpassant(int srow, int scol, int drow, int dcol, int color);
    void clearEnPassant();

    ~CBoard();
};

#endif
