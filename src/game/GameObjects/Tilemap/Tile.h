//
// Created by hewis on 20/03/2021.
//

#ifndef ASGEGROUND_TILE_H
#define ASGEGROUND_TILE_H

#include <game/GameObjects/Sprites/SpriteObject.h>
class Tile : public GameObject
{
 public:
  Tile();
  Tile(ASGE::Renderer* renderer, const std::string& tileset_path, std::array<float,4> rect, ASGE::Point2D position = ASGE::Point2D(),  int collision_layer = -1);
  void update(float dt) override;
  void render(ASGE::Renderer* renderer) override;
  [[nodiscard]] int collisionLayer() const;
 private:
  std::unique_ptr<SpriteObject> sprite;
  int collision;
};

#endif // ASGEGROUND_TILE_H
