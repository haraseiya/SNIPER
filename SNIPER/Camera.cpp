#include "Player.h"
#include "TargetStage.h"
#include "Camera.h"
#include <math.h>

#define USE_LERP_CAMERA 1

//-----------------------------------------------------------------------------
// @brief  コンストラクタ.
//-----------------------------------------------------------------------------
Camera::Camera()
{
	//奥行0.1～1000までをカメラの描画範囲とする
	SetCameraNearFar(0.1f, 15000.0f);

	m_pos = VGet(0, 0, 0);
	m_rotateT = 0.0f;
}

//-----------------------------------------------------------------------------
// @brief  デストラクタ.
//-----------------------------------------------------------------------------
Camera::~Camera()
{
	// 処理なし.
}

//-----------------------------------------------------------------------------
// @brief  更新.
//-----------------------------------------------------------------------------
void Camera::Update(Player& player)
{
	aimPos = VGet(player.GetPos().x, player.GetPos().y + 20.0f, player.GetPos().z + 30.0f);
	SetCameraPositionAndTarget_UpVecY(m_pos, player.GetPos());
	posToAim = VSub(aimPos, m_pos);	// (b-a)
	scaledPosToAim = VScale(posToAim, 0.03f);	// ((b-a) * t)
	m_pos = VAdd(m_pos, scaledPosToAim);	// a + ((b-a) * t)
}

void Camera::Update()
{
	// マウスの座標を取得
	GetMousePoint(&m_mouseX, &m_mouseY);
	
	// カメラ回転速度
	m_rotateSpeedH = (float)m_mouseX / 120.0f;	// 水平
	m_rotateSpeedV = (float)m_mouseY / 120.0f;	// 垂直

	// カメラ位置、角度を反映
	SetCameraPositionAndAngle(VGet(0,20,30), m_rotateSpeedV, m_rotateSpeedH, m_rotateT);
}

