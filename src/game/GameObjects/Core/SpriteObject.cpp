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
  sprite->width(_dimensions.x);
  sprite->height(_dimensions.y);
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
bool SpriteObject::isInside(ASGE::Point2D position)
{
  return position.x >= sprite->xPos() &&
         position.x <= sprite->xPos() + sprite->width() &&
         position.y >= sprite->yPos() &&
         position.y <= sprite->yPos() + sprite->height();
}
short SpriteObject::zOrder()
{
  return sprite->getGlobalZOrder();
}
void SpriteObject::zOrder(short z_order)
{
  sprite->setGlobalZOrder(z_order);
}

void SpriteObject::srcRect(float x, float y, float w, float h)
{
  auto* src_rect = sprite->srcRect();
  src_rect[0] = x;
  src_rect[1] = y;
  src_rect[2] = w;
  src_rect[3] = h;
}
