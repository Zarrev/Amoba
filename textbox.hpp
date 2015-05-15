#ifndef TEXTBOX_HPP_INCLUDED
#define TEXTBOX_HPP_INCLUDED
#include "orginalwidget.hpp"

class Textbox : public Originalwidget
{
public:
    Textbox(int _posx, int _posy, int _sizex, int _sizey, string _textmess, int _row, int _r, int _g, int _b);
     virtual void draw() const;
     virtual void functionmake(event ev);
     virtual string sgetter(string a);
     virtual string ssetter();
};

#endif // TEXTBOX_HPP_INCLUDED
