#ifndef _STAGE_BASE_H_
#define _STAGE_BASE_H_

#include "DxLib.h"

class StageBase 
{
public:
	StageBase() {}		//コンストラクタ
	virtual ~StageBase() {}		//デストラクタ

	virtual void Draw();		//描画
	virtual void Update() = 0;	//更新

	int GetModelhandle() { return m_modelHandle; }

	//　初期位置のゲッター
	const VECTOR& GetPos() const{ return m_pos; }
	//　初期位置のセッター
	void SetPos(const VECTOR m_set) { m_pos = m_set; }

protected:
	int m_modelHandle;			//　モデル
	VECTOR m_pos;				//　位置
};

#endif