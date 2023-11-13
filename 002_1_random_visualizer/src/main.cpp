#include <cstdlib>

#include "raylib.h"
#include "raygui.h"

#include "random.hpp"

void initialize_random_numbers(int** randoms, int values) {
	*randoms = (int*) calloc(values, sizeof(int));
}

void roll_random_numbers(
	int* randoms,
	int values,
	int random_number_count,
	Random random,
	int active_random_type
) {
	for (int i = 0; i < values; i++) {
		randoms[i] = 0;
	}
	for (int i = 0; i < random_number_count; i++) {
		switch (active_random_type) {
			// INT
			// gleichverteilung
			case 0:
				randoms[random.random_uniform_distribution_int(
					0,
					values
				)]++;
				break;
			// normalverteilung
			case 1:
				randoms[random.random_normal_distribution_int(
					0,
					values
				)]++;
				break;
			// FLOAT
			// gleichverteilung
			case 2: {
				float random_number = random.random_uniform_distribution_float(
					0,
					values
				);
				randoms[(int)floor(random_number)]++;
				break;
			}
			// normalverteilung
			case 3: {
				float random_number = random.random_normal_distribution_float(
					0,
					values
				);
				randoms[(int)floor(random_number)]++;
				break;
			}
		}
	}
}

int main(void) {
	const int screen_width = 800;
	const int screen_height = 450;

	InitWindow(screen_width, screen_height, "uebung 002_1");

	int dynamic_screen_width = screen_width;
	int dynamic_screen_height = screen_height;

	SetTargetFPS(60);

	int values = 25;
	int scale = 4;
	int active_random_type = 0;
	bool edit_active_random_type = false;
	int* randoms;
	int random_number_count = 10000;
	Random random = Random();

	//randoms = (int*) calloc(values, sizeof(int));
	initialize_random_numbers(&randoms, values);
	roll_random_numbers(
		randoms, values, random_number_count, random, active_random_type
	);

	while (!WindowShouldClose()) {
		dynamic_screen_width = GetScreenWidth();
		dynamic_screen_height = GetScreenHeight();
		if (IsKeyPressed(KEY_R)) {
			initialize_random_numbers(&randoms, values);
			roll_random_numbers(
				randoms, values, random_number_count, random, active_random_type
			);
		}
		if (IsKeyDown(KEY_UP)) {
			random_number_count += 1000;
		}
		if (IsKeyDown(KEY_DOWN)) {
			random_number_count -= 1000;
			if (random_number_count <= 0) {
				random_number_count = 0;
			}
		}
		if (IsKeyDown(KEY_RIGHT)) {
			values++;
		}
		if (IsKeyDown(KEY_LEFT)) {
			values--;
			if(values <= 1) {
				values = 1;
			}
		}
		BeginDrawing();
			ClearBackground(RAYWHITE);
			for (int i = 0; i < values; i++) {
				int local_scale = 2;
				// only consider scale when normal distribution is active (1 & 3)
				if (active_random_type == 1 || active_random_type == 3) {
					local_scale = scale;
				}
				int height = (
					randoms[i] * dynamic_screen_height
					/ random_number_count * values / local_scale
				);
				DrawRectangle(
					(dynamic_screen_width / values) * i,
					dynamic_screen_height - height,
					dynamic_screen_width / values,
					height,
					SKYBLUE
				);
				DrawLine(
					(dynamic_screen_width / values) * i,
					dynamic_screen_height,
					(dynamic_screen_width / values) * i,
					dynamic_screen_height - height,
					BLUE
				);
				DrawLine(
					(dynamic_screen_width / values) * (i + 1),
					dynamic_screen_height,
					(dynamic_screen_width / values) * (i + 1),
					dynamic_screen_height - height,
					BLUE
				);
				DrawLine(
					(dynamic_screen_width / values) * i,
					dynamic_screen_height - height,
					(dynamic_screen_width / values) * (i + 1),
					dynamic_screen_height - height,
					BLUE
				);
				DrawText(
					TextFormat("%i", i),
					(dynamic_screen_width / values) * i,
					dynamic_screen_height - 20,
					20,
					RED
				);
				DrawText(
					TextFormat("%i", randoms[i]),
					(dynamic_screen_width / values) * i,
					dynamic_screen_height - height,
					20,
					RED
				);
			}

			DrawText(
				TextFormat(
					"random numbers: %i\nvalues: %i",
					random_number_count, values
				),
				10, 10, 20, BLACK
			);

			GuiSpinner(
				(Rectangle) {35, 70, 100, 20},
				"scale", &scale,
				0, 90000, false
			);

            if (
				GuiDropdownBox(
					(Rectangle){ 10, 100, 125, 30 },
					"INT_UNIFORM;INT_NORMAL;FLOAT_UNIFORM;FLOAT_NORMAL",
					&active_random_type,
					edit_active_random_type
				)
			) edit_active_random_type = !edit_active_random_type;
		EndDrawing();
	}

	CloseWindow();

	return 0;
}