#include "game.h"
#include <Engine/Sprite.h>

ASGEGame::ASGEGame(const ASGE::GameSettings& settings) : OGLGame(settings)
{
  inputs->use_threads = false;
  toggleFPS();

  // create a camera to frame the window
  camera = ASGE::Camera2D{ static_cast<float>(ASGE::SETTINGS.window_width),
                           static_cast<float>(ASGE::SETTINGS.window_height) };

  // point the camera towards the middle of the window i.e. 0,0
  camera.lookAt(
    ASGE::Point2D{ static_cast<float>(-ASGE::SETTINGS.window_width) / 2.f,
                   static_cast<float>(-ASGE::SETTINGS.window_height) / 2.f });
}
ASGEGame::~ASGEGame()
{
  this->inputs->unregisterCallback(static_cast<unsigned int>(key_callback_id));
  this->inputs->unregisterCallback(static_cast<unsigned int>(mouse_callback_id));
}

bool ASGEGame::init()
{
  key_callback_id =
    inputs->addCallbackFnc(ASGE::E_KEY, &ASGEGame::keyHandler, this);
  mouse_callback_id =
    inputs->addCallbackFnc(ASGE::E_MOUSE_CLICK, &ASGEGame::clickHandler, this);

  return true;
}

void ASGEGame::keyHandler(const ASGE::SharedEventData& data)
{
  const auto* key = dynamic_cast<const ASGE::KeyEvent*>(data.get());

  if (key->key == ASGE::KEYS::KEY_ESCAPE)
  {
    signalExit();
  }
}

void ASGEGame::clickHandler(const ASGE::SharedEventData& /*data*/)
{
  //const auto* click = dynamic_cast<const ASGE::ClickEvent*>(data.get());
}

void ASGEGame::update(const ASGE::GameTime& game_time)
{
  // auto dt_sec = game_time.delta.count() / 1000.0;
  if (inputs->getGamePad(0).is_connected)
  {
    camera.translateX(inputs->getGamePad(0).axis[0] * -100);
    camera.translateY(inputs->getGamePad(0).axis[1] * -100);
  }

  camera.update(game_time);
}

void ASGEGame::render()
{
  renderer->setFont(0);
  renderer->setProjectionMatrix(camera.getView());
}
