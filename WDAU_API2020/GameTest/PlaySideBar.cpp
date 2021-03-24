//-------------------------------------------------------------------
// PlaySideBar.cpp
// Creates play side bar entity containing player informatiion and towers
// Derived from GameEntity
//-------------------------------------------------------------------
#include "stdafx.h"
#include "PlaySidebar.h"
//-------------------------------------------------------------------
// PlaySideBar
//-------------------------------------------------------------------
PlaySideBar::PlaySideBar() {

	mTimer = Timer::Instance();
	mToggleTimer = 0.0f;
	mToggleTime = 1.5f;
	mLabelVisible = false;

	mBackground = new SpriteEntity(mFileName, 1, 1, 45.0f, 300.0f);
	mBackground->Parent(this);
	mBackground->XPos(0.0f);
	mBackground->YPos(0.0f);
	mBackground->SetScale(2);

	mSelectedTower = TowerEntity::TYPE::unknown;
	mCanonTower = new SpriteEntity(".\\TestData\\basicCanon.bmp", 1, 1, 0, 0);
	mCanonTower->Parent(this);
	mCanonTower->XPos(60.0f);
	mCanonTower->YPos(64.0f);
	mCanonTower->SetScale(2);

	mRocketTower = new SpriteEntity(".\\TestData\\basicRocket.bmp", 1, 1, 0, 0);
	mRocketTower->Parent(this);
	mRocketTower->XPos(-60.0f);
	mRocketTower->YPos(61.0f);
	mRocketTower->SetScale(2.5);
}

PlaySideBar::~PlaySideBar() {

	mTimer->Release();

	delete mBackground;
	mBackground = NULL;
}

void PlaySideBar::SetCurrency(int amount) {
	mCurrency = amount;
}

void PlaySideBar::SetHealth(int health) {
	mHealth = health;
}

void PlaySideBar::SetLevel(int level) {
	mCurrentLevel = level;
}

TowerEntity::TYPE PlaySideBar::GetSelectedTower() {

	return mSelectedTower;
}

void PlaySideBar::CreateLabel(float x, float y, int value) {
	App::Print(x, y, std::to_string(value).c_str(), 1.0f, 1.0f, 1.0f, GLUT_BITMAP_TIMES_ROMAN_24);
}


void PlaySideBar::ToggleInvalidFundsLabel() {
	mLabelVisible = true;
	while (mLabelVisible) {
		App::Print(0, 0, mInvalidFundsLabel, 1.0f, 1.0f, 1.0f, GLUT_BITMAP_TIMES_ROMAN_24);
		mToggleTimer += mTimer->DeltaTime();
		if (mToggleTimer >= mToggleTime) {
			mLabelVisible = false;
			mToggleTimer = 0.0f;
			break;
		}
	}
}

void PlaySideBar::Render() {

	mBackground->Render();
	mCanonTower->Render();
	mRocketTower->Render();
	//CreateLabel(1, 1, mScore);

}

