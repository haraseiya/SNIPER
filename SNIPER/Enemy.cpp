#include "Enemy.h"

Enemy::Enemy()
{
	m_pos = VGet(0, 0, 50);
	m_modelHandle = MV1LoadModel("data/model/Enemy/Enemy.pmx");

	// �G�̃R���W����
	m_setupCollision = MV1SetupCollInfo(m_modelHandle, 0, 8, 8, 8);

	if (m_modelHandle < 0)
	{
		printfDx("Enemy.cpp:�f�[�^�ǂݍ��݂Ɏ��s");
	}
}

Enemy::~Enemy()
{
	// ���f���̍폜
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
