//-------------------------------------------------------------------
// Level.h
// The class manages all aspects of the level entity
// Derived from GameEntity
//-------------------------------------------------------------------
#ifndef _LEVEL_H
#define _LEVEL_H
//-------------------------------------------------------------------
#include "Enemy.h"
#include "Map.h"
#include "PlaySideBar.h"
#include "Player.h"
#include "TowerEntity.h"
//-------------------------------------------------------------------
// Level
//-------------------------------------------------------------------
class Level : public GameEntity {
public:

	// number of enemies based on type
	static const int MAX_NUMBER_OF_ENEMIES = 5;
	float mEnemyDeployDelay;
	//timer
	float mEnemySpawnTimer;
	Timer* mTimer;

	//level delay timer

	//gold incrementing
	//health incrementing

	// keeps track of the level states
	// finished if all enemies are destroyed
	enum LEVEL_STATES { running, finished, gameover };

	//boolean to check if level started;
	bool mLevelStarted;

	// list of enemies in level
	std::vector<Enemy*> mEnemy;

	// list of towers in level
	std::vector <TowerEntity*> mTowers;

	//---------------------------------------------------------------------
	// important entities in level
	//---------------------------------------------------------------------
	// map entity
	Map* mMap;
	// side bar entity
	PlaySideBar* mSideBar;
	// player entity
	Player* mPlayer;

	// current stage number
	int mStage;

	// current tower type
	TowerEntity::TYPE mTowerType;

private: 
	//---------------------------------------------------------------------
	// Spawn enemies in level
	//---------------------------------------------------------------------
	void SpawnEnemy();
	//---------------------------------------------------------------------
	// Spawn towers in level
	//---------------------------------------------------------------------
	void SpawnTower(TowerEntity::TYPE type, float x, float y);

public:
	// constructor
	Level(int stage, PlaySideBar* sideBar, Player* player);
	~Level();

	// set level states
	LEVEL_STATES State();

	//void SetCurrentTowerType();

	// update level
	void Update();

	// render level items
	void Render();
};

#endif // !_LEVEL_H

