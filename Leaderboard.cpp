#include "leaderboard.h"

void leaderboard::HighScore(int score, int lvlcounter)
{
    string filename;

    switch (lvlcounter)
    {
        case 0:
        {
            filename = "easy";
            break;
        }
        case 1:
        {
            filename = "medium";
            break;
        }
        case 2:
        {
            filename = "hard";
            break;
        }
        default:
            break;
    }

    list<int>l;
    int counter = 0;
    ofstream file1;
    file1.open(filename, std::ios::app);
    file1 << score << "\n";
    file1.close();
    ifstream file;
    file.open(filename);
    int x;
    while (file >> x)
    {
        l.push_back(x);
        counter++;
    }
    l.sort();
    l.reverse();
    ofstream f;
    f.open(filename);
    list<int> ::iterator it;
    for (it = l.begin(); it != l.end(); ++it)
        f << *it << "\n";
}


void leaderboard::drawto(RenderWindow& window, int count)
{
    Texture texture;
    Sprite sprite;
    ifstream file1;
    Font font;
    Text t[5];
    int x, min, sec, i = 0;
    String time;
    if (!font.loadFromFile("EvilEmpire.ttf"))
        cout << "error in loading font";

    switch (count)
    {
        case 0:
        {
            file1.open("Easy", ios::in);
            if (!texture.loadFromFile("EHS.png"))
                cout << "error in loading image! " << endl;
            break;
        }
        case 1:
        {
            file1.open("Medium", ios::in);
            if (!texture.loadFromFile("MHS.png"))
                cout << "error in loading image! " << endl;
            break;
        }
        case 2:
        {
            file1.open("Hard", ios::in);
            if (!texture.loadFromFile("HHS.png"))
                cout << "error in loading image! " << endl;
            break;
        }
    }

    sprite.setTexture(texture);

    while (file1 >> x)
    {
        if (i < 5)
        {
            min = x / 60;
            sec = x % 60;
            if (sec < 10)
                time = to_string(min) + ":0" + to_string(sec);
            else
                time = to_string(min) + ":" + to_string(sec);
            t[i].setFont(font);
            t[i].setString(time);
            t[i].setFillColor(Color::White);
            t[i].setCharacterSize(40);
        }
        i++;
    }

    for (int i = 0; i < 5; i++)
        t[i].setPosition(350.f, (288 + (i * 135)));
    window.draw(sprite);

    for (int i = 0; i < 5; i++)
        window.draw(t[i]);
}
