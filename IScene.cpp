#include "IScene.h"

//�^�C�g���V�[���ŏ�����
int IScene::sceneNo = TITLE;

//���z�f�X�g���N�^�̒�`
//�������z�֐������Ă��Ȃ��̂ŁA�����Œ�`�ł���
IScene::~IScene() {}

//�V�[���ԍ��̃Q�b�^�[
int IScene::GetSceneNo() { return sceneNo; };
