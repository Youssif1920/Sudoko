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

class Button {
public:

	Button(Vector2f size, Color bgcolor, Vector2f pos);

	Button();

	Button(string t, Vector2f size, int charsize, Color bgcolor, Color txtcolor, Font& font, float x, float y);

	void setFont(Font& font);

	void settext(string t);

	void setBackColor(Color color);

	void buttonIsClicked(bool);

	void setpos(float x, float y);

	Vector2f setTxtPos();

	string getText();

	void drawto(RenderWindow& window);

	bool mousehover(RenderWindow& window);

	bool MouseClicked(RenderWindow& window);

	bool IsClickable = true;
private:
	
	Text text;
	RectangleShape button;
	int width, height;
	Color color;
	Font font;
};