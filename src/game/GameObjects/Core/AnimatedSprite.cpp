//
// Created by hewis on 19/03/2021.
//

#include "AnimatedSprite.h"
#include <Engine/Sprite.h>
#include <cmath>
AnimatedSprite::AnimatedSprite(
  ASGE::Renderer* renderer, const std::vector<std::string>& sprite_paths,
  ASGE::Point2D position, float _speed)
{
  for (auto& file_path : sprite_paths)
  {
    auto& sprite = sprites.emplace_back(renderer->createUniqueSprite());
    sprite->loadTexture(file_path);
    sprite->xPos(position.x);
    sprite->yPos(position.y);
  }
  speed = _speed;
}
void AnimatedSprite::update(float dt)
{
  timer = fmod(timer + dt,sprites.size() * (1/speed));
}
void AnimatedSprite::render(ASGE::Renderer* renderer)
{
  if (visible)
  {
    renderer->renderSprite(*sprites[floor(timer * (1/speed))]);
  }
}
bool AnimatedSprite::visibility() const
{
  return visible;
}
void AnimatedSprite::visibility(bool _visibility)
{
  visible = _visibility;
}
ASGE::Point2D AnimatedSprite::position()
{
  return ASGE::Point2D(sprites.front()->xPos(),sprites.front()->yPos());
}
void AnimatedSprite::position(ASGE::Point2D _position)
{
  for (auto& sprite : sprites)
  {
    sprite->xPos(_position.x);
    sprite->yPos(_position.y);
  }
}
void AnimatedSprite::translate(ASGE::Point2D _translation)
{
  for (auto& sprite : sprites)
  {
    sprite->xPos(sprite->xPos() + _translation.x);
    sprite->yPos(sprite->yPos() + _translation.y);
  }
}
float AnimatedSprite::rotation()
{
  return sprites.front()->rotationInRadians();
}
void AnimatedSprite::rotation(float _radians)
{
  for (auto& sprite : sprites)
  {
    sprite->rotationInRadians(_radians);
  }
}
void AnimatedSprite::rotate(float _radians)
{
  for (auto& sprite : sprites)
  {
    sprite->rotationInRadians(sprite->rotationInRadians() + _radians);
  }
}
ASGE::Colour AnimatedSprite::colour()
{
  return sprites.front()->colour();
}
void AnimatedSprite::colour(ASGE::Colour _colour)
{
  for (auto& sprite : sprites)
  {
    sprite->colour(_colour);
  }
}
float AnimatedSprite::opacity()
{
  return sprites.front()->opacity();
}
void AnimatedSprite::opacity(float _opacity)
{
  for (auto& sprite : sprites)
  {
    sprite->opacity(_opacity);
  }
}
ASGE::Point2D AnimatedSprite::centre()
{
  return ASGE::Point2D(sprites.front()->xPos() + sprites.front()->width()/2,
                       sprites.front()->yPos() + sprites.front()->height()/2);
}
