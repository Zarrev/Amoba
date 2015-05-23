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
    int meret = 20;
    gout.open(SX,SY);
    event ev;
    gin.timer(50);
    /*
    vector<Originalwidget*> Widget;
    Widget.push_back(new Textbox(20,20,100,25,"Ez egy StaticTextBox",1,255,0,0,true));
    Widget.push_back(new Counter(20,50,100,25,"0",2,20,20,20,100,-5));
    Widget.push_back(new Textbox(20,80,100,25,"--",3,150,150,150,false));
    Widget.push_back(new Select(20,140,100,50,"--",4,0,0,0));
    Widget.push_back(new Button(20,110,100,25,"+",5,600,600,1000,"+++",[&]()
    {

    }));
    */
    bool player = true;
    MyApplication* Engine = new MyApplication(meret,meret);
    Textbox Textb(SX*3/4,SY*3/4,80,50,"ok",1,0,100,255, true);
    vector<vector<Originalwidget*>> Widget = vector<vector<Originalwidget *> >(meret, vector<Originalwidget*>(meret,0));
    int x = 1, y = 1, szamlalo = 1;
    for (unsigned int i = 0; i < Widget.size(); i++)
    {
        for (unsigned int j = 0; j < Widget.size(); j++)
        {
            /// Valszeg mutato fv kell lambda fv helyett, de majd csak hnap...
            Widget[i][j] = new Button(12*(x),12*(y),10,10,i,0,50,200,[&]()
            {
                return ' ';
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
        /*
        for (unsigned int i = 0; i < Widget.size(); i++)
        {
        Widget[i] -> functionmake(ev);
        Widget[i] -> focus(ev,i);
        Widget[i] -> draw();
        }
        */
        if(ev.keycode == key_f5)
        {
            delete Engine;
            Engine = new MyApplication(meret,meret);

            for (unsigned int i = 0; i < Widget.size(); i++)
            {
                for (unsigned int j = 0; j < Widget.size(); j++)
                {

                        Widget[i][j] -> setText(" ");
                }
            }

            cout << "#yolo";
        }

        if (1 == 1){
        for (unsigned int i = 0; i < Widget.size(); i++)
        {
            for (unsigned int j = 0; j < Widget.size(); j++)
            {
                Widget[i][j] -> focus(ev,i);
                //Widget[i][j] -> functionmake(ev);
                Widget[i][j] -> draw();
                if(Widget[i][j] -> isClicked(ev)) {
                    Engine->step(i,j);
                    stringstream ss;
                    ss << Engine->cell(i,j);
                    string tmp;
                    ss >> tmp;
                    Widget[i][j] -> setText(tmp);
                }

            }
        }
        }

        switch ( Engine->status() ) {

          case 0 :
            Textb.setText("Dontetlen");
            break;

          case -1 :
            Textb.setText("X win");
            break;

          case -2 :
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

        gout << refresh;


    }
}
