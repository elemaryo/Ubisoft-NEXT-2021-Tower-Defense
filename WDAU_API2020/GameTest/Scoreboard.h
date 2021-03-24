//-------------------------------------------------------------------
// ScoreBoard.h
// Used to display the score onto the screen
// Derived from GameEntity
//-------------------------------------------------------------------
#ifndef _SCOREBOARD_H
#define _SCOREBOARD_H
//-------------------------------------------------------------------
#include "SpriteEntity.h"
#include "App/app.h"
//-------------------------------------------------------------------
// ScoreBoard
//-------------------------------------------------------------------
class Scoreboard : public GameEntity {

private:
	// file name for 0 character
	char* mZero = ".\\TestData\\0.bmp";

	// vector containing score sprite entities
	//std::vector<SpriteEnt> mScore;

	// value for score
	int mScore;

public:
	// constructor takes in float x and float y for positions
	Scoreboard(float x = 0.0f, float y = 0.0f);

	// destructor
	~Scoreboard();

	// set the score based on a certain amount
	void SetScore(int score);

	// render the scoreboard onto the screen
	void Render();

private:
	// clear the content values of the scoreboard
	void ClearBoard();
};



#endif // !_SCOREBOARD_H