//-------------------------------------------------------------------
// SpriteEntity.h
// Creates sprites for game entities
// Derived from GameEntity
//-------------------------------------------------------------------
#ifndef _SPRITEENTITY_H
#define _SPRITEENTITY_H
//-------------------------------------------------------------------
#include "App/SimpleSprite.h"
#include "GameEntity.h"
//-------------------------------------------------------------------
// SpriteEntity
//------------------------------------------------------------------
class SpriteEntity : public GameEntity {

private:
	int mRows;
	int mColumns;
	char* mfileName;
	CSimpleSprite* mSprite;

public:
	SpriteEntity(char *filename, int rows, int columns, float x, float y);
	~SpriteEntity();

public:
	//---------------------------------------------------------------------
	// Sprite properties setters
	//---------------------------------------------------------------------
	void SetScale(float scale);
	void SetAngle(float angle);
	float GetAngle();

	void Update();
	void Render();

};

#endif // !_SPRITEENTITY_H

