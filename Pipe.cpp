#include "Pipe.h"
Pipe::Pipe(sf::Time deltatime) {
	this->deltatime = deltatime;
	this->speed = 30.0f;
	this->pipeTexture.loadFromFile("pipe.png");
	this->up.setTexture(pipeTexture);
	this->down.setTexture(pipeTexture);
	this->up.setScale(1.f, -1.f);
	
}
void Pipe::spawn() {
	int x = 300;

	int upY = rand() % 150 + 100; 
	int downY = upY + 150;  

	this->up.setPosition(x, upY);
	this->down.setPosition(x, downY);
}
void Pipe::move() {
	sf::Vector2f cur_up_pos = up.getPosition();
	sf::Vector2f cur_down_pos = down.getPosition();
	this->up.setPosition( cur_up_pos.x - speed * deltatime.asSeconds() ,cur_up_pos.y);
	this->down.setPosition(cur_down_pos.x - speed * deltatime.asSeconds(), cur_down_pos.y);
}
