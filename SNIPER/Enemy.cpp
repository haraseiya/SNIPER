#include "Enemy.h"

Enemy::Enemy()
{
	m_pos = VGet(0, 0, 50);
	m_modelHandle = MV1LoadModel("data/model/Enemy/Enemy.pmx");

	// 敵のコリジョン
	m_setupCollision = MV1SetupCollInfo(m_modelHandle, 0, 8, 8, 8);

	if (m_modelHandle < 0)
	{
		printfDx("Enemy.cpp:データ読み込みに失敗");
	}
}

Enemy::~Enemy()
{
	// モデルの削除
	MV1DeleteModel(m_modelHandle);
}

void Enemy::Draw()
{
	MV1DrawModel(m_modelHandle);
}

void Enemy::Update()
{
	MV1SetPosition(m_modelHandle, m_pos);
}
