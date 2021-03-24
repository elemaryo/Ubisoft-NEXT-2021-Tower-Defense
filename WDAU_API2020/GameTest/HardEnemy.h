//-------------------------------------------------------------------
// HardEnemy.h
// The class describing hard level enemy
// Derived from Enemy
//-------------------------------------------------------------------
#ifndef _HARDENEMY_H
#define _HARDENEMY_H
//-------------------------------------------------------------------
#include "Enemy.h"
//-------------------------------------------------------------------
// Hard Enemy
//-------------------------------------------------------------------
class HardEnemy : public Enemy {
private:
	//---------------------------------------------------------------------
	// Hard Enemy Filename
	//---------------------------------------------------------------------
	char* mHardEnemyfileName = ".\\TestData\\hardEnemy.bmp";

public:
	// constructor takes in float x and float y for positions
	HardEnemy(float x, float y);
	// destructor
	~HardEnemy();
	// update enemy
	void Update();
	// render the enemy onto the screen
	void Render();
};

#endif // !_HardENEMY_H