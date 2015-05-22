#ifndef SELECT_HPP_INCLUDED
#define SELECT_HPP_INCLUDED

#include "orginalwidget.hpp"
#include <cmath>
#include <sstream>

#define u1 5
#define v1 5
#define r 4.5

class Select : public Originalwidget
{

protected:

    virtual void value ();
    canvas circle;
    canvas selectedCircle;
    canvas base;

public:

    Select(int _posx, int _posy, int _sizex, int _sizey, string _textmess, int _row, int _r, int _g, int _b);
    virtual void draw() ;
    virtual void functionmake(event ev);
    virtual string sgetter(string a) {};
    virtual void ssetter() {};

};

#endif // SELECT_HPP_INCLUDED
