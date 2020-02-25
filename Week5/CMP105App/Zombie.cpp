#include "Zombie.h"


Zombie::Zombie()
{
	//Setup Walk Animation
	walk.addFrame(sf::IntRect(0, 0, 55, 108));
	walk.addFrame(sf::IntRect(55, 0, 55, 108));
	walk.addFrame(sf::IntRect(110, 0, 55, 108));
	walk.addFrame(sf::IntRect(165, 0, 55, 108));
	walk.addFrame(sf::IntRect(220, 0, 55, 108));
	walk.addFrame(sf::IntRect(275, 0, 55, 108));
	walk.addFrame(sf::IntRect(330, 0, 55, 108));
	walk.addFrame(sf::IntRect(385, 0, 55, 108));
	walk.setFrameSpeed(1.f / 10.f);

	speed = 200;
}

Zombie::~Zombie() 
{

}

void Zombie::update(float dt)
{
	setTextureRect(walk.getCurrentFrame());
}

void Zombie::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		move(speed * dt, 0);
		walk.animate(dt);	
		walk.setFlipped(false);
	}
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		move(-speed * dt, 0);
		walk.animate(dt);
		walk.setFlipped(true);
	}
}
