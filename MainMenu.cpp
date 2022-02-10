#include "MainMenu.h"
#include "Button.h"



MainMenu::MainMenu()
{

}

Texture MainMenu::BackgroundTxt()
{
	switch (lvlCount)
	{
	case 0:
		if (!T1.loadFromFile("GSudoku.png")) {
			cout << "couldn't load file";
		}
		else
			break;
	case 1:
		if (!T1.loadFromFile("OSudoku.png")) {
			cout << "couldn't load file";
		}
		else
			break;
	case 2:
		if (!T1.loadFromFile("RSudoku.png")) {
			cout << "couldn't load file";
		}
		else
			break;
	}
	return T1;
}

Texture MainMenu::BackPressed(int lvlcount)
{
	switch (lvlCount)
	{
	case 0:
		if (!T1.loadFromFile("GSudoku.png")) {
			cout << "couldn't load file";
		}
		else
			break;
	case 1:
		if (!T1.loadFromFile("OSudoku.png")) {
			cout << "couldn't load file";
		}
		else
			break;
	case 2:
		if (!T1.loadFromFile("RSudoku.png")) {
			cout << "couldn't load file";
		}
		else
			break;
	}
	return T1;
}

void MainMenu::MoveLeft()
{
	while (true)
	{
		if (Counter == 0)
		{
			lvlCount = 0;
			break;
		}
		if (Counter == 1)
		{

			Counter--;
			lvlCount = 1;

			break;
		}
		if (Counter == 2)
		{
			Counter--;
			lvlCount = 2;

			break;
		}
		else break;

	}
}




void MainMenu::MoveRight()
{
	while (true)
	{
		if (Counter == 0)
		{

			lvlCount = 0;
			Counter++;

			break;
		}
		else if (Counter == 1)
		{

			Counter++;
			lvlCount = 1;


			break;
		}
		else if (Counter == 2)
		{
			lvlCount = 2;

			break;

		}
		else break;
	}
}

int MainMenu::GetPressedItem()
{
	return lvlCount;
}