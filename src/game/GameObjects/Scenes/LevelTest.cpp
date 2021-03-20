//
// Created by hewis on 20/03/2021.
//

#include "LevelTest.h"
#include <game/GameObjects/Tilemap/TileMap.h>
LevelTest::LevelTest(ASGE::Renderer* renderer)
{
  addObject(std::make_unique<TileMap>(renderer));
}
