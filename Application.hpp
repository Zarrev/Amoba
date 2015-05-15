#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

class Application
{
protected:

    int SX;
    int SY;
//    vector<Originalwidget* Widget>

public:

    Application(int SX, int SY);
    virtual void run();
//    virtual void add(Originalwidget* W);

};
#endif // APPLICATION_HPP_INCLUDED
