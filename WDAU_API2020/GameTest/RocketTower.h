//-------------------------------------------------------------------
// RocketTower.h
// The class describing rocket tower entity
// Derived from TowerEntity
//-------------------------------------------------------------------
#ifndef _ROCKETTOWER_H
#define _ROCKETTOWER_H
//-------------------------------------------------------------------
#include "TowerEntity.h"
//-------------------------------------------------------------------
// RocketTower
//-------------------------------------------------------------------
class RocketTower : public TowerEntity {
private:
	//---------------------------------------------------------------------
	// Rocket Tower Filenames
	//---------------------------------------------------------------------
	char* mBasicRocketfileName = ".\\TestData\\basicRocket.bmp";
	char* mUpgradedRocketfileName = ".\\TestData\\upgradedRocket.bmp";

public:

	RocketTower(float x, float y);
	~RocketTower();

	void Update();
	void Render();

};

#endif
