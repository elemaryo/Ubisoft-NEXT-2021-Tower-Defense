//-------------------------------------------------------------------
// SpriteEntity.h
// Creates sprites for game entities
// Derived from GameEntity
//-------------------------------------------------------------------
#include "stdafx.h"
#include "SpriteEntity.h"
//-------------------------------------------------------------------
// SpriteEntity
//------------------------------------------------------------------
SpriteEntity::SpriteEntity(char* filename, int rows, int columns, float x, float y) {
	mColumns = columns;
	mRows = rows;
	mfileName = filename;
	XPos(x);
	YPos(y);
	mSprite = new CSimpleSprite(mfileName, mRows, mColumns);
}

SpriteEntity::~SpriteEntity() {

	delete mSprite;
	mSprite = NULL;
}

// set sprite entity scale
void SpriteEntity::SetScale(float scale) {
	mSprite->SetScale(scale);
}

// set sprite entity angle
void SpriteEntity::SetAngle(float angle) {
	mSprite->SetAngle(angle);
}

float SpriteEntity::GetAngle() {
	return mSprite->GetAngle();
}

// update sprite entity
void SpriteEntity::Update() {
	mSprite->SetPosition(XPos(false), YPos(false));
}

// render sprite entity
void SpriteEntity::Render() {
	mSprite->SetPosition(XPos(false), YPos(false));
	mSprite->Draw();
}