#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>


class Participant;
class Player;
class Bot;
class Interface
{
public:
	//open menu
	void open_menu(bool &is_first_bot, bool &is_second_bot,bool& _continue);
	//write something
	void print_message(std::string msg_text, sf::Vector2f pos,sf::RenderWindow &window);
	Interface();
	~Interface();
};

