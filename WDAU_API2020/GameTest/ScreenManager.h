//---------------------------------------------------------------------//
// ScreenManager.h                                                     //
// Singleton                                                           //
// Used to manage all screens and transitions between them             //
//---------------------------------------------------------------------//
#ifndef _SCREENMANAGER_H

#define _SCREENMANAGER_H

#include "StartScreen.h"

#include "PlayScreen.h"

#include "App/app.h"
//-------------------------------------------------------------------
// ScreenManager - Singleton
//-------------------------------------------------------------------
class ScreenManager {

private:
	//---------------------------------------------------------------------
	// Screen states
	//---------------------------------------------------------------------
	enum SCREENS { start, play };
	static ScreenManager* sInstance;

	StartScreen* mStartScreen;
	PlayScreen* mPlayScreen;

	SCREENS mCurrentScreen;

public:
	static ScreenManager* Instance();
	//---------------------------------------------------------------------
	// Release instance
	//---------------------------------------------------------------------
	static void Release();

	void Update();
	void Render();

private:
	//------------------------------------------------------------------------------------------
	//Contructor is private so that Instance() must be used to get an instance when needed  
	//------------------------------------------------------------------------------------------
	ScreenManager();
	//--------------------------------------------------------------------------------------
	//Destructor is private so that the instance can only be destroyed using Release()  
	//--------------------------------------------------------------------------------------
	~ScreenManager();
};

#endif // !_SCREENMANAGER_H
