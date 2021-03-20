//
// Created by hewis on 20/03/2021.
//

#include "Tile.h"
#include <game/GameObjects/Core/AnimatedSprite.h>
#include <utility>

Tile::Tile(
  ASGE::Renderer* renderer, const std::string& file_path, ASGE::Point2D position,
  int collision_layer, int animation_frames, float playback_speed,
  ASGE::Point2D collision_offset_ul, ASGE::Point2D collision_offset_br) :
  layer(collision_layer),
  collision_offset_1(std::move(collision_offset_ul)),
  collision_offset_2(std::move(collision_offset_br))
{
  if (animation_frames <= 0) /// Static Sprite
  {
    sprite = std::make_unique<SpriteObject>(renderer, file_path, position);
  }
  else /// Animated Sprite
  {
    sprite = std::make_unique<AnimatedSprite>(renderer, file_path, animation_frames, position, playback_speed);
  }
}
void Tile::update(float dt)
{
  if (sprite == nullptr) { return; }
  sprite->update(dt);
}
void Tile::render(ASGE::Renderer* renderer)
{
  if (sprite == nullptr) { return; }
  sprite->render(renderer);
}
bool Tile::isColliding(ASGE::Point2D position, int other_collision_layer)
{
  if (other_collision_layer <= layer || layer < 0) { return false; }
  return (position.x >= sprite->position().x + collision_offset_1.x &&
      position.x <= sprite->position().x + sprite->dimensions().x + collision_offset_2.x &&
      position.y >= sprite->position().y + collision_offset_1.y &&
      position.y <= sprite->position().y + sprite->dimensions().y + collision_offset_2.y);
}
bool Tile::isColliding(ASGE::Point2D position_ul, ASGE::Point2D position_br, int other_collision_layer)
{
  if (other_collision_layer <= layer || layer < 0) { return false; }
  return (position_br.x >= sprite->position().x + collision_offset_1.x &&
           position_ul.x <= sprite->position().x + sprite->dimensions().x + collision_offset_2.x &&
           position_br.y >= sprite->position().y + collision_offset_1.y &&
           position_ul.y <= sprite->position().y + sprite->dimensions().y + collision_offset_2.y);
}
Tile::Tile() : layer(-1)
{
}
