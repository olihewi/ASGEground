#include "game.h"
int main()
{
  ASGE::GameSettings game_settings;
  game_settings.window_title  = "HelloASGE";
  game_settings.window_width  = 1280;
  game_settings.window_height = 720;
  game_settings.msaa_level    = 2;

  ASGEGame asge_game(game_settings);
  if (asge_game.init())
  {
    asge_game.run();
  }
  return 0;
}