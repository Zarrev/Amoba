#ifndef ORGINALWIDGET_HPP_INCLUDED
#define ORGINALWIDGET_HPP_INCLUDED
#include "graphics.hpp"
#include <string>
#include <vector>

using namespace std;
using namespace genv;

class Originalwidget
{
protected:

    int posx, posy, sizex, sizey, row, r, g, b;
    int counter = 0;
    int number = 0;
    int reckon = 0;
    int upbar, downbar;
    bool statictextbox = false;
    bool logical = false;
    bool unlogical = false;
    bool focusban = false;
    string textmess;
    string textmass;
    vector<string> stringtext;
    vector<int> intnumber;

public:
    string result = "Nem lett kivalasztott elem.";
    Originalwidget (int _posx, int _posy, int _sizex, int _sizey);
    Originalwidget(int _posx, int _posy, int _sizex, int _sizey, string _textmess, int _row, int _r, int _g, int _b);
    virtual void draw()  = 0;
    virtual void functionmake(event ev) = 0;
    virtual int igetter(int a) {};
    virtual void isetter() {};
    virtual string sgetter(string a) {};
    virtual void ssetter() {};
    virtual void focus(event ev, int a);

};

#endif // ORGINALWIDGET_HPP_INCLUDED
