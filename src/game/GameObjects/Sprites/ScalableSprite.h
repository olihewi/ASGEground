//
// Created by hewis on 22/03/2021.
//

#ifndef ASGEGROUND_SCALABLESPRITE_H
#define ASGEGROUND_SCALABLESPRITE_H

#include "SpriteObject.h"
class ScalableSprite : public SpriteObject
{
 public:
  ScalableSprite(ASGE::Renderer* renderer, const std::string& file_path, std::array<float,6> part_sizes, ASGE::Point2D _position, ASGE::Point2D _dimensions);
  void dimensions(ASGE::Point2D _dimensions) final;
  void position(ASGE::Point2D _position) final;
  void render(ASGE::Renderer *renderer) override;
 private:
  std::array<std::unique_ptr<ASGE::Sprite>,8> border;
};

#endif // ASGEGROUND_SCALABLESPRITE_H
