#include "Board.h"

using namespace std;
using namespace sf;
void Board::fillboard(int select)
{


    fstream file;
    Font font;
    if (!font.loadFromFile("EvilEmpire.ttf"))
        cout << "error in loading font";



    int line;
    switch (select)
    {
    case 0:
    {
        file.open("level1");
        vector<int> temp;
        for (int i = 0; i <= 8; i++)
        {
            for (int j = 0; j <= 8; j++)
            {
                file >> line;
                temp.push_back(line);
            }
            v.push_back(temp);
            temp.clear();
        }
        break;
    }
    case 1:
    {
        file.open("level2");
        vector<int> temp;
        for (int i = 0; i <= 8; i++)
        {
            for (int j = 0; j <= 8; j++)
            {
                file >> line;
                temp.push_back(line);
                //cout << temp << endl;
            }
            v.push_back(temp);
            temp.clear();
        }
        break;
    }
    case 2:
    {
        file.open("level3");
        vector<int> temp;
        for (int i = 0; i <= 8; i++)
        {
            for (int j = 0; j <= 8; j++)
            {
                file >> line;
                temp.push_back(line);
            }
            v.push_back(temp);
            temp.clear();
        }
        break;
    }
    }
}