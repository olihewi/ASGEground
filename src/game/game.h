#pragma once
#include <Engine/Camera2D.hpp>
#include <Engine/OGLGame.h>
#include <game/GameObjects/Scenes/Scene.h>
#include <string>

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
  int key_callback_id    = -1; /// Keyboard Input Callback ID.
  int click_callback_id  = -1; /// Mouse Click Input Callback ID.
  int mouse_callback_id  = -1; /// Mouse Move Input Callback ID.
  int scroll_callback_id = -1; /// Mouse Scroll Input Callback ID.
  ///
  void render() override;
  void update(const ASGE::GameTime&) override;

  ASGE::Camera2D camera{};
  ASGE::Text menu_text{};

  std::unique_ptr<Scene> scene;
};