#include "Counter.hpp"
///Még az RGB kódot javítani kell!!!
Counter::Counter(int _posx, int _posy, int _sizex, int _sizey, string _textmess, int _row, int _r, int _g, int _b,  int _upbar, int _downbar)
: Originalwidget( _posx, _posy, _sizex, _sizey, _textmess, _row, _r, _g, _b)
{
    upbar = _upbar;
    downbar = _downbar;
}

    void Counter::value(event ev)
    {
        if ((ev.button == btn_left xor ev.keycode == key_up xor ev.keycode == key_down) && focusban)
        {
            if (logical)
            {
                if (number < upbar)
                {
                    number++;
                }
                stringstream ss;
                ss << number;
                textmess = ss.str();
                ss.clear();
            }
            if (unlogical)
            {
                if (number > downbar)
                {
                    number--;
                }
                stringstream ss;
                ss << number;
                textmess = ss.str();
                ss.clear();
            }
        }
        if ((ev.keycode == key_pgup xor ev.keycode == key_pgdn)&&focusban)
        {
            if (logical)
            {
                number = upbar;
                stringstream ss;
                ss << number;
                textmess = ss.str();
                ss.clear();
            }
            if (unlogical)
            {
                number = downbar;
                stringstream ss;
                ss << number;
                textmess = ss.str();
                ss.clear();
            }
        }
    }

    void Counter::draw() const
    {
        gout<<color(r,g,b)<<move_to(posx,posy)<<box(sizex,sizey)<<move_to(posx+5,posy+sizey-sizey/3)<<color(255-r,255-g,255-b) << text(textmess);
        gout << color(255-r,255-g,255-b)<<move_to(posx+sizex-(sizey-sizey/3),posy)<<box(sizey-sizey/3,sizey);
        gout << color(150,150,150)<< move_to(posx+sizex-(sizey-sizey/3),posy+sizey/2) << line(sizey-sizey/3,0);

        if (logical && focusban)
        {
            gout << color(0,255,0) << move_to(posx+sizex-(sizey-sizey/4)/2,posy+sizey/4-sizey/8) << line(-5,5) << line(10,0) << line(-5,-5);
        }
        else
        {
            gout << color(255,0,0) << move_to(posx+sizex-(sizey-sizey/4)/2,posy+sizey/4-sizey/8) << line(-5,5) << line(10,0) << line(-5,-5);
        }
        if (unlogical && focusban)
        {
            gout << color(0,255,0) << move_to(posx+sizex-(sizey-sizey/4)/2,posy+sizey-(sizey/4-sizey/8)) << line(-5,-5) << line(10,0) << line(-5,5);
        }
        else
        {
            gout << color(255,0,0) << move_to(posx+sizex-(sizey-sizey/4)/2,posy+sizey-(sizey/4-sizey/8)) << line(-5,-5) << line(10,0) << line(-5,5);
        }
    }

    void Counter::functionmake(event ev)
    {
        if (focusban)
        {
            if (ev.button == btn_left)
            {
                if (posx+sizex-(sizey-sizey/3) <= ev.pos_x && posx+sizex+sizey-sizey/3 >= ev.pos_x && posy <= ev.pos_y && posy+sizey/2 > ev.pos_y )
                {
                    logical = true;
                }
                if (posx+sizex-(sizey-sizey/3) <= ev.pos_x && posx+sizex+sizey-sizey/3 >= ev.pos_x && posy+sizey/2 < ev.pos_y && posy+sizey >= ev.pos_y )
                {
                    unlogical = true;
                }
            }
            if (ev.button == -btn_left)
            {
                logical = false;
                unlogical = false;
            }
        }
        if (focusban)
        {
            if (ev.keycode == key_up xor ev.keycode == key_pgup)
            {
                logical = true;
            }
            if (ev.keycode == -key_up xor ev.keycode == -key_pgup)
            {
                logical = false;
            }
            if (ev.keycode == key_down xor ev.keycode == key_pgdn)
            {
                unlogical = true;
            }
            if (ev.keycode == -key_down xor ev.keycode == -key_pgdn)
            {
                unlogical = false;
            }
        }
        if (!focusban)
        {
           logical = false;
           unlogical = false;
        }
        value(ev);
    }

    int Counter::igetter(int a)
    {

    }

    int Counter::isetter()
    {

    }
