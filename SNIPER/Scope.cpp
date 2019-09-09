#include "Scope.h"

Scope::Scope()
{
	m_pos = VGet(0, 0, 0);
	m_x = 0.0f;
	m_y = 0.0f;
	m_imageHandle=LoadGraph("data/image/scope1.png");
	m_fov = 60.0f;

	// スクリーンの大きさをとってくる
	GetScreenState(&m_sizeX, &m_sizeY, &m_colorBit);
}

Scope::~Scope()
{
	DeleteGraph(m_imageHandle);
}

void Scope::Update()
{
	// カメラ画角を反映
	SetupCamera_Perspective(m_fov * DX_PI_F / 180.0f);

	// マウスホイールでズーム
	m_fov -= GetMouseWheelRotVol();
}

void Scope::Draw()
{
	int Mouse = GetMouseInput();

	if (Mouse&MOUSE_INPUT_RIGHT)
	{
		DrawExtendGraph(m_x, m_y, m_sizeX, m_sizeY, m_imageHandle, TRUE);
	}
}