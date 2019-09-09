#ifndef _TARGET_STAGE_H_
#define _TARGET_STAGE_H_

#include "StageBase.h"

class TargetStage :public StageBase
{
public:
	TargetStage();
	virtual ~TargetStage();

	void Update();
};

#endif
