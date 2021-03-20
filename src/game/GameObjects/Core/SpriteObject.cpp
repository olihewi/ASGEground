//
// Created by hewis on 19/03/2021.
//

#include "SpriteObject.h"
#include <cmath>

SpriteObject::SpriteObject(
  ASGE::Renderer* renderer, const std::string& file_path,
  ASGE::Point2D position)
{
  loadSprite(renderer, file_path);
  sprite->xPos(position.x);
  sprite->yPos(position.y);
}
bool SpriteObject::loadSprite(
  ASGE::Renderer* renderer, const std::string& file_path)
{
  if (sprite == nullptr)
  {
    sprite = renderer->createUniqueSprite();
  }
  return sprite->loadTexture(file_path);
}

void SpriteObject::render(ASGE::Renderer* renderer)
{
  if (visible)
  {
    renderer->renderSprite(*sprite);
  }
}

bool SpriteObject::visibility() const
{
  return visible;
}
void SpriteObject::visibility(bool _visibility)
{
  visible = _visibility;
}

ASGE::Point2D SpriteObject::position()
{
  return ASGE::Point2D(sprite->xPos(), sprite->yPos());
}
void SpriteObject::position(ASGE::Point2D _position)
{
  sprite->xPos(_position.x);
  sprite->yPos(_position.y);
}
void SpriteObject::translate(ASGE::Point2D _translation)
{
  sprite->xPos(sprite->xPos() + _translation.x);
  sprite->yPos(sprite->yPos() + _translation.y);
}
ASGE::Point2D SpriteObject::dimensions()
{
  return ASGE::Point2D(sprite->width(),sprite->height());
}
void SpriteObject::dimensions(ASGE::Point2D _dimensions)
{
  sprite->dimensions(_dimensions.x,_dimensions.y);
}

float SpriteObject::rotation()
{
  return sprite->rotationInRadians();
}
void SpriteObject::rotation(float _radians)
{
  sprite->rotationInRadians(_radians);
}
void SpriteObject::rotate(float _radians)
{
  sprite->rotationInRadians(fmod(sprite->rotationInRadians() + _radians,2 * 3.14159265358979323846F));
}

ASGE::Colour SpriteObject::colour()
{
  return sprite->colour();
}
void SpriteObject::colour(ASGE::Colour _colour)
{
  sprite->colour(_colour);
}

float SpriteObject::opacity()
{
  return sprite->opacity();
}
void SpriteObject::opacity(float _opacity)
{
  sprite->opacity(_opacity);
}

ASGE::Point2D SpriteObject::centre()
{
  return ASGE::Point2D(sprite->xPos() + sprite->width() / 2,
                       sprite->yPos() + sprite->height() / 2);
}
