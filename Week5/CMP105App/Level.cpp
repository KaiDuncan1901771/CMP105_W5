#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

	zombTexture.loadFromFile("gfx/animZombie.png");
	zombie.setTexture(&zombTexture);
	zombie.setSize(sf::Vector2f(55, 108));
	zombie.setPosition(100, 100);
	zombie.setInput(input);

	marioTexture.loadFromFile("gfx/MarioSheetT.png");
	mario.setTexture(&marioTexture);
	mario.setSize(sf::Vector2f(48, 63));
	mario.setPosition(500, 100);
	mario.setInput(input);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	zombie.handleInput(dt);
	zombie.update(dt);

	mario.handleInput(dt);
	mario.update(dt);
}

// Update game objects
void Level::update(float dt)
{

}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(zombie);
	window->draw(mario);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}