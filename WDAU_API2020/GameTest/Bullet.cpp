#include "stdafx.h"
//#include "Bullet.h"
//
//Bullet::Bullet(char* fileName) {
//
//	mSpeed = 20.0f;
//	mxVel = xDir * mSpeed;
//	myVel = yDir * mSpeed;
//
//	mTexture = new SpriteEntity(fileName, 1, 1, );
//	mTexture->Parent(this);
//
//	// reuse bullet object instead of creating a new object every time
//	Reload();
//}
//
//Bullet::~Bullet() {
//
//	delete mTexture;
//	mTexture = NULL;
//}
//
//void Bullet::Reload() {
//	Active(false);
//}
//
//void Bullet::Update() {
////	if (Active()) {
////		// move bullet up on the screen
////		Translate(-VEC2_UP * mSpeed * mTimer->DeltaTime(), local);
////
////		Vector2 pos = Pos();
////
////		// check bounds
////		if (pos.y < -OFFSCREEN_BUFFER || pos.y > Graphics::Instance()->SCREEN_HEIGHT + OFFSCREEN_BUFFER) {
////
////			Reload();
////		}
////	}
////}
//
//void Bullet::Render() {
//
//	if (Active()) {
//		mTexture->Render();
//	}
//}