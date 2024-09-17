#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <thread>
#include "Bird.h"
#include "Pipe.h"
#include <iostream>
#include <windows.h>
#pragma once
class Game
{
public:
	Game();
	~Game();
	void load();
private:
	void handleEvents(sf::Event e);
	void render();
	void update();
	void start();
	void end();
	void spawn_pipes();
	sf::RenderWindow window;
/*************************************/
	sf::Texture background;
	Bird* bird;
	std::vector<Pipe> pipes;
	sf::Time deltatime;

	std::atomic<bool> stopThread;
	std::thread pipesThread;
};

