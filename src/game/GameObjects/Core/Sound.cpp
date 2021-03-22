//
// Created by hewis on 20/03/2021.
//

#include "Sound.h"
#include <Engine/FileIO.h>

SoLoud::Soloud Sound::engine; // NOLINT(cert-err58-cpp)

Sound::Sound(const std::string& file_path)
{
  ASGE::FILEIO::File file;
  if (file.open(file_path))
  {
    auto io_buffer = file.read();
    audio.loadMem(io_buffer.as_unsigned_char(), static_cast<unsigned int>(io_buffer.length),false, false);
  }
}
void Sound::init()
{
  engine.init();
}
void Sound::play()
{
  engine.play(audio);
}
