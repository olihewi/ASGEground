//
// Created by hewis on 19/03/2021.
//

#include "AnimatedSprite.h"
#include <Engine/Sprite.h>
#include <cmath>
AnimatedSprite::AnimatedSprite(
  ASGE::Renderer* renderer, const std::string& folder_path, size_t num_frames,
  ASGE::Point2D position, float playback_speed) : SpriteObject(renderer,folder_path + "/1.png")
{
  for (size_t i = 1; i <= num_frames; i++)
  {
    auto& sprite = sprites.emplace_back(renderer->createUniqueSprite());
    sprite->loadTexture(folder_path + "/" + std::to_string(i) + ".png");
    sprite->xPos(position.x);
    sprite->yPos(position.y);
  }
  speed = playback_speed;
}
void AnimatedSprite::update(float dt)
{
  timer = fmod(timer + dt,sprites.size() / speed);
}
void AnimatedSprite::render(ASGE::Renderer* renderer)
{
  if (visible)
  {
    renderer->renderSprite(*sprites[floor(timer * speed)]);
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
ASGE::Point2D AnimatedSprite::dimensions()
{
  return ASGE::Point2D(sprites.front()->width(),sprites.front()->height());
}
void AnimatedSprite::dimensions(ASGE::Point2D _dimensions)
{
  for (auto& sprite : sprites)
  {
    sprite->width(_dimensions.x);
    sprite->height(_dimensions.y);
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
bool AnimatedSprite::isInside(ASGE::Point2D position)
{
  return position.x >= sprites.front()->xPos() &&
         position.x <= sprites.front()->xPos() + sprites.front()->width() &&
         position.y >= sprites.front()->yPos() &&
         position.y <= sprites.front()->yPos() + sprites.front()->height();
}
