#ifndef _DISPLAYGRAPHICS_H
#define _DISPLAYGRAPHICS_H

#include "subject.h"
#include "observer.h"
#include <iostream>

class Xwindow;

class DisplayGraphics : public Observer
{
    //:std::ostream &out = std::cout;
    Subject *theSubject;
    Xwindow *w;
    int row, col;

public:
    explicit DisplayGraphics(Subject *subject = nullptr) : theSubject{subject}, w{nullptr} {}
    ~DisplayGraphics();
    void setAttributes(int row, int col);
    void attachSubject(Subject *subject);
    void notify();
    Subject *&getSubject() { return theSubject; }
};

#endif
