#ifndef KINEMATICS_HPP
#define KINEMATICS_HPP

#include "raylib.h"
#include "raymath.h"

// ggf zu struct machen
// class Kinematics {
// 	public:
// 		Kinematics();
// 		Vector2 position;
// 		// rotation im bogenmaß
// 		float orientation;
// 		Vector2 movementVelocity;
// 		// rotation im bogenmaß
// 		float rotationVelocity;

// 		float maxMovementForce;
// 		float maxMovementVelocity;

// 		float maxRotationForce;
// 		float maxRotationVelocity;
// 	private:
// };

typedef struct {
	Vector2 position;
	// rotation im bogenmaß
	float rotation;
	Vector2 movementVelocity;
	// rotation im bogenmaß
	float rotationVelocity;

	float maxMovementForce;
	float maxMovementVelocity;

	float maxRotationForce;
	float maxRotationVelocity;
} Kinematics;

#endif // KINEMATICS_HPP