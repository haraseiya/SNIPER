#ifndef _STAGE_BASE_H_
#define _STAGE_BASE_H_

#include "DxLib.h"

class StageBase 
{
public:
	StageBase() {}		//�R���X�g���N�^
	virtual ~StageBase() {}		//�f�X�g���N�^

	virtual void Draw();		//�`��
	virtual void Update() = 0;	//�X�V

	int GetModelhandle() { return m_modelHandle; }

	//�@�����ʒu�̃Q�b�^�[
	const VECTOR& GetPos() const{ return m_pos; }
	//�@�����ʒu�̃Z�b�^�[
	void SetPos(const VECTOR m_set) { m_pos = m_set; }

protected:
	int m_modelHandle;			//�@���f��
	VECTOR m_pos;				//�@�ʒu
};

#endif