#pragma once
#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>
#include<cstring>
#include<SFML\Audio.hpp>
#include<SFML\Graphics.hpp>
#include<SFML\System.hpp>
#include<SFML\window.hpp>
#include<SFML\network.hpp>



using namespace std;
using namespace sf;

class Button{
public:

	Button(Vector2f size, Color bgcolor, Vector2f pos);

	Button();

	Button(string t, Vector2f size, int charsize, Color bgcolor, Color txtcolor, Font& font , float x, float y);
	

	void setFont(Font& font);
	
	void settext(string t);

	void setBackColor(Color color);

	void setpos(float x, float y);

	void settextpos(Vector2f pos);
	

	void drawto(RenderWindow& window);

	bool mousehover(RenderWindow& window);

	bool MouseClicked(RenderWindow& window);


private:
	Text text;
   RectangleShape button;
};