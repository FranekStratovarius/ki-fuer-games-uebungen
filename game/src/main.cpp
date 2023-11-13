#include "option.hpp"
#include "raylib.h"
#include "raymath.h"

#include "npc.hpp"
#include "option/option_text_output.hpp"

int main(void) {
	const int screen_width = 800;
	const int screen_height = 450;

	InitWindow(screen_width, screen_height, "uebung 001");

	Camera camera = { 0 };
	camera.position = (Vector3){ 20.0f, 10.0f, 0.0f };
	camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
	camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
	camera.fovy = 45.0f;
	camera.projection = CAMERA_PERSPECTIVE;

	SetTargetFPS(60);

	int number_of_npcs = 10;
	Npc npcs[number_of_npcs];

	OptionTextOutput option = OptionTextOutput(
		"Hallo, hier kommt dann text raus."
	);
	option.start();

	while (!WindowShouldClose()) {
		float delta_time = GetFrameTime();

		option.update(delta_time);

		float rotation = 0.0f;
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			rotation = GetMouseDelta().x * -0.01f;
		}
		camera.position = Vector3RotateByAxisAngle(camera.position, (Vector3) {0.0f, 1.0f, 0.0f}, rotation);

		BeginDrawing();
			ClearBackground(BLACK);

			BeginMode3D(camera);

				DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f }, (Vector2){ 20.0f, 20.0f }, RAYWHITE);

				for (int i = 0; i < number_of_npcs; i++) {
					npcs[i].draw();
				}

			EndMode3D();

			// DrawText(TextFormat("mouse delta: %f", rotation), 10, 10, 20, RED);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}