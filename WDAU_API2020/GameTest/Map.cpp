//-------------------------------------------------------------------
// Map.cpp
// Singleton
// Creates a single map instance as a 2D grid with path
//-------------------------------------------------------------------
#include "stdafx.h"
#include "Map.h"
//-------------------------------------------------------------------
// Map - Singleton
//-------------------------------------------------------------------
Map* Map::sInstance = NULL;

Map* Map::Instance() {
	if (sInstance == NULL) {
		sInstance = new Map();
	}

	return sInstance;
}

Map::Map() {

	GeneratePath();

	int halfTileSize = TILESIZE * 0.5;

	for (int i = 0; i < mPath.size()-1; i++) {
		mTiles[mPath[i].first][mPath[i].second] = new Tile(Tile::TILETYPE::path, ".\\TestData\\pathTile.bmp", 1, 1, GetTileXPos(mPath[i].second), GetTileYPos(mPath[i].first));
		mTiles[mPath[i].first][mPath[i].second]->Parent(this);
	}

	// set last tile to base sprite

	mTiles[mPath[mPath.size() - 1].first][mPath[mPath.size() - 1].second] = new Tile(Tile::TILETYPE::path, ".\\TestData\\base.bmp", 1, 1, GetTileXPos(mPath[mPath.size() - 1].second), GetTileYPos(mPath[mPath.size() - 1].first));
	mTiles[mPath[mPath.size() - 1].first][mPath[mPath.size() - 1].second]->Parent(this);

	// create map grid with tiles
	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_HEIGHT; j++) {
			if (mTiles[i][j] == NULL) {
				mTiles[i][j] = new Tile(Tile::TILETYPE::empty, ".\\TestData\\emptyTile.bmp", 1, 1, GetTileXPos(j), GetTileYPos(i));
				mTiles[i][j]->Parent(this);
			}
		}
	}

	// position map at center of the screen
	XPos(APP_INIT_WINDOW_WIDTH * 0.4f);
	YPos(APP_INIT_WINDOW_HEIGHT * 0.5f);

	CreateTower(8, 9);

}

Map::~Map() {

	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_HEIGHT; j++) {
			delete mTiles[i][j];
			mTiles[i][j] = NULL;
		}
	}

}

// create custom path
void Map::GeneratePath() {

	for (int i = 0; i < 6; i++) {
		mPath.push_back(std::make_pair(i, 0));
	}


	for (int i = 1; i < 5; i++) {
		mPath.push_back(std::make_pair(5, i));
	}



	for (int i = 6; i < 13; i++) {
		mPath.push_back(std::make_pair(i, 4));
	}



	for (int i = 5; i < 9; i++) {
		mPath.push_back(std::make_pair(12, i));
	}



	for (int i = 12; i > 1; i--) {
		mPath.push_back(std::make_pair(i, 8));
	}

	for (int i = 8; i < 12; i++) {
		mPath.push_back(std::make_pair(2, i));
	}

	for (int i = 2; i < 12; i++) {
		mPath.push_back(std::make_pair(i, 11));
	}

	for (int i = 11; i < 15; i++) {
		mPath.push_back(std::make_pair(11, i));
	}

}


//void Map::GeneratePath(){
//
//	// set start point as a random grid point from top row
//	mStart = mTopTiles[rand1;
//	// set end point as a random grid point from bottom row
//	mEnd = rand2;
//
//	mCurrentTile = mStart;
//
//	for (int i = 0; i < MAP_HEIGHT - 1; i++) {
//		mPath.push_back(mTiles[0][0]);
//	}
//


	//while (mCurrentTile->XPos() != mEnd->XPos()) {
	//	// move left
	//	if (mCurrentTile->XPos() > mEnd->XPos()) {
	//		mPath.push_back(mCurrentTile);
	//		mCurrentTile = std::find(mTiles, length(mTiles), mCurrentTile);
	//	}
	//	//move right
	//	else if (mCurrentTile->XPos() < mEnd->XPos()) {
	//		mPath.push_back(mCurrentTile);
	//		mCurrentTile = mTiles[0];
	//	}

	//	else {
	//		break;
	//	}
	//	
	//}

	//while (mCurrentTile->YPos() != mEnd->YPos()) {
	//	// move down
	//	if (mCurrentTile->YPos() > mEnd->YPos()) {
	//		mPath.push_back(mCurrentTile);
	//		mCurrentTile = mTiles[0];
	//	}

	//	else {
	//		break;
	//	}

	//}

	//mPath.pushback(mEnd);
//}
void Map::Release() {
	delete sInstance;
	sInstance = NULL;
}

float Map::GetTileXPos(int column){
	int halfTileSize = TILESIZE * 0.5;
	return -(MAP_HEIGHT * halfTileSize - halfTileSize) + column * TILESIZE;
}


float Map::GetTileYPos(int row) {
	int halfTileSize = TILESIZE * 0.5;
	return -(MAP_WIDTH * halfTileSize - halfTileSize) + row * TILESIZE;
}

float Map::GetTileColumn(float x) {
	int halfTileSize = TILESIZE * 0.5;
	return (x + (MAP_WIDTH * halfTileSize)) / TILESIZE;
}

float Map::GetTileRow(float y) {
	int halfTileSize = TILESIZE * 0.5;
	return (y + (MAP_WIDTH * halfTileSize - halfTileSize)) / TILESIZE;
}


std::pair <int,int> Map::GetPathStart() {

	return mPath[0];
}

std::pair <int, int> Map::GetPathEnd() {

	return mPath[mPath.size() - 1];
}

std::pair <int, int> Map::GetPathIndex(int i) {

	return mPath[i];
}

int Map::GetPathSize() {

	return mPath.size();
}

void Map::ConvertMouseToTile(float &x, float& y) {
	x = x - XPos(false);
	y = y - YPos(false);
	int row = GetTileRow(y);
	int col = GetTileColumn(x);
	x = GetTileXPos(col);
	y = GetTileYPos(row);
}

void Map::CreateTower(float x, float y) {
	x = x - XPos(false);
	y = y - YPos(false);
	int row = GetTileRow(y);
	int col = GetTileColumn(x);
	if (row >= 0 && col >=0 && row < MAP_HEIGHT && col < MAP_WIDTH) {
		delete mTiles[row][col];
		mTiles[row][col] = new Tile(Tile::TILETYPE::tower, ".\\TestData\\towerBase.bmp", 1, 1, GetTileXPos(col), GetTileYPos(row));
		mTiles[row][col]->Parent(this);
	}

}

void Map::DestroyTower(float x, float y) {
	x = x - XPos(false);
	y = y - YPos(false);
	int row = GetTileRow(y);
	int col = GetTileColumn(x);
	if (row >= 0 && col >= 0 && row < MAP_HEIGHT && col < MAP_WIDTH) {
		delete mTiles[row][col];
		mTiles[row][col] = new Tile(Tile::TILETYPE::empty, ".\\TestData\\towerDefense_tile162.bmp", 1, 1, GetTileXPos(col), GetTileYPos(row));
		mTiles[row][col]->Parent(this);
	}

}

void Map::Update(){}

void Map::Render() {
	for (int i = 0; i < MAP_WIDTH; i++) {
		for (int j = 0; j < MAP_HEIGHT; j++) {
			mTiles[i][j]->Render();
		}
	}
}