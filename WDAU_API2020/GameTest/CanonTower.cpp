//-------------------------------------------------------------------
// CanonTower.cpp
// The class describing canon tower entity
// Derived from TowerEntity
//-------------------------------------------------------------------
#include "stdafx.h"
//-------------------------------------------------------------------
#include "CanonTower.h"
//-------------------------------------------------------------------
CanonTower::CanonTower(float x, float y)
	: TowerEntity(x, y)
{
	mType = TYPE::canon;
	mLevel = LEVEL::basic;

	mTower = new SpriteEntity(mBasicCanonfileName, 1, 1, 0, 0);
	mTower->Parent(this);
	XPos(x);
	YPos(y);
	//---------------------------------------------------------------------
	// Initialize tower stats
	//---------------------------------------------------------------------
	mRange = 10.0f;
	mDamage = 10;

}

CanonTower::~CanonTower() {}

void CanonTower::Update() {}

// render towers
void CanonTower::Render() {
	TowerEntity::Render();
};