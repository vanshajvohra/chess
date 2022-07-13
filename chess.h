#ifndef _CHESS_H_
#define _CHESS_H_
#include <string>
#include <sstream>
#include "cboard.h"
#include "chessMoves.h"
#include "displayText.h"
#include "displayGraphics.h"

//class CBoard;

class Chess
{
    CBoard cb;
    ChessMoves cm;
    DisplayText text;
    DisplayGraphics gr;
    std::string prompt;
    int nextMoveColor;
    bool gameOn;
    bool setupMode;
    bool setupModeDone;
    bool isKinCheck;
    bool isStaleMate;
    bool gameOver;
    int checkMateColor;

    void displayGameErrorMsg(int);
    void setPrompt(std::string);
    bool gameCmdHandler(std::istringstream &);
    bool moveCmdHandler(std::istringstream &);
    bool setupCmdHandler(std::string cmd, std::istringstream &is);
    bool getLocation(std::string, int *row, int *col);

    int getChessPieceType(std::string);

public:
    Chess();
    bool makeMove(char sc, int sr, char dc, int dr);
    bool chessMove(int sc, int sr, int dc, int dr);

    void render();
    CBoard *getBoard();
    bool isKinginCheck(int);
    bool isAnyMovePossible(int);
    void play();
};
#endif
