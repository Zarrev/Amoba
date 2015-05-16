#include "graphics.hpp"
#include "Application.hpp"
#include "orginalwidget.hpp"
#include "textbox.hpp"
#include "Counter.hpp"
#include "Select.hpp"

using namespace genv;
using namespace std;

Application::Application(int _SX, int _SY) : SX(_SX), SY(_SY) {}

void Application::run()
{
    gout.open(SX,SY);
    event ev;
    gin.timer(50);
    vector<Originalwidget*> Widget;
    Widget.push_back(new Textbox(20,20,100,25,"Ez egy StaticTextBox",1,255,0,0,true));
    Widget.push_back(new Counter(20,50,100,25,"0",2,20,20,20,100,-5));
    Widget.push_back(new Textbox(20,80,100,25,"--",3,150,150,150,false));
    Widget.push_back(new Select(20,110,100,50,"--",4,0,0,0));
    while(gin >> ev && ev.keycode != key_escape)
    {
        for (unsigned int i = 0; i < Widget.size(); i++)
        {
        Widget[i] -> functionmake(ev);
        Widget[i] -> focus(ev,i);
        Widget[i] -> draw();
        }
        gout << refresh;
    }
}
