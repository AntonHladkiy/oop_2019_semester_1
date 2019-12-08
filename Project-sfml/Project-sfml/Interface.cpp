#include "Interface.h"



void Interface::print_message(std::string msg_text, sf::Vector2f pos, sf::RenderWindow &window)
{
	sf::Font font;
	font.loadFromFile("calibri.ttf");
	sf::Text text;
	text.setFont(font);
	text.setString(msg_text);
	text.setCharacterSize(35);
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(5);
	text.setPosition(pos);
	window.draw(text);
}

Interface::Interface()
{
}


Interface::~Interface()
{
}
