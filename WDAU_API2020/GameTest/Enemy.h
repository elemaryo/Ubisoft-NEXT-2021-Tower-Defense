//-------------------------------------------------------------------
// Enemy.h
// The class describing all the behaviours of the game's enemies
// Derived from GameEntity
//-------------------------------------------------------------------
#ifndef _ENEMY_H
#define _ENEMY_H
//-------------------------------------------------------------------
#include "Timer.h"
#include "SpriteEntity.h"
//-------------------------------------------------------------------
// Enemy
//-------------------------------------------------------------------
class Enemy : public GameEntity {

protected:

	//---------------------------------------------------------------------
	// Enemy details
	//---------------------------------------------------------------------

	int mHealth;

	// The amount of money the player is rewarded when enemy is killed
	int mReward;

	int mDamage;

	SpriteEntity* mEnemy;

	//---------------------------------------------------------------------
	// Enemy states
	//---------------------------------------------------------------------
	enum STATES {alive, dead};

	enum TYPE {easy, medium, hard};

	enum DIRECTION {up, down, left, right};

	TYPE mType;

	STATES mCurrentState;

	bool mVisible;

	//---------------------------------------------------------------------
	// Timer for spawn
	//---------------------------------------------------------------------
	float mMoveSpeed;

	float mMovementTimer;

	Timer* mTimer;

	int mPathIndex;

public:
	// constructor takes in float x and float y for positions
	Enemy(float x, float y);
	// destructor
	~Enemy();

	// setter for enemy position
	void SetPos(int x, int y);

	// get path index to manage movement
	int GetPathIndex();

	// getter for enemy coordinates
	void GetPos(float &x, float &y);

	// handle hit
	void WasHit();

	//DIRECTION GetDirection();

	//void SetDirection();

	// getter for enemy angle
	float GetAngle();

	// set enemy sprite angle
	void SetAngle(float angle);

	// update enemy
	void Update();

	// render the enemy onto the screen
	void Render();

	// void Attack(target)
	//virtual void HandleDeadState();

	void HandleStates();
};

#endif // !_ENEMY_H

