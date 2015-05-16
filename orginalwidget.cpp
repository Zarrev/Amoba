#include "orginalwidget.hpp"

Originalwidget::Originalwidget(int _posx, int _posy, int _sizex, int _sizey, string _textmess, int _row, int _r, int _g, int _b)
 : posx(_posx), posy(_posy), sizex(_sizex), sizey(_sizey), textmess(_textmess), row(_row), r(_r), g(_g), b(_b) {}

Originalwidget::Originalwidget (int _posx, int _posy, int _sizex, int _sizey) : posx(_posx), posy(_posy), sizex(_sizex), sizey(_sizey) {}

void Originalwidget::focus(event ev, int a)
{
    if (!statictextbox)
    {
        if (posx <= ev.pos_x && posx+sizex >= ev.pos_x && posy <= ev.pos_y && posy+sizey >= ev.pos_y && ev.button == btn_left && ev.keycode != key_tab)
        {
            gout << color(0,255,0) << move_to(posx-1,posy-1) << line(sizex+2,0) << line(0,sizey+2) << line(-(sizex+2),0) << line(0,-(sizey+2));
            focusban = true;
        }
        else if (focusban  && ev.button == btn_left)
        {
            gout << color(0,0,0) << move_to(posx-1,posy-1) << line(sizex+2,0) << line(0,sizey+2) << line(-(sizex+2),0) << line(0,-(sizey+2));
            focusban = false;
        }
    }
}
