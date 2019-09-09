#include"InitialStage.h"

InitialStage::InitialStage()
{
	//　モデル読み込み
	m_modelHandle = MV1LoadModel("data/model/Stage/Stage.x");

	if (m_modelHandle < 0)
	{
		printfDx("InitialStage:データ読み込みに失敗");
	}

	//初期位置
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