#include"BackGround.h"

//�R���X�g���N�^
BackGround::BackGround()
{
	m_modelHandle = MV1LoadModel("data/model/background//background/background.pmx");

	if (m_modelHandle < 0)
	{
		printfDx("BackGround:�f�[�^�ǂݍ��݂Ɏ��s");
	}

	m_pos = VGet(0, 0, 0);

	//�@���f���傫���ύX
	MV1SetScale(m_modelHandle, VGet(10.0f, 10.0f, 10.0f));
}

//�f�X�g���N�^
BackGround::~BackGround()
{
	MV1DeleteModel(m_modelHandle);
}


//�X�V
void BackGround::Update()
{
	MV1SetPosition(m_modelHandle, m_pos);
}
