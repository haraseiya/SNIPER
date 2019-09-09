#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include "StageBase.h"

class BackGround :public StageBase
{
public:
	BackGround();		//コンストラクタ
	~BackGround();		//デストラクタ

	void Update();		//更新
};

#endif