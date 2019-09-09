#include "DxLib.h"
#include "Player.h"
#include "Enemy.h"
#include "Camera.h"
#include "StageBase.h"
#include "InitialStage.h"
#include "TargetStage.h"
#include "BackGround.h"
#include "Scope.h"
#include "HitChecker.h"

#define STAGENUM 3

//-----------------------------------------------------------------------------
// @brief  メイン関数.
//-----------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) 
{
	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)		
	{
		return -1;	// エラーが起きたら直ちに終了
	}

	// 画面モードのセット
	SetGraphMode(1920, 1080, 16);
	ChangeWindowMode(FALSE);

	//Zバッファを有効にする
	SetUseZBuffer3D(TRUE);

	//Zバッファへの書き込みを有効にする
	SetWriteZBuffer3D(TRUE);

	// カメラを生成.
	Camera* camera = new Camera();

	// プレイヤーを生成.
	Player* player = new Player();

	// 敵を生成
	Enemy* enemy = new Enemy();

	//ステージを生成
	StageBase* stagebase[STAGENUM];

	// ステージ1を生成
	stagebase[0] = new InitialStage();

	// ステージ2を生成
	stagebase[1] = new TargetStage();

	// 背景
	stagebase[2] = new BackGround();

	//背景を生成
	BackGround* background = new BackGround();

	//ステージの位置を初期化
	stagebase[0]->SetPos(VGet(0, 0, 0));
	stagebase[1]->SetPos(VGet(0, -100, 0));
	stagebase[2]->SetPos(VGet(0, 0, 0));

	//スコープを生成
	Scope* scope = new Scope();

	HitChecker* hit = new HitChecker(*enemy);

	// エスケープキーが押されるかウインドウが閉じられるまでループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// プレイヤー制御.
		player->Update();

		// 敵の制御
		enemy->Update();

		int Mouse = GetMouseInput();

		// カメラ制御
		if (Mouse&MOUSE_INPUT_RIGHT)
		{
			camera->Update();
			scope->Update();
		}
		else
		{
			camera->Update(*player);
		}

		//ステージ制御
		for(int i=0;i<STAGENUM;i++)
		{ 
			stagebase[i]->Update();
		}

		// 当たり判定制御
		hit->Update(*camera,*enemy);

		// 画面を初期化する
		ClearDrawScreen();

		// プレイヤー描画.
		player->Draw();

		// 敵描画
		enemy->Draw();

		//ステージ描画
		for (int i = 0;i < STAGENUM;i++)
		{
			stagebase[i]->Draw();
		}

		// スコープ描画
		scope->Draw();

		// 弾軌道描画
		hit->Draw();

		// 裏画面の内容を表画面に反映させる
		ScreenFlip();
	}

	// プレイヤーを削除.
	delete(player);

	// 敵を削除
	delete(enemy);

	// カメラを削除.
	delete(camera);

	//ステージを削除
	for (int i = 0;i < STAGENUM;i++)
	{
		delete(stagebase[i]);
	}

	// 背景を削除
	delete(background);

	// スコープ削除
	delete(scope);

	// 当たり判定削除
	delete(hit);

	// ＤＸライブラリの後始末
	DxLib_End();

	// ソフトの終了
	return 0;
}