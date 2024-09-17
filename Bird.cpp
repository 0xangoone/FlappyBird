#include "Bird.h"
Bird::Bird(int x ,int y , sf::Texture texture) {
	this->birdTexture = texture;
	load(x, y, birdTexture);
}
Bird::Bird(int x, int y) {
	birdTexture.loadFromFile("flappy.png");
	load(x, y, birdTexture);

}
void Bird::load(int x, int y,sf::Texture& texture) {
	this->jump_hight = 0.4f;
	this->gravity_r = 0.5f;
	this->cur_gravity_r = gravity_r;

	this->setTexture(texture);
	this->setPosition(x, y);
	this->setScale(0.1f, 0.1f);
}
void Bird::jump(sf::Time deltatime) {
	this->cur_gravity_r = -1.0f;
	sf::Vector2 cur_pos = this->getPosition();
	this->setPosition(cur_pos.x, cur_pos.y - jump_hight * deltatime.asMilliseconds());
}
void Bird::gravity(sf::Time deltatime) {
	if (cur_gravity_r < gravity_r) {
		cur_gravity_r += 0.1f;
	}
	sf::Vector2 cur_pos = this->getPosition();
	this->setPosition(cur_pos.x, cur_pos.y + cur_gravity_r * deltatime.asMilliseconds());
}
bool Bird::checkCollision(Pipe pipe) {
	if (this->getGlobalBounds().intersects(pipe.up.getGlobalBounds())) {
		return true;
	}
	if (this->getGlobalBounds().intersects(pipe.down.getGlobalBounds())) {
		return true;
	}
	return false;
}