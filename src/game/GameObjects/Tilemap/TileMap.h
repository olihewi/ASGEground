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
  explicit TileMap(ASGE::Renderer* renderer);
  void update(float dt) override;
  void render(ASGE::Renderer* renderer) override;
 private:
  std::array<Tile,2500> tiles;
};

#endif // ASGEGROUND_TILEMAP_H
