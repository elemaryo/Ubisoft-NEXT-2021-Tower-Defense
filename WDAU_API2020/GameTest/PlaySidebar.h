//-------------------------------------------------------------------
// PlaySideBar.h
// The class describing play side bar entity that contains key information
// Derived from GameEntity
//-------------------------------------------------------------------
#ifndef _PLAYSIDEBAR_H
#define _PLAYSIDEBAR_H
//-------------------------------------------------------------------
#include "GameEntity.h"
#include "TowerEntity.h"
#include "App/app.h"
#include "Timer.h"
//-------------------------------------------------------------------
// PlaySideBar
//-------------------------------------------------------------------
class PlaySideBar : public GameEntity {
private:

	//---------------------------------------------------------------------
	// Side bar background
	//---------------------------------------------------------------------
	char* mFileName = ".\\TestData\\greenBackground.bmp";

	SpriteEntity* mBackground;

	//---------------------------------------------------------------------
	// Player relative stats
	//---------------------------------------------------------------------
	int mCurrency;

	int mHealth;

	int mCurrentLevel;

	int mTowerCost;
	
	//---------------------------------------------------------------------
	// Selected tower to pass to level through playscreen
	//---------------------------------------------------------------------
	TowerEntity::TYPE mSelectedTower;

	//---------------------------------------------------------------------
	// Variables to render sprites of towers
	//---------------------------------------------------------------------
	SpriteEntity* mCanonTower;
	SpriteEntity* mRocketTower;

	//---------------------------------------------------------------------
	// Timer
	//---------------------------------------------------------------------
	Timer* mTimer;
	bool mLabelVisible;
	char* mInvalidFundsLabel = "Can't purchase tower, you do not have enough funds!";
	float mToggleTime;
	float mToggleTimer;

public:
	PlaySideBar();
	~PlaySideBar();

	//---------------------------------------------------------------------
	// Label Setters
	//---------------------------------------------------------------------
	void SetCurrency(int amount);
	void SetHealth(int health);
	void SetLevel(int level);
	TowerEntity::TYPE GetSelectedTower();

	//---------------------------------------------------------------------
	// Create labels to be displayed on playside bar
	//---------------------------------------------------------------------
	void CreateLabel(float x, float y, int value);

	void ToggleInvalidFundsLabel();

	void Render();

};


#endif // !_PLAYSIDEBAR_H