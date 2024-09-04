#include "GameManager.h"
#include"Novice.h"

using namespace std;

//�R���X�g���N�^
GameManager::GameManager()
{
	//�e�V�[���̔z��
	sceneArr_[TITLE] = make_unique<TitleScene>();
	sceneArr_[STAGE] = make_unique<StageScene>();
	sceneArr_[CLEAR] = make_unique<ClearScene>();

	//�����V�[���̐ݒ�
	currentSceneNo_ = TITLE;
}

//�f�X�g���N�^
GameManager::~GameManager()
{

}

int GameManager::Run(char* keys, char* preKeys)
{

	//�V�[���̃`�F�b�N
	prevSceneNo_ = currentSceneNo_;
	currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

	//�V�[���ύX�`�F�b�N
	if (prevSceneNo_ != currentSceneNo_)
	{
		sceneArr_[currentSceneNo_]->Init();
	}

	//�X�V����
	sceneArr_[currentSceneNo_]->Update(keys, preKeys);//�V�[�����Ƃ̍X�V����

	//�`�揈��
	sceneArr_[currentSceneNo_]->Draw();

	return 0;
}
