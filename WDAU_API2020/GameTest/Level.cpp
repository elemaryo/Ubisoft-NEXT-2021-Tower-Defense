//-------------------------------------------------------------------
// Level.h
// The class manages all aspects of the level entity
// Derived from GameEntity
//-------------------------------------------------------------------
#include "stdafx.h"
#include "Level.h"
#include "MathHelper.h"
#include "CanonTower.h"
#include "RocketTower.h"
//-------------------------------------------------------------------

Level::Level(int stage, PlaySideBar* sideBar, Player* player){

	mSideBar = sideBar;
	mPlayer = player;
	mMap = Map::Instance();

	mTimer = Timer::Instance();
	mEnemyDeployDelay = 2.0f;
	mEnemySpawnTimer = 0.0f;

	mStage = stage;

	mTowerType = TowerEntity::TYPE::unknown;

	SpawnEnemy();


}

Level::~Level(){
	//mSideBar = NULL;
	mMap = NULL;
	mPlayer = NULL;

	for (int i = 0; i < mEnemy.size(); i++) {
		delete mEnemy[i];
		mEnemy[i] = NULL;
	}

}

Level::LEVEL_STATES Level::State(){
	return running;
}

void Level::SpawnEnemy() {
		mEnemy.push_back(new Enemy(mMap->GetTileXPos(mMap->GetPathStart().second), mMap->GetTileYPos(mMap->GetPathStart().first)));
		int index = mEnemy.size() - 1;
		
		mEnemy[index]->Parent(mMap);
		mEnemy[index]->XPos(0.0f);
		mEnemy[index]->YPos(0.0f);
}

void Level::SpawnTower(TowerEntity::TYPE type, float x, float y) {

	mMap->CreateTower(x, y);
	mMap->ConvertMouseToTile(x, y);
	//switch (type) {
	//	case canon:
	//		mTowers.push_back(new CanonTower(x, y));
	//		break;
	//	case rocket:
	//		mTowers.push_back(new RocketTower(x, y));
	//		break;
	//}
	mTowers.push_back(new CanonTower(x, y));
	mTowers[mTowers.size() - 1]->Parent(mMap);
	mTowers[mTowers.size() - 1]->XPos(x);
	mTowers[mTowers.size() - 1]->YPos(y);
}

void Level::Update(){

	if (mEnemy.size() < MAX_NUMBER_OF_ENEMIES) {

	mEnemySpawnTimer += mTimer->DeltaTime();

		if (mEnemySpawnTimer >= mEnemyDeployDelay) {
			SpawnEnemy();
			mEnemySpawnTimer = 0.0f;
		}
	}

	for (int i = 0; i < mEnemy.size(); i++) {
		mEnemy[i]->Update();
		int pathIndex = MathHelper::Clamp(mEnemy[i]->GetPathIndex(), 0, mMap->GetPathSize() - 1);
		mEnemy[i]->SetPos(mMap->GetTileXPos(mMap->GetPathIndex(pathIndex).second), mMap->GetTileYPos(mMap->GetPathIndex(pathIndex).first));
		//if (mEnemy[i]->GetDirection() == mEnemy::DIRECTION::right) {
		//	mEnemy[i]->SetAngle(90);
		//}
	}

	for (int i = 0; i < mTowers.size(); i++) {
		mTowers[i]->FindNearestEnemy(mEnemy);
	}

	if (App::IsKeyPressed(VK_LBUTTON)) {

		//if (mMap->GetTileRow(xMouse)
		float xMouse;
		float yMouse;
		App::GetMousePos(xMouse, yMouse);
		//set mTowerType?
		SpawnTower(mSideBar->GetSelectedTower(), xMouse, yMouse);
	}

	// controls to destroy towers
	//if (App::IsKeyPressed(VK_RBUTTON)) {
	//	float xMouse;
	//	float yMouse;
	//	App::GetMousePos(xMouse, yMouse);
	//	mMap->CreateTower(xMouse, yMouse);
	//	mMap->ConvertMouseToTile(xMouse, yMouse);
	//	mTowers.push_back(new CanonTower(xMouse, yMouse));
	//	mTowers[mTowers.size() - 1]->Parent(mMap);
	//	mTowers[mTowers.size() - 1]->XPos(xMouse);
	//	mTowers[mTowers.size() - 1]->YPos(yMouse);
	//	/*PlaceTower(xMouse, yMouse);*/
	//}

	// check enemy position to rotate

}

void Level::Render() {

	// if mStageStarted condition
	mMap->Render();

	// mEnemy respawn delay

	// render enemies
	for (int i = 0; i < mEnemy.size(); i++) {
		mEnemy[i]->Render();
	}

	// render towers
	for (int i = 0; i < mTowers.size(); i++) {
		mTowers[i]->Render();
	}
};
