#include "HitChecker.h"
#include "Player.h"
#include "Enemy.h"
#include "Camera.h"



HitChecker::HitChecker(Enemy& enemy)
{
	// 初期化
	HitPoly = MV1CollCheck_Line(enemy.GetModelHandle(), 0, startPos, endPos);
}


HitChecker::~HitChecker()
{

}

void HitChecker::Update(Camera& camera, Enemy& enemy)
{
	int mouse = GetMouseInput();
	startPos = VGet(camera.GetPos().x, camera.GetPos().y, camera.GetPos().z);
	endPos = VGet(enemy.GetPos().x, enemy.GetPos().y + 10, enemy.GetPos().z + 10);


	if (mouse&MOUSE_INPUT_RIGHT&&mouse&MOUSE_INPUT_LEFT)
	{
		HitPoly = MV1CollCheck_Line(enemy.GetModelHandle(), 0, startPos, endPos);
	}
	
	// モデルに当たったら
	if (HitPoly.HitFlag == 1)
	{
		enemy.~Enemy();
	}
}

void HitChecker::Draw()
{
	int mouse = GetMouseInput();
	// 弾が当たった場合
	if (mouse&MOUSE_INPUT_RIGHT&&mouse&MOUSE_INPUT_LEFT)
	{
		// 線分の描画
		DrawLine3D(startPos, endPos, GetColor(255, 255, 0));
	}

	// 当たったかどうかを表示する
	DrawFormatString(0, 0, GetColor(255, 255, 255), "HIT:%d", HitPoly.HitFlag);
}
