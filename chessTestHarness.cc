#include "ChessTestHarness.h"
#include "cboard.h"
#include <iostream>
#include "cboard.h"
#include "box.h"
#include "displayGraphics.h"
#include "displayText.h"
#include "chessPiece.h"
#include "ChessTestHarness.h"
#include "globalEnums.h"
#include "chess.h"
//class CBoard;

using namespace std;

bool ChessTestHarness::test1()
{

    CBoard b;
    cout << "Test 1 " << endl;
    cout << " Test constructor, destructor, clearAllPieces and setInitialBoardPieces " << endl;

    DisplayText text(&b);
    b.attach(&text);
    text.setAttributes(11, 10);
    //cout << " render now " << endl;

    b.render();
    cout << endl;

    b.clearAllPieces();

    b.render();
    cout << endl;
    b.setInitialBoardPieces();
    b.render();
    cout << endl;
    /*
    DisplayGraphics gd(&b);
    b.attach(&gd);
    gd.setAttributes(11, 10);
    b.render();

    b.render();
*/
    return true;
}

bool ChessTestHarness::test2()
{

    CBoard b;
    cout << "Test 2 CBoard addPieceToBoard " << endl;

    int r = 0;
    int c = 0;

    DisplayText text(&b);
    b.attach(&text);
    text.setAttributes(11, 10);

    b.render();
    cout << endl;
    b.clearAllPieces();

    b.render();
    cout << endl;
    b.convertLocation('b', 7, &c, &r);
    cout << "Test 2 1 ";
    if (!b.addPieceToBoard(r, c, GlobalEnums::CPType::WKing))
    {
        cout << " failed " << endl;
    }
    b.render();
    cout << endl;
    cout << "Test 2 2 ";
    b.convertLocation('c', 7, &c, &r);
    b.addPieceToBoard(r, c, GlobalEnums::CPType::WQueen);
    b.render();
    cout << endl;
    cout << "Test 2 1 " << endl;
    b.convertLocation('d', 6, &c, &r);
    b.addPieceToBoard(r, c, GlobalEnums::CPType::WPawn);
    b.render();
    cout << endl;
    b.convertLocation('c', 6, &c, &r);
    b.addPieceToBoard(r, c, GlobalEnums::CPType::WPawn);
    b.render();
    cout << endl;
    b.convertLocation('b', 7, &c, &r);
    b.addPieceToBoard(r, c, GlobalEnums::CPType::WKing);
    b.render();
    cout << endl;
    b.convertLocation('e', 7, &c, &r);
    b.addPieceToBoard(r, c, GlobalEnums::CPType::WBishop);
    b.render();
    cout << endl;
    b.convertLocation('h', 7, &c, &r);
    b.addPieceToBoard(r, c, GlobalEnums::CPType::WKnight);
    b.render();
    cout << endl;
    b.convertLocation('h', 8, &c, &r);
    b.addPieceToBoard(r, c, GlobalEnums::CPType::BKnight);
    b.render();
    cout << endl;
    b.convertLocation('h', 1, &c, &r);
    b.addPieceToBoard(r, c, GlobalEnums::CPType::BQueen);
    b.render();
    cout << endl;
    b.convertLocation('a', 1, &c, &r);
    b.addPieceToBoard(r, c, GlobalEnums::CPType::BBishop);
    b.render();
    cout << endl;
    b.convertLocation('a', 8, &c, &r);
    b.addPieceToBoard(r, c, GlobalEnums::CPType::BPawn);
    b.render();
    cout << endl;
    return true;
}

bool ChessTestHarness::test3()
{

    CBoard b;
    cout << "Test 3 CBoard validateBoard" << endl;

    int r = 0;
    int c = 0;

    DisplayText text(&b);
    b.attach(&text);
    text.setAttributes(11, 10);

    b.clearAllPieces();

    b.convertLocation('b', 7, &c, &r);
    b.addPieceToBoard(r, c, GlobalEnums::CPType::WKing);

    b.convertLocation('c', 7, &c, &r);
    b.addPieceToBoard(r, c, GlobalEnums::CPType::WKing);

    b.convertLocation('d', 6, &c, &r);
    b.addPieceToBoard(r, c, GlobalEnums::CPType::WPawn);

    b.convertLocation('c', 6, &c, &r);
    b.addPieceToBoard(r, c, GlobalEnums::CPType::WPawn);

    b.convertLocation('b', 7, &c, &r);
    b.addPieceToBoard(r, c, GlobalEnums::CPType::WKing);

    b.convertLocation('e', 7, &c, &r);
    b.addPieceToBoard(r, c, GlobalEnums::CPType::WBishop);

    b.convertLocation('h', 7, &c, &r);
    b.addPieceToBoard(r, c, GlobalEnums::CPType::WKnight);

    b.convertLocation('h', 8, &c, &r);
    b.addPieceToBoard(r, c, GlobalEnums::CPType::BKnight);

    b.convertLocation('h', 1, &c, &r);
    b.addPieceToBoard(r, c, GlobalEnums::CPType::BQueen);

    b.convertLocation('a', 1, &c, &r);
    b.addPieceToBoard(r, c, GlobalEnums::CPType::BBishop);

    b.convertLocation('a', 8, &c, &r);
    b.addPieceToBoard(r, c, GlobalEnums::CPType::BPawn);
    b.render();

    if (b.validateBoard() == true)
    {
        cout << " Test 3 Passed Validation " << endl;
    }
    else
    {
        cout << "Test 3 Failed Validation " << endl;
    }

    cout << endl;
    return true;
}

bool ChessTestHarness::test4()
{

    CBoard b;
    cout << "Test 4 validateBoard " << endl;

    int r = 0;
    int c = 0;

    DisplayText text(&b);
    b.attach(&text);
    text.setAttributes(11, 10);

    b.clearAllPieces();

    b.convertLocation('b', 8, &c, &r);
    b.addPieceToBoard(r, c, GlobalEnums::CPType::WPawn);

    b.convertLocation('c', 1, &c, &r);
    b.addPieceToBoard(r, c, GlobalEnums::CPType::WPawn);

    b.render();

    if (b.validateBoard() == true)
    {
        cout << " Test 4 Passed Validation " << endl;
    }
    else
    {
        cout << "Test 4 Failed Validation " << endl;
    }

    cout << endl;
    return true;
}

bool ChessTestHarness::test5()
{
    cout << "Test 5 chess makeMove Pawn " << endl;
    Chess c;

    if (!c.makeMove('b', 2, 'b', 4))
        cout << "Failed Test 5 1 " << endl;
    c.render();

    if (c.makeMove('b', 4, 'b', 6))
        cout << "Failed Test 5 2 " << endl;
    c.render();

    if (c.makeMove('b', 2, 'c', 3))
        cout << "Failed Test 5 3 " << endl;
    c.render();

    if (c.makeMove('b', 3, 'b', 4))
        cout << "Failed Test 5 4 " << endl;
    c.render();
    if (!c.makeMove('b', 4, 'b', 5))
        cout << "Failed Test 5 4 " << endl;
    c.render();
    if (!c.makeMove('b', 5, 'b', 6))
        cout << "Failed Test 5 4 " << endl;
    c.render();

    if (!c.makeMove('b', 6, 'c', 7))
        cout << "Failed Test 5 4 " << endl;
    c.render();

    cout << endl;
    return true;
}

bool ChessTestHarness::test6()
{
    cout << "Test 5 chess makeMove Queen " << endl;
    Chess c;

    if (!c.makeMove('d', 1, 'd', 2))
    {
        cout << "Test 6 1 Failed" << endl;
    }
    else
    {
        cout << "Test 6 1 Passed" << endl;
    }
    c.render();

    if (!c.makeMove('d', 1, 'd', 5))
        cout << "Failed Test 6 2 " << endl;
    c.render();

    if (!c.makeMove('d', 1, 'd', 8))
        cout << "Failed Test 6 3 " << endl;
    c.render();

    if (!c.makeMove('d', 1, 'c', 1))
        cout << "Failed Test 6 4 " << endl;
    c.render();

    if (!c.makeMove('d', 1, 'e', 1))
        cout << "Failed Test 6 5 " << endl;
    c.render();

    if (!c.makeMove('d', 2, 'd', 4))
        cout << "Failed Test 6 6 " << endl;
    if (!c.makeMove('d', 4, 'd', 5))
        cout << "Failed Test 6 7 " << endl;
    if (!c.makeMove('d', 1, 'd', 3))
        cout << "Failed Test 6 8 " << endl;
    c.render();

    if (!c.makeMove('d', 3, 'b', 3))
        cout << "Failed Test 6 9 " << endl;
    c.render();

    if (!c.makeMove('b', 3, 'h', 3))
        cout << "Failed Test 6 9 " << endl;
    c.render();

    if (!c.makeMove('h', 3, 'f', 5))
        cout << "Failed Test 6 10 " << endl;
    c.render();

    if (!c.makeMove('f', 5, 'd', 5))
        cout << "Failed Test 6 11 " << endl;
    c.render();

    if (!c.makeMove('f', 5, 'f', 7))
        cout << "Failed Test 6 12 " << endl;
    c.render();

    c.render();

    cout << endl;
    return true;
}

bool ChessTestHarness::test7()
{
    cout << "Test 7 chess isKinginCheck " << endl;

    Chess c;
    CBoard *cb;

    cb = c.getBoard();

    cb->clearAllPieces();
    cb->addPieceToBoard(5, 5, GlobalEnums::CPType::BKing);
    cb->addPieceToBoard(5, 6, GlobalEnums::CPType::WKing);

    if (!c.isKinginCheck(GlobalEnums::ChessColors::White))
    {
        cout << "Test 7 1 Failed " << endl;
    }
    else
    {
        cout << "Test 7 1 Passed " << endl;
    }
    c.render();
}

bool ChessTestHarness::test8()
{
    cout << "Test 8 chess isAnyMovePossible  " << endl;

    Chess c;
    CBoard *cb;

    cb = c.getBoard();

    cb->clearAllPieces();
    cb->addPieceToBoard(5, 5, GlobalEnums::CPType::BPawn);
    cb->addPieceToBoard(6, 5, GlobalEnums::CPType::WPawn);

    if (c.isAnyMovePossible(GlobalEnums::ChessColors::White))
    {
        cout << "Test 8 1 Failed " << endl;
    }
    else
    {
        cout << "Test 8 1 Passed " << endl;
    }
    c.render();

    cb->clearAllPieces();
    cb->addPieceToBoard(5, 7, GlobalEnums::CPType::BPawn);
    cb->addPieceToBoard(6, 5, GlobalEnums::CPType::WPawn);
    cb->addPieceToBoard(2, 7, GlobalEnums::CPType::BKing);
    cb->addPieceToBoard(2, 4, GlobalEnums::CPType::WKing);
    c.render();
    if (!c.isAnyMovePossible(GlobalEnums::ChessColors::White))
    {
        cout << "Test 8 2 Failed " << endl;
    }
    else
    {
        cout << "Test 8 2 Passed " << endl;
    }
    c.render();
}