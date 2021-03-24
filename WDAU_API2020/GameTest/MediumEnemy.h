//-------------------------------------------------------------------
// MediumEnemy.h
// The class describing medium level enemy
// Derived from Enemy
//-------------------------------------------------------------------
#ifndef _MEDIUMENEMY_H
#define _MEDIUMENEMY_H
//-------------------------------------------------------------------
#include "Enemy.h"
//-------------------------------------------------------------------
// Medium Enemy
//-------------------------------------------------------------------
class MediumEnemy : public Enemy {
private:
	//---------------------------------------------------------------------
	// Medium Enemy Filename
	//---------------------------------------------------------------------
	char* mMediumEnemyfileName = ".\\TestData\\mediumEnemy.bmp";

public:
	MediumEnemy(float x, float y);
	~MediumEnemy();

	void Update();
	void Render();
};

#endif // !_MediumENEMY_H