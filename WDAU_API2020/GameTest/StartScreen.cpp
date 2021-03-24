//-------------------------------------------------------------------
// StartScreen.h
// Used to display Start Screen
// Derived from GameEntity
//-------------------------------------------------------------------
#include "stdafx.h"
//-------------------------------------------------------------------
#include "StartScreen.h"
//-------------------------------------------------------------------
StartScreen::StartScreen()
{
}

StartScreen::~StartScreen() {

}

void StartScreen::Update() {}

void StartScreen::CreateLabel(float x, float y, char* value) {
	App::Print(APP_INIT_WINDOW_WIDTH * 0.5f + x, APP_INIT_WINDOW_HEIGHT * 0.5f + y, value, 1.0f, 1.0f, 1.0f, GLUT_BITMAP_TIMES_ROMAN_24);
}

// render the start screen labels
void StartScreen::Render() {

	CreateLabel(mHorizontalOffset, mVerticalOffset*2, mWelcomeMessage);
	CreateLabel(mHorizontalOffset, mVerticalOffset, mName);
	CreateLabel(mHorizontalOffset, 0, mStartMessage);
}