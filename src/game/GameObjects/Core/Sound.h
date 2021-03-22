//
// Created by hewis on 20/03/2021.
//

#ifndef ASGEGROUND_SOUND_H
#define ASGEGROUND_SOUND_H

#include <soloud.h>
#include <soloud_wav.h>
#include <string>
class Sound
{
 public:
  explicit Sound(const std::string& file_path);
  static void init();
  void play();
  static SoLoud::Soloud engine;
 private:
  SoLoud::Wav audio;
};

#endif // ASGEGROUND_SOUND_H
