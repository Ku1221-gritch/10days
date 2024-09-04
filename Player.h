#pragma once
#include "Vector2.h"
#include "Novice.h"

class Player
{
public:
	Vector2 pos_;
	int r_;
	int speed_;

public:
	Player(Vector2 pos, int r, int speed);
	~Player();
	void Update(char* keys, char* preKeys);
	void Draw();
};
