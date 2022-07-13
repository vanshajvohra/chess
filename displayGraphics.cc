#include "displayGraphics.h"
#include "window.h"
#include <string>

using namespace std;

DisplayGraphics::~DisplayGraphics()
{
    if (w)
        delete w;
}
void DisplayGraphics::setAttributes(int r, int c)
{
    row = r;
    col = c;
}
void DisplayGraphics::notify()
{

    //std::cout << "called notify of add graphics observer " << std::endl;
    /*
    if (this->w)
        delete w;
    w = new Xwindow;
    */

    if (this->w == nullptr)
    {
        this->w = new Xwindow;
        //std::cout << "1 called notify of add graphics observer " << std::endl;
    }

    //Xwindow w(180, 180);
    char val = ' ';

    // launch a window

    for (int j = 0; j < 11; ++j)
    {

        for (int i = 0; i < 10; ++i)
        {
            val = getSubject()->getState(j, i);
            string t(1, val);
            //w->drawString((i * 20) + 12, (j * 20) + 12, " ");
            w->fillRectangle((i * 20), (j * 20), 20, 20, Xwindow::White);
            w->drawString((i * 20) + 12, (j * 20) + 12, t);
        }
    }
    // int i;
    // std::cin >> i;
}
void DisplayGraphics::attachSubject(Subject *subject)
{
    theSubject = subject;
}
