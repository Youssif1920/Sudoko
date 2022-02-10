#include "Button.h"

Button::Button(Vector2f size, Color bgcolor, Vector2f pos)
{
	button.setFillColor(bgcolor);
	button.setSize(size);
	button.setPosition(pos);
}
Button::Button()
{
	button.setFillColor(Color::White);
	button.setSize(Vector2f(57, 56));
	text.setFont(font);
	text.setString("");
	text.setFillColor(Color::White);
	text.setCharacterSize(40);
	text.setPosition((button.getGlobalBounds().width / 2) -
		(text.getGlobalBounds().width / 2) , (button.getGlobalBounds().height / 2) -
		(text.getGlobalBounds().height / 2));


}

Button::Button(string t, Vector2f size, int charsize, Color bgcolor, Color txtcolor, Font& font, float x, float y)
{
	text.setString(t);
	text.setFillColor(txtcolor);
	text.setCharacterSize(charsize);
	button.setFillColor(bgcolor);
	button.setSize(size);
	text.setFont(font);
	button.setPosition(x, y);
	float posX = (x + button.getGlobalBounds().width / 2) -(text.getGlobalBounds().width / 2);
	float posY = (y + button.getGlobalBounds().height / 2) -(text.getGlobalBounds().height / 2);
	text.setPosition({ posX,posY });
}

void Button::setFont(Font& font)
{
	text.setFont(font);
}


void Button::setBackColor(Color color)
{
	button.setFillColor(color);
}


void Button::settext(string t)
{
	text.setString(t);
}

void Button::setpos(float x, float y)
{
	button.setPosition(x, y);
}

Vector2f Button::setTxtPos()
{
	float x = button.getPosition().x;
	float y = button.getPosition().y;
	float posX = (x + button.getGlobalBounds().width / 2) - (text.getGlobalBounds().width / 2);
	float posY = (y + button.getGlobalBounds().height / 2) - (text.getGlobalBounds().height / 2);
	text.setPosition({ posX,posY });
	return { posX,posY };
}

string Button::getText()
{
	return text.getString();
}

bool Button::mousehover(RenderWindow& window)
{
	float mouseX = Mouse::getPosition(window).x;
	float mouseY = Mouse::getPosition(window).y;

	float BtnPosX = button.getPosition().x;
	float BtnPosY = button.getPosition().y;
	float BtnPosW = button.getPosition().x + button.getGlobalBounds().width;
	float BtnPosH = button.getPosition().y + button.getGlobalBounds().height;

	if (mouseX<BtnPosW && mouseX>BtnPosX && mouseY<BtnPosH && mouseY> BtnPosY)
	{
		return true;
	}
	return false;

}
bool Button::MouseClicked(RenderWindow& window)
{
	float mouseX = Mouse::getPosition(window).x;
	float mouseY = Mouse::getPosition(window).y;

	float BtnPosX = button.getPosition().x;
	float BtnPosY = button.getPosition().y;
	float BtnPosW = button.getPosition().x + button.getGlobalBounds().width;
	float BtnPosH = button.getPosition().y + button.getGlobalBounds().height;

	while (Mouse::isButtonPressed(Mouse::Left) && mouseX<BtnPosW && mouseX>BtnPosX && mouseY<BtnPosH && mouseY> BtnPosY)
	{
		return true;
	}
	return false;

}

void Button::buttonIsClicked(bool val)
{
	IsClickable = val;
}
void Button::drawto(RenderWindow& window)
{
	window.draw(button);
	window.draw(text);

}