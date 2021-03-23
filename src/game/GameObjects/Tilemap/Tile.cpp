//
// Created by hewis on 20/03/2021.
//

#include "Tile.h"

Tile::Tile(
  ASGE::Renderer* renderer, const std::string& tileset_path, std::array<float,4> rect, ASGE::Point2D position,
  int collision_layer) :
  sprite(std::make_unique<SpriteObject>(renderer, tileset_path, position)),
  collision(collision_layer)
{
  sprite->dimensions(ASGE::Point2D(32,32));
  sprite->srcRect(rect[0],rect[1],rect[2],rect[3]);
}
Tile::Tile() : collision(-1)
{
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
int Tile::collisionLayer() const
{
  return collision;
}
