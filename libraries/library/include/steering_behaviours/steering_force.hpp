#ifndef STEERING_FORCE_HPP
#define STEERING_FORCE_HPP

#include "raylib.h"
#include "raymath.h"

class SteeringForce {
	public:
		SteeringForce(Vector2 movementForce, float rotationForce);
		SteeringForce();

		SteeringForce operator+=(const SteeringForce& rhs);
		// SteeringForce operator*(const SteeringForce& rhs);
		SteeringForce operator+(const SteeringForce& rhs);

		Vector2 movementForce;
		float rotationForce;
	private:
};

#endif // STEERING_FORCE_HPP