 

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "Player.h"
#include "Bot.h"
#include "Participant.h"
#include "Interface.h"

TEST_CASE("Start of game check", "[start]") {
	Participant* pl_2=new Bot(false);
	Participant* pl_1 = new Player(true);
	REQUIRE(pl_1->is_bot() == false);
	REQUIRE(pl_2->is_bot() == true);
	Game* game=new Game;
	REQUIRE(game->are_we_still_playing() == true);
}
TEST_CASE("check for hitting right part of board", "[board check]") {
	Game game;
	Participant* pl_1 = new Player(true);
	REQUIRE(pl_1->make_turn(game,sf::Vector2f(400,150) )== false);
	REQUIRE(pl_1->make_turn(game, sf::Vector2f(540, 400)) == false);
	REQUIRE(pl_1->make_turn(game, sf::Vector2f(540, 600)) == false);
	REQUIRE(pl_1->make_turn(game, sf::Vector2f(900, 180)) == true);
	REQUIRE(pl_1->make_turn(game, sf::Vector2f(900, 180)) == false);
	REQUIRE(pl_1->make_turn(game, sf::Vector2f(900, 600)) == true);
}
TEST_CASE("check for placing ship", "[placing check]") {
	Game game;
	cell** pl_1_field;
	pl_1_field = new cell*[10];
	for (size_t i = 0; i < 10; i++)
	{
		pl_1_field[i] = new cell[10];
	}
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			pl_1_field[i][j] = cell::empty;
		}
	}
	Participant* pl_1 = new Player(true);
	//if(game.place_ship(std::pair<int, int>(1, 0), sf::Vector2f(540, 400), pl_1_field, false)!=true)
	//REQUIRE( 2==1);//if i just use require it tells me true!=true
	REQUIRE(game.place_ship(std::pair<int, int>(1, 0), sf::Vector2f(540, 400), pl_1_field, false) != true);
	REQUIRE(game.place_ship(std::pair<int, int>(1, 0), sf::Vector2f(900, 400), pl_1_field, false) != true);
	REQUIRE(game.place_ship(std::pair<int, int>(1, 0), sf::Vector2f(540, 150), pl_1_field, false) != true);
}
TEST_CASE("check for calculating ship by pointing", "[calculating]") {
	Game game;
	cell** pl_1_field;
	pl_1_field = new cell*[10];
	for (size_t i = 0; i < 10; i++)
	{
		pl_1_field[i] = new cell[10];
	}
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			pl_1_field[i][j] = cell::empty;
		}
	}
	Participant* pl_1 = new Player(true);
	game.place_ship(std::pair<int, int>(3, 2), sf::Vector2f(400, 400), pl_1_field, false);
	REQUIRE(game.calc_ship_coord(4, 3, -1, -1, pl_1_field).first == 3);
}
TEST_CASE("check ship for destruction", "[destruction]") {
	Game game;
	cell** pl_1_field;
	pl_1_field = new cell*[10];
	for (size_t i = 0; i < 10; i++)
	{
		pl_1_field[i] = new cell[10];
	}
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			pl_1_field[i][j] = cell::empty;
		}
	}
	size_t size;
	pl_1_field[0][1] = cell::destroyed_ship;
	pl_1_field[0][2] = cell::destroyed_ship;
	pl_1_field[0][3] = cell::destroyed_ship;

	pl_1_field[3][1] = cell::destroyed_ship;
	pl_1_field[3][2] = cell::destroyed_ship;
	pl_1_field[3][3] = cell::ship;
	REQUIRE(game.check_for_destruction(0,1,pl_1_field,-1,-1,size) == true);
	REQUIRE(game.check_for_destruction(3, 1, pl_1_field, -1, -1, size) == false);
}
