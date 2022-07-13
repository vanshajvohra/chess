#include "displayText.h"
#include <string>

using namespace std;

DisplayText::~DisplayText()
{
    //cout << "Destructor of DisplayText " << endl;
}
void DisplayText::setAttributes(int r, int c)
{
    row = r;
    col = c;
}
void DisplayText::notify()
{
    //cerr << "called notify of text observer " << endl;
    cout << endl;
    char val = ' ';

    for (int j = 0; j < 11; ++j)
    {

        for (int i = 0; i < 10; ++i)
        {
            val = getSubject()->getState(j, i);
            string t(1, val);

            std::cout << " " << val;
        }
        cout << endl;
    }
}
void DisplayText::attachSubject(Subject *subject)
{
    theSubject = subject;
}