#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <random>
#include <cstdlib>
#pragma once
class Pipe
{
public:
	Pipe(sf::Time deltatime);
	void spawn();
	void move();
	sf::Sprite up;
	sf::Sprite down;
private:
	sf::Time deltatime;
	sf::Texture pipeTexture;
	int speed;
};

