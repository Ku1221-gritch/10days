#include "Gimic.h"
#include "math.h"
#include "Novice.h"

Gimic::Gimic()
{
}

Gimic::~Gimic()
{
}

void Gimic::Init(int radius, Vector2 in, Vector2 out)
{
	radius_ = radius;
	in_ = in;
	out_ = out;
	isWarp_ = true;
}

void Gimic::Draw()
{
	Novice::DrawEllipse(int(in_.x), int(in_.y), radius_, radius_, 0.0f, WHITE, kFillModeSolid);
	Novice::DrawEllipse(int(out_.x), int(out_.y), radius_, radius_, 0.0f, WHITE, kFillModeSolid);
}

float Gimic::Distance(Vector2 a, Vector2 b)
{
	float c = b.x - a.x;
	float d = b.y - a.y;
	float distance = sqrtf(c * c + d * d);

	return distance;
}

Vector2 Gimic::Warp(Vector2 player, Vector2 in, Vector2 out)
{
	if (isWarp_) {

		if (Distance(player, in) <= radius_ * 2) {
			isWarp_ = false;
			return { out.x + 20,out.y + 20 };
		}
		else if (Distance(player, out) <= radius_ * 2) {
			isWarp_ = false;
			return { in.x + 20,in.y + 20 };
		}
	}
	isWarp_ = true;
	return player;
}
