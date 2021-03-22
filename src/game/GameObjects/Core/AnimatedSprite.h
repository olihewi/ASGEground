//
// Created by hewis on 19/03/2021.
//

#ifndef HELLOASGE_ANIMATEDSPRITE_H
#define HELLOASGE_ANIMATEDSPRITE_H

#include <game/GameObjects/Core/SpriteObject.h>
#include <vector>
class AnimatedSprite : public SpriteObject
{
 public:
  AnimatedSprite(ASGE::Renderer* renderer, const std::string& folder_path, size_t num_frames, ASGE::Point2D position = ASGE::Point2D(), float playback_speed = 1);

  void update(float dt) override;
  void render(ASGE::Renderer* renderer) override;

  [[nodiscard]] bool visibility() const override;
  void visibility(bool _visibility) override;

  [[nodiscard]] ASGE::Point2D position() override;
  void position(ASGE::Point2D _position) override;
  void translate(ASGE::Point2D _translation) override;

  [[nodiscard]] ASGE::Point2D dimensions() override;
  void dimensions(ASGE::Point2D _dimensions) override;

  [[nodiscard]] float rotation() override;
  void rotation(float _radians) override;
  void rotate(float _radians) override;

  [[nodiscard]] ASGE::Colour colour() override;
  void colour(ASGE::Colour _colour) override;

  [[nodiscard]] float opacity() override;
  void opacity(float _opacity) override;

  [[nodiscard]] ASGE::Point2D centre() override;

  [[nodiscard]] bool isInside(ASGE::Point2D position) override;

 private:
  std::vector<std::unique_ptr<ASGE::Sprite>> sprites;
  bool visible = true;
  float timer = 0;
  float speed = 1;
};

#endif // HELLOASGE_ANIMATEDSPRITE_H
