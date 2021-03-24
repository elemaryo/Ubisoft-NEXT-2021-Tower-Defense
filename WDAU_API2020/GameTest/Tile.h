//-------------------------------------------------------------------
// Tile.h
// Describes each tile object with type 
// Derived from SpriteEntity
//-------------------------------------------------------------------
#ifndef _TILE_H
#define _TILE_H
//-------------------------------------------------------------------
#include "SpriteEntity.h"
//-------------------------------------------------------------------
// Tile
//------------------------------------------------------------------
class Tile : public SpriteEntity {

public:
	//---------------------------------------------------------------------
	// Set Tile Types
	//---------------------------------------------------------------------
	enum TILETYPE { empty, tower, path };

private:
	TILETYPE mCurrentTileType;

public:
	// constructor
	Tile(TILETYPE tile, char* filename, int rows, int columns, float x, float y) : SpriteEntity(filename, rows, columns, x, y) {
		mCurrentTileType = tile;
	}
	// destructor
	~Tile(){}
	//---------------------------------------------------------------------
	// Getter for Tile Types
	//---------------------------------------------------------------------
	TILETYPE GetTileType() {
		return mCurrentTileType;
	}
};

#endif // !_TILE_H