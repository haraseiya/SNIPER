#include "HitChecker.h"
#include "Player.h"
#include "Enemy.h"
#include "Camera.h"



HitChecker::HitChecker(Enemy& enemy)
{
	// ������
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
	
	// ���f���ɓ���������
	if (HitPoly.HitFlag == 1)
	{
		enemy.~Enemy();
	}
}

void HitChecker::Draw()
{
	int mouse = GetMouseInput();
	// �e�����������ꍇ
	if (mouse&MOUSE_INPUT_RIGHT&&mouse&MOUSE_INPUT_LEFT)
	{
		// �����̕`��
		DrawLine3D(startPos, endPos, GetColor(255, 255, 0));
	}

	// �����������ǂ�����\������
	DrawFormatString(0, 0, GetColor(255, 255, 255), "HIT:%d", HitPoly.HitFlag);
}
