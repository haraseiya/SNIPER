#include "HitChecker.h"
#include "Player.h"
#include "Enemy.h"
#include "Camera.h"



HitChecker::HitChecker(Enemy& enemy)
{
	// ‰Šú‰»
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
	
	// ƒ‚ƒfƒ‹‚É“–‚½‚Á‚½‚ç
	if (HitPoly.HitFlag == 1)
	{
		enemy.~Enemy();
	}
}

void HitChecker::Draw()
{
	int mouse = GetMouseInput();
	// ’e‚ª“–‚½‚Á‚½ê‡
	if (mouse&MOUSE_INPUT_RIGHT&&mouse&MOUSE_INPUT_LEFT)
	{
		// ü•ª‚Ì•`‰æ
		DrawLine3D(startPos, endPos, GetColor(255, 255, 0));
	}

	// “–‚½‚Á‚½‚©‚Ç‚¤‚©‚ğ•\¦‚·‚é
	DrawFormatString(0, 0, GetColor(255, 255, 255), "HIT:%d", HitPoly.HitFlag);
}
