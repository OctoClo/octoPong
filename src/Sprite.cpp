#include "Sprite.h"

Sprite::Sprite():
    x(0),
    y(0),
    width(0),
    height(0)
{}

Sprite::~Sprite() {}

void Sprite::init(float newX, float newY, float newWidth, float newHeight)
{
    this->x = newX;
    this->y = newY;
    this->width = newWidth;
    this->height = newHeight;
}

void Sprite::draw()
{

}
