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
	//ƒNƒŠƒA‰æ–Ê•`‰æ

}
