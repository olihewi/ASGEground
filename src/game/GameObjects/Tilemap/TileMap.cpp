//
// Created by hewis on 20/03/2021.
//

#include "TileMap.h"
#include <Engine/Input.h>
TileMap::TileMap(ASGE::Renderer* _renderer) : renderer(_renderer)
{
  /*int x = 0;
  int y = 0;
  for (auto& tile : tiles)
  {
    //tile = Tile(renderer, "data/images/tilesets/japanese_city/tileset.png", std::array<float,4> {0,128,32,32}, ASGE::Point2D(x * 32, y * 32));
    x++;
    if (x >= 50)
    {
      x = 0;
      y++;
    }
  }*/
}
void TileMap::update(float dt)
{
  for (auto& tile : tiles)
  {
    tile.update(dt);
  }
}
void TileMap::render(ASGE::Renderer* _renderer)
{
  for (auto& tile : tiles)
  {
    tile.render(_renderer);
  }
}
void TileMap::setTile(size_t index, std::array<float,4> rect)
{
  tiles[index] = Tile(renderer, "data/images/tilesets/japanese_city/tileset.png", rect, ASGE::Point2D(static_cast<float>(index%50) * 32 + 256,static_cast<float>(index/50) * 32));
}
