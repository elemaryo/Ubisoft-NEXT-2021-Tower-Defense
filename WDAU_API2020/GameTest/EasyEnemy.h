//-------------------------------------------------------------------
// EasyEnemy.h
// The class describing easy level enemy
// Derived from Enemy
//-------------------------------------------------------------------
#ifndef _EASYENEMY_H
#define _EASYENEMY_H
//-------------------------------------------------------------------
#include "Enemy.h"
//-------------------------------------------------------------------
// Easy Enemy
//-------------------------------------------------------------------
class EasyEnemy : public Enemy {
private:
	//---------------------------------------------------------------------
	// Easy Enemy Filename
	//---------------------------------------------------------------------
	char* mEasyEnemyfileName = ".\\TestData\\easyEnemy.bmp";

public:
	// constructor takes in float x and float y for positions
	EasyEnemy(float x, float y);
	// destructor
	~EasyEnemy();
	// update enemy
	void Update();
	// render the enemy onto the screen
	void Render();
};

#endif // !_EASYENEMY_H