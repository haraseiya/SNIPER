#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "DxLib.h"

class Player;

class Camera
{
public:
	Camera();							// コンストラクタ.
	~Camera();							// デストラクタ.

	void Update(Player& player);		// プレイヤーカメラ更新
	void Update();						// エイムカメラ更新

	// ポジションのgetter/setter.
	const VECTOR& GetPos() const { return m_pos; }

private:
	VECTOR m_pos;						// ポジション.
	VECTOR aimPos;						// ターゲットの位置
	VECTOR posToAim;
	VECTOR scaledPosToAim;
	VECTOR m_scopePos;					// スコープ時ポジション

	float m_rotateSpeedV;				// 垂直回転角度
	float m_rotateSpeedH;				// 水平回転角度
	float m_rotateT;					// 捻り回転角度

	int m_mouseX;						// マウスのX座標
	int m_mouseY;						// マウスのY座標
	int m_mouseRot;						// ホイール回転量
};

#endif // _CAMERA_H_