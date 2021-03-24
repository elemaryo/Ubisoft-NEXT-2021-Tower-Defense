//---------------------------------------------------------------------//
// PlayScreen.h														   //
// Used to manage all aspects of the game screen	                   //
// Derived from GameEntity												//
//---------------------------------------------------------------------//
#ifndef _PLAYSCREEN_H
#define _PLAYSCREEN_H
//-----------------------------------------------------------------
#include "App/app.h"
#include "TowerEntity.h"
#include "Level.h"
//-------------------------------------------------------------------
// PlayScreen
//-------------------------------------------------------------------
class PlayScreen : public GameEntity {
private:


	Timer* mTimer;

	float mLevelStartTimer;
	float mLevelStartDelay;
	Level* mLevel;
	bool mLevelStarted;
	
	int mCurrentStage;

	//int ClickDelayTimer

	bool mGameStarted;

	// a level cannot have a player instance everytime so it should be passed
	// to the level from the play screen to keep state
	Player* mPlayer;
	PlaySideBar* mSideBar;

	//int mClickCounter
	TowerEntity::TYPE mCurrentTower;


public:
	PlayScreen();
	~PlayScreen();


	void StartNextLevel();

	void StartNewGame();

	bool GameOver();

	void HandleMouse();

	void BuyTower(TowerEntity::TYPE tower);

	void SellTower(TowerEntity* tower);

	void PlaceTower(float x, float y);

	//void UpgradeTower(TowerEntity* tower);

	void Update();
	void Render();
};

#endif // !_PLAYSCREEN_H