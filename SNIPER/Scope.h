#include"DxLib.h"

#ifndef _SCOPE_H_
#define _SCOPE_H_

class Scope
{
public:
	Scope();			//�R���X�g���N�^
	~Scope();			//�f�X�g���N�^
	void Draw();
	void Update();

private:
	VECTOR m_pos;		// �摜��`�悷����W
	int m_x;			// �`�悷�钆�Sx���W
	int m_y;			// �`�悷�钆�Sy���W
	int m_sizeX;		// �摜�̉��T�C�Y
	int m_sizeY;		// ��ʂ̏c�T�C�Y
	int m_colorBit;		// ��ʂ̃J���[�r�b�g�[�x
	int m_imageHandle;	// �`�悷��摜�̃n���h��
	float m_fov;		// ��p
};

#endif