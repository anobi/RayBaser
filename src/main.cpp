#include <iostream>
#include <glm/glm.hpp>
#include <raylib.h>

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 1024;

void raytrace(Image* output) {
    for (int y = output->height-1; y >= 0; y--) {
        for (int x = 0; x < output->width; x++) {
            Color pixel_color = {
                (int)(255.9f * (float(x) / (output->width - 1))), 
                (int)(255.9f * (float(y) / (output->height - 1))), 
                (int)(255.9f * 0.25f),
                255
            };
            ImageDrawPixel(output, x, y, pixel_color);
        }
    }
}


int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "RayBaser");
    SetTargetFPS(60);

    Texture2D out_texture;
    Image raytraced_image = GenImageColor(SCREEN_WIDTH, SCREEN_HEIGHT, BLACK);

    raytrace(&raytraced_image);
    out_texture = LoadTextureFromImage(raytraced_image);
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(out_texture, 0, 0, WHITE);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
