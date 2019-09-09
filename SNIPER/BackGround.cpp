#include"BackGround.h"

//コンストラクタ
BackGround::BackGround()
{
	m_modelHandle = MV1LoadModel("data/model/background//background/background.pmx");

	if (m_modelHandle < 0)
	{
		printfDx("BackGround:データ読み込みに失敗");
	}

	m_pos = VGet(0, 0, 0);

	//　モデル大きさ変更
	MV1SetScale(m_modelHandle, VGet(10.0f, 10.0f, 10.0f));
}

//デストラクタ
BackGround::~BackGround()
{
	MV1DeleteModel(m_modelHandle);
}


//更新
void BackGround::Update()
{
	MV1SetPosition(m_modelHandle, m_pos);
}
