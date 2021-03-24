//-------------------------------------------------------------------
// StartScreen.h
// Used to display Start Screen
// Derived from GameEntity
//-------------------------------------------------------------------
#ifndef _STARTSCREEN_H
#define _STARTSCREEN_H
//-------------------------------------------------------------------
#include "App/app.h"
#include "GameEntity.h"
//-------------------------------------------------------------------
// StartScreen
//-------------------------------------------------------------------
class StartScreen : public GameEntity {

private:

	//-------------------------------------------------------------------
	// Characters to render
	//-------------------------------------------------------------------
	char* mWelcomeMessage = "Tower Defense";
	char* mName = "Omar Elemary";
	char* mStartMessage = "Press Enter To Start Game!";

	float mHorizontalOffset = -100.0f;
	float mVerticalOffset = 30.0f;

public:

	StartScreen();
	~StartScreen();

	//-------------------------------------------------------------------
	// Method to create labels and position them
	//-------------------------------------------------------------------
	void CreateLabel(float x, float y, char* value);

	void Update();
	void Render();
};

#endif
