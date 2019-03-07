#pragma once
#include "Vec3.h"
#include "Graphics.h"

class ScreenSpaceTransformer {

public:
	ScreenSpaceTransformer() : xFactor(float(Graphics::ScreenWidth / 2.0f)), yFactor(float(Graphics::ScreenHeight / 2.0f)){}
	Vec3& Transform(Vec3& vector) {
		vector.x = (vector.x + 1.0f) * xFactor;
		vector.y = (-vector.y + 1.0f) * yFactor;

		return vector;
	}

private:
	float xFactor;
	float yFactor;

};