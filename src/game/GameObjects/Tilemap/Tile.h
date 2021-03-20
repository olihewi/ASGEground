//
// Created by hewis on 20/03/2021.
//

#ifndef ASGEGROUND_TILE_H
#define ASGEGROUND_TILE_H

#include <game/GameObjects/Core/SpriteObject.h>
class Tile : public GameObject
{
 public:
  Tile();
  Tile(ASGE::Renderer* renderer, const std::string& file_path, ASGE::Point2D position = ASGE::Point2D(), int collision_layer = -1, int animation_frames = 0, float playback_speed = 1, ASGE::Point2D collision_offset_ul = ASGE::Point2D(), ASGE::Point2D collision_offset_br = ASGE::Point2D());
  void update(float dt) override;
  void render(ASGE::Renderer* renderer) override;
  bool isColliding(ASGE::Point2D position, int other_collision_layer);
  bool isColliding(ASGE::Point2D position_ul, ASGE::Point2D position_br, int other_collision_layer);
 private:
  std::unique_ptr<SpriteObject> sprite;
  int layer;
  ASGE::Point2D collision_offset_1;
  ASGE::Point2D collision_offset_2;
};

#endif // ASGEGROUND_TILE_H
