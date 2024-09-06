#include <math.h>
#include "StageScene.h"

StageScene::~StageScene()
{
	delete player_;
	delete enemy_;
}

void StageScene::Init()
{
	player_ = new Player({ 1280 / 2, 720 / 2 }, 32, 10,32);
	enemy_ = new Enemy({ 100, 300 }, 3, 16, true,32);
	gimic_ = new Gimic();
	gimic_->Init(10, { 100,500 },{500,500});
	for (int i = 0; i < 2; i++) {
		isStageArea[i] = false;
	}

}

void StageScene::Update(char* keys, char* preKeys)
{
	/*プレイヤーの更新*/
	player_->Update(keys, preKeys);
	/*敵の更新*/
	enemy_->Update();

	//当たり判定の処理
	float enemyRadius = (float)enemy_->radius_;
	float playerRadius = (float)player_->r_;

	float a = enemy_->pos_.x - player_->pos_.x;
	float b = enemy_->pos_.y - player_->pos_.y;
	float distance = sqrtf(a * a + b * b);

	//プレイヤーと敵が当たったらとりあえずクリア
	if (distance <= enemyRadius + playerRadius) {
		sceneNo = CLEAR;
	}

	player_->pos_ = gimic_->Warp(player_->pos_, gimic_->in_, gimic_->out_);

	if (isNextStage == true) {
		switch (stage) {
			case S1:
				isNextStage = false;
				memcpy(map, map1, sizeof(map1));
				memcpy(object, object1, sizeof(object1));
				break;
			case S2:
				isNextStage = false;
				memcpy(map, map2, sizeof(map2));
				memcpy(object, object2, sizeof(object2));
				break;
			case S3:
				isNextStage = false;
				memcpy(map, map3, sizeof(map3));
				memcpy(object, object3, sizeof(object3));
				break;
		}
	}
}


void StageScene::Draw()
{
	/*プレイヤーの描画関数*/
	player_->Draw();
	/*敵の描画関数*/
	enemy_->Draw();
	gimic_->Draw();
	//マップチップ対応描画
	MapChipComPatibleDrawing();
}

//マップチップ対応描画
void StageScene::MapChipComPatibleDrawing() {
	for (int y = 0; y < kMapMaxY; y++) {
		for (int x = 0; x < kMapMaxX; x++) {
			//床の描画
			if (map[y][x] == FLOOR) {
				Novice::DrawSprite(x * blockSize, y * blockSize, blockTex, 1, 1, 0.0f, WHITE);
			}
		}
	}
}