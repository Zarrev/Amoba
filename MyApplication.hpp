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
    int draw = 0;
    void forcycle(int &counter, char &ch, char a);

    vector<vector<char>> TABLE;

public:
    MyApplication(int _SX, int _SY);
    bool check();
    bool step(int x, int y);
    bool winner();
    int status();
    char cell(int x, int y);
    vector<vector<char>> fulltable ();


};


#endif // MYAPPLICATION_HPP_INCLUDED
