#pragma once
#include"IScene.h"
#include<Novice.h>

//�^�C�g���V�[��
class TitleScene : public IScene {
public:
	void Init() override;
	void Update(char* keys, char* preKeys) override;
	void Draw() override;
};