//-------------------------------------------------------------------
// GameEntity.h
// Works as the base class for all game entities, providing variables for position and rotation.
// 
// As well as a system to set one GameEntity as a parent of another,
// making the child's position and rotation relative to the parent's instead of the origin
//-------------------------------------------------------------------
#ifndef _GAMEENTITY_H
#define _GAMEENTITY_H
//-------------------------------------------------------------------
#include <vector>
//-------------------------------------------------------------------
#include "app\app.h"
//-------------------------------------------------------------------
// GameEntity
//-------------------------------------------------------------------
class GameEntity {

public:

	//---------------------------------------------------------------------
	// Line structs consist of sx(start x) sy(start y) ex(end x) ey(end y) describing a line
	//---------------------------------------------------------------------
	struct Line {

		float sx = 0.0f;
		float sy = 0.0f;
		float ex = 0.0f;
		float ey = 0.0f;

		Line(float _sx = 0.0f, float _sy = 0.0f, float _ex = 0.0f, float _ey = 0.0f)
			: sx(_sx), sy(_sy), ex(_ex), ey(_ey) {}
	};

private:
	//----------------------------------------------------------------------
	// Position and rotation variables are set to private to make sure the setter 
	// functions are used in derived classes instead, to take advantage of the parent/child system
	//----------------------------------------------------------------------
	float m_xPos;
	float m_yPos;
	float m_rotationAngle;

	bool m_dead;
	//---------------------------------------------------------
	//Set to true if the object is to be updated and rendered  
	//---------------------------------------------------------
	bool mActive;
	GameEntity *m_parent;

protected:

	bool m_readyForDeletion;
	std::vector<Line> m_collisionLines;

protected:

	void RotationAngle(float angle);
	//-------------------------------------------------------------------------------
	// Wraps the GameEntity back around the window if they go over the edges. 
	// e.g. if the object goes off the edge on the right, they appear from the left of the screen
	//-------------------------------------------------------------------------------
	void BoundaryCheck();
	//-------------------------------------------------------------------------------
	// To be called to updates the collision lines of the GameEntity when the Entity is moved or rotated
	//-------------------------------------------------------------------------------
	virtual void UpdateColliders();
	//-------------------------------------------------------------------------------
	// Called when the entity dies, is called by the Die function my default
	//-------------------------------------------------------------------------------
	virtual void PlayDeathAnimation();

public:

	GameEntity(float x = 0.0f, float y = 0.0f);
	~GameEntity();

	void XPos(float x);
	void YPos(float y);

	virtual void Update();
	virtual void Render();

	//--------------------------------------------------------------------------------
	// Returns the x position of the entity, 
	// if local = true and the entity has a parent, then the local x is relative to the parent, otherwise it is relative to the origin
	// if local = false then the world x position is returned taking into account the parent's x
	//--------------------------------------------------------------------------------
	float XPos(bool local);
	//--------------------------------------------------------------------------------
	// Returns the x position of the entity, 
	// if local = true and the entity has a parent, then the local y is relative to the parent, otherwise it is relative to the origin
	// if local = false then the world y position is returned taking into account the parent's y
	//--------------------------------------------------------------------------------
	float YPos(bool local);
	//--------------------------------------------------------------------------------
	// Returns the rotation of the entity, 
	// if local = true and the entity has a parent, then the rotation is relative to the parent, otherwise it is relative to the origin
	// if local = false then the entity's total rotation is returned
	//--------------------------------------------------------------------------------
	float RotationAngle(bool local);

	//--------------------------------------------------------------------------------------------------------------------------
	//Sets the parent of the GameEnity as the given GameEntity                                                                  
	//If the GameEntity has no parent, the given GameEntity is set as its parent                                                
	//If the GameEntity has a parent, the given game entity is set as the new parent,                                           
	//       and the lcoal Position/Rotation/Scale are changed to be relative to the new parent (world values are unchanged)    
	//If NULL is passed in, the GameEntity is considered without a parent,                                                      
	//       and all values are set to be relative to the origin (world values are unchanged)                                   
	//--------------------------------------------------------------------------------------------------------------------------
	void Parent(GameEntity* parent);

	//-----------------------------------------------
	//Returns the Current parent of the GameEntity,  
	//Returns NULL if the GameEntity has no parent   
	//-----------------------------------------------
	GameEntity *Parent();

	//--------------------------------------------
	//Sets the active state of the GameEntity     
	//--------------------------------------------
	void Active(bool active);
	//--------------------------------------------
	//Returns the active state of the GameEntity  
	//--------------------------------------------
	bool Active();

	void Die();
	bool IsDead();
	bool ReadyForDeletion();

	std::vector<Line>* CollisionLines();

	//---------------------------------------------------------------------
	// Checks if any of the Entity's collision lines intersect with the line passed in and returns the result
	//---------------------------------------------------------------------
	bool LineCollision(Line& line);
};

#endif // !_GAME_ENTITY_H
