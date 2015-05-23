#include "MyApplication.hpp"

MyApplication::MyApplication(int _SX, int _SY) : SX(_SX), SY(_SY) {
    TABLE = vector<vector<char> >(SX, vector<char>(SY,' '));
}

void MyApplication::forcycle(int &counter, char &ch, char a)
{

            if (a == 'X' && ch == 'X')
            {
                counter++;
            }
            else if (a == 'O' && ch == 'O')
            {
                counter++;
            }
            else if (a == 'X' && ch != 'X')
            {
                ch = 'X';
                counter = 1;
            }
            else if (a == 'O' && ch != 'O')
            {
                ch = 'O';
                counter = 1;
            }
            else if (a == ' ')
            {
                ch = ' ';
            }
}

bool MyApplication::check()
{
    if(draw == SX*SY){
        gameover = true;
        return gameover;
    }


    int counter1 = 0, counter2 = 0, counter3 = 0, counter4 = 0;
    char ch1 = ' ', ch2 = ' ', ch3 = ' ', ch4 = ' ';

    ///sorszerinti es oszlopszerinti
    for (unsigned int i = 0; i < TABLE.size(); i++)
    {
        for (unsigned int j = 0; j < TABLE[i].size(); j++)
        {
            forcycle(counter1, ch1, TABLE[i][j]);
            forcycle(counter2, ch2, TABLE[j][i]);
            if (counter1 == 5 or counter2 == 5)
            {
                gameover = true;
                return gameover;
            }
        }
    }
    counter1 = 0, counter2 = 0;
    ch1 = ' ', ch2 = ' ';

    ///atloszerinti
    for (unsigned int i = 0; i < TABLE.size(); i++)
    {
        for (unsigned int j = 0; j < TABLE[i].size()-i; j++)
        {
            forcycle(counter1, ch1, TABLE[i+j][j]);
            forcycle(counter2, ch2, TABLE[j][i+j]);
            forcycle(counter3, ch3, TABLE[TABLE.size()-j-1][i+j]);
            forcycle(counter4, ch4, TABLE[i+j][TABLE.size()-j-1]);
            if (counter1 == 5 or counter2 == 5 or counter3 == 5 or counter4 == 5)
            {
                gameover = true;
                return gameover;
            }
        }
    }
    return gameover;
}

bool MyApplication::step(int x, int y)
{
    if ((TABLE.size() <= x) or (TABLE[0].size() <= y) or (TABLE[x][y] != ' '))
        return false;


    if ( gameover )
    {
        return false;
    }


    if (player)
        TABLE[x][y] = 'X';
    else
        TABLE[x][y] = 'O';

    draw++;
    if (!check())
    {
        player = !player;
    }

    return true;

}

bool MyApplication::winner()
{
    return player;
}

vector<vector<char>> MyApplication::fulltable()
{
    return TABLE;
}

int MyApplication::status(){
    if(gameover and draw != SX*SY)
    {
        if(player)
            return -1;
        else
            return -2;
    } else if(draw == SX*SY) {
        return 0;
    }

    if(player)
        return 1;
    else
        return 2;


}
char MyApplication::cell(int x, int y) {
    return TABLE[x][y];
}
