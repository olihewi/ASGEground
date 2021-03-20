//
// Created by hewis on 20/03/2021.
//

#ifndef ASGEGROUND_SCENE_H
#define ASGEGROUND_SCENE_H

#include <game/GameObjects/GameObject.h>
#include <vector>
class Scene : public GameObject
{
 public:
  void keyInput(const ASGE::KeyEvent* key) override;
  void clickInput(const ASGE::ClickEvent* click) override;
  void mouseInput(const ASGE::MoveEvent* mouse) override;
  void scrollInput(const ASGE::ScrollEvent* scroll) override;
  void update(float dt) override;
  void render(ASGE::Renderer* renderer) override;
  void addObject(std::unique_ptr<GameObject> object);
 private:
  std::vector<std::unique_ptr<GameObject>> game_objects;
};

#endif // ASGEGROUND_SCENE_H
