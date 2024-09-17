#include "game.h"

Game::Game() : window(sf::VideoMode(288, 512), "Game") { 
	std::srand((unsigned)time(NULL));
	load();
}
Game::~Game() {
	delete this->bird;
}
void Game::load() {
	this->window.setFramerateLimit(60);
	start();
	sf::Event event;
	sf::Clock deltaClock;
	while (window.isOpen()) {
		this->deltatime = deltaClock.restart();
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			handleEvents(event);
		}
		update();
		render();
	}
}
void Game::start() {
	stopThread = false;
	this->background.loadFromFile("background.png");
	bird = new Bird(20,225);
	pipesThread = std::thread([this]() { spawn_pipes(); });
	pipesThread.detach();
}
void Game::spawn_pipes() {
	while (!stopThread) {
			Pipe pipe(this->deltatime);
			pipe.spawn();
			pipes.push_back(pipe);
			sf::sleep(sf::seconds(4));
	}


}
void Game::handleEvents(sf::Event e) {
	switch (e.type) {
	case sf::Event::KeyPressed:
		switch (e.key.code) {
		case sf::Keyboard::Space:
			if (bird != nullptr)
				bird->jump(this->deltatime);
		}
		break;
	}
}
void Game::render() {
	window.clear();
	sf::Sprite backgroundSprite(this->background);
	window.draw(backgroundSprite);
	if (bird != nullptr)
		window.draw(*bird);
	for (Pipe& p : pipes) {
		window.draw(p.up);
		window.draw(p.down);
	}
	window.display();
}
void Game::update() {
	bird->gravity(this->deltatime);
	int i = 0;
	for (Pipe &p : pipes) {
		p.move();

		if (bird->checkCollision(p)) {
			this->end();
			break;
		}
		if (p.down.getPosition().x < -50) {
			pipes.erase(pipes.begin() + i );
		}
		i++;
	}
}

void Game::end() {
	window.close();
	exit(0);
}