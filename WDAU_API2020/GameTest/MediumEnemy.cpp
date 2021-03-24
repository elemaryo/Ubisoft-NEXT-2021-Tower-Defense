//-------------------------------------------------------------------
// MediumEnemy.h
// The class describing medium level enemy
// Derived from Enemy
//-------------------------------------------------------------------
#include "stdafx.h"
#include "MediumEnemy.h"
#include "Enemy.h"
//-------------------------------------------------------------------
// Medium Enemy
//-------------------------------------------------------------------
MediumEnemy::MediumEnemy(float x, float y) : Enemy(x, y) {
	mType = TYPE::medium;

	mHealth = 200;

	mReward = 150;

	mDamage = 50;


	// set faster move speed here?

}

MediumEnemy::~MediumEnemy() {


}

void MediumEnemy::Update() {


}

void MediumEnemy::Render() {

};