//-------------------------------------------------------------------
// Enemy.h
// The class describing all the behaviours of the game's enemies
// Derived from GameEntity
//-------------------------------------------------------------------
#include "stdafx.h"
#include "Enemy.h"
//-------------------------------------------------------------------
// Enemy
//-------------------------------------------------------------------
Enemy::Enemy(float x, float y) {
	
	mTimer = Timer::Instance();
	mMovementTimer = 0.0f;
	mMoveSpeed = 1.0f;
	mPathIndex = 0;

	Active(true);
	mEnemy = new SpriteEntity(".\\TestData\\easyEnemy.bmp", 1, 1, 0, 0);
	mEnemy->Parent(this);
	XPos(x);
	YPos(y);
}

Enemy::~Enemy() {

	delete mEnemy;
	mEnemy = NULL;
}

void Enemy::WasHit() {

}

void Enemy::SetPos(int x, int y) {
	XPos((float)x);
	YPos((float)y);
}

void Enemy::GetPos(float &x, float &y) {
	x = XPos(false);
	y = YPos(false);
}


//void Enemy::HandleStates() {
//	switch (mCurrentState) {
//	case attack:
//		HandleAttack();
//		break;
//
//	case dead:
//		HandleDeadState();
//		break;
//	}
//}

//void Enemy::HandleDeadState() {
//
//}

int Enemy::GetPathIndex() {

	return mPathIndex;
}

float Enemy::GetAngle() {

	return mEnemy->GetAngle();
}

void Enemy::SetAngle(float angle) {
	mEnemy->SetAngle(angle);
}

void Enemy::Update(){

	if (Active()) {
		mMovementTimer += mTimer->DeltaTime();
		if (mMovementTimer >= mMoveSpeed) {
			mPathIndex++;
			mMovementTimer = 0.0f;
		}

		/*HandleStates();*/

	}
}


void Enemy::Render() {
	if (Active()) {
		mEnemy->Render();
	}
}