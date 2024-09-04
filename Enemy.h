#pragma once
#include "Vector2.h"

class Enemy {
public:
	Vector2 pos_;
	int speed_;
	int radius_;
	bool isAlive_;

public:
	Enemy(Vector2 pos, int s, int r, int isAlive);
	void Update();
	void Draw();

};