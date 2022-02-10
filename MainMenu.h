#pragma once

#include <SFML/Graphics.hpp>
#include <SFML\Graphics\Font.hpp>
#include <SFML\Window\Cursor.hpp>
#include <SFML\Graphics\RenderWindow.hpp>
#include "Button.h"
#define UNIQUE_mainmenu
#ifndef UNIQUE_mainmenu

#endif // !UNIQUE


using namespace std;
using namespace sf;



class  MainMenu {
public:
	//Constructor
	MainMenu();

	//Functions
	Texture BackgroundTxt();
	Texture BackPressed(int lvlcount);
	void MoveLeft();
	void MoveRight();
	int GetPressedItem();



public:

	int Counter = 0;
	int lvlCount = 0;
	Texture T1;


};