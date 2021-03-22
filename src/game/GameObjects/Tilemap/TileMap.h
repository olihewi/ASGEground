//
// Created by hewis on 20/03/2021.
//

#ifndef ASGEGROUND_TILEMAP_H
#define ASGEGROUND_TILEMAP_H

#include <game/GameObjects/Tilemap/Tile.h>
#include <vector>
class TileMap : public GameObject
{
 public:
  explicit TileMap(ASGE::Renderer* _renderer);
  void update(float dt) override;
  void render(ASGE::Renderer* _renderer) override;
  void setTile(size_t index, std::array<float,4> rect);
 private:
  std::array<Tile,2500> tiles;
  ASGE::Renderer* renderer;
};

#endif // ASGEGROUND_TILEMAP_H
