//-------------------------------------------------------------------
// Map.h
// Singleton
// The class describing map layout along with path for enemies
// Derived from GameEntity
//-------------------------------------------------------------------
#ifndef _MAP_H

#define _MAP_H

#include "App/TextureLoader.h"

#include "SpriteEntity.h"

#include "GameEntity.h"

#include "TowerEntity.h"

#include "Tile.h"
//-------------------------------------------------------------------
// Map - Singleton
//-------------------------------------------------------------------
class Map : public GameEntity {

private:
	static Map* sInstance;

	static const int MAP_WIDTH = 15;
	static const int MAP_HEIGHT = 15;

	static const int TILESIZE = 34;

	// Random numbers for start and end
	int rand1 = rand() % (MAP_WIDTH - 0 + 1) + 0;

	int rand2 = rand() % (MAP_WIDTH - 0 + 1) + 0;

	Tile* mTiles [MAP_WIDTH][MAP_HEIGHT];

	/*std::vector<SpriteEntity*> mPath;*/

	//SpriteEntity* mTopTiles[MAP_WIDTH];
	//SpriteEntity* mBottomTiles[MAP_WIDTH];

	//SpriteEntity* mStart;
	//SpriteEntity* mEnd;
	//SpriteEntity* mCurrentTile;

	//int mStart;
	//int mEnd;
	//int mCurrentTile;


public:
	std::vector<std::pair <int, int>> mPath;


private:
	//------------------------------------------------------------------------------------------
	//Contructor is private so that Instance() must be used to get an instance when needed  
	//------------------------------------------------------------------------------------------
	Map();
	//--------------------------------------------------------------------------------------
	//Destructor is private so that the instance can only be destroyed using Release()  
	//--------------------------------------------------------------------------------------
	~Map();

	void GeneratePath();

public:
	static Map* Instance();

	// returns tile x position
	float GetTileXPos(int column);
	// returns tile y position
	float GetTileYPos(int row);
	// returns tile column
	float GetTileColumn(float x);
	// returns tile row
	float GetTileRow(float y);

	// returns the start point of the path
	std::pair <int, int> GetPathStart();

	// returns the end point of the path
	std::pair <int, int> GetPathEnd();

	// returns the point of the path at specified index
	std::pair <int, int> GetPathIndex(int i);

	// return path size
	int GetPathSize();

	void ConvertMouseToTile(float &x, float &y);

	//void CreateTower(int row, int col);

	void CreateTower(float x, float y);

	void DestroyTower(float x, float y);

	//void DestroyTower(int row, int col);

	void Update();
	void Release();
	void Render();

};

#endif 