#include "math.hpp"

Vector2 limit(Vector2 value, float maxValue) {
	float forceLength = Vector2Length(value);
	if (forceLength > maxValue) {
		return Vector2Scale(value, maxValue / forceLength);
	}
	return value;
}

Vector2 limit(Vector2 value, float minValue, float maxValue) {
	float vectorLength = Vector2Length(value);
	if (vectorLength > maxValue) {
		return Vector2Scale(value, maxValue / vectorLength);
	} else if (vectorLength < minValue) {
		return Vector2Scale(value, minValue / vectorLength);
	}
	return value;
}

float limit(float value, float maxValue) {
	return limit(value, -maxValue, maxValue);
}

float limit(float value, float minValue, float maxValue) {
	if (value > maxValue) {
		return maxValue;
	} else if (value < minValue) {
		return minValue;
	}
	return value;
}

float degreesToRadians(float degree) {
	return degree * M_PI / 180.0f;
}