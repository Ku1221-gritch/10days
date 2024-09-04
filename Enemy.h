#pragma once
#include "Vector2.h"

class Enemy {
public:
	Vector2 pos_;
	int speed_;
	int radius_;
	bool isAlive_;
	int texGap_;
	int enemyTex = Novice::LoadTexture("./Resources/enemy.png");

public:
	Enemy(Vector2 pos, int s, int r, int isAlive, int texGap);
	void Update();
	void Draw();

};