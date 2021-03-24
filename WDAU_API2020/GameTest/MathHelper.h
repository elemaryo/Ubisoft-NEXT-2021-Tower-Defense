//-------------------------------------------------------------------
// MathHelper.h
// Used to do vector math and trig calculations
//-------------------------------------------------------------------
#ifndef _MATHHELPER_H
#define _MATHHELPER_H
//-------------------------------------------------------------------
#include <math.h>
//-------------------------------------------------------------------
// MathHelper namespace: Contains some math helper functions
//-------------------------------------------------------------------
namespace MathHelper {
	//---------------------------------------------------------------
	// Rotates the given point around the origin
	//---------------------------------------------------------------
	void RotatePoint(float& x, float& y, float angle);
	//---------------------------------------------------------------
	// Clamps the given value between min and max
	//---------------------------------------------------------------
	float Clamp(float value, float min, float max);
	//---------------------------------------------------------------
	// returns the square of the magnitide of the given vector
	//---------------------------------------------------------------
	float MagnitudeSqu(float x, float y);
	//---------------------------------------------------------------
	// Turns the given vector described by x and y into a directional vector
	// stored in normalizedX and normalizedY
	//---------------------------------------------------------------
	void Normalize(float x, float y, float& normalizedX, float& normalizedY);
	//---------------------------------------------------------------
	// Checks if the two given line segments intersect
	//---------------------------------------------------------------
	bool LineSegIntersection(float sx1, float sy1, float ex1, float ey1, float sx2, float sy2, float ex2, float ey2);
}

#endif