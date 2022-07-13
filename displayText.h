#ifndef _DISPLAYTEXT_H
#define _DISPLAYTEXT_H

#include "subject.h"
#include "observer.h"
#include <iostream>

class Xwindow;

class DisplayText : public Observer
{
    //:std::ostream &out = std::cout;
    Subject *theSubject;

    int row, col;

public:
    explicit DisplayText(Subject *subject = nullptr) : theSubject{subject} {}
    ~DisplayText();
    void attachSubject(Subject *subject);
    void setAttributes(int row, int col);
    void notify();
    Subject *&getSubject() { return theSubject; }
};

#endif
