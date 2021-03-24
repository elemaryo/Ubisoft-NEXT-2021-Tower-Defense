//-------------------------------------------------------------------
// TowerEntity.h
// The class describing all the behaviours of the game's towers
// Derived from GameEntity
//-------------------------------------------------------------------
#ifndef _TOWERENTITY_H
#define _TOWERENTITY_H
//-------------------------------------------------------------------
#include "SpriteEntity.h"
//#include "Bullet.h"
#include "Enemy.h"
//-------------------------------------------------------------------
// TowerEntity
//-------------------------------------------------------------------
class TowerEntity : public GameEntity {

public:
	//---------------------------------------------------------------------
	// Tower types
	//---------------------------------------------------------------------
	enum TYPE { unknown, canon, rocket };
	//---------------------------------------------------------------------
	// Tower levels
	//---------------------------------------------------------------------
	enum LEVEL { basic, upgraded };

protected:
	//---------------------------------------------------------------------
	// Tower stats
	//---------------------------------------------------------------------
	float mRange;
	int mDamage;
	TYPE mType;
	LEVEL mLevel;
	// bullet delay
	//float mShotDuration;

	//---------------------------------------------------------------------
	// Tower to enemy variables
	//---------------------------------------------------------------------
	SpriteEntity* mTower;
	Enemy* mCurrentTarget;
	float mCurrentDistance;
	float mNewDistance;

	//---------------------------------------------------------------------
	// vector of bullets
	//---------------------------------------------------------------------
	//std::vector<Bullet*> mBullet;

private:

	void Shoot(); //add new bullets to vector

	

public:
	TowerEntity(float x, float y);
	~TowerEntity();

	//---------------------------------------------------------------------
	// Getter for tower cost based on type
	//---------------------------------------------------------------------
	static int GetCost(TYPE type);

	//---------------------------------------------------------------------
	// Tower upgrade function
	//---------------------------------------------------------------------
	void UpgradeTower(TYPE);

	//---------------------------------------------------------------------
	// tower find the nearest enemy
	//---------------------------------------------------------------------
	void FindNearestEnemy(std::vector<Enemy*> mEnemy);

	void Update();	//update bullets
	void Render(); //render bullets
};

#endif // !_TOWERENTITY_H

