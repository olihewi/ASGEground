//
// Created by hewis on 20/03/2021.
//

#include "LevelTest.h"
#include <Engine/Input.h>
LevelTest::LevelTest(ASGE::Renderer* renderer) : tile_map(renderer), tileset(renderer, "data/images/tilesets/japanese_city/tileset.png")
{
}
void LevelTest::update(float dt)
{
  Scene::update(dt);
  tile_map.update(dt);
}
void LevelTest::render(ASGE::Renderer* renderer)
{
  tileset.render(renderer);
  Scene::render(renderer);
  tile_map.render(renderer);
}
void LevelTest::keyInput(const ASGE::KeyEvent* key)
{
  Scene::keyInput(key);
}
void LevelTest::clickInput(const ASGE::ClickEvent* click)
{
  tileset.clickInput(click);
  Scene::clickInput(click);
  auto click_pos = ASGE::Point2D(static_cast<float>(click->xpos) - 256,static_cast<float>(click->ypos));
  if (click_pos.x >= 0 && click->action == ASGE::KEYS::KEY_PRESSED)
  {
    auto x_pos = static_cast<int>(click_pos.x) / 32;
    auto y_pos = static_cast<int>(click_pos.y) / 32;
    if (x_pos < 50 && y_pos < 50)
    {
      tile_map.setTile(x_pos + y_pos * 50, tileset.getCurrentRect());
    }
  }
}
