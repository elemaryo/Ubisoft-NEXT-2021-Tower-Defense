//---------------------------------------------------------------------//
// ScreenManager.h                                                     //
// Singleton                                                           //
// Used to manage all screens and transitions between them             //
//---------------------------------------------------------------------//
#include "stdafx.h"
#include "ScreenManager.h"
//-------------------------------------------------------------------
ScreenManager* ScreenManager::sInstance = NULL;

ScreenManager* ScreenManager::Instance()
{
	if (sInstance == NULL)
	{
		sInstance = new ScreenManager();
	}

	return sInstance;
}

void ScreenManager::Release()
{
	delete sInstance;
	sInstance = NULL;
}

ScreenManager::ScreenManager()
{

	//Initialize StartScreen
	mStartScreen = new StartScreen();

	mPlayScreen = new PlayScreen();

	mCurrentScreen = start;
}

ScreenManager::~ScreenManager()
{

	delete mStartScreen;
	mStartScreen = NULL;

	delete mPlayScreen;
	mPlayScreen = NULL;
}

void ScreenManager::Update()
{
	switch (mCurrentScreen)
	{
	case start:
		mStartScreen->Update();
		// update current screen if enter is pressed
		if (App::IsKeyPressed(VK_RETURN))
		{
			mCurrentScreen = play;
			mPlayScreen->StartNewGame();
		}
		break;

	case play:
		mPlayScreen->Update();
		// update current screen if escape is pressed
		if (App::IsKeyPressed(VK_ESCAPE) || mPlayScreen->GameOver())
		{
			mCurrentScreen = start;
		}
		break;
	}
};

void ScreenManager::Render()
{

	switch (mCurrentScreen)
	{
	case start:
		mStartScreen->Render();
		break;

	case play:
		mPlayScreen->Render();
		break;
	}
}
