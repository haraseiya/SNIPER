#ifndef _INITIAL_STAGE_H_
#define _INITIAL_STAGE_H_

#include "StageBase.h"

class InitialStage :public StageBase
{
public:
	InitialStage();					//　コンストラクタ
	virtual ~InitialStage();			//　デストラクタ

	void Update();				//　更新
};

#endif
