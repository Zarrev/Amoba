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

    MyApplication* Engine = new MyApplication(meret,meret);
    Textbox Textb(SX*3/4,SY*2/4,120,50," ",1,0,100,255, true);
    Textbox Textbo(SX*3/4,SY*1/4,100,50,"Press F5 to restart",1,0,100,255, true);
    vector<vector<Originalwidget*>> Widget = vector<vector<Originalwidget *> >(meret, vector<Originalwidget*>(meret,0));
    int x = 1, y = 1, szamlalo = 30;
    for (unsigned int i = 0; i < Widget.size(); i++)
    {
        for (unsigned int j = 0; j < Widget.size(); j++)
        {
            Widget[i][j] = new Button(12*(x),12*(y)+szamlalo,10,10,i,0,50,200,[&]()
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
            Textb.setText("DRAW");
            break;

          case -1 :
            Textb.ssetter();
            Textb.setText("X WIN");
            break;

          case -2 :
            Textb.ssetter();
            Textb.setText("O WIN");
            break;

        case 1 :
            Textb.setText("NEXT ONE IS X");
            break;
        case 2 :
            Textb.setText("NEXT ONE IS O");
            break;

        }
        Textb.draw();
        Textbo.draw();


        gout << refresh;


    }
}
