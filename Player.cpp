#include "Player.h"

Player::Player(Vector2 pos, int r, int speed, int texGap)
{
	pos_ = pos;
	r_ = r;
	speed_ = speed;
	texGap_ = texGap;
	velocity_ = { 0.0f,0.0f };
	accelaration_ = { 0.0f,-0.8f };
	scrollX_ = 0;
}

Player::~Player()
{

}

void Player::Update(char* keys, char* preKeys)
{
	//if (keys[DIK_W] && preKeys[DIK_W])pos_.y -= speed_;

	//if (keys[DIK_S] && preKeys[DIK_S])pos_.y += speed_;

	if (keys[DIK_A] && preKeys[DIK_A])pos_.x -= speed_;

	if (keys[DIK_D] && preKeys[DIK_D])pos_.x += speed_;

	//W押したらジャンプするよー
	if (keys[DIK_W] && preKeys[DIK_W] == 0 && pos_.y == 650) {
		velocity_.y = 20.0f;
	}

	velocity_.x += accelaration_.x;
	velocity_.y += accelaration_.y;

	pos_.x += velocity_.x;
	pos_.y -= velocity_.y;

	if (pos_.y >= 650) {
		pos_.y = 650;
	}

	//下行ったら上から出てくるよー
	/*if (pos_.y >= 720) {
		pos_.y = -20;
	}*/


	///スクロール
	if ((int)pos_.x >= 640 && (int)pos_.x <= 1408) {
		scrollX_ = (int)pos_.x - 640;
	}

}

void Player::Draw()
{
	texGap_ = 64;
	Novice::DrawSprite((int)pos_.x - texGap_ - scrollX_, (int)pos_.y, playerTex, 1, 1, 0.0f, WHITE);
}
