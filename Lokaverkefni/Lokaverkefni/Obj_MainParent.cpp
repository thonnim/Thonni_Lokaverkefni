#include "Objects.h"


Obj_MainParent::Obj_MainParent(SDL_Renderer* rendererIn, int startX, int startY)
{
	renderer = rendererIn;
	x = startX;
	y = startY;
	imageRectangle.x = startX;
	imageRectangle.y = startY;
	
	sprite = new Sprite(renderer, "resources/mario.png", 16, 28, 4);
}

//A function that takes in a string path and sets the texture to that image
void Obj_MainParent::setTexture(std::string path)
{
	texture = textureLoader.loadTexture(renderer, path);
	SDL_QueryTexture(texture, NULL, NULL, &imageRectangle.w, &imageRectangle.h);
}

void Obj_MainParent::mainUpdate(EventHandler e, GameTime t)
{
	imageRectangle.x = x;
	imageRectangle.y = y;

	sprite->update();
	update(e, t);
}

void Obj_MainParent::update(EventHandler e, GameTime t) {};

//A function that renders the object
void Obj_MainParent::render()
{
	sprite->render(x, y);
}