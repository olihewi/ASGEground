//
// Created by hewis on 19/03/2021.
//

#include "AnimatedSprite.h"
#include <cmath>
AnimatedSprite::AnimatedSprite(
  ASGE::Renderer* renderer, const std::string& file_path,
  ASGE::Point2D position, float playback_speed) : SpriteObject(renderer,file_path, position), speed(playback_speed)
{
  auto dims = SpriteObject::dimensions();
  frames = dims.x / dims.y;
  sprite_size = dims.y;
  SpriteObject::srcRect(0,0,dims.y,dims.y);
  SpriteObject::dimensions(ASGE::Point2D(dims.y,dims.y));
}
void AnimatedSprite::update(float dt)
{
  timer = fmod(timer + dt,frames / speed);
  int this_frame = floor(timer * speed);
  SpriteObject::srcRect(static_cast<float>(this_frame) * sprite_size,0,sprite_size,sprite_size);
}