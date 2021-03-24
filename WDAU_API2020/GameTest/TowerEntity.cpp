//-------------------------------------------------------------------
// TowerEntity.h
// The class describing all the behaviours of the game's towers
// Derived from GameEntity
//-------------------------------------------------------------------
#include "stdafx.h"
#include "TowerEntity.h"
//-------------------------------------------------------------------
// TowerEntity
//-------------------------------------------------------------------
TowerEntity::TowerEntity(float x, float y){

	
	//mBullet = new Bullet();

	mCurrentTarget = NULL;
	mCurrentDistance = INFINITY;
}

TowerEntity::~TowerEntity(){

	delete mTower;
	mTower = NULL;
}

void TowerEntity::FindNearestEnemy(std::vector<Enemy*> mEnemy) {

	//loop enemies
	for (int i = 0; i < mEnemy.size(); i++) {
		if (mEnemy[i] != NULL) {
			float mEnemyXPos;
			float mEnemyYPos;
			mEnemy[i]->GetPos(mEnemyXPos, mEnemyYPos);
			mNewDistance = sqrt((mEnemyXPos - XPos(false)) + (mEnemyYPos - YPos(false)));
				if (mCurrentDistance > mNewDistance) {
					mCurrentDistance = mNewDistance;
					mCurrentTarget = mEnemy[i];
				}
		}
	}


	if (mCurrentDistance <= mRange) {
		mCurrentTarget = mCurrentTarget;
	}

	else {
		mCurrentTarget = NULL;
	}
}

void TowerEntity::Shoot() {


}

int TowerEntity::GetCost(TYPE type) {
	switch (type){
	case canon:
		return 250;
		break;
	case rocket:
		return 500;
		break;
	}
}

// if to check for upgrade

// update towers
void TowerEntity::Update(){

	//if (//check timer) {
	//	if (mCurrentTarget != NULL) {
	//		Shoot();
	//	}

	//}	
}

// render towers
void TowerEntity::Render() {
	mTower->Render();
}

