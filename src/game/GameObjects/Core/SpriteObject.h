//
// Created by hewis on 19/03/2021.
//

#ifndef HELLOASGE_SPRITEOBJECT_H
#define HELLOASGE_SPRITEOBJECT_H

#include "game/GameObjects/GameObject.h"
class SpriteObject : public GameObject
{
 public:
  SpriteObject(ASGE::Renderer* renderer, const std::string& file_path, ASGE::Point2D position = ASGE::Point2D());
  bool loadSprite(ASGE::Renderer* renderer, const std::string& file_path);

  void render(ASGE::Renderer* renderer) override;

  [[nodiscard]] bool visibility() const;
  void visibility(bool _visibility);

  [[nodiscard]] ASGE::Point2D position();
  void position(ASGE::Point2D _position);
  void translate(ASGE::Point2D _translation);

  [[nodiscard]] ASGE::Point2D dimensions();
  void dimensions(ASGE::Point2D _dimensions);

  [[nodiscard]] float rotation();
  void rotation(float _radians);
  void rotate(float _radians);

  [[nodiscard]] ASGE::Colour colour();
  void colour(ASGE::Colour _colour);

  [[nodiscard]] float opacity();
  void opacity(float _opacity);

  [[nodiscard]] ASGE::Point2D centre();

 private:
  std::unique_ptr<ASGE::Sprite> sprite;
  bool visible = true;
};

#endif // HELLOASGE_SPRITEOBJECT_H
