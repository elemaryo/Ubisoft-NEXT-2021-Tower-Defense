//-------------------------------------------------------------------
// ScoreBoard.h
// Used to display the score onto the screen
// Derived from GameEntity
//-------------------------------------------------------------------
#include "stdafx.h"
//-------------------------------------------------------------------
#include "Scoreboard.h"
//-------------------------------------------------------------------
Scoreboard::Scoreboard(float x, float y){
	
	XPos(x);
	YPos(y);
	mScore = 0;

	

	//for (int i = 0; i < 2; i++)
	//	mScore.push_back(new SpriteEntity(mZero, 1, 1, i ,0));

	//// All characters are added as a child of this class to make them all move when this entity is moved or rotated
	//for (int i = 0; i < mScore.size(); i++)
	//	mScore[i]->Parent(this);
		
}

Scoreboard::~Scoreboard() {

	ClearBoard();
}

void Scoreboard::ClearBoard() {

	mScore = 0;

	//for (int i = 0; i < mScore.size(); i++)
	//	delete mScore[i];

	//mScore.clear();
}

void Scoreboard::SetScore(int score) {
	mScore = score;
}


void Scoreboard::Render() {

	App::Print(XPos(false), YPos(false), std::to_string(mScore).c_str(), 1.0f, 1.0f, 1.0f, GLUT_BITMAP_TIMES_ROMAN_24);
	//for (int i = 0; i < mScore.size(); i++)
	//	mScore[i]->Render();
}