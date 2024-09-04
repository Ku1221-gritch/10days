#include "TitleScene.h"

void TitleScene::Init() {}

void TitleScene::Update(char* keys, char* preKeys)
{
	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE])
	{
		sceneNo = STAGE;
	}
}

void TitleScene::Draw()
{
	Novice::ScreenPrintf(670, 420, "push the space");
}
