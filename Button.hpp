#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include "orginalwidget.hpp"
#include <functional>

class Button : public Originalwidget
{
protected:
    function<string()> f;
public:
    Button(int _posx, int _posy, int _sizex, int _sizey, int _row, int _r, int _g, int _b, function<string()> _f);
    virtual void draw();
    virtual void functionmake(event ev);
    virtual void ssetter();
};

#endif // BUTTON_HPP_INCLUDED
