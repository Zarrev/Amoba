#include "graphics.hpp"
#include "Application.hpp"
#include "orginalwidget.hpp"
#include "textbox.hpp"
#include "Counter.hpp"
#include "Select.hpp"
#include "Button.hpp"
#include "MyApplication.hpp"
#include <iostream>
#include <sstream>
#include <string>


using namespace genv;
using namespace std;

Application::Application(int _SX, int _SY) : SX(_SX), SY(_SY) {}

void Application::run()
{
    int meret = 40;
    gout.open(SX,SY,true);
    event ev;
    gin.timer(50);
    bool player = true;
    bool valtozo = false;
    MyApplication* Engine = new MyApplication(meret,meret);
    Textbox Textb(SX*3/4,SY*3/4,120,50," ",1,0,100,255, true);
    Textbox Textbo(SX*3/4,SY*2/4,100,50,"Restart - F5",1,0,100,255, true);
    Button START(SX/2-200,SY/2-100,200,100,0,125,0,255,[&]()
    {
        valtozo = true;
        return "START";
    });
    vector<vector<Originalwidget*>> Widget = vector<vector<Originalwidget *> >(meret, vector<Originalwidget*>(meret,0));
    int x = 1, y = 1, szamlalo = 1;
    for (unsigned int i = 0; i < Widget.size(); i++)
    {
        for (unsigned int j = 0; j < Widget.size(); j++)
        {
            Widget[i][j] = new Button(12*(x),12*(y),10,10,i,0,50,200,[&]()
            {
                return " ";
            });
            if (j == Widget.size()-1)
            {
                x++;
            }
            y++;
        }
        y = 1;
    }


    while(gin >> ev && ev.keycode != key_escape)
    {
        if (!valtozo){
            START.functionmake(ev);
            START.focus(ev, x);
        gout << color(0,0,0) << move_to(0,0) << box(SX,SY);
            START.draw();
        }
        if (valtozo){

        if(ev.keycode == key_f5)
        {
            delete Engine;
            Engine = new MyApplication(meret,meret);

            for (unsigned int i = 0; i < Widget.size(); i++)
            {
                for (unsigned int j = 0; j < Widget.size(); j++)
                {

                        Widget[i][j] -> setText(" ");
                        Widget[i][j] -> focustounfocus();
                }
            }
            Textb.ssetter2();
        }

        if (1 == 1){
        for (unsigned int i = 0; i < Widget.size(); i++)
        {
            for (unsigned int j = 0; j < Widget.size(); j++)
            {
                Widget[i][j] -> focus(ev,i);
                Widget[i][j] -> draw();
                if(Widget[i][j] -> isClicked(ev)) {
                    Engine->step(i,j);
                    stringstream ss;
                    ss << Engine->cell(i,j);
                    string tmp;
                    ss >> tmp;
                    Widget[i][j] -> setText(tmp);
                    ss.clear();
                }

            }
        }
        }

        switch ( Engine->status() ) {

          case 0 :
            Textb.setText("Dontetlen");
            break;

          case -1 :
            Textb.ssetter();
            Textb.setText("X win");
            break;

          case -2 :
            Textb.ssetter();
            Textb.setText("O win");
            break;

        case 1 :
            Textb.setText("X kore");
            break;
        case 2 :
            Textb.setText("O kore");
            break;

        }
        Textb.draw();
        Textbo.draw();
        }

        gout << refresh;


    }
}
