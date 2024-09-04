#pragma once

#include <memory>
#include "IScene.h"
#include"StageScene.h"
#include"TitleScene.h"
#include"ClearScene.h"
#include"DeathScene.h"
#include<Novice.h>

using namespace std;

class GameManager {
private:
	//�V�[����ێ����郁���o�ϐ�
	unique_ptr<IScene> sceneArr_[3];

	//�ǂ̃X�e�[�W���Ăяo�������Ǘ�����ϐ�
	int currentSceneNo_;//���݂̃V�[��
	int prevSceneNo_;//�O�̃V�[��

public:
	GameManager();//�R���X�g���N�^
	~GameManager();//�f�X�g���N�^

	int Run(char* keys, char* preKeys);//���̊֐��ŃQ�[�����[�v���Ăяo��
};