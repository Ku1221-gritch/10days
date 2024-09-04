#include "GameManager.h"

using namespace std;

//コンストラクタ
GameManager::GameManager()
{
	//各シーンの配列
	sceneArr_[TITLE] = make_unique<TitleScene>();
	sceneArr_[STAGE] = make_unique<StageScene>();
	sceneArr_[CLEAR] = make_unique<ClearScene>();

	//初期シーンの設定
	currentSceneNo_ = TITLE;
}

//デストラクタ
GameManager::~GameManager()
{

}

int GameManager::Run(char* keys, char* preKeys)
{

	//シーンのチェック
	prevSceneNo_ = currentSceneNo_;
	currentSceneNo_ = sceneArr_[currentSceneNo_]->GetSceneNo();

	//シーン変更チェック
	if (prevSceneNo_ != currentSceneNo_)
	{
		sceneArr_[currentSceneNo_]->Init();
	}

	//更新処理
	sceneArr_[currentSceneNo_]->Update(keys, preKeys);//シーンごとの更新処理

	//描画処理
	sceneArr_[currentSceneNo_]->Draw();

	return 0;
}
