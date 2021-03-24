//-------------------------------------------------------------------
// RocketTower.cpp
// The class describing rocket tower entity
// Derived from TowerEntity
//-------------------------------------------------------------------
#include "stdafx.h"
//-------------------------------------------------------------------
#include "RocketTower.h"
//-------------------------------------------------------------------
RocketTower::RocketTower(float x, float y)
	: TowerEntity(x, y)
{
	mType = TYPE::rocket;
	mLevel = LEVEL::basic;

	mTower = new SpriteEntity(mBasicRocketfileName, 1, 1, x, y);
	mTower->Parent(this);
	XPos(x);
	YPos(y);
	//---------------------------------------------------------------------
	// Initialize tower stats
	//---------------------------------------------------------------------
	mRange = 30.0f;
	mDamage = 20;

}

RocketTower::~RocketTower() {


}

void RocketTower::Update() {


}
// render towers
void RocketTower::Render() {
	TowerEntity::Render();
};