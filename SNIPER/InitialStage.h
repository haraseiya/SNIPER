#ifndef _INITIAL_STAGE_H_
#define _INITIAL_STAGE_H_

#include "StageBase.h"

class InitialStage :public StageBase
{
public:
	InitialStage();					//�@�R���X�g���N�^
	virtual ~InitialStage();			//�@�f�X�g���N�^

	void Update();				//�@�X�V
};

#endif
