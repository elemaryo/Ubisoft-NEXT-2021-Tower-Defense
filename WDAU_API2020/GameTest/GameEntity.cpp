//-------------------------------------------------------------------
// GameEntity.cpp
// Works as the base class for all game entities, providing variables for position and rotation.
// 
// As well as a system to set one GameEntity as a parent of another,
// making the child's position and rotation relative to the parent's instead of the origin
//-------------------------------------------------------------------
#include "stdafx.h"
//-------------------------------------------------------------------
#include "GameEntity.h"
#include "MathHelper.h"
//-------------------------------------------------------------------

GameEntity::GameEntity(float x, float y) {

	m_xPos = x;
	m_yPos = y;
	m_rotationAngle = 0.0f;
	m_parent = NULL;
	m_dead = false;
	m_readyForDeletion = false;
}

GameEntity::~GameEntity() {
	m_parent = NULL;
}

void GameEntity::XPos(float x) {
	m_xPos = x;
}

void GameEntity::YPos(float y) {
	m_yPos = y;
}

void GameEntity::RotationAngle(float angle) {

	// Wraps the angle between 0 and 360 degrees, addition and subtraction are used to avoid snapping
	if (angle > 360.0f)
		angle -= 360.0f;
	else if (angle < 0.0f)
		angle += 360.0f;

	m_rotationAngle = angle;
}

void GameEntity::BoundaryCheck() {

	// Checks of the entity left the screen from the top or bottom, if so it is wrapped around
	if(YPos(true) < 0.0f)
		YPos((float)APP_VIRTUAL_HEIGHT);
	else if(YPos(true) > APP_VIRTUAL_HEIGHT)
		YPos(0.0f);

	// Checks of the entity left the screen from the left or right, if so it is wrapped around
	if(XPos(true) < 0.0f)
		XPos((float)APP_VIRTUAL_WIDTH);
	else if(XPos(true) > APP_VIRTUAL_WIDTH)
		XPos(0.0f);
}

//-------------------------------------------------------------------------------
// Since colliders will differ between entities, this function will be overridden in derived classes
//-------------------------------------------------------------------------------
void GameEntity::UpdateColliders() {}

float GameEntity::XPos(bool local) {

	if (local)
		return m_xPos;

	//if the entity has a parent, use the parent's x position to calculate the entity's world x position
	if(m_parent != NULL)
		return m_parent->XPos(false) + m_xPos;
	else
		return m_xPos;
}

void GameEntity::PlayDeathAnimation() {

	m_readyForDeletion = true;
}

float GameEntity::YPos(bool local) {

	if (local)
		return m_yPos;

	//if the entity has a parent, use the parent's y position to calculate the entity's world y position
	if(m_parent != NULL)
		return m_parent->YPos(false) + m_yPos;
	else
		return m_yPos;
}

float GameEntity::RotationAngle(bool local) {

	if(local)
		return m_rotationAngle;

	//if the entity has a parent, use the parent's rotation to calculate the entity's total rotation
	if(m_parent != NULL)
		return m_parent->RotationAngle(false) + m_rotationAngle;
	else
		return m_rotationAngle;
}

void GameEntity::Parent(GameEntity* parent) {

	m_parent = parent;
}

GameEntity* GameEntity::Parent() {

	return m_parent;
}

void GameEntity::Active(bool active) {

	mActive = active;
}

bool GameEntity::Active() {

	return mActive;
}

void GameEntity::Die() {

	m_dead = true;
	PlayDeathAnimation();
}

bool GameEntity::IsDead() {

	return m_dead;
}

bool GameEntity::ReadyForDeletion() {

	return m_readyForDeletion;
}

std::vector<GameEntity::Line>* GameEntity::CollisionLines() {

	return &m_collisionLines;
}

bool GameEntity::LineCollision(Line& line) {

	// Checks if any of the collision lines intersect with the given line
	for(int i = 0; i < m_collisionLines.size(); i++) {
		if(MathHelper::LineSegIntersection(line.sx, line.sy, line.ex, line.ey, m_collisionLines[i].sx, m_collisionLines[i].sy, m_collisionLines[i].ex, m_collisionLines[i].ey))
			return true;
	}

	return false;
}

void GameEntity::Update() {


}

void GameEntity::Render() {


}