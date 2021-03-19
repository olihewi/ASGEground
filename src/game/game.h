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
  explicit ASGEGame(const ASGE::GameSettings& settings);
  ~ASGEGame() override;
  bool init();

 private:
  /// Input Handlers
  void keyHandler(const ASGE::SharedEventData& data);
  void clickHandler(const ASGE::SharedEventData& data);
  void mouseHandler(const ASGE::SharedEventData& data);
  void scrollHandler(const ASGE::SharedEventData& data);
  void render() override;
  void update(const ASGE::GameTime&) override;

  int key_callback_id    = -1; /// Keyboard Input Callback ID.
  int click_callback_id  = -1; /// Mouse Click Input Callback ID.
  int mouse_callback_id  = -1; /// Mouse Move Input Callback ID.
  int scroll_callback_id = -1; /// Mouse Scroll Input Callback ID.

  ASGE::Camera2D camera{};
  ASGE::Text menu_text{};
};