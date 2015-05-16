#include "Select.hpp"

Select::Select(int _posx, int _posy, int _sizex, int _sizey, string _textmess, int _row, int _r, int _g, int _b) :
    Originalwidget( _posx, _posy, _sizex, _sizey, _textmess, _row, _r, _g, _b)
{
    circle.open(10, 10);
    selectedCircle.open(10, 10);
    base.open(sizex, sizey*5);



    for (unsigned int x = 0; x < 10; x++)
    {
        for (unsigned int y = 0; y < 10; y++ )
        {
            if (pow(x,2) + pow(y,2) -2*u1*x - 2*v1*y + pow(u1,2) + pow (v1,2) - pow(r,2) <= 0)
            {
                circle<< move_to(x,y) << color(255,255,255) << dot;
                selectedCircle<< move_to(x,y) << color(255,0,0) << dot;
            }
            if (pow(x,2) + pow(y,2) -2*5*x - 2*5*y + pow(5,2) + pow (5,2) - pow(3.5,2) <= 0)
            {
                circle<< move_to(x,y) << color(150,150,150) << dot;
                selectedCircle<< move_to(x,y) << color(150,150,150) << dot;
            }
        }
    }
    number = -1;
}
void Select::value()
{
        stringtext.push_back(textmess);
        textmess = "--";
        logical = false;
        result = stringtext[number];
}
void Select::draw()
{
    for (unsigned int i = 0; i < stringtext.size(); i++)
    {
        if(number == i)
        {
            base<< stamp(selectedCircle, 0, 20*i+gout.cascent());

        }
        else
        {
            base<< stamp(circle, 0, 20*i+gout.cascent());
        }

        base << color(255,255,255) << move_to(0+18,(0)+20*(i)+10+gout.cascent()) << text(stringtext[i]);
    }
    base << color(50,50,50) << move_to(15,20*stringtext.size()+gout.cascent()) << box(85,gout.cascent()*1.5);
    base << color (255,255,255) << move_to(20,20*stringtext.size()+gout.cascent()*2) << text(textmess);
    if (logical)
    {
        base << color(0,0,0) << move_to(15,20*stringtext.size()+gout.cascent()) << box(85,gout.cascent()*1.5);
        value();
    }
    if (unlogical)
    {
        base << color(100,100,100) << move_to(15,20*stringtext.size()+gout.cascent()) << box(85,gout.cascent()*1.5);
        base << color (255,255,255) << move_to(20,20*stringtext.size()+gout.cascent()*2) << text(textmess);
    }
    gout << stamp(base, -5, counter, sizex, sizey, posx, posy);

}

void Select::functionmake(event ev)
{
    int szamol = 0;
    if (ev.keycode == key_enter && textmess != "")
    {
        if (textmess != "--" or szamol > 0){
        logical = true;
        unlogical = false;
        number = stringtext.size();
        }
    }

    if (ev.button == btn_left)
    {
        szamol++;
        if(posx+20 <= ev.pos_x && posx+sizex >= ev.pos_x && (posy+stringtext.size()*20-counter+gout.cascent()) <= ev.pos_y && (posy+stringtext.size()*20-counter+gout.cascent()*3 - 5) >= ev.pos_y && focusban)
        {
            textmess = "";
            unlogical = true;
        }
        else
        {
            textmess = "--";
            unlogical = false;
            szamol = 0;
        }
    }
    if (unlogical)
    {
        if (ev.keycode>=32 && ev.keycode<255 && reckon < (65))
        {
            textmess+=ev.keycode;
        }
        else if (ev.keycode == 8 && textmess != "")
        {
            string seged = textmess;
            textmess = "";
            for (unsigned int i = 0; i<seged.length()-1; i++)
            {
                textmess += seged[i];
            }
        }
        reckon = gout.twidth(textmess);
    }
    if (focusban)
    {
        if (ev.button == btn_wheelup)
        {
            if (counter < 0)
            {
                counter = 0;
            }
            counter--;
        }
        if (ev.button == btn_wheeldown)
        {
            counter++;
        }
        if (ev.button == btn_left)
        {
            for (unsigned int i = 0; i < stringtext.size(); i++)
            {
                if (ev.pos_x >= posx && ev.pos_x <= posx+sizex && ev.pos_y >= posy && ev.pos_y <= posy+sizey)
                {
                    if(posx <= ev.pos_x && posx+sizex >= ev.pos_x && posy+((i+1)*20-counter)+gout.cascent() >= ev.pos_y && (posy+(i*20)-counter)+gout.cascent() <= ev.pos_y)
                    {
                        number = i;
                        result = stringtext[number];
                        break;
                    }
                    else
                    {
                        number = -1;
                        result = "Nem lett kivalasztott elem.";
                    }
                }
            }
        }
    }
    bool igaz = false, hamis = false;
    if (focusban)
    {
        if (ev.keycode == key_up)
        {
            unlogical = false;
            textmess = "--";
            number--;
            if(number+1 < 0)
            {
                number = stringtext.size()-1;
            }
            if (number == -1)
            {
                result = "Nem lett kiválasztott elem";
            }
            else
            {
                result = stringtext[number];
            }
            for (unsigned int i = 0; i < stringtext.size()+1;i++)
            {
                if (number == i or i == stringtext.size()+1)
                {
                    igaz = true;
                }
            }
            if (!igaz){hamis = true;}
            if (hamis){
                unlogical = true;
                textmess = "";
                igaz = false;
                number = stringtext.size();}

        }
        if (ev.keycode == key_down)
        {
            number++;
            unlogical = false;
            textmess = "--";
            if(number > stringtext.size())
            {
                number = 0;
            }
            if (number == stringtext.size())
            {
                result = "Nem lett kiválasztott elem";
            }
            else
            {
                result = stringtext[number];
            }
            for (unsigned int i = 0; i < stringtext.size();i++)
            {
                if (number == i or i == stringtext.size())
                {
                    igaz = true;
                }
            }
            if (!igaz){hamis = true;}
            if (hamis){
                unlogical = true;
                textmess = "";
                igaz = false;
                }
        }
        if (ev.keycode == key_pgup)
        {
            number = 0;
            result = stringtext[0];
        }
        if (ev.keycode == key_pgdn)
        {
            number = stringtext.size()-1;
            result = stringtext[stringtext.size()-1];
        }
    }
    if (!focusban)
    {
        unlogical = false;
        textmess = "--";
    }
}
