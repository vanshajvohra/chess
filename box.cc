#include <iostream>
#include "box.h"
#include "chessPiece.h"

using namespace std;

Box::Box(int x_val, int y_val, char c)
{
    x = x_val;
    y = y_val;

    if ((x + y) % 2)
    {
        bcolor = Box::boxColor::Black;
        dispChar = '_';
    }
    else
    {
        bcolor = Box::boxColor::White;
        dispChar = ' ';
    }

    if (c != ' ')
    {
        dispChar = c;
    }

    cPiece = nullptr;
    //cout << "Box constructor called " << endl;
}

Box::~Box()
{
    /*
    if (cPiece != nullptr)
    {
        delete cPiece;
    }
    */
    // cerr << "Destructor of Box " << endl;
}

int Box::getXVal()
{
    return x;
}
int Box::getYVal()
{
    return y;
}
void Box::setXVal(int val)
{
    x = val;
    if ((x + y) % 2)
    {
        // odd box
        bcolor = Black;
    }
    else
    {
        bcolor = White;
    }
}
void Box::setYVal(int val)
{
    y = val;
}

int Box::getColor()
{
    return bcolor;
}

void Box::addChessPiece(ChessPiece *data)
{
    cPiece = data;
}
void Box::removeChessPiece()
{

    cPiece = nullptr;
}
ChessPiece *Box::getChessPiece()
{
    return cPiece;
}
char Box::getDisplayChar()
{
    //char c = ' ';
    if (cPiece)
    {
        return cPiece->getChessPieceDisplayChar();
    }
    return dispChar;
}
void Box::setDisplayChar(char c)
{
    dispChar = c;
}
