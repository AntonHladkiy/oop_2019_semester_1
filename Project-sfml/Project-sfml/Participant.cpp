
#include "Participant.h"

#define CELL_SIZE 160
bool Participant::check_cell(Game &game, size_t x, size_t y, cell ** enemy_field,bool& is_destroyed)
{
	
	if (enemy_field[x][y] == cell::miss) return false;
	if (enemy_field[x][y] == cell::destroyed_ship) return false;
	if (enemy_field[x][y] == cell::ship) {
		enemy_field[x][y] = cell::empty;
		size_t size_of_ship = 0;
		if (game.check_for_destruction(x, y, enemy_field, -1, -1, size_of_ship)) {
			is_destroyed = true;
			//is_destroyed = true;
			game.fill_cells(x, y, enemy_field, -1, -1);
			if (am_i_first_pl) {
				//std::cout << game.pl_2_ships[size_of_ship - 1] << std::endl;
				game.pl_2_ships[size_of_ship - 1]--;
			}
			else {
				game.pl_1_ships[size_of_ship - 1]--;
			}
			enemy_field[x][y] = cell::destroyed_ship;
			return false;
		}
		is_destroyed = false;
		enemy_field[x][y] = cell::destroyed_ship;
		return false;
	}
	if (enemy_field[x][y] == cell::empty) {
		if (is_destroyed) {
			is_destroyed = true;
		}
		else {
			is_destroyed = false;
		}
		enemy_field[x][y] = cell::miss;
		return true;
	}

}

bool Participant::am_i_won(Game & game, bool am_i_first_pl)
{
	bool res = true;
	if (am_i_first_pl) {
		for (auto i = 0; i < game.pl_2_ships.size(); i++) {
			if (game.pl_2_ships[i] != 0) {
				res = false;
			}
		}
	}
	else {
		for (auto i = 0; i < game.pl_1_ships.size(); i++) {
			if (game.pl_1_ships[i] != 0) {
				res = false;
			}
		}
	}
	return res;
}



Participant::Participant(bool _am_i_first_pl)
{
	am_i_first_pl = _am_i_first_pl;
}

Participant::Participant()
{
}

Participant::~Participant()
{
}

void Game::draw(sf::RenderWindow & window, Participant* p_1, Participant* p_2)
{
	Interface interface;
	interface.print_message("Your field", sf::Vector2f(150, 100), window);
	interface.print_message("Enemy field", sf::Vector2f(150 + CELL_SIZE * x_scale*board_size + CELL_SIZE, 100), window);
	if (_first_pl_turn) {
		if (!p_1->is_bot()) {
			interface.print_message("Player's 1 turn", sf::Vector2f(600, 50), window);
			draw_pl_field(window, pl_1_field, pl_2_field);
		}
		else {
			interface.print_message("Player's 2 turn", sf::Vector2f(600, 50), window);
			draw_pl_field(window, pl_2_field, pl_1_field);
		}
	}
	else {
		if (!p_2->is_bot()) {
			interface.print_message("Player's 2 turn", sf::Vector2f(600, 50), window);
			draw_pl_field(window, pl_2_field, pl_1_field);
		}
		else {
			interface.print_message("Player's 1 turn", sf::Vector2f(600, 50), window);
			draw_pl_field(window, pl_1_field, pl_2_field);
		}
	}
}

void Interface::open_menu(bool &is_first_bot, bool &is_second_bot, bool& _continue)
{
	sf::Sprite _sprite;
	sf::Texture _texture;
	sf::RenderWindow window(sf::VideoMode(448, 800), "Menu");
	while (window.isOpen())
	{
		sf::Vector2i pixelPos = sf::Mouse::getPosition(window); //coord of mouse (in px)
		sf::Vector2f pos = window.mapPixelToCoords(pixelPos); //coord of mous (transform)
		window.clear();
		print_message("Main Menu", sf::Vector2f(135, 0), window);
		_texture.loadFromFile("../images/pvp2.png");
		_texture.setSmooth(true);
		_sprite.setTexture(_texture);
		_sprite.setPosition(sf::Vector2f(0, 89));
		_sprite.setScale(sf::Vector2f(float(447) / _texture.getSize().x, 1));
		window.draw(_sprite);

		_texture.loadFromFile("../images/pve2.png");
		_sprite.setTexture(_texture);
		_sprite.setPosition(sf::Vector2f(0, 280));
		_sprite.setScale(sf::Vector2f(float(447) / _texture.getSize().x, 1));
		window.draw(_sprite);


		_texture.loadFromFile("../images/exit.png");
		_sprite.setTexture(_texture);
		_sprite.setScale(sf::Vector2f(float(447) / _texture.getSize().x, float(89) / _texture.getSize().y));
		_sprite.setTextureRect(sf::IntRect(0, 0, 453, 89));
		_sprite.setPosition(sf::Vector2f(0, 711));
		window.draw(_sprite);


		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed) {
				window.close();
				_continue = false;
			}
			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.key.code == sf::Mouse::Left) {
					if (pos.y <= 178 && pos.y >= 89 && pos.x >= 0 && pos.x <= 447) {
						is_first_bot = false;
						is_second_bot = false;
						window.close();
					}
					if (pos.y <= 369 && pos.y >= 280 && pos.x >= 0 && pos.x <= 447) {
						is_first_bot = false;
						is_second_bot = true;
						window.close();
					}
					if (pos.y <= 800 && pos.y >= 711 && pos.x >= 0 && pos.x <= 447) {
						window.close();
						_continue = false;
					}
				}
			}

		}
		window.display();
	}
}
