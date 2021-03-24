//-------------------------------------------------------------------
// HardEnemy.h
// The class describing hard level enemy
// Derived from Enemy
//-------------------------------------------------------------------
#include "stdafx.h"
#include "HardEnemy.h"
//-------------------------------------------------------------------
// Hard Enemy
//-------------------------------------------------------------------
HardEnemy::HardEnemy(float x, float y) : Enemy(x, y) {
	mType = TYPE::hard;

	mHealth = 300;

	mReward = 300;

	mDamage = 100;


	// set move speed here?

}

HardEnemy::~HardEnemy() {


}

void HardEnemy::Update() {


}

void HardEnemy::Render() {

};