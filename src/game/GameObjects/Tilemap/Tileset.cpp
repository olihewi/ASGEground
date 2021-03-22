//
// Created by hewis on 22/03/2021.
//

#include "Tileset.h"
#include <Engine/Input.h>
#include <cmath>
Tileset::Tileset(
  ASGE::Renderer* renderer, const std::string& file_path, int _sprite_size) : sprite_sheet(renderer, file_path, ASGE::Point2D(0,0)), cursor(renderer, "data/images/tilesets/cursor.png"), sprite_size(_sprite_size)
{
  //cursor.visibility(false);
}
void Tileset::render(ASGE::Renderer* renderer)
{
  sprite_sheet.render(renderer);
  cursor.render(renderer);
  GameObject::render(renderer);
}
void Tileset::clickInput(const ASGE::ClickEvent* click)
{
  GameObject::clickInput(click);
  ASGE::Point2D click_pos = ASGE::Point2D(static_cast<float>(click->xpos),static_cast<float>(click->ypos));
  if (sprite_sheet.isInside(click_pos) && click->action == ASGE::KEYS::KEY_PRESSED)
  {
    cursor.visibility(true);
    int click_x = floor((click_pos.x - sprite_sheet.position().x) / (sprite_sheet.position().x + sprite_sheet.dimensions().x) * (sprite_sheet.dimensions().x / static_cast<float>(sprite_size)));
    int click_y = floor((click_pos.y - sprite_sheet.position().y) / (sprite_sheet.position().y + sprite_sheet.dimensions().y) * (sprite_sheet.dimensions().y / static_cast<float>(sprite_size)));
    cursor.position(ASGE::Point2D(static_cast<float>(click_x * sprite_size) - 1, static_cast<float>(click_y * sprite_size) - 1));
    current_selection = click_x + click_y * (static_cast<int>(sprite_sheet.dimensions().x) / sprite_size);
  }
}
std::array<float,4> Tileset::getCurrentRect()
{
  int num_horizontal = static_cast<int>(sprite_sheet.dimensions().x) / sprite_size;
  float x = static_cast<float>(current_selection % num_horizontal) * static_cast<float>(sprite_size);
  int row = current_selection / num_horizontal;
  float y = static_cast<float>(row) * static_cast<float>(sprite_size);
  std::array<float,4> rect
    {
      x,
      y,
      static_cast<float>(sprite_size),
      static_cast<float>(sprite_size)
    };
  return rect;
}
