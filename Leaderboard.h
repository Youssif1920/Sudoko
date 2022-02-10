#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include<list>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
using namespace std;
using namespace sf;
class leaderboard
{
public:
	void HighScore(int score, int lvlcount);
	void drawto(RenderWindow& window, int count);
};

