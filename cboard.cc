#include "cboard.h"
#include "board.h"
#include "subject.h"
#include "box.h"
#include "chessPiece.h"

#include "king.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "pawn.h"
#include "globalEnums.h"

#include <iostream>

using namespace std;

CBoard::CBoard()
{

    grid[10][0] = new Box(10, 0);
    grid[10][1] = new Box(10, 1);

    grid[10][2] = new Box(10, 2, 'a');
    grid[10][3] = new Box(10, 3, 'b');
    grid[10][4] = new Box(10, 4, 'c');
    grid[10][5] = new Box(10, 5, 'd');
    grid[10][6] = new Box(10, 6, 'e');
    grid[10][7] = new Box(10, 7, 'f');
    grid[10][8] = new Box(10, 8, 'g');
    grid[10][9] = new Box(10, 9, 'h');

    grid[0][0] = new Box(0, 0, '8');
    grid[1][0] = new Box(1, 0, '7');
    grid[2][0] = new Box(2, 0, '6');
    grid[3][0] = new Box(3, 0, '5');
    grid[4][0] = new Box(4, 0, '4');
    grid[5][0] = new Box(5, 0, '3');
    grid[6][0] = new Box(6, 0, '2');
    grid[7][0] = new Box(7, 0, '1');
    grid[8][0] = new Box(7, 0, ' ');
    grid[9][0] = new Box(7, 0, ' ');
    grid[10][0] = new Box(7, 0, ' ');
    //cout << " row " << row << " col " << col << endl;

    for (int i = 0; i < row - 1; i++)
    {
        for (int j = 1; j < col; j++)
        {
            //   cout << " row " << i << " col " << j << endl;
            grid[i][j] = new Box(i, j);
        }
    }
    setInitialBoardPieces();
    // cout << "CBoard constructor done " << endl;
    clearEnPassant();
}

CBoard::~CBoard()
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            ChessPiece *cp = grid[i][j]->getChessPiece();
            if (cp != nullptr)
            {
                delete cp;
                grid[i][j]->removeChessPiece();
            }
            delete grid[i][j];
        }
    }
    //delete grid;

    //cout << "CBoard Destructor done " << endl;
}

Box *CBoard::getBox(int row, int col)
{

    return grid[row][col];
}

char CBoard::getState(int row, int col) const
{
    //cout << "row " << row << " col " << col << endl;

    if (col == 1)
    {
        return ' ';
    }
    if (row == 8 || row == 9)
    {
        return ' ';
    }
    if (col == 0 && row == 10)
    {
        return ' ';
    }
    return grid[row][col]->getDisplayChar();
}
void CBoard::setInitialBoardPieces()
{

    // clear any existing pieces if any
    //cout << "here 1 " << endl;
    clearAllPieces();
    // set the white  pieces first
    //cout << "here 2" << endl;

    grid[7][2]->addChessPiece(new Rook(GlobalEnums::CPType::WRook, 7, 2, this));
    grid[7][3]->addChessPiece(new Knight(GlobalEnums::CPType::WKnight, 7, 3, this));
    grid[7][4]->addChessPiece(new Bishop(GlobalEnums::CPType::WBishop, 7, 4, this));
    grid[7][5]->addChessPiece(new Queen(GlobalEnums::CPType::WQueen, 7, 5, this));
    grid[7][6]->addChessPiece(new King(GlobalEnums::CPType::WKing, 7, 6, this));
    grid[7][7]->addChessPiece(new Bishop(GlobalEnums::CPType::WBishop, 7, 7, this));
    grid[7][8]->addChessPiece(new Knight(GlobalEnums::CPType::WKnight, 7, 8, this));
    grid[7][9]->addChessPiece(new Rook(GlobalEnums::CPType::WRook, 7, 9, this));

    grid[6][2]->addChessPiece(new Pawn(GlobalEnums::CPType::WPawn, 6, 2, this));
    grid[6][3]->addChessPiece(new Pawn(GlobalEnums::CPType::WPawn, 6, 3, this));
    grid[6][4]->addChessPiece(new Pawn(GlobalEnums::CPType::WPawn, 6, 4, this));
    grid[6][5]->addChessPiece(new Pawn(GlobalEnums::CPType::WPawn, 6, 5, this));
    grid[6][6]->addChessPiece(new Pawn(GlobalEnums::CPType::WPawn, 6, 6, this));
    grid[6][7]->addChessPiece(new Pawn(GlobalEnums::CPType::WPawn, 6, 7, this));
    grid[6][8]->addChessPiece(new Pawn(GlobalEnums::CPType::WPawn, 6, 8, this));
    grid[6][9]->addChessPiece(new Pawn(GlobalEnums::CPType::WPawn, 6, 9, this));

    grid[0][2]->addChessPiece(new Rook(GlobalEnums::CPType::BRook, 0, 2, this));
    grid[0][3]->addChessPiece(new Knight(GlobalEnums::CPType::BKnight, 0, 3, this));
    grid[0][4]->addChessPiece(new Bishop(GlobalEnums::CPType::BBishop, 0, 4, this));
    grid[0][5]->addChessPiece(new Queen(GlobalEnums::CPType::BQueen, 0, 5, this));
    grid[0][6]->addChessPiece(new King(GlobalEnums::CPType::BKing, 0, 6, this));
    grid[0][7]->addChessPiece(new Bishop(GlobalEnums::CPType::BBishop, 0, 7, this));
    grid[0][8]->addChessPiece(new Knight(GlobalEnums::CPType::BKnight, 0, 8, this));
    grid[0][9]->addChessPiece(new Rook(GlobalEnums::CPType::BRook, 0, 9, this));

    grid[1][2]->addChessPiece(new Pawn(GlobalEnums::CPType::BPawn, 1, 2, this));
    grid[1][3]->addChessPiece(new Pawn(GlobalEnums::CPType::BPawn, 1, 3, this));
    grid[1][4]->addChessPiece(new Pawn(GlobalEnums::CPType::BPawn, 1, 4, this));
    grid[1][5]->addChessPiece(new Pawn(GlobalEnums::CPType::BPawn, 1, 5, this));
    grid[1][6]->addChessPiece(new Pawn(GlobalEnums::CPType::BPawn, 1, 6, this));
    grid[1][7]->addChessPiece(new Pawn(GlobalEnums::CPType::BPawn, 1, 7, this));
    grid[1][8]->addChessPiece(new Pawn(GlobalEnums::CPType::BPawn, 1, 8, this));
    grid[1][9]->addChessPiece(new Pawn(GlobalEnums::CPType::BPawn, 1, 9, this));
    /*
    cpListW.push_back(grid[7][1]->getChessPiece());
    cpListW.push_back(grid[7][2]->getChessPiece());
    cpListW.push_back(grid[7][3]->getChessPiece());
    cpListW.push_back(grid[7][4]->getChessPiece());
    cpListW.push_back(grid[7][5]->getChessPiece());
    cpListW.push_back(grid[7][6]->getChessPiece());
    cpListW.push_back(grid[7][7]->getChessPiece());
    cpListW.push_back(grid[7][8]->getChessPiece());

    cpListW.push_back(grid[6][1]->getChessPiece());
    cpListW.push_back(grid[6][2]->getChessPiece());
    cpListW.push_back(grid[6][3]->getChessPiece());
    cpListW.push_back(grid[6][4]->getChessPiece());
    cpListW.push_back(grid[6][5]->getChessPiece());
    cpListW.push_back(grid[6][6]->getChessPiece());
    cpListW.push_back(grid[6][7]->getChessPiece());
    cpListW.push_back(grid[6][8]->getChessPiece());

    cpListB.push_back(grid[0][1]->getChessPiece());
    cpListB.push_back(grid[0][2]->getChessPiece());
    cpListB.push_back(grid[0][3]->getChessPiece());
    cpListB.push_back(grid[0][4]->getChessPiece());
    cpListB.push_back(grid[0][5]->getChessPiece());
    cpListB.push_back(grid[0][6]->getChessPiece());
    cpListB.push_back(grid[0][7]->getChessPiece());
    cpListB.push_back(grid[0][8]->getChessPiece());

    cpListB.push_back(grid[1][1]->getChessPiece());
    cpListB.push_back(grid[1][2]->getChessPiece());
    cpListB.push_back(grid[1][3]->getChessPiece());
    cpListB.push_back(grid[1][4]->getChessPiece());
    cpListB.push_back(grid[1][5]->getChessPiece());
    cpListB.push_back(grid[1][6]->getChessPiece());
    cpListB.push_back(grid[1][7]->getChessPiece());
    cpListB.push_back(grid[1][8]->getChessPiece());
    */
}

void CBoard::clearAllPieces()
{

    // cout << "clearAllPieces "
    //     << "row " << row << "col " << col << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            //    cout << "clearAllPieces "
            //       << "row " << row << "col " << col << endl;

            ChessPiece *p = grid[i][j]->getChessPiece();
            if (p)
            {
                //    cout << " delete piece on row " << j << col << " " << i << endl;
                delete p;
                grid[i][j]->removeChessPiece();
            }
        }
    }
}
void CBoard::resetBoard()
{

    clearAllPieces();
    setInitialBoardPieces();
}

int CBoard::getRows()
{
    return row;
}
int CBoard::getCols()
{
    return col;
}

bool CBoard::validateBoard()
{
    // cout << "Not implemented " << endl;

    int K = 0;
    int k = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            ChessPiece *cp = nullptr;
            cp = grid[i][j]->getChessPiece();

            if (cp)
            {
                int chessPieceType = cp->getTypeOfChessPiece();
                switch (chessPieceType)
                {
                case GlobalEnums::CPType::WKing:
                    K++;

                    if (K > 1)
                    {

                        return false;
                    }
                    break;
                case GlobalEnums::CPType::BKing:
                    k++;

                    if (k > 1)
                    {
                        return false;
                    }
                    break;

                case GlobalEnums::CPType::WPawn:
                case GlobalEnums::CPType::BPawn:
                    if (i == 0 || i == 7)
                    {
                        //cout << " Pawn failed " << endl;
                        return false;
                    }
                    break;
                }
            }
        }
    }
    //cout << "true returned " << endl;
    return true;
}

bool CBoard::addPieceToBoard(int row, int col, int chessPieceType)
{

    this->removePieceFromBoard(row, col);

    switch (chessPieceType)
    {
    case GlobalEnums::CPType::WKing:
    case GlobalEnums::CPType::BKing:
        // cerr << " adding King at r : c " << row << " : " << col << "color " << color << endl;
        grid[row][col]->addChessPiece(new King(chessPieceType, row, col, this));
        break;
    case GlobalEnums::CPType::WQueen:
    case GlobalEnums::CPType::BQueen:
        grid[row][col]->addChessPiece(new Queen(chessPieceType, row, col, this));
        break;
    case GlobalEnums::CPType::WBishop:
    case GlobalEnums::CPType::BBishop:
        grid[row][col]->addChessPiece(new Bishop(chessPieceType, row, col, this));
        break;
    case GlobalEnums::CPType::WRook:
    case GlobalEnums::CPType::BRook:
        grid[row][col]->addChessPiece(new Rook(chessPieceType, row, col, this));
        break;
    case GlobalEnums::CPType::WKnight:
    case GlobalEnums::CPType::BKnight:
        grid[row][col]->addChessPiece(new Knight(chessPieceType, row, col, this));
        break;
    case GlobalEnums::CPType::WPawn:
    case GlobalEnums::CPType::BPawn:
        grid[row][col]->addChessPiece(new Pawn(chessPieceType, row, col, this));
        break;

    default:
        return false;
    }

    return true;
}
void CBoard::removePieceFromBoard(int row, int col)
{

    //cout << " remove piece row and col " << row << " " << col << endl;
    /*
    if (row < 0 || row > 7)
    {
        return;
    }

    if (col < 1 || col > 7)
    {
        return;
    }
*/

    // if a piece already exists, delete it
    ChessPiece *cp = nullptr;

    cp = grid[row][col]->getChessPiece();
    if (cp)
    {
        delete cp;
        grid[row][col]->removeChessPiece();
    }
}
bool CBoard::movePieceOnBoard(int srow, int scol, int drow, int dcol)
{

    // if a chess piece exists at destination, fail

    if (grid[drow][dcol]->getChessPiece() != nullptr)
    {
        return false;
    }

    ChessPiece *data = grid[srow][scol]->getChessPiece();
    data->setLocation(drow, dcol);

    grid[drow][dcol]->addChessPiece(data);
    grid[srow][scol]->removeChessPiece();

    return true;
}

void CBoard::convertLocation(char c, int r, int *col, int *row)
{

    switch (c)
    {
    case 'a':
        *col = 2;
        break;
    case 'b':
        *col = 3;
        break;
    case 'c':
        *col = 4;
        break;
    case 'd':
        *col = 5;
        break;
    case 'e':
        *col = 6;
        break;
    case 'f':
        *col = 7;
        break;
    case 'g':
        *col = 8;
        break;
    case 'h':
        *col = 9;
        break;
    default: // error case
        *col = 0;
        break;
    }

    *row = 8 - r;

    if (*row < 0)
    { // error case
        *row = 0;
    }
}
ChessPiece *CBoard::getChessPiece(int srow, int scol)
{
    return grid[srow][scol]->getChessPiece();
}

void CBoard::setEnpassant(int srow, int scol, int drow, int dcol, int color)
{
    enpass.sr = srow;
    enpass.sc = scol;
    enpass.dr = drow;
    enpass.dc = dcol;
    enpass.valid = true;
    enpass.color = color;
}
void CBoard::clearEnPassant()
{
    enpass.sr = 0;
    enpass.sc = 0;
    enpass.dr = 0;
    enpass.dc = 0;
    enpass.valid = false;
}
