//
// Created by hewis on 22/03/2021.
//

#include "Tileset.h"
#include <Engine/Input.h>
#include <cmath>
Tileset::Tileset(
  ASGE::Renderer* renderer, const std::string& file_path, int _sprite_size) : sprite_sheet(renderer, file_path, ASGE::Point2D(0,0)), cursor(renderer, "data/images/tilesets/cursor.png", std::array<float,6> {3,3,28,28,3,3}, ASGE::Point2D(), ASGE::Point2D(32,32)), sprite_size(_sprite_size)
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
  if (sprite_sheet.isInside(click_pos) && click->action != ASGE::KEYS::KEY_REPEATED)
  {
    cursor.visibility(true);
    int click_x = floor((click_pos.x - sprite_sheet.position().x) / (sprite_sheet.position().x + sprite_sheet.dimensions().x) * (sprite_sheet.dimensions().x / static_cast<float>(sprite_size)));
    int click_y = floor((click_pos.y - sprite_sheet.position().y) / (sprite_sheet.position().y + sprite_sheet.dimensions().y) * (sprite_sheet.dimensions().y / static_cast<float>(sprite_size)));
    if (click->action == ASGE::KEYS::KEY_PRESSED)
    {
      selection_start = click_x + click_y * (static_cast<int>(sprite_sheet.dimensions().x) / sprite_size);
      selection_end = selection_start;
    }
    else if (click->action == ASGE::KEYS::KEY_RELEASED)
    {
      selection_end = click_x + click_y * (static_cast<int>(sprite_sheet.dimensions().x) / sprite_size);
    }
    int cursor_pos_y = (selection_end / 8 > selection_start / 8) ? selection_start / 8 * sprite_size - 1 : selection_end / 8 * sprite_size - 1;
    int cursor_pos_x = (selection_end % 8 > selection_start % 8) ? selection_start % 8 * sprite_size - 1 : selection_end % 8 * sprite_size - 1;
    cursor.position(ASGE::Point2D(static_cast<float>(cursor_pos_x), static_cast<float>(cursor_pos_y)));
    float cursor_width = fabs(static_cast<float>(selection_start%8-selection_end%8)) * 32 + 32;
    int selection_vert_height = abs(selection_start/8 - selection_end/8);
    float cursor_height = static_cast<float>(selection_vert_height) * 32 + 32;
    cursor.dimensions(ASGE::Point2D(cursor_width,cursor_height));
  }
}
std::array<float,4> Tileset::getCurrentRect()
{
  int num_horizontal = static_cast<int>(sprite_sheet.dimensions().x) / sprite_size;
  float x = static_cast<float>(selection_start % num_horizontal) * static_cast<float>(sprite_size);
  int row = selection_start / num_horizontal;
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