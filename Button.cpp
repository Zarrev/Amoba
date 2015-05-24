#include "Button.hpp"
#include <iostream>

Button::Button(int _posx, int _posy, int _sizex, int _sizey, int _row, int _r, int _g, int _b, function<string()> _f)
    : Originalwidget( _posx, _posy, _sizex, _sizey, _row, _r, _g, _b)
    {
        textmess = " ";
        f = _f;
    }

void Button::draw()
{
    gout << move_to(posx,posy) << color(r,g,b) << box(sizex,sizey) << move_to(posx+sizex/2-gout.twidth(textmess)/2,posy+sizey/2+gout.cdescent())
         << color(0,0,0) << text(textmess);


    if (focusban && logical)
    {
        gout << move_to(posx,posy) << color(0,0,0) << box(sizex,sizey) << move_to(posx+sizex/2-gout.twidth(textmess)/2,posy+sizey/2+gout.cdescent())
             << color(r,g,b) << text(textmess);
    }
}

void Button::functionmake(event ev)
{
    if (focusban)
    {
        if (ev.button == btn_left)
        {
            if (posx+sizex >= ev.pos_x && posx <= ev.pos_x && posy <= ev.pos_y && posy+sizey >= ev.pos_y )
            {
                logical = true;
                ssetter();
            }
        }
        if (ev.button == -btn_left)
        {
                logical = false;
        }
    }
    if (focusban)
    {
        if (ev.keycode == key_up xor ev.keycode == key_pgup)
        {
            logical = true;
            ssetter();
        }
        if (ev.keycode == -key_up xor ev.keycode == -key_pgup)
        {
            logical = false;
        }
    }
    if (!focusban)
    {
       logical = false;
    }
}
void Button::ssetter()
{
    r = 255;
    g = 0;
    b = 0;
    textmess = f();
}
