#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include "orginalwidget.hpp"
#include <functional>

class Button : public Originalwidget
{
protected:
    function<void()> f;
    string a;
public:
    Button(int _posx, int _posy, int _sizex, int _sizey, string _textmess, int _row, int _r, int _g, int _b, string _textmass, function<void()> _f);
    virtual void draw();
    virtual void functionmake(event ev);
    virtual void ssetter();
};

#endif // BUTTON_HPP_INCLUDED
