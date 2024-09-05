#include <math.h>
#include "StageScene.h"

StageScene::~StageScene()
{
	delete player_;
	delete enemy_;
}

void StageScene::Init()
{
	player_ = new Player({ 1280 / 2, 720 / 2 }, 16, 10,32);
	enemy_ = new Enemy({ 100, 300 }, 3, 16, true,32);
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
}

void StageScene::Draw()
{
	/*プレイヤーの描画関数*/
	player_->Draw();
	/*敵の描画関数*/
	enemy_->Draw();
}
