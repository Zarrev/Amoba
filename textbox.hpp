#ifndef TEXTBOX_HPP_INCLUDED
#define TEXTBOX_HPP_INCLUDED
#include "orginalwidget.hpp"

class Textbox : public Originalwidget
{
public:
    Textbox(int _posx, int _posy, int _sizex, int _sizey, string _textmess, int _row, int _r, int _g, int _b, bool _statictextbox);
     virtual void draw() ;
     virtual void functionmake(event ev);
     virtual string sgetter(string a);
     virtual void ssetter();
};

#endif // TEXTBOX_HPP_INCLUDED
