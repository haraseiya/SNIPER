#include "Player.h"

//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
Player::Player()
{
	//アニメーション処理
	m_modelHandle = MV1LoadModel("data/model/player/player.pmx");
	m_animNum = 2;
	m_attachIndex = MV1AttachAnim(m_modelHandle, m_animNum);
	m_totalTime = MV1GetAttachAnimTotalTime(m_modelHandle, m_attachIndex);
	m_playTime = 0.0f;
	MV1SetAttachAnimTime(m_modelHandle, m_attachIndex, m_playTime);
	//初期位置
	m_pos = VGet(0, 0, -120);
	//プレイヤースピード
	m_speed = 1;
}

//-----------------------------------------------------------------------------
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
Player::~Player()
{
	MV1DeleteModel(m_modelHandle);
}

//-----------------------------------------------------------------------------
// @brief  更新.
//-----------------------------------------------------------------------------
void Player::Update()
{
	// 入力取得
	int Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	int Mouse = GetMouseInput();

	// 上を押していたら上に進む
	if (Key & PAD_INPUT_UP)
	{
		m_pos.z -= m_speed;
	}

	// 下を押していたら下に進む
	if (Key & PAD_INPUT_DOWN)
	{
		m_pos.z += m_speed;
	}

	// 右を押していたら右に進む
	if (Key & PAD_INPUT_RIGHT)
	{
		m_pos.x -= m_speed;
	}

	// 左を押していたら左に進む
	if (Key & PAD_INPUT_LEFT)
	{
		m_pos.x += m_speed;
	}

	//アニメーションが終わっているかつマウス左クリックでもう1回再生
	if (m_totalTime < m_playTime&&Mouse & MOUSE_INPUT_LEFT)
	{
		m_playTime = 0.0f;
	}

	//アニメーションスピード
	m_playTime += 0.01f;

	//アニメーション時間アタッチ
	MV1SetAttachAnimTime(m_modelHandle, m_attachIndex, m_playTime);
	// ３Dモデルのポジション設定
	MV1SetPosition(m_modelHandle, m_pos);
}

//-----------------------------------------------------------------------------
// @brief  描画.
//-----------------------------------------------------------------------------
void Player::Draw()
{
	// ３Ｄモデルの描画
	MV1DrawModel(m_modelHandle);
}
