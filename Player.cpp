#include "Player.h"

Player::Player(Vector2 pos, int r, int speed)
{
	pos_ = pos;
	r_ = r;
	speed_ = speed;

}

Player::~Player()
{

}

void Player::Update(char* keys, char* preKeys)
{
	if (keys[DIK_W] && preKeys[DIK_W])pos_.y -= speed_;

	if (keys[DIK_S] && preKeys[DIK_S])pos_.y += speed_;

	if (keys[DIK_A] && preKeys[DIK_A])pos_.x -= speed_;

	if (keys[DIK_D] && preKeys[DIK_D])pos_.x += speed_;
}

void Player::Draw()
{

}
