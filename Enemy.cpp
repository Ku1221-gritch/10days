#include <Novice.h>
#include "Enemy.h"

Enemy::Enemy(Vector2 pos, int s, int r, int isAlive,int texGap)
{
	pos_ = pos;
	radius_ = r;
	speed_ = s;
	isAlive_ = isAlive;
	texGap_ = texGap;
}

void Enemy::Update() {
	pos_.x += speed_;

	// 画面端に当たったら反対に移動
	if (pos_.x - radius_ <= 0 || pos_.x + radius_ >= 1280)speed_ *= -1;
}


void Enemy::Draw() 
{
	texGap_ = 32;
	Novice::DrawSprite((int)pos_.x - texGap_, (int)pos_.y, enemyTex, 1, 1, 0.0f, WHITE);
}
