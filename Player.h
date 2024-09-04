#pragma once
#include "Vector2.h"
#include "Novice.h"

class Player
{
public:
	Vector2 pos_;
	int r_;
	int speed_;
	int texGap_;
	int playerTex = Novice::LoadTexture("./Resources/player_001.png");

public:
	Player(Vector2 pos, int r, int speed, int texGap);
	~Player();
	void Update(char* keys, char* preKeys);
	void Draw();
};
