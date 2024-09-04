#pragma once
#include"IScene.h"
#include"Vector2.h"
#include"Player.h"
#include"Enemy.h"
#include"Novice.h"

//�X�e�[�W�V�[��
class StageScene : public IScene {
public:
	~StageScene();
	void Init() override;
	void Update(char* keys, char* preKeys) override;
	void Draw() override;

public:
	Player* player_;
	Enemy* enemy_;
	int stageTex = Novice::LoadTexture("./Resources/stagescene.png");
};