//
// Created by hewis on 19/03/2021.
//

#include "TextObject.h"
TextObject::TextObject(
  ASGE::Renderer* renderer, std::string contents, ASGE::Point2D position,
  int font_index, ASGE::Colour colour, float scale, short z_order)
{
  text.setString(contents);
  text.setFont(renderer->getFont(font_index));
  text.setPosition(position);
  text.setColour(colour);
  text.setScale(scale);
  text.setZOrder(z_order);
}
std::string TextObject::contents()
{
  return text.getString();
}
void TextObject::contents(std::string _contents)
{
  text.setString(_contents);
}
ASGE::Point2D TextObject::position()
{
  return text.getPosition();
}
void TextObject::position(ASGE::Point2D _position)
{
  text.setPosition(_position);
}
void TextObject::translate(ASGE::Point2D _translation)
{
  text.setPosition(ASGE::Point2D(text.getPosition().x + _translation.x,
                                 text.getPosition().y + _translation.y));
}
ASGE::Colour TextObject::colour()
{
  return text.getColour();
}
void TextObject::colour(ASGE::Colour _colour)
{
  text.setColour(_colour);
}
void TextObject::zOrder(short _z_order)
{
  text.setZOrder(_z_order);
}