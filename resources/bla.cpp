        #include <SFML/Graphics.hpp>
        #include <iostream>
        #include "MainMenu.h"
        #include"Button.h"




        using namespace sf;
        using namespace std;


        int main()
        {

            RenderWindow window(VideoMode(720, 1080), "Sudoko");

            int count = 0;
            int start0 = 1;
            int start1 = 1;
            int start2 = 1;
            int close = 1;
            Font font;
            Texture texture;

            if (!texture.loadFromFile("GGame.png")) {
                cout << "couldn't load file";


            }
            if (!font.loadFromFile("ariblk.ttf"))
            {
                cout << "font not loaded\n";
            }

            Sprite sprite;
            sprite.setTexture(texture);

            Button* b =new Button[10];
            for (int i = 0; i < 5; i++) {
                b[i]=Button(to_string(i+1),{ 66 ,59 },30, Color::Transparent,Color::Black,font,(150 +(99*i)),825);
               b[i].setpos( (129 +(40 *i)+(59 *i)),816 );
            }
            for (int i = 0; i < 5; i++) {
                b[i+5] = Button(to_string(i + 6), { 66 ,59 }, 30, Color::Transparent, Color::Black, font, (150 + (99 * i)), 903);
                b[i+5].setpos((129 + (40 * i) + (59 * i)), 892);
                b[9].settext("X");
            }



            while (window.isOpen())
            {
        
           


       
       
       

                Event event;
                while (window.pollEvent(event))
                {
                    switch (event.type)
                    {
                    case Event::Closed:
                        window.close();
                    

                    }
                    for (int i = 0; i < 10; i++)
                    {
                        if (b[i].MouseClicked(window) == true) {
                            cout<< i+1 << endl;
                        }
                    }
                   
           
           
        
                }

                window.clear();
                window.draw(sprite);
                for (int i = 0; i < 10; i++){
                    b[i].drawto(window);

                }
               
                window.display();
       
            }

            return 0;
    
        }



