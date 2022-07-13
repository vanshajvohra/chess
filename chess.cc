#include <iostream>
#include <string>
#include <sstream>

#include "chess.h"
#include "cboard.h"
#include "displayText.h"
#include "displayGraphics.h"
#include "chessMoves.h"
#include "globalEnums.h"
#include "chessPiece.h"

using namespace std;

Chess::Chess()
{

    cm.attachBoard(&cb);

    text.attachSubject(&cb);
    cb.attach(&text);
    text.setAttributes(11, 10);
    
    gr.attachSubject(&cb);
    cb.attach(&gr);
    gr.setAttributes(11, 10);

    prompt = "(game|setup) : ";
    nextMoveColor = GlobalEnums::ChessColors::White;
    gameOn = false;
    setupMode = false;
    setupModeDone = false;
    isKinCheck = false;
    isStaleMate = false;
    gameOver = false;
    checkMateColor = false;
}

bool Chess::chessMove(int sr, int sc, int dr, int dc)
{
    // Basic validations
    // validations by chess piece

    int scol = sc;
    int dcol = dc;
    int srow = sr;
    int drow = dr;
    bool retval = true;

    //cb.convertLocation(sc, sr, &scol, &srow);
    //cb.convertLocation(dc, dr, &dcol, &drow);
    //cout << "moving for sr sc dr dc " << srow << " " << scol << " " << drow << " " << dcol << endl;
    if (false == cm.isValidMove(srow, scol, drow, dcol))
    {
        return false;
    }
    cm.storeMove(srow, scol, drow, dcol);
    cb.removePieceFromBoard(drow, dcol);
    retval = cb.movePieceOnBoard(srow, scol, drow, dcol);

    // cout << " Chess : makeMove returning " << endl;

    return retval;
}

bool Chess::makeMove(char sc, int sr, char dc, int dr)
{
    // Basic validations
    // validations by chess piece

    int scol = 0;
    int dcol = 0;
    int srow = 0;
    int drow = 0;
    bool retval = true;

    cb.convertLocation(sc, sr, &scol, &srow);
    cb.convertLocation(dc, dr, &dcol, &drow);

    if (false == cm.isValidMove(srow, scol, drow, dcol))
    {
        return false;
    }
    cm.storeMove(srow, scol, drow, dcol);
    cb.removePieceFromBoard(drow, dcol);
    retval = cb.movePieceOnBoard(srow, scol, drow, dcol);

    // cout << " Chess : makeMove returning " << endl;

    return retval;
}
void Chess::render()
{

    // TODO : make DisplayTest text a global.....
    //cout << "rendering " << endl;

    cb.render();
}

CBoard *Chess::getBoard()
{
    return &cb;
}

bool Chess::isKinginCheck(int color)
{
    return cm.isKinginCheck(color);
}

bool Chess::isAnyMovePossible(int color)
{
    return cm.isAnyMovePossible(color);
}

void displayHelp()
{
}

void Chess::play()
{
    cout << "##########################################" << endl;
    cout << " Welcome to the beautiful game of Chess " << endl;
    cout << "##########################################" << endl;

    while (true)
    {

        if (isKinCheck && isStaleMate)
        {
            cout << " Checkmate! ";
            if (nextMoveColor == GlobalEnums::ChessColors::White)
            {
                cout << "Black wins!" << endl;
            }
            else
            {
                cout << "White wins!" << endl;
            }
            gameOver = true;
            gameOn = false;
            setPrompt("(game|setup) : ");
            cout << endl;
        }
        else if (!isKinCheck && isStaleMate)
        {
            cout << "Stalemate!";
            gameOver = true;
            gameOn = false;
            setPrompt("(game|setup) : ");
            cout << endl;
        }
        else if (isKinCheck && !isStaleMate)
        {
            if (nextMoveColor == GlobalEnums::ChessColors::White)
            {
                cout << "White is in check." << endl;
            }
            else
            {
                cout << "Black is in check." << endl;
            }
        }

        cout << prompt;
        string cmdLine;
        string cmd;
        if (!getline(cin, cmdLine))
        {
            break;
        }
        istringstream is(cmdLine);
        is >> cmd;

        if (cmd == "game")
        {
            //cout << " game command " << endl;
            if (gameOn)
            {
                displayGameErrorMsg(3);
                continue;
            }
            if (setupMode)
            {
                displayGameErrorMsg(5);
                continue;
            }
            gameCmdHandler(is);
        }
        else if (cmd == "resign")
        {
            cout << " resign command " << endl;
            if (gameOn == false || setupMode == true)
            {
                displayGameErrorMsg(2);
                continue;
            }
            else
            {
                gameOn = false;
                //setPrompt("Welcome to Chess ");
                // TODO end the game
            }
        }
        else if (cmd == "move")
        {
            // cout << " move command " << endl;

            if (moveCmdHandler(is))
            {
                cb.render();
            }
        }
        else if (cmd == "setup")
        {
            //cout << " setup command " << endl;
            if (gameOn == true)
            {
                displayGameErrorMsg(4);
                continue;
            }
            if (setupMode == true)
            {
                displayGameErrorMsg(6);
                continue;
            }
            setupMode = true;
            cb.clearAllPieces();
            //cout << endl;
            cb.render();
            setPrompt("(setup mode |+|-|=|done) : ");
        }
        else if (cmd == "+")
        {

            if (setupCmdHandler("+", is))
            {
                cb.render();
            }
        }
        else if (cmd == "-")
        {
            // cout << " setup -  command " << endl;
            if (setupCmdHandler("-", is))
            {
                cb.render();
            }
        }
        else if (cmd == "=")
        {
            // cout << " setup =  command " << endl;
            if (setupCmdHandler("=", is))
            {
                cb.render();
            }
        }
        else if (cmd == "done")
        {
            //cout << " setup done command " << endl;
            if (setupCmdHandler("done", is))
            {
                cb.render();
                setupModeDone = true;
                setupMode = false;
            }
            cout << "chess :: Done Now " << endl;
        }
        else
        {
            cout << "invalid command " << endl;
        }
    }

    cout << "Game Ended " << endl;
}

void Chess::displayGameErrorMsg(int msgNum)
{
    cout << endl;
    switch (msgNum)
    {
    case 0:
        cout << " Error in passed parameter : 'game white-player black-player' " << endl;
        cout << " where white-player or black-player valid values are human or computer only" << endl;
        break;
    case 1:
        cout << " This is not a valid input " << endl;
        break;
    case 2:
        cout << "Cannot resign as no game is underway " << endl;
        break;
    case 3:
        cout << "A Game is already underway, cannot start another game. " << endl;
        cout << "You can use 'resign' to finish this game or use the 'move' command " << endl;
        cout << " to make a move to continue with current game ";
        break;
    case 4:
        cout << "Cannot enter setup mode while a game is on " << endl;
        break;
    case 5:
        cout << "Exit the setup mode using 'done' before starting a new game" << endl;
        break;

    case 6:
        cout << "Error, already in setup mode " << endl;
        break;
    case 7:
        cout << "Error, should be in setup mode for this command " << endl;
        break;
    case 8:
        cout << "Error input, expecting one of K|Q|B|N|R|P|k|q|b|n|r|p " << endl;
        break;
    case 9:
        cout << "Error input, expecting a board location like e2 or f5" << endl;
        break;
    case 10:
        cout << "Error input, expecting a color - W(w)hite or B(b)lack" << endl;
        break;
    case 11:
        cout << "Error. Board Validation Failed. Please correct before exiting setup mode" << endl;
        break;
    case 12:
        cout << "Error. No Chess Piece to move" << endl;
        break;
    case 13:
        cout << "Error. Cannot move piece of this color " << endl;
        break;
    case 14:
        cout << "Error. Invalid move for this Chess Piece " << endl;
        break;
    case 15:
        cout << "Error.  move command can be run in a game or after a setup has been executed " << endl;

    default:
        break;
    }
}
void Chess::setPrompt(string s)
{
    prompt = s;
}
bool Chess::moveCmdHandler(std::istringstream &is)
{

    // expect 2 arguments
    // source location , destination location

    if (!(gameOn || setupModeDone))
    {
        displayGameErrorMsg(15);
        return false;
    }
    string sloc;

    if (!(is >> sloc))
    {
        displayGameErrorMsg(9);
        return false;
    }
    int srow = 0;
    int scol = 0;
    if (!getLocation(sloc, &srow, &scol))
    {
        displayGameErrorMsg(9);
        return false;
    }

    string dloc;

    if (!(is >> dloc))
    {
        displayGameErrorMsg(9);
        return false;
    }
    int drow = 0;
    int dcol = 0;
    if (!getLocation(dloc, &drow, &dcol))
    {
        displayGameErrorMsg(9);
        return false;
    }
    // cout << " Move Handler Converted locations " << srow << " " << scol << " " << drow << " " << dcol << endl;

    ChessPiece *cp = cb.getChessPiece(srow, scol);
    if (cp == nullptr)
    {
        displayGameErrorMsg(12);
        return false;
    }
    if (cp->getChessPieceColor() != nextMoveColor)
    {
        displayGameErrorMsg(13);
        return false;
    }

    if (false == chessMove(srow, scol, drow, dcol))
    {
        displayGameErrorMsg(14);
        return false;
    }

    if (nextMoveColor == GlobalEnums::ChessColors::White)
    {
        nextMoveColor = GlobalEnums::ChessColors::Black;
        //cout << " next color black " << endl;
    }
    else
    {
        nextMoveColor = GlobalEnums::ChessColors::White;
        //cout << " next color white " << endl;
    }

    // check if this is a stalemate or checkmate situation
    if (isKinginCheck(nextMoveColor))
    {
        isKinCheck = true;
    }
    else
    {
        isKinCheck = false;
    }
    if (!isAnyMovePossible(nextMoveColor))
    {
        isStaleMate = true;
    }

    return true;
}

bool Chess::gameCmdHandler(std::istringstream &is)
{

    // expect 2 more arguments
    // human, human
    // human, computer
    // computer, computer

    string player1;
    is >> player1;
    if (!(player1 == "human" || player1 == "computer"))
    {
        //    cout << " Player is " << player1;
        displayGameErrorMsg(0);

        return false;
    }

    string player2;
    is >> player2;
    if (!(player2 == "human" || player2 == "computer"))
    {
        displayGameErrorMsg(0);
        return false;
    }

    gameOn = true;
    if (nextMoveColor == GlobalEnums::ChessColors::White)
    {
        setPrompt("(move|resign - white) : ");
    }
    else
    {
        setPrompt("(move|resign - white) : ");
    }
    cb.resetBoard();
    cb.render();
    return true;
}

bool Chess::setupCmdHandler(string cmd, std::istringstream &is)
{

    if (setupMode == false)
    {
        displayGameErrorMsg(7);
        return false;
    }

    if (cmd == "+" || cmd == "-")
    {
        string chessPiece;
        if (!(is >> chessPiece))
        {
            displayGameErrorMsg(8);
            return false;
        }
        if (!(chessPiece == "K" || chessPiece == "Q" ||
              chessPiece == "B" || chessPiece == "N" ||
              chessPiece == "R" || chessPiece == "P" ||
              chessPiece == "k" || chessPiece == "q" ||
              chessPiece == "b" || chessPiece == "n" ||
              chessPiece == "r" || chessPiece == "p"

              ))
        {
            displayGameErrorMsg(8);
            return false;
        }

        string loc;
        if (!(is >> loc))
        {
            displayGameErrorMsg(9);
            return false;
        }
        int row = 0;
        int col = 0;
        if (!getLocation(loc, &row, &col))
        {
            displayGameErrorMsg(9);
            return false;
        }

        int chessPType = 0;
        chessPType = getChessPieceType(chessPiece);
        if (chessPType == GlobalEnums::CPType::NoPiece)
        {
            displayGameErrorMsg(9);
            return false;
        }
        if (cmd == "+")
        {
            cb.addPieceToBoard(row, col, chessPType);
        }
        else
        {
            cb.removePieceFromBoard(row, col);
        }
        return true;
    }
    else if (cmd == "=")
    {
        string chessColor;
        if (!(is >> chessColor))
        {
            displayGameErrorMsg(10);
            return false;
        }
        if (chessColor == "White" || chessColor == "white")
        {
            nextMoveColor = GlobalEnums::ChessColors::White;
        }
        else if (chessColor == "Black" || chessColor == "black")
        {
            nextMoveColor = GlobalEnums::ChessColors::Black;
        }
        else
        {
            displayGameErrorMsg(10);
            return false;
        }
        return true;
    }
    else if (cmd == "done" || cmd == "Done")
    {
        // check the exit criteria defined

        // cout << "Done " << endl;

        if (cb.validateBoard())
        {
            setupMode = false;
            setupModeDone = true;
            setPrompt("(game|setup|move) : ");
        }
        else
        {
            displayGameErrorMsg(11);
            return false;
        }
    }

    return true;
}

bool Chess::getLocation(std::string loc, int *row, int *col)
{

    if (loc.length() != 2)
    {
        return false;
    }

    char c = loc[0];
    int r = loc[1] - '0';

    if (!(c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'g' || c == 'h'))
    {
        return false;
    }

    if (r <= 0 || r >= 9)
    {
        return false;
    }

    cb.convertLocation(c, r, col, row);

    // cout << " c r " << c << " " << r << " " << *row << " " << *col << endl;

    return true;
}

int Chess::getChessPieceType(string c)
{

    if (c == "K")
    {
        return GlobalEnums::CPType::WKing;
    }
    else if (c == "k")
    {
        return GlobalEnums::CPType::BKing;
    }
    else if (c == "Q")
    {
        return GlobalEnums::CPType::WQueen;
    }
    else if (c == "q")
    {
        return GlobalEnums::CPType::BQueen;
    }
    else if (c == "B")
    {
        return GlobalEnums::CPType::WBishop;
    }
    else if (c == "b")
    {
        return GlobalEnums::CPType::BBishop;
    }
    else if (c == "N")
    {
        return GlobalEnums::CPType::WKnight;
    }
    else if (c == "n")
    {
        return GlobalEnums::CPType::BKnight;
    }
    else if (c == "R")
    {
        return GlobalEnums::CPType::WRook;
    }
    else if (c == "r")
    {
        return GlobalEnums::CPType::BRook;
    }
    else if (c == "P")
    {
        return GlobalEnums::CPType::WPawn;
    }
    else if (c == "p")
    {
        return GlobalEnums::CPType::BPawn;
    }
    else
    {
        return GlobalEnums::CPType::NoPiece;
    }
}
