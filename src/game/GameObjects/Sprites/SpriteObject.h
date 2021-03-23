//
// Created by hewis on 19/03/2021.
//

#ifndef HELLOASGE_SPRITEOBJECT_H
#define HELLOASGE_SPRITEOBJECT_H

#include "game/GameObjects/GameObject.h"
#include <Engine/Sprite.h>
class SpriteObject : public GameObject
{
 public:
  SpriteObject(ASGE::Renderer* renderer, const std::string& file_path, ASGE::Point2D position = ASGE::Point2D());
  bool loadSprite(ASGE::Renderer* renderer, const std::string& file_path);

  void render(ASGE::Renderer* renderer) override;

  [[nodiscard]] virtual bool visibility() const;
  virtual void visibility(bool _visibility);

  [[nodiscard]] virtual ASGE::Point2D position();
  virtual void position(ASGE::Point2D _position);
  virtual void translate(ASGE::Point2D _translation);

  [[nodiscard]] virtual ASGE::Point2D dimensions();
  virtual void dimensions(ASGE::Point2D _dimensions);

  [[nodiscard]] virtual float rotation();
  virtual void rotation(float _radians);
  virtual void rotate(float _radians);

  [[nodiscard]] virtual ASGE::Colour colour();
  virtual void colour(ASGE::Colour _colour);

  [[nodiscard]] virtual float opacity();
  virtual void opacity(float _opacity);

  [[nodiscard]] virtual ASGE::Point2D centre();

  [[nodiscard]] virtual bool isInside(ASGE::Point2D position);

  [[nodiscard]] virtual short zOrder();
  virtual void zOrder(short z_order);

  virtual void srcRect(float x, float y, float w, float h);

 private:
  std::unique_ptr<ASGE::Sprite> sprite;
  bool visible = true;
};

#endif // HELLOASGE_SPRITEOBJECT_H
