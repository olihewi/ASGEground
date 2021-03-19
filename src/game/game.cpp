#include <string>

#include "game.h"
#include <Engine/Logger.hpp>
#include <Engine/Sprite.h>

/**
 *   @brief   Default Constructor.
 */
ASGEGame::ASGEGame(ASGE::GameSettings settings) : OGLGame(settings)
{
  renderer->setClearColour(ASGE::COLOURS::SLATEGRAY);
  inputs->use_threads = false;
  toggleFPS();

  initBackground();
  initCamera();
  initText();

  logStartup();
}

void ASGEGame::initText()
{
  menu_text.setString("LOAD A FONT INSTEAD OF USING THE DEBUG ONE");
  menu_text.setFont(renderer->getDefaultFont());
  menu_text.setZOrder(100);
  menu_text.setPositionY(350);
  menu_text.setColour(ASGE::COLOURS::BLACK);

  auto window_width = static_cast<float>(ASGE::SETTINGS.window_width);
  menu_text.setPositionX((window_width - menu_text.getWidth()) / 2.0f);
}

void ASGEGame::initBackground()
{
  for (size_t i = 0; i < background.size(); ++i)
  {
    background[i] = renderer->createRawSprite();
    background[i]->loadTexture(
      "/data/backgrounds/parallax-forest-" + std::to_string(i) + ".png");
    background[i]->setGlobalZOrder(-background.size() + i);
    background[i]->setMagFilter(ASGE::Texture2D::MagFilter::NEAREST);
    background[i]->width(static_cast<float>(ASGE::SETTINGS.window_width));
    background[i]->height(static_cast<float>(ASGE::SETTINGS.window_height));
  }
}

void ASGEGame::initCamera()
{
  // create a camera to frame the window
  camera = ASGE::Camera2D{ static_cast<float>(ASGE::SETTINGS.window_width),
                           static_cast<float>(ASGE::SETTINGS.window_height) };

  // point the camera towards the middle of the window i.e. 0,0
  camera.lookAt(
    ASGE::Point2D{ static_cast<float>(-ASGE::SETTINGS.window_width) / 2.f,
                   static_cast<float>(-ASGE::SETTINGS.window_height) / 2.f });
}

void ASGEGame::logStartup() const
{
  // these are just examples of the logging system.. you dont need to keep em
  std::ostringstream ss{ "initialisation complete" };
  Logging::ERRORS(ss.str());
  Logging::WARN(ss.str());
  Logging::INFO(ss.str());
  Logging::DEBUG(ss.str());
  Logging::TRACE(ss.str());
  Logging::log(Logging::timestamp() + " \x1b[35;1m[CUSTOM]\x1b[0m " + ss.str() + '\n');
}

/**
 *   @brief   Destructor.
 *   @details Remove any non-managed memory and callbacks.
 */
ASGEGame::~ASGEGame()
{
  this->inputs->unregisterCallback(static_cast<unsigned int>(key_callback_id));
  this->inputs->unregisterCallback(static_cast<unsigned int>(mouse_callback_id));

  for(auto &sprite : background)
  {
    delete sprite;
  }
}

/**
 *   @brief   Initialises the game.
 *   @details The game window is created and all assets required to
 *            run the game are loaded. The keyHandler and clickHandler
 *            callback should also be set in the initialise function.
 *   @return  True if the game initialised correctly.
 */
bool ASGEGame::init()
{
  key_callback_id =
    inputs->addCallbackFnc(ASGE::E_KEY, &ASGEGame::keyHandler, this);
  mouse_callback_id =
    inputs->addCallbackFnc(ASGE::E_MOUSE_CLICK, &ASGEGame::clickHandler, this);

  return true;
}

/**
 *   @brief   Processes any key inputs
 *   @details This function is added as a callback to handle the game's
 *            keyboard input. Input events are not guaranteed to be thread
 *            safe, so ensure data races are avoided
 *   @param   data The event data relating to key input.
 *   @see     KeyEvent
 *   @return  void
 */
void ASGEGame::keyHandler(const ASGE::SharedEventData& data)
{
  const auto* key = dynamic_cast<const ASGE::KeyEvent*>(data.get());

  if (key->key == ASGE::KEYS::KEY_ESCAPE)
  {
    signalExit();
  }
}

/**
 *   @brief   Processes any click inputs
 *   @details This function is added as a callback to handle the game's
 *            mouse button input. For this game, calls to this function
 *            are thread safe, so you may alter the game's state as you
 *            see fit.
 *   @param   data The event data relating to key input.
 *   @see     ClickEvent
 *   @return  void
 */
void ASGEGame::clickHandler(const ASGE::SharedEventData& data)
{
  const auto* click = dynamic_cast<const ASGE::ClickEvent*>(data.get());

  double x_pos = click->xpos;
  double y_pos = click->ypos;

  Logging::TRACE("x_pos: " + std::to_string(x_pos));
  Logging::TRACE("y_pos: " + std::to_string(y_pos));
}

/**
 *   @brief   Updates the scene
 *   @details Prepares the renderer subsystem before drawing the
 *            current frame. Once the current frame is has finished
 *            the buffers are swapped accordingly and the image shown.
 *   @return  void
 */
void ASGEGame::update(const ASGE::GameTime& game_time)
{
  // auto dt_sec = game_time.delta.count() / 1000.0;;
  // make sure you use delta time in any movement calculations!
  if (inputs->getGamePad(0).is_connected)
  {
    camera.translateX(inputs->getGamePad(0).axis[0] * -100);
    camera.translateY(inputs->getGamePad(0).axis[1] * -100);
  }

  camera.update(game_time);
}

/**
 *   @brief   Renders the scene
 *   @details Renders all the game objects to the current frame.
 *            Once the current frame is has finished the buffers are
 *            swapped accordingly and the image shown.
 *   @return  void
 */
void ASGEGame::render()
{
  renderer->setFont(0);
  renderer->setProjectionMatrix(camera.getView());
  if (in_menu)
  {
    for (const auto* sprite : background)
    {
      renderer->renderSprite(*sprite);
    }
    renderer->renderText(menu_text);
  }
}
