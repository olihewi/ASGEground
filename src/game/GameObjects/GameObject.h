//
// Created by hewis on 19/03/2021.
//

#ifndef HELLOASGE_GAMEOBJECT_H
#define HELLOASGE_GAMEOBJECT_H

#include <Engine/Renderer.h>

/// Forward Declarations
namespace ASGE
{
  struct KeyEvent;
  struct ClickEvent;
  struct MoveEvent;
  struct ScrollEvent;
}

class GameObject
{
 public:
  virtual ~GameObject() = default;

  virtual void keyInput(const ASGE::KeyEvent* /*key*/) {}
  virtual void clickInput(const ASGE::ClickEvent* /*click*/) {}
  virtual void mouseInput(const ASGE::MoveEvent* /*mouse*/) {}
  virtual void scrollInput(const ASGE::ScrollEvent* /*scroll*/) {}

  virtual void update(float /*dt*/) {}
  virtual void render(ASGE::Renderer* /*renderer*/) {}
};

#endif // HELLOASGE_GAMEOBJECT_H
