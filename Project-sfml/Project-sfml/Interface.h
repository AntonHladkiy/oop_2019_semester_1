#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
class Interface
{
public:
	//write something
	void print_message(std::string msg_text, sf::Vector2f pos,sf::RenderWindow &window);
	Interface();
	~Interface();
};

