////-------------------------------------------------------------------
//// BulletEntity.h
//// Describes the behaviour of all the bullets used
//// Derived from GameEntity
////-------------------------------------------------------------------
//#ifndef _BULLET_H
//#define _BULLET_H
////-------------------------------------------------------------------
//
//class Bullet : public GameEntity {
//
//private:
//	// bullet needs to disappear if its 10 pixels off screen
//	const int OFFSCREEN_BUFFER = 10;
//
//	float mxVel;
//	float myVel;
//	
//	float mSpeed;
//
//	SpriteEntity* mTexture;
//
//
//public:
//	//----------------------------------------------------------------------------------------
//	// Constructor / x - local x pos / y - local y pos / xDir - x travel direction / yDir - y travel direction / fileName - Bullet Texture
//	//----------------------------------------------------------------------------------------
//	Bullet(float x, float y, float xDir, float yDir, char* fileName);
//	~Bullet();
//
//	void UpdateColliders();
//
//	void Update();
//	void Render();
//};
//
//#endif // !_BULLET_H
