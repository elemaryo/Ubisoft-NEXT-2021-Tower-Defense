//-------------------------------------------------------------------
// Player.h
// The class describing all player stats
// Derived from GameEntity
//-------------------------------------------------------------------
#ifndef _PLAYER_H
#define _PLAYER_H
//-------------------------------------------------------------------
#include "App/app.h"
#include "GameEntity.h"
//-------------------------------------------------------------------
// Player
//-------------------------------------------------------------------
class Player : public GameEntity {

private:
	
	//bool WasHit;

	//---------------------------------------------------------------------
	// Player details
	//---------------------------------------------------------------------

	// player health
	int mHealth;

	// player money
	int mCurrency;


public:
	Player();
	~Player();

	int Health();

	int Currency();

	//void WasHit();
	//---------------------------------------------------------------------
	// Setterws Player details
	//---------------------------------------------------------------------
	void SetHealth(int change);
	void SetCurrency(int change);

	void Update();
	void Render();
};

#endif // !_PLAYER_H
