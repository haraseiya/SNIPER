#ifndef _HITCHECKER_H_
#define _HITCHECKER_H_

#include "DxLib.h"

class Player;
class Enemy;
class Camera;

class HitChecker
{
public:
	HitChecker(Enemy& enemy);
	~HitChecker();
	
	void Update(Camera& camera, Enemy& enemy);
	void Draw();

private:
	VECTOR startPos;
	VECTOR endPos;

	MV1_COLL_RESULT_POLY HitPoly;
};

#endif
