//---------------------------------------------------------------------//
// PlayScreen.cpp													   //
// Used to manage all aspects of the game screen	                   //
// Derived from GameEntity												//
//---------------------------------------------------------------------//
#include "stdafx.h"
#include "PlayScreen.h"
//-------------------------------------------------------------------
// PlayScreen
//-------------------------------------------------------------------
PlayScreen::PlayScreen() {

	mTimer = Timer::Instance();

	// player side bar properties
	mSideBar = new PlaySideBar();
	mSideBar->Parent(this);
	mSideBar->XPos(APP_INIT_WINDOW_WIDTH * 0.87f);
	mSideBar->YPos(APP_INIT_WINDOW_HEIGHT * 0.5f);

	// level properties
	mLevel = NULL;
	mLevelStartDelay = 1.0f;
	mLevelStarted = false;
	mGameStarted = false;

	//player created in start new game function
	mPlayer = NULL;

}

PlayScreen::~PlayScreen()
{
	delete mSideBar;
	mSideBar = NULL;

	delete mLevel;
	mLevel = NULL;

	delete mPlayer;
	mPlayer = NULL;
}


void PlayScreen::StartNextLevel()
{
	mCurrentStage++;
	mLevelStartTimer = 0.0f;
	mLevelStarted = true;

	// delete the old level
	delete mLevel;

	// create new level
	mLevel = new Level(mCurrentStage, mSideBar, mPlayer);
}

// set base variables for a new game
void PlayScreen::StartNewGame()
{
	// delete old player
	delete mPlayer;
	// set new player
	mPlayer = new Player();
	mPlayer->Parent(this);

	// initialize sidebar
	mSideBar->SetHealth(mPlayer->Health());
	mSideBar->SetLevel(0);

	mGameStarted = true;
	/*mLevelStarted = true;*/
	StartNextLevel();
	mLevelStartTimer = 0.0f;
	mLevelStartDelay = 1.0f;
	mCurrentStage = 0;

}

bool PlayScreen::GameOver() {

	if (!mLevelStarted) {
		return false;
	}

	return (mLevel->State() == Level::gameover);
}

void PlayScreen::HandleMouse() {

	//if (IsKeyPressed(MOUSEEVENTF_LEFTDOWN)) {
	//	//timer
	//	// check if its in play screen
	//	// check if its in sidebar on a tower
	//	if (GetMousePosition() == ) {
	//		mCurrentTower =
	//	}
	//	// check if its on the map
	//	else if (GetMousePosition() == ) {
	//		if (mMap->CheckTile()) {
	//			// put tower there
	//		}
	//	}
	//}


}

void PlayScreen::BuyTower(TowerEntity::TYPE tower) {

	//if (mPlayer->Currency() <= tower->GetCost()) {
	//	mPlayer->SetCurrency(-tower->GetCost());
	//	mPlayer->AddScore(10);
	//	mCurrentTower = tower;
	//}

	//else {
	//	mSideBar->ToggleInvalidFundsLabel();
	//	mCurrentTower = NULL;
	//}

}

void PlayScreen::SellTower(TowerEntity* tower) {
	//mPlayer->SetCurrency(tower->GetCost());
	//delete tower;
	//mPlayer->AddScore(10);
	//mCurrentTower = NULL;

}

//void PlayScreen::PlaceTower(float x, float y) {
//
//
//	mLevel->SetCurrentTowerType(mSideBar->GetSelectedTower());
//	
//
//}


void PlayScreen::Update() {

	if (mGameStarted)
	{
		// wait for a second then start level
		if (!mLevelStarted)
		{
			mLevelStartTimer += mTimer->DeltaTime();
			if (mLevelStartTimer >= mLevelStartDelay)
			{
				StartNextLevel();
			}
		}
	}

	// if the game and level start then start the flashing
	if (mGameStarted)
	{
		// update level once it started

		if (mLevelStarted) {
			mLevel->Update();

			// check if level state is finished or not and tell playscreen
			if (mLevel->State() == Level::finished) {
				mLevelStarted = false;
			}
		}
	}

	// playscreen tower variable that is = to the side bar
	

	//if (mPlayer->Currency() <= TowerEntity::GetCost(mSideBar->GetSelectedTower())) {

	//		mPlayer->SetCurrency(-TowerEntity::GetCost(mSideBar->GetSelectedTower()));
	//		PlaceTower(App::)
	//}

	//mSideBar->Update();
	//mLevel->Update();
	//while loop
	//HandleMouse();
}

void PlayScreen::Render() {
	
	mSideBar->Render();

	if (!mGameStarted)
	{
		App::Print(APP_INIT_WINDOW_WIDTH * 0.4f, APP_INIT_WINDOW_HEIGHT * 0.5f, std::strcat("Level:" ,std::to_string(mCurrentStage).c_str()), 1.0f, 1.0f, 1.0f, GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if (mGameStarted)
	{
		if (mLevelStarted) {
			mLevel->Render();
		}
	}

}