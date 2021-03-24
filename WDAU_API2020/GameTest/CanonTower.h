//-------------------------------------------------------------------
// CanonTower.h
// The class describing canon tower entity
// Derived from TowerEntity
//-------------------------------------------------------------------
#ifndef _CANONTOWER_H
#define _CANONTOWER_H
//-------------------------------------------------------------------
#include "TowerEntity.h"
//-------------------------------------------------------------------
// CanonTower
//-------------------------------------------------------------------
class CanonTower : public TowerEntity {
private:
	//---------------------------------------------------------------------
	// Canon Tower Filenames
	//---------------------------------------------------------------------
	char* mBasicCanonfileName = ".\\TestData\\basicCanon.bmp";
	char* mUpgradedCanonfileName = ".\\TestData\\upgradedCanon.bmp";

public:

	CanonTower(float x, float y);
	~CanonTower();

	void Update();
	void Render();

};

#endif
