#ifndef _BOARD_H_
#define _BOARD_H_
#include <vector>
#include "subject.h"

class Box;
class Subject;

class Board : public Subject

{
    //int row = 0;
    //int col = 0;

public:
    //Board(int r = 9, int c = 9) : row(r), col(c){};
    // virtual void setRow(int row);
    // virtual void setCol(int col);
    virtual int getRows() = 0;
    virtual int getCols() = 0;
    virtual Box *getBox(int row, int col) = 0;
    virtual char getState(int row, int col) const = 0;
    void render();
    virtual void resetBoard() = 0;
    virtual bool validateBoard() = 0;
    virtual void clearAllPieces() = 0;
    virtual bool addPieceToBoard(int row, int col, int chessPieceType) = 0;
    virtual void removePieceFromBoard(int row, int col) = 0;

    virtual ~Board() = default;
};

#endif
