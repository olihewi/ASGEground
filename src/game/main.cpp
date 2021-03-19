#include "game.h"
int main()
{
  ASGE::GameSettings game_settings;
  game_settings.window_title  = "ASGEground";
  game_settings.window_width  = 1920;
  game_settings.window_height = 1080;
  game_settings.msaa_level    = 2;
  game_settings.mag_filter    = ASGE::GameSettings::MagFilter::NEAREST;

  ASGEGame asge_game(game_settings);
  if (asge_game.init())
  {
    asge_game.run();
  }
  return 0;
}