//
// Created by hewis on 22/03/2021.
//

#ifndef ASGEGROUND_TILESET_H
#define ASGEGROUND_TILESET_H

#include <game/GameObjects/Core/AnimatedSprite.h>
class Tileset : public GameObject
{
 public:
  Tileset(ASGE::Renderer* renderer, const std::string& file_path, int _sprite_size = 32);
  void render(ASGE::Renderer* renderer) override;
  void clickInput(const ASGE::ClickEvent* click) override;
  [[nodiscard]] std::array<float,4> getCurrentRect();
 private:
  SpriteObject sprite_sheet;
  SpriteObject cursor;
  int sprite_size;
  int current_selection = 0;
};

#endif // ASGEGROUND_TILESET_H
