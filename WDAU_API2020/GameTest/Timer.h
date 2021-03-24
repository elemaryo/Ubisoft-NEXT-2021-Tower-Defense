//---------------------------------------------------------------------//
// Timer.h															   //
// Singleton                                                           //
// Used to keep track of time in game for entities                     //
//---------------------------------------------------------------------//
#ifndef _TIMER_H
#define _TIMER_H
//-----------------------------------------------------------------
// Timer - Singleton
//-----------------------------------------------------------------
class Timer {

private:
	static Timer* sInstance;
	//---------------------------------------------------------------------
	//Stores the time elapsed since the last reset in seconds
	//---------------------------------------------------------------------
	float mDeltaTime;


public:
	//-----------------------------------------
	//Returns a pointer to the class instance  
	//-----------------------------------------
	static Timer* Instance();
	//-----------------------------------------------------
	//Releases the class instance and sets it back to NULL 
	//-----------------------------------------------------
	static void Release();

	//-------------------------------------------------------
	// Getter forTime elapsed in seconds
	//-------------------------------------------------------
	float DeltaTime();
	//-------------------------------------------------------
	// Setter forTime elapsed in seconds
	//-------------------------------------------------------
	void DeltaTime(float deltaTime);


private:

	//------------------------------------------------------------------------------------------
	//Contructor is private so that Instance() must be used to get an instance when needed  
	//------------------------------------------------------------------------------------------
	Timer();
	//--------------------------------------------------------------------------------------
	//Destructor is private so that the instance can only be destroyed using Release()  
	//--------------------------------------------------------------------------------------
	~Timer();
};

#endif
