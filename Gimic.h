#pragma once
#include"Vector2.h"

class Gimic
{
public:
	Gimic();
	~Gimic();
	void Init(int radius,Vector2 in,Vector2 out);
	void Draw();

	float Distance(Vector2 a, Vector2 b);
	Vector2 Warp(Vector2 player, Vector2 in,Vector2 out);

public:

	int radius_;
	Vector2 in_;
	Vector2 out_;
	bool isWarp_;
};

