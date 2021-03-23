//
// Created by hewis on 19/03/2021.
//

#ifndef HELLOASGE_ANIMATEDSPRITE_H
#define HELLOASGE_ANIMATEDSPRITE_H

#include "SpriteObject.h"
#include <vector>
class AnimatedSprite : public SpriteObject
{
 public:
  AnimatedSprite(ASGE::Renderer* renderer, const std::string& file_path, ASGE::Point2D position = ASGE::Point2D(), float playback_speed = 1);
  void update(float dt) override;
 private:
  size_t frames;
  float sprite_size;
  float timer = 0;
  float speed = 1;
};

#endif // HELLOASGE_ANIMATEDSPRITE_H
