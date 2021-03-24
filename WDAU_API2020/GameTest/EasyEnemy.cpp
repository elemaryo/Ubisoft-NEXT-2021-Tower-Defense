//-------------------------------------------------------------------
// EasyEnemy.h
// The class describing easy level enemy
// Derived from Enemy
//-------------------------------------------------------------------
#include "stdafx.h"
#include "EasyEnemy.h"
//-------------------------------------------------------------------
// Easy Enemy
//-------------------------------------------------------------------
EasyEnemy::EasyEnemy(float x, float y) : Enemy(x, y) {
	mType = TYPE::easy;

	mHealth = 100;

	mReward = 50;

	mDamage = 25;


	// set move speed here?

}

EasyEnemy::~EasyEnemy() {


}

void EasyEnemy::Update() {


}

void EasyEnemy::Render() {

};