//
// Created by hewis on 20/03/2021.
//

#ifndef ASGEGROUND_LEVELTEST_H
#define ASGEGROUND_LEVELTEST_H

#include "Scene.h"
#include <game/GameObjects/Tilemap/TileMap.h>
#include <game/GameObjects/Tilemap/Tileset.h>
class LevelTest : public Scene
{
 public:
  explicit LevelTest(ASGE::Renderer* renderer);
  void update(float dt) override;
  void render(ASGE::Renderer *renderer) override;
  void keyInput(const ASGE::KeyEvent *key) override;
  void clickInput(const ASGE::ClickEvent *click) override;
 private:
  TileMap tile_map;
  Tileset tileset;
};

#endif // ASGEGROUND_LEVELTEST_H
