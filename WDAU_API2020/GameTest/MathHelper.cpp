//-------------------------------------------------------------------
// MathHelper.cpp
// Used to do vector math and trig calculations
//-------------------------------------------------------------------
#include "stdafx.h"
//-------------------------------------------------------------------
#include "MathHelper.h"
//-------------------------------------------------------------------
namespace MathHelper {

	#define PI 3.14159265

	const double DEG_TO_RAD = PI / 180.0f;

	void RotatePoint(float& x, float& y, float angle) {

		float oX = x;
		float oY = y;

		float radAngle = (float)(angle * DEG_TO_RAD);

		x = (float)(oX*cos(radAngle) - oY*sin(radAngle));
		y = (float)(oX*sin(radAngle) + oY*cos(radAngle));
	}

	float Clamp(float value, float min, float max) {
		
		if (value < min)
			return min;

		if (value > max)
			return max;
		
		return value;
	}

	float MagnitudeSqu(float x, float y) {

		return x*x + y*y;
	}

	void Normalize(float x, float y, float& normalizedX, float& normalizedY) {

		float mag = (float)sqrt(MagnitudeSqu(x, y));
		
		// To avoid dividing by 0
		if (mag == 0.0f)
			return;

		normalizedX = x / mag;
		normalizedY = y / mag;
	}

	bool LineSegIntersection(float sx1, float sy1, float ex1, float ey1, float sx2, float sy2, float ex2, float ey2) {

		float lengthSqu1 = MagnitudeSqu(ex1 - sx1, ey1 - sy1);
		float lengthSqu2 = MagnitudeSqu(ex2 - sx2, ey2 - sy2);

		float slope1;
		float slope2;

		float b1;
		float b2;

		float xIntersect;
		float yIntersect;

		// if both lines are vertical or either of the lines is length 0, then no collision
		if((ex1 == sx1 && ex2 == sx2) || lengthSqu1 == 0.0f || lengthSqu2 == 0.0f) {
			return false;
		}

		// if the first line is vertical then the xIntersection has to be on the x point of that line
		if(ex1 == sx1) {

			slope2 = (ey2 - sy2) / (ex2 - sx2);
			b2 = sy2 - slope2 * sx2;

			xIntersect = sx1;
			yIntersect = slope2 * xIntersect + b2;

		} else if(ex2 == sx2) {		// if the second line is vertical then the xIntersection has to be on the x point of that line

			slope1 = (ey1 - sy1) / (ex1 - sx1);
			b1 = sy1 - slope1 * sx1;

			xIntersect = sx2;
			yIntersect = slope1 * xIntersect + b1;

		} else {	// Otherwise use m1x1+b1=m2x2+b2 to slove for the intersection point

			slope1 = (ey1 - sy1) / (ex1 - sx1);
			slope2 = (ey2 - sy2) / (ex2 - sx2);

			if(slope1 == slope2)
				return false;

			b1 = sy1 - slope1 * sx1;
			b2 = sy2 - slope2 * sx2;

			xIntersect = (b2 - b1) / (slope1 - slope2);
			yIntersect = slope1 * xIntersect + b1;
		}

		// if the distance from both points of both lines is less than the magnitude of those lines, then there was a collision
		return (MagnitudeSqu(sx1 - xIntersect, sy1 - yIntersect) < lengthSqu1 && MagnitudeSqu(ex1 - xIntersect, ey1 - yIntersect) < lengthSqu1) && 
			(MagnitudeSqu(sx2 - xIntersect, sy2 - yIntersect) < lengthSqu2 && MagnitudeSqu(ex2 - xIntersect, ey2 - yIntersect) < lengthSqu2);
	}
}