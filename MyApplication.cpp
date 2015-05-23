#include "MyApplication.hpp"

MyApplication::MyApplication(int _SX, int _SY) : SX(_SX), SY(_SY) {}

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
                ch = 'X';
                counter = 1;
            }
            else if (a == ' ')
            {
                ch = ' ';
            }
}

bool MyApplication::check()
{
    int counter1 = 0, counter2 = 0, counter3 = 0, counter4 = 0;
    char ch1 = ' ', ch2 = ' ', ch3 = ' ', ch4 = ' ';

    ///sorszerinti es oszlopszerinti
    for (unsigned int i = 0; i < TABLE.size(); i++)
    {
        for (unsigned int j = 0; j < TABLE.size(); j++)
        {
            forcycle(counter1, ch1, TABLE[i][j]);
            forcycle(counter2, ch2, TABLE[j][i]);
            if (counter1 == 5 && counter2 == 5)
            {
                gameover = true;
                return gameover;
            }
        }
    }
    counter1 = 0, counter2 = 0;
    ch1 = ' ', ch2 = ' ';

    ///atloszerinti
    ///1.
    for (unsigned int i = 0; i < TABLE.size(); i++)
    {
        for (unsigned int j = 0; j < TABLE.size()-i; j++)
        {
            forcycle(counter1, ch1, TABLE[i+j][j]);
            forcycle(counter2, ch2, TABLE[j][i+j]);
            forcycle(counter3, ch3, TABLE[TABLE.size()-j][i+j]);
            forcycle(counter4, ch4, TABLE[i+j][TABLE.size()-j]);
            if (counter1 == 5 && counter2 == 5 && counter3 == 5 && counter4 == 5)
            {
                gameover = true;
                return gameover;
            }
        }
    }
}
