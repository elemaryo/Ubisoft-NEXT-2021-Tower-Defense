//---------------------------------------------------------------------//
// GameManager.h                                                       //
// Singleton                                                           //
// Used to intialize and release all other manager                     //
//---------------------------------------------------------------------//
#include "stdafx.h"
#include "GameManager.h"
//-------------------------------------------------------------------

GameManager* GameManager::sInstance;

GameManager* GameManager::Instance()
{
	if (sInstance == NULL) {

		sInstance = new GameManager();
	}
	return sInstance;
}

//-------------------------------------------------------------------
// deletes the singleton instance, only called once when the game is being closed
//-------------------------------------------------------------------
void GameManager::Release() {

	if (sInstance != NULL) {

		delete sInstance;
		sInstance = NULL;
	}
}

GameManager::GameManager() {
	
	//Initialize Timer
	mTimer = Timer::Instance();

	//Initialize Screen Manager
	mScreenMgr = ScreenManager::Instance();

}

GameManager::~GameManager() {
	// Release Timer
	Timer::Release();
	mTimer = NULL;

	// Release ScreenManager
	mScreenMgr->Release();
	mScreenMgr = NULL;

}

void GameManager::Update(float deltaTime) {
	// Timer saves delta time
	mTimer->DeltaTime(deltaTime);

	// Screen manager updates here
	mScreenMgr->Update();
}

void GameManager::Render() {
	// Screen manager renders here
	mScreenMgr->Render();
}

