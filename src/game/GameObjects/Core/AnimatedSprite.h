//
// Created by hewis on 19/03/2021.
//

#ifndef HELLOASGE_ANIMATEDSPRITE_H
#define HELLOASGE_ANIMATEDSPRITE_H

#include <game/GameObjects/GameObject.h>
#include <vector>
class AnimatedSprite : public GameObject
{
 public:
  AnimatedSprite(ASGE::Renderer* renderer, const std::vector<std::string>& sprite_paths, ASGE::Point2D position = ASGE::Point2D(), float _speed = 1);

  void update(float dt) override;
  void render(ASGE::Renderer* renderer) override;

  [[nodiscard]] bool visibility() const;
  void visibility(bool _visibility);

  [[nodiscard]] ASGE::Point2D position();
  void position(ASGE::Point2D _position);
  void translate(ASGE::Point2D _translation);

  [[nodiscard]] float rotation();
  void rotation(float _radians);
  void rotate(float _radians);

  [[nodiscard]] ASGE::Colour colour();
  void colour(ASGE::Colour _colour);

  [[nodiscard]] float opacity();
  void opacity(float _opacity);

  [[nodiscard]] ASGE::Point2D centre();

 private:
  std::vector<std::unique_ptr<ASGE::Sprite>> sprites;
  bool visible = true;
  float timer = 0;
  float speed = 1;
};

#endif // HELLOASGE_ANIMATEDSPRITE_H
