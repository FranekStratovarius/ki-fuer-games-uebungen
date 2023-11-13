#include "raylib.h"
#include "raygui.h"

#include "random.hpp"
#include "octave.hpp"
#include "perlin_noise.hpp"

int main(void) {
	const int screen_width = 800;
	const int screen_height = 450;

	InitWindow(screen_width, screen_height, "uebung 002_1");

	int dynamic_screen_width = screen_width;
	int dynamic_screen_height = screen_height;

	SetTargetFPS(60);

	// Random random = Random();
	// Octave octave = Octave(1);
	PerlinNoise1D perlin_noise = PerlinNoise1D(5, 0.5);
	PerlinNoise1D continuous_perlin_noise = PerlinNoise1D(5, 0.5);

	while (!WindowShouldClose()) {
		dynamic_screen_width = GetScreenWidth();
		dynamic_screen_height = GetScreenHeight();
		if (IsKeyPressed(KEY_R)) {
			
		}
		BeginDrawing();
			ClearBackground(RAYWHITE);

			DrawText("0",
				dynamic_screen_width * 0.1 - 15, dynamic_screen_height * 0.9 - 10,
				20, BLACK
			);
			// bottom line
			DrawLine(
				dynamic_screen_width * 0.1, dynamic_screen_height * 0.9,
				dynamic_screen_width * 0.9, dynamic_screen_height * 0.9,
				BLACK
			);

			DrawText("0.5",
				dynamic_screen_width * 0.1 - 35, dynamic_screen_height * 0.5 - 10,
				20, BLACK
			);
			// middle line
			DrawLine(
				dynamic_screen_width * 0.1, dynamic_screen_height * 0.5,
				dynamic_screen_width * 0.9, dynamic_screen_height * 0.5,
				BLACK
			);

			DrawText("1",
				dynamic_screen_width * 0.1 - 10, dynamic_screen_height * 0.1 - 10,
				20, BLACK
			);
			// top line
			DrawLine(
				dynamic_screen_width * 0.1, dynamic_screen_height * 0.1,
				dynamic_screen_width * 0.9, dynamic_screen_height * 0.1,
				BLACK
			);

			for (int x = 0; x < dynamic_screen_width * 0.8; x++) {
				/*
				float y = random.random_normal_distribution_float(
					dynamic_screen_height * 0.1,
					dynamic_screen_height * 0.9,
					dynamic_screen_height * 0.5f,
					dynamic_screen_height * 0.1f
				);
				//*/
				// float y = octave.get(x / (dynamic_screen_width * 0.8));
				float y = perlin_noise.get(x / (dynamic_screen_width * 0.8));
				DrawCircle(
					dynamic_screen_width * 0.1 + x,
					dynamic_screen_height * 0.9 - dynamic_screen_height * 0.8 * y,
					3.0f,
					BLUE
				);
			}

			DrawCircle(
				dynamic_screen_width * 0.9,
				dynamic_screen_height * 0.9
					- dynamic_screen_height * 0.8
					// * continuous_perlin_noise.update(0.01),
					* continuous_perlin_noise.update(GetFrameTime()),
				3.0f,
				RED
			);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}