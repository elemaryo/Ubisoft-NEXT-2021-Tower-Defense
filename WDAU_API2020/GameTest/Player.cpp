//-------------------------------------------------------------------
// Player.cpp
// The class describing all player stats
// Derived from GameEntity
//-------------------------------------------------------------------
#include "stdafx.h"
#include "Player.h"
//-------------------------------------------------------------------
// Player
//-------------------------------------------------------------------
Player::Player() {

	mCurrency = 1000;
	mHealth = 500;

}

Player::~Player() {


}

int Player::Health() {
	return mHealth;
}

int Player::Currency() {
	return mCurrency;
}

void Player::SetHealth(int change) {
	mHealth += change;
}

void Player::SetCurrency(int change) {
	mCurrency += change;
}

void Player::Update(){}

void Player::Render(){}