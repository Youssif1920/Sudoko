#pragma once
#include <SFML\Graphics\RenderWindow.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
#include <SFML/window.hpp>
#include <SFML/system.hpp>
#include <fstream>
#include <list>
#include <string>
#include <vector>
#include "button.h"
using namespace sf;
class Board
{
public:
	void fillboard(int select);
	vector<vector<int>> v;

};
