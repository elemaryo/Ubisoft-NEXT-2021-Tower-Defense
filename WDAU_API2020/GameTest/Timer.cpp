//---------------------------------------------------------------------//
// Timer.h															   //
// Singleton                                                           //
// Used to keep track of time in game for entities                     //
//---------------------------------------------------------------------//
#include "stdafx.h"
#include "Timer.h"
//-----------------------------------------------------------------
// Timer - Singleton
//-----------------------------------------------------------------
Timer* Timer::sInstance = nullptr;

Timer* Timer::Instance() {

	//Create a new instance of Timer if no instance was created before
	if (sInstance == nullptr)
		sInstance = new Timer();

	return sInstance;
}

void Timer::Release() {

	delete sInstance;
	sInstance = nullptr;
}

Timer::Timer() {
	
}

Timer::~Timer() {

}


float Timer::DeltaTime() {

	return mDeltaTime;
}

void Timer::DeltaTime(float deltaTime) {
	mDeltaTime = deltaTime*0.001;
}
