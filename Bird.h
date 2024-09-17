#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Pipe.h"
#pragma once
class Bird : public sf::Sprite {
public:
	Bird(int x , int y, sf::Texture texture);
	Bird(int x, int y);
	void jump(sf::Time deltatime);
	void gravity(sf::Time deltatime);
	bool checkCollision(Pipe pipe);
private:
	sf::Texture birdTexture;
	void load(int x, int y, sf::Texture& texture);

	float jump_hight;
	float gravity_r;
	float cur_gravity_r;
};

