#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "DxLib.h"

class Enemy
{
public:
	Enemy();
	~Enemy();

	const VECTOR& GetPos() const { return m_pos; }
	void SetPos(const VECTOR m_set) { m_pos = m_set; }

	int GetModelHandle() { return m_modelHandle; }

	void Draw();
	void Update();

private:
	VECTOR m_pos;

	int m_modelHandle;
	int m_setupCollision;
};

#endif
