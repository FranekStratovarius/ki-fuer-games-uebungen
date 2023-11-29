#include "blackboard.hpp"
#include "math.hpp"
#include "option.hpp"
#include "raylib.h"
#include "raymath.h"

#include "world.hpp"
#include "player.hpp"
#include "option/option_text_output.hpp"
#include <algorithm>
#include <cmath>
#include <math.h>

int main(void) {
	const int screen_width = 800;
	const int screen_height = 450;

	InitWindow(screen_width, screen_height, "uebung 001");

	Camera camera = { {0} };
	camera.position = (Vector3){ 20.0f, 10.0f, 0.0f };
	camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
	camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
	camera.fovy = 45.0f;
	camera.projection = CAMERA_PERSPECTIVE;

	SetTargetFPS(60);

	World world = World(20);
	Player player = Player();
	Blackboard *sharedBlackboard = world.getSharedBlackboard();

	// OptionTextOutput option = OptionTextOutput(
	// 	"Hallo, hier kommt dann text raus."
	// );
	// option.start();

	float rotation_x = 0.0f;
	float rotation_y = 0.0f;
	float cameraDistance = 1.0f;

	while (!WindowShouldClose()) {
		float delta_time = GetFrameTime();

		world.update(delta_time);
		// option.update(delta_time);

		float deltaRotation_x = 0.0f;
		float deltaRotation_y = 0.0f;
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			deltaRotation_x = GetMouseDelta().x * -0.01f;
			deltaRotation_y = GetMouseDelta().y * 0.01f;
		}
		rotation_x += deltaRotation_x;
		rotation_y += deltaRotation_y;
		cameraDistance -= GetMouseWheelMove() * 0.1f;
		Vector3 cameraPosition = Vector3RotateByAxisAngle((Vector3){ 20.0f, 10.0f, 0.0f }, (Vector3) {0.0f, 0.0f, 1.0f}, rotation_y);
		cameraPosition = Vector3RotateByAxisAngle(cameraPosition, (Vector3) {0.0f, 1.0f, 0.0f}, rotation_x);
		camera.position = Vector3Scale(
			cameraPosition,
			cameraDistance
		);

		float dir_x = 0.0f;
		float dir_y = 0.0f;
		if (IsKeyDown(KEY_S)) {
			dir_x++;
		}
		if (IsKeyDown(KEY_W)) {
			dir_x--;
		}
		if (IsKeyDown(KEY_A)) {
			dir_y++;
		}
		if (IsKeyDown(KEY_D)) {
			dir_y--;
		}
		player.update(Vector2Rotate(Vector2{dir_x, dir_y}, -rotation_x), delta_time, sharedBlackboard);
		// player.update(Vector2{dir_x, dir_y}, delta_time);

		BeginDrawing();
			ClearBackground(BLACK);

			BeginMode3D(camera);

				DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f }, (Vector2){ 80.0f, 80.0f }, RAYWHITE);

				world.draw();

				player.draw();

			EndMode3D();
		EndDrawing();
	}

	CloseWindow();

	return 0;
}