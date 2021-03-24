//---------------------------------------------------------------------//
// GameManager.h                                                       //
// Singleton                                                           //
// Used to intialize and release all other manager                     //
//---------------------------------------------------------------------//
#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H
//-------------------------------------------------------------------
#include "Timer.h"
#include "ScreenManager.h"
//-------------------------------------------------------------------
// GameManager - Singleton
//-------------------------------------------------------------------
class GameManager {
private:
	static GameManager* sInstance;
	//---------------------------------------------------------------------
	// Manager Pointers
	//---------------------------------------------------------------------
	Timer* mTimer;
	ScreenManager* mScreenMgr;
	Level* mLevel;

private:
	//------------------------------------------------------------------------------------------
	//Contructor is private so that Instance() must be used to get an instance when needed  
	//------------------------------------------------------------------------------------------
	GameManager();
	//--------------------------------------------------------------------------------------
	//Destructor is private so that the instance can only be destroyed using Release()  
	//--------------------------------------------------------------------------------------
	~GameManager();

public:

	static GameManager* Instance();
	//---------------------------------------------------------------------
	// Release instance
	//---------------------------------------------------------------------
	static void Release();
	//---------------------------------------------------------------------
	// Update game manager
	//---------------------------------------------------------------------
	void Update(float deltaTime);
	void Render();
};

#endif