#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
#include <SFML/window.hpp>
#include <SFML/system.hpp>
#include <fstream>
#include <list>
#include "Button.h"
#include "MainMenu.h"
#include "Leaderboard.h"
#include "board.h"
#include "Undo_Redo.h"
#include <set>

using namespace std;
using namespace sf;


const int MAX_NUMBER_OF_COLUMNS = 9;
const int MAX_NUMBER_OF_ROWS = 9;



struct move {
    int i;
    int j;
    int value;
}m[9] = {};

Texture MainBackgroundTxt(int Lvlcount)
{
    Texture T1;
    switch (Lvlcount)
    {
    case 0:
        if (!T1.loadFromFile("GGame.png"))
        {
            cout << "couldn't load file";
        }
        else
            break;
    case 1:
        if (!T1.loadFromFile("OGame.png"))
        {
            cout << "couldn't load file";
        }
        else
            
            break;
    case 2:
        if (!T1.loadFromFile("RGame.png"))
        {
            cout << "couldn't load file";
        }
        else
           
            break;
    }

    return T1;
}

bool Check(bool play,Button bttn[9][9],int time,int lvlcounter) {
    int WinCount = 0;
    for (int size = 0; size < 9; size++)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                //cout << "will check " << bttn[size][size].getText() << '.' << bttn[size][j].getText() << '.' << bttn[i][size].getText() << '.'<< endl;
                if (bttn[size][size].getText() != bttn[size][j].getText() && bttn[size][size].getText() != bttn[i][size].getText())
                {
                    WinCount++;
                    if (WinCount == 9) { //WIN CONDITION
                        return true;
                    }
                }
            }
        }
    }
}

int main()
{
    //VARIABLES
    RenderWindow window(sf::VideoMode(720, 1080), "Sudoku", sf::Style::Close | sf::Style::Titlebar);
    leaderboard highscore;
    Undo_Redo  Undo;
    Undo_Redo  Redo;


    Board board;
    Font font;
    
    Texture BackGroundTxt,MenuBackGroundTxt;
    Sprite Background, MenuBackGround;

    bool play = false;
    bool leaderBoard = false;
    bool MenuVariable = true;
    bool generate = true;

    Vector2i position;
    float y;
    float x;
    int LvlCounter=-1;


    ///CLOCK INIT
    Clock clockgamed;
    int TimeTaken = 0;
    int timesec = 0;
    int timemin = 0;

    Text timescore;
    timescore.setString(to_string(timemin) + ":0" + to_string(timesec));
    timescore.setFont(font);
    timescore.setFillColor(Color::White);
    timescore.setPosition(325.f, 40.f);


    //INIT GRID

    Button bttn[9][9];

    //INIT NUMBER BUTTONS
    Button* NumBtn = new Button[10];
    for (int i = 0; i < 5; i++)
    {
        //Setting firt 5 Number buttons
        NumBtn[i] = Button(to_string(i + 1), { 66 ,59 }, 42, Color::Transparent, Color::Black, font, (129 + (40 * i) + (59 * i)), 790);

    }
    for (int i = 0; i < 5; i++)
    {
        //Setting second 5 Number buttons
        NumBtn[i + 5] = Button(to_string(i + 6), { 66 ,59 }, 42, Color::Transparent, Color::Black, font, (129 + (40 * i) + (59 * i)), 870);
        NumBtn[9].settext("X");
    }

    Button* SpecialBtn = new Button[5];
    for (int i = 0; i < 5; i++)
    {
        //Setting firt 5 Number buttons
        SpecialBtn[i] = Button(" ", { 66 ,59 }, 30, Color::Transparent, Color::Black, font, (129 + (40 * i) + (59 * i)), 710);
    }



    //LOADING FONT
    if (!font.loadFromFile("EvilEmpire.ttf"))
    {
        cout << "font not loaded\n";
    }

    //MAIN MENU
    MainMenu menu;
    MenuBackGroundTxt = menu.BackgroundTxt();
    MenuBackGround.setTexture(MenuBackGroundTxt);


    //TIME


    map <string, int> StoInt;
    StoInt["1"] = 1;
    StoInt["2"] = 2;
    StoInt["3"] = 3;
    StoInt["4"] = 4;
    StoInt["5"] = 5;
    StoInt["6"] = 6;
    StoInt["7"] = 7;
    StoInt["8"] = 8;
    StoInt["9"] = 9;

    int A; int B = 0; int C = 0; int D = 0;
    int E = 0; int F = 0; int G = 0; int H = 0; int I = 0; int temp;
    map <char, int> Randomising;

 A = (1 + (rand() % 9));

  while (generate) {
        temp = (1 + (rand() % 9));

        if (temp != A && temp != B && temp != C && temp != D && temp != E && temp != F && temp != G && temp != H && temp != I)
        {
            if (B == 0) {

                if (temp != B && C == 0) {

                    if (temp != C && D == 0)
                    {
                        if (temp != D && E == 0)
                        {
                            if (temp != E && F == 0)
                            {
                                if (temp != F && G == 0)
                                {
                                    if (temp != G && H == 0)
                                    {
                                        if (temp != H && I == 0)
                                        {
                                            if (temp != I)
                                            {
                                                I = temp;
                                                cout << "done   " << endl;
                                            }
                                            else break;
                                        }
                                        else H = temp;
                                    }
                                    else G = temp;
                                }
                                else F = temp;
                            }
                            else E = temp;
                        }
                        else D = temp;
                    }
                    else C = temp;
                }
                else B = temp;
            }
        }
        
        if (A != 0 && B != 0 && C != 0 && D != 0 && E != 0 && F != 0 && G != 0 && H != 0 && I != 0)
            generate = false;  
  }
 
 
    cout << "\n" << A << " " << B << " " << C << "\n" << D << " " << E << " " << F << "\n" << G << " " << H << " " << I << "\n" << temp;

    Randomising['A'] = A;
    Randomising['B'] = B;
    Randomising['C'] = C;
    Randomising['D'] = D;
    Randomising['E'] = E;
    Randomising['F'] = F;
    Randomising['G'] = G;
    Randomising['H'] = H;
    Randomising['I'] = I;

   for (map<char, int>::iterator it = Randomising.begin(); it != Randomising.end(); it++) 
   {

        cout << it->second << endl;
   }

   
    //GAME LOOP  
   int lastCellClickedCol = -1, lastCellClickedRow = -1;
   while (window.isOpen())
   {
       Event event;

       while (window.pollEvent(event))
       {

           if (MenuVariable)
           {
               position = sf::Mouse::getPosition(window);
               x = position.x;
               y = position.y;

               if (event.type == Event::MouseButtonPressed)
               {
                   if (Mouse::isButtonPressed(Mouse::Left) && x > 460 && x < 535 && y > 420 && y < 470)
                   {
                       menu.MoveRight();

                       MenuBackGroundTxt = menu.BackgroundTxt();
                       MenuBackGround.setTexture(MenuBackGroundTxt);
                   }
                   else if (Mouse::isButtonPressed(Mouse::Left) && x > 175 && x < 250 && y > 420 && y < 470)
                   {
                       menu.MoveLeft();

                       MenuBackGroundTxt = menu.BackgroundTxt();
                       MenuBackGround.setTexture(MenuBackGroundTxt);
                   }
                   else if (Mouse::isButtonPressed(Mouse::Left) && x > 262 && x < 456 && y > 545 && y < 603)
                   {
                       LvlCounter = menu.GetPressedItem();
                       MenuVariable = false;
                       leaderBoard = false;
                       play = true;


                       BackGroundTxt = MainBackgroundTxt(LvlCounter);
                       Background.setTexture(BackGroundTxt);

                       board.fillboard(LvlCounter);
                       for (int i = 0; i < 9; i++)
                       {
                           for (int j = 0; j < 9; j++)
                           {
                               string temp = to_string(board.v[j][i]);
                               bttn[i][j] = Button{ temp,Vector2f(57.f, 56.f),40,Color::Transparent,Color::White,font,(100.f + (59 * (i)) - (i / 2)), (124.f + (59 * (j)) - (j / 2)) };
                               if (bttn[i][j].getText()._Equal("0")) {
                                   bttn[i][j].settext(" ");
                                   bttn[i][j].buttonIsClicked(true);
                               }
                               else bttn[i][j].buttonIsClicked(false);



                           }
                       }

                   }
                   else if (Mouse::isButtonPressed(Mouse::Left) && x > 135 && x < 584 && y > 663 && y < 721)
                   {
                       LvlCounter = menu.GetPressedItem();
                       MenuVariable = false;
                       leaderBoard = true;
                       play = false;



                   }
                   else if (Mouse::isButtonPressed(Mouse::Left) && x > 288 && x < 436 && y > 781 && y < 839)
                   {
                       window.close();
                   }

               }


           }
           if (play)
           {
               //board.fillboard(LvlCounter);
               // CLOCK WORK
               float timergamed = clockgamed.getElapsedTime().asSeconds();
               if (timergamed > 0.6)
               {
                   timesec = TimeTaken % 60, timemin = TimeTaken / 60;
                   ++TimeTaken;
                   timescore.setString(to_string(timemin) + ":" + to_string(timesec));

                   if (timesec < 10)
                       timescore.setString(to_string(timemin) + ":0" + to_string(timesec));

                   cout << TimeTaken << endl;
                   clockgamed.restart();
               }

               /////////BACK BUTTON
               ////if (event.type == Event::MouseButtonPressed)
               ////{
               ////    if (Mouse::isButtonPressed(Mouse::Left) && x > 30 && x < 160 && y > 25 && y < 77 && play)
               ////    {
               ////        cout << "wba3deen";
               ////        play = false;
               ////        MenuVariable = true;
               ////        LvlCounter = menu.GetPressedItem();
               ////        MenuBackGroundTxt = menu.BackPressed(LvlCounter);
               ////        MenuBackGround.setTexture(MenuBackGroundTxt);
               ////    }
               ////}

               /*for (int i = 0; i < 9; i++)
               {
                   for (int j = 0; j < 9; j++)
                   {
                       string temp = to_string(board.v[j][i]);
                       bttn[i][j] = Button{ temp,Vector2f(57.f, 56.f),40,Color::Transparent,Color::White,font,(100.f + (59 * (i)) - (i / 2)), (124.f + (59 * (j)) - (j / 2)) };
                       if (bttn[i][j].getText()._Equal("0")) {
                           bttn[i][j].settext(" ");
                           bttn[i][j].buttonIsClicked(true);
                       }
                       else bttn[i][j].buttonIsClicked(false);



                   }
               }*/


               switch (event.type)
               {

               case Event::MouseButtonPressed:
               {
                   position = sf::Mouse::getPosition(window);
                   x = position.x;
                   y = position.y;
                   cout << "clicked : " << x << ' ' << y << endl;
                   if (Mouse::isButtonPressed(Mouse::Left) && x > 30 && x < 160 && y > 25 && y < 77)
                   {
                       cout << "eshtghaal";
                       play = false;
                       MenuVariable = true;
                       menu.lvlCount = 0;
                       MenuBackGroundTxt = menu.BackgroundTxt();
                       MenuBackGround.setTexture(MenuBackGroundTxt);
                   }
                   for (int col = 0; col < 9; col++)
                   {
                       for (int row = 0; row < 9; row++)
                       {
                           if (bttn[col][row].MouseClicked(window) && bttn[col][row].IsClickable)
                           {
                               lastCellClickedCol = col, lastCellClickedRow = row;
                               cout << "Cell clicked : " << row << ' ' << col << endl;

                               bttn[col][row].setBackColor(sf::Color(255, 255, 255, 128));
                           }
                           else bttn[col][row].setBackColor(Color::Transparent);
                       }
                   }
                   for (int i = 0; i < 10; i++)
                   {
                       if (NumBtn[i].MouseClicked(window) == true && lastCellClickedCol != -1 && lastCellClickedRow != -1) {
                           string t = NumBtn[i].getText();
                           bttn[lastCellClickedCol][lastCellClickedRow].settext(t);
                           cout << "mohsen: " << lastCellClickedCol << ' ' << lastCellClickedRow << ' ' << t << endl;
                           //UNDO REDO LOGIC
                           m[i].i = lastCellClickedCol;
                           m[i].j = lastCellClickedRow;
                           m[i].value = stoi(NumBtn[i].getText());
                           Undo.PushMoves(m[i].value);
                           cout << "wslt" << endl;

                           if (SpecialBtn[4].MouseClicked(window) == true) {
                               cout << "special bttn clicked 4" << endl;
                               Undo.PopMoves();
                               cout << Undo.top();
                               Redo.PushMoves(Undo.top());
                               bttn[lastCellClickedCol][lastCellClickedRow].settext(" ");
                               Undo.PushMoves(Redo.top());
                               cout << i + 1 << endl;
                           }
                           if (SpecialBtn[3].MouseClicked(window) == true) {
                               cout << "special bttn clicked 3" << endl;
                               Redo.PopMoves();
                               bttn[m[i].i][m[i].j].settext(to_string(m[i].value));
                           }
                           if (Check(play, bttn, TimeTaken, LvlCounter) == true)
                           {
                               cout << "Winner winner chicken dinner!!!" << endl;
                           }
                           break;
                       }
                   }
                   

               }
               }
           }

           window.clear();

           if (MenuVariable)
           {

               window.draw(MenuBackGround);
           }

           if (play)
           {
               window.draw(Background);
               for (int i = 0; i < 9; i++)
               {
                   for (int j = 0; j < 9; j++)
                   {
                       bttn[j][i].drawto(window);
                   }
               }
               for (int i = 0; i < 10; i++)
               {
                   NumBtn[i].drawto(window);
               }
               for (int i = 0; i < 5; i++)
               {
                   SpecialBtn[i].drawto(window);
               }
               window.draw(timescore);
           }

           if (leaderBoard)
           {

               highscore.HighScore(TimeTaken, LvlCounter);
               highscore.drawto(window, LvlCounter);
           }

           window.display();



       }




   }


    return 0;
}