//
// Created by hewis on 22/03/2021.
//

#include "ScalableSprite.h"
ScalableSprite::ScalableSprite(
  ASGE::Renderer* renderer, const std::string& file_path,
  std::array<float, 6> part_sizes, ASGE::Point2D _position,
  ASGE::Point2D _dimensions) : SpriteObject(renderer, file_path, ASGE::Point2D(_position.x + part_sizes[0], _position.y + part_sizes[1]))
{
  SpriteObject::srcRect(part_sizes[0],part_sizes[1],part_sizes[2],part_sizes[3]);
  for (auto& spr : border)
  {
    spr = renderer->createUniqueSprite();
    spr->loadTexture(file_path);
  }

  auto* bd0 = border[0]->srcRect();
  bd0[2] = part_sizes[0];
  bd0[3] = part_sizes[1];
  auto* bd1 = border[1]->srcRect();
  bd1[0] = part_sizes[0];
  bd1[2] = part_sizes[2];
  bd1[3] = part_sizes[1];
  auto* bd2 = border[2]->srcRect();
  bd2[0] = part_sizes[0] + part_sizes[2];
  bd2[2] = part_sizes[4];
  bd2[3] = part_sizes[1];
  auto* bd3 = border[3]->srcRect();
  bd3[1] = part_sizes[1];
  bd3[2] = part_sizes[0];
  bd3[3] = part_sizes[3];
  auto* bd4 = border[4]->srcRect();
  bd4[0] = part_sizes[0] + part_sizes[2];
  bd4[1] = part_sizes[1];
  bd4[2] = part_sizes[4];
  bd4[3] = part_sizes[3];
  auto* bd5 = border[5]->srcRect();
  bd5[1] = part_sizes[1] + part_sizes[3];
  bd5[2] = part_sizes[0];
  bd5[3] = part_sizes[5];
  auto* bd6 = border[6]->srcRect();
  bd6[0] = part_sizes[0];
  bd6[1] = part_sizes[1] + part_sizes[3];
  bd6[2] = part_sizes[2];
  bd6[3] = part_sizes[5];
  auto* bd7 = border[7]->srcRect();
  bd7[0] = part_sizes[0] + part_sizes[2];
  bd7[1] = part_sizes[1] + part_sizes[3];
  bd7[2] = part_sizes[4];
  bd7[3] = part_sizes[5];

  border[0]->width(part_sizes[0]);
  border[0]->height(part_sizes[1]);
  border[1]->width(part_sizes[2]);
  border[1]->height(part_sizes[1]);
  border[2]->width(part_sizes[4]);
  border[2]->height(part_sizes[1]);
  border[3]->width(part_sizes[0]);
  border[3]->height(part_sizes[3]);
  border[4]->width(part_sizes[4]);
  border[4]->height(part_sizes[3]);
  border[5]->width(part_sizes[0]);
  border[5]->height(part_sizes[5]);
  border[6]->width(part_sizes[2]);
  border[6]->height(part_sizes[5]);
  border[7]->width(part_sizes[4]);
  border[7]->height(part_sizes[5]);

  position(_position);
  dimensions(_dimensions);
}
void ScalableSprite::dimensions(ASGE::Point2D _dimensions)
{
  float centre_w = _dimensions.x - border[3]->width() - border[4]->width();
  float centre_h = _dimensions.y - border[1]->height() - border[6]->height();
  SpriteObject::dimensions(ASGE::Point2D(centre_w,centre_h));
  border[1]->width(centre_w);
  border[3]->height(centre_h);
  border[4]->height(centre_h);
  border[6]->width(centre_w);
  position(ASGE::Point2D(border[0]->xPos(),border[0]->yPos()));
}
void ScalableSprite::position(ASGE::Point2D _position)
{
  border[0]->xPos(_position.x);
  border[0]->yPos(_position.y);
  border[1]->xPos(_position.x + border[0]->width());
  border[1]->yPos(_position.y);
  border[2]->xPos(border[1]->xPos() + border[1]->width());
  border[2]->yPos(_position.y);
  border[3]->xPos(_position.x);
  border[3]->yPos(_position.y + border[0]->height());
  SpriteObject::position(ASGE::Point2D(_position.x + border[4]->width(), _position.y + border[1]->height()));
  border[4]->xPos(SpriteObject::position().x + SpriteObject::dimensions().x);
  border[4]->yPos(_position.y + border[2]->height());
  border[5]->xPos(_position.x);
  border[5]->yPos(border[3]->yPos() + border[3]->height());
  border[6]->xPos(_position.x + border[5]->width());
  border[6]->yPos(SpriteObject::position().y + SpriteObject::dimensions().y);
  border[7]->xPos(border[6]->xPos() + border[6]->width());
  border[7]->yPos(border[4]->yPos() + border[4]->height());
}
void ScalableSprite::render(ASGE::Renderer* renderer)
{
  SpriteObject::render(renderer);
  for (auto& bd : border)
  {
    renderer->renderSprite(*bd);
  }
}
