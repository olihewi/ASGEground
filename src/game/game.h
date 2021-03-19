#pragma once
#include <Engine/Camera2D.hpp>
#include <Engine/OGLGame.h>
#include <string>

/**
 *  An OpenGL Game based on ASGE.
 */
class ASGEGame final: public ASGE::OGLGame
{
 public:
  explicit ASGEGame(ASGE::GameSettings settings);
  ~ASGEGame() override;
  bool init();

 private:
  void clickHandler(const ASGE::SharedEventData& data);
  void initCamera();
  void initBackground();
  void initText();
  void keyHandler(const ASGE::SharedEventData& data);
  void logStartup() const;
  void render() override;
  void update(const ASGE::GameTime&) override;

  int key_callback_id   = -1; /**< Key Input Callback ID. */
  int mouse_callback_id = -1; /**< Mouse Input Callback ID. */
  bool in_menu          = true;
  std::array<ASGE::Sprite*, 4> background{ nullptr };

  // ASGEv2 examples
  ASGE::Camera2D camera{};
  ASGE::Text menu_text{};
};