//
// Created by hewis on 19/03/2021.
//

#ifndef HELLOASGE_TEXTOBJECT_H
#define HELLOASGE_TEXTOBJECT_H

#include <game/GameObjects/GameObject.h>

class TextObject : public GameObject
{
 public:
  TextObject(ASGE::Renderer* renderer, std::string contents,
             ASGE::Point2D position = ASGE::Point2D(), int font_index = 0,
             ASGE::Colour colour = ASGE::COLOURS::WHITE, float scale = 1,
             short z_order = 1);

  [[nodiscard]] std::string contents();
  void contents(std::string _contents);

  [[nodiscard]] ASGE::Point2D position();
  void position(ASGE::Point2D _position);
  void translate(ASGE::Point2D _translation);

  [[nodiscard]] ASGE::Colour colour();
  void colour(ASGE::Colour _colour);

  void zOrder(short _z_order);

 private:
  ASGE::Text text;
};

#endif // HELLOASGE_TEXTOBJECT_H
