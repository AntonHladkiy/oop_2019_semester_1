 

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

//Problem with unit testing visual game like this is that almost all methods are private or dont return anything
TEST_CASE("Start of game check", "[start]") {
	Participant* pl_2=new Bot(false);
	Participant* pl_1 = new Player(true);
	REQUIRE(pl_1->is_bot() == false);
	REQUIRE(pl_2->is_bot() == true);
	Game* game=new Game;
	REQUIRE(game->are_we_still_playing() == true);
}
TEST_CASE("check for ship placing", "[placing]") {
	Game game;
	Participant* pl_1 = new Player(true);
	REQUIRE(pl_1->make_turn(game,sf::Vector2f(400,150) )== false);
	REQUIRE(pl_1->make_turn(game, sf::Vector2f(540, 400)) == false);
	REQUIRE(pl_1->make_turn(game, sf::Vector2f(540, 600)) == false);
	REQUIRE(pl_1->make_turn(game, sf::Vector2f(900, 180)) == true);
	REQUIRE(pl_1->make_turn(game, sf::Vector2f(900, 180)) == false);
	REQUIRE(pl_1->make_turn(game, sf::Vector2f(900, 600)) == true);
}
