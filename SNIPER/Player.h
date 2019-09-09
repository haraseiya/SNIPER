#ifndef _PLAYER_H_
#define _PLAYER_H_

#include"DxLib.h"

class Player final
{
public:
	Player();				// コンストラクタ.
	~Player();				// デストラクタ.

	void Update();			// 更新.
	void Draw();			// 描画

	int GetModelHandle() { return m_modelHandle; }

	const VECTOR& GetPos() const { return m_pos; }
	void SetPos(const VECTOR m_set) { m_pos = m_set; }

private :
	VECTOR m_pos;			// プレイヤー初期位置
	int m_modelHandle;		// プレイヤーモデル
	int m_attachIndex;		// アニメーションアタッチ
	int m_speed;			// プレイヤースピード
	int m_animNum;			// アニメーション番号

	float m_totalTime;		// アニメーションの総合時間
	float m_playTime;		// アニメーションの現在時間
};

#endif // _PLAYER_H_