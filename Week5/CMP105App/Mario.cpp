#include "Mario.h"

Mario::Mario() 
{
	walk.addFrame(sf::IntRect(0, 0, 15, 21));
	walk.addFrame(sf::IntRect(15, 0, 15, 21));
	walk.addFrame(sf::IntRect(30, 0, 15, 21));
	walk.addFrame(sf::IntRect(45, 0, 15, 21));
	walk.setFrameSpeed(1.f / 3.f);

	swim.addFrame(sf::IntRect(0, 21, 16, 20));
	swim.addFrame(sf::IntRect(16, 21, 16, 20));
	swim.addFrame(sf::IntRect(32, 21, 16, 20));
	swim.setFrameSpeed(1.f / 3.f);


	duck.addFrame(sf::IntRect(0, 41, 16, 20));
	duck.addFrame(sf::IntRect(16, 41, 16, 20));
	swim.setFrameSpeed(1.f / 3.f);

	currentAnimation = &walk;
	setTextureRect(currentAnimation->getCurrentFrame());
}

Mario::~Mario()
{

}

void Mario::update(float dt) 
{
	currentAnimation->animate(dt);
	setTextureRect(currentAnimation->getCurrentFrame());

	if (input->isKeyDown(sf::Keyboard::Num1))
	{
		currentAnimation = &walk;
		currentAnimation->reset();
		setTextureRect(currentAnimation->getCurrentFrame());
	}

	if (input->isKeyDown(sf::Keyboard::Num2))
	{
		currentAnimation = &swim;
		currentAnimation->reset();
		setTextureRect(currentAnimation->getCurrentFrame());
	}

	if (input->isKeyDown(sf::Keyboard::Num3))
	{
		currentAnimation = &duck;
		currentAnimation->reset();
		setTextureRect(currentAnimation->getCurrentFrame());
	}

}

void Mario::handleInput(float dt)
{

}