#include "ClearScene.h"

void ClearScene::Init() {}

void ClearScene::Update(char* keys, char* preKeys)
{
	if (!preKeys[DIK_SPACE] && keys[DIK_SPACE]) {
		sceneNo = TITLE;
	}
}

void ClearScene::Draw()
{
	//クリア画面描画
	Novice::ScreenPrintf(670, 420, "GameClear");
}
