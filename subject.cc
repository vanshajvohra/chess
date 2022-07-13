#include "subject.h"
#include "observer.h"
#include <vector>
#include <iostream>
using namespace std;

void Subject::attach(Observer *o) { observers.emplace_back(o); }

void Subject::detach(Observer *o)
{
  for (auto it = observers.begin(); it != observers.end();)
  {
    if (*it == o)
      it = observers.erase(it);
    else
      ++it;
  }
}

void Subject::notifyObservers()
{
  //cout << "notify observer called " << endl;
  for (auto &ob : observers)
  {
    //cout << "here 1" << endl;
    ob->notify();
    // cout << "here 2 " << endl;
  }
}
