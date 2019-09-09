#include"TargetStage.h"

TargetStage::TargetStage()
{
	m_modelHandle = MV1LoadModel("data/model/TargetStage/TargetStage/TargetStage.pmx");

	if (m_modelHandle < 0)
	{
		printfDx("TargetStage.cpp:ƒf[ƒ^“Ç‚Ýž‚Ý‚ÉŽ¸”s");
	}

	m_pos = VGet(0, 0, 0);
	//MV1SetScale(m_modelHandle, VGet(0,0,0));
}

TargetStage::~TargetStage()
{
	MV1DeleteModel(m_modelHandle);
}

void TargetStage::Update()
{
	MV1SetPosition(m_modelHandle, m_pos);
}