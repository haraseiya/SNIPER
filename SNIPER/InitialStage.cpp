#include"InitialStage.h"

InitialStage::InitialStage()
{
	//�@���f���ǂݍ���
	m_modelHandle = MV1LoadModel("data/model/Stage/Stage.x");

	if (m_modelHandle < 0)
	{
		printfDx("InitialStage:�f�[�^�ǂݍ��݂Ɏ��s");
	}

	//�����ʒu
	m_pos = VGet(0, 0, 0);
	MV1SetScale(m_modelHandle, VGet(4.0f, 4.0f, 4.0f));
}

InitialStage::~InitialStage()
{
	MV1DeleteModel(m_modelHandle);
}

void InitialStage::Update()
{
	MV1SetPosition(m_modelHandle, m_pos);
}