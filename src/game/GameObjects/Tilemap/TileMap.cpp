//
// Created by hewis on 20/03/2021.
//

#include "TileMap.h"
TileMap::TileMap(ASGE::Renderer* renderer)
{
  int x = 0;
  int y = 0;
  for (auto& tile : tiles)
  {
    tile = Tile(renderer, "data/images/tilesets/japanese_city/tiles/pavement/GK_JC__014.png", ASGE::Point2D(x * 32, y * 32));
    x++;
    if (x >= 50)
    {
      x = 0;
      y++;
    }
  }
}
void TileMap::update(float dt)
{
  for (auto& tile : tiles)
  {
    tile.update(dt);
  }
}
void TileMap::render(ASGE::Renderer* renderer)
{
  for (auto& tile : tiles)
  {
    tile.render(renderer);
  }
}
