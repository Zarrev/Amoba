#ifndef MYAPPLICATION_HPP_INCLUDED
#define MYAPPLICATION_HPP_INCLUDED
#include <vector>
using namespace std;
class MyApplication
{

protected:
    int SX, SY;
    bool player = true;
    bool gameover = false;
    vector<vector<char>> TABLE = vector<vector<char> >(40, vector<char>(40,' '));

public:
    MyApplication(int _SX, int _SY);
    virtual bool check();
    virtual bool step(int x, int y);

};


#endif // MYAPPLICATION_HPP_INCLUDED
