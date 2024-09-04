#include <Novice.h>
#include "Enemy.h"

Enemy::Enemy(Vector2 pos, int s, int r, int isAlive)
{
	pos_ = pos;
	radius_ = r;
	speed_ = s;
	isAlive_ = isAlive;
}

void Enemy::Update() {
	pos_.x += speed_;

	// ‰æ–Ê’[‚É“–‚½‚Á‚½‚ç”½‘Î‚ÉˆÚ“®
	if (pos_.x - radius_ <= 0 || pos_.x + radius_ >= 1280)speed_ *= -1;
}


void Enemy::Draw() 
{

}
