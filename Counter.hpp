#ifndef COUNTER_HPP_INCLUDED
#define COUNTER_HPP_INCLUDED

#include "orginalwidget.hpp"
#include "sstream"

class Counter : public Originalwidget
{
protected:

     virtual void value (event ev);

public:

     Counter(int _posx, int _posy, int _sizex, int _sizey, string _textmess, int _row, int _r, int _g, int _b,  int _upbar, int _downbar);
     virtual void draw() ;
     virtual void functionmake(event ev);
     virtual int igetter(int a);
     virtual void isetter();

};

#endif // COUNTER_HPP_INCLUDED
