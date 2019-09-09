#include"DxLib.h"

#ifndef _SCOPE_H_
#define _SCOPE_H_

class Scope
{
public:
	Scope();			//コンストラクタ
	~Scope();			//デストラクタ
	void Draw();
	void Update();

private:
	VECTOR m_pos;		// 画像を描画する座標
	int m_x;			// 描画する中心x座標
	int m_y;			// 描画する中心y座標
	int m_sizeX;		// 画像の横サイズ
	int m_sizeY;		// 画面の縦サイズ
	int m_colorBit;		// 画面のカラービット深度
	int m_imageHandle;	// 描画する画像のハンドル
	float m_fov;		// 画角
};

#endif