#include <iostream>
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <raylib.h>

#include "ray.hpp"

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 1024;
const float ASPECT_RATIO = SCREEN_WIDTH / SCREEN_HEIGHT;


int c_f2i(const float f) { return (f >= 1.0 ? 255 : (f <= 0.0 ? 0 : (int)floor(f * 256.0))); }

Color color_fvec(const glm::fvec3 v) {
    Color c = { 
        static_cast<int>(c_f2i(v.r)),
        static_cast<int>(c_f2i(v.g)),
        static_cast<int>(c_f2i(v.b)),
        255
    };
    return c;
}


Color ray_color_at(const Raybaser::Ray& ray) {
    glm::fvec3 unit_direction = glm::normalize(ray.get_direction());
    auto a = 0.5f * (unit_direction.y + 1.0f);

    glm::fvec3 c1 = glm::fvec3(1.0f);
    glm::fvec3 c2 = glm::fvec3(0.5f, 0.7f, 1.0f);
    Color out = color_fvec((1.0f - a) * c1 + a * c2);
    return out;
}

void raytrace(Image* output) {
    auto focal_length = 1.0f;
    auto viewport_height = 2.0f;
    auto viewport_width = viewport_height * (static_cast<float>(output->width) / output->height);
    glm::fvec3 camera_position = glm::fvec3(0.0f);
    
    auto u = glm::fvec3(viewport_width, 0.0f, 0.0f);
    auto v = glm::fvec3(0, -viewport_height, 0.0f);
    auto pixel_delta_u = u / static_cast<float>(output->width);
    auto pixel_delta_v = v / static_cast<float>(output->height);

    auto viewport_upper_left = camera_position - glm::fvec3(0.0f, 0.0f, focal_length) - u/2.0f - v/2.0f;
    auto first_pixel = viewport_upper_left + 0.5f * (pixel_delta_u + pixel_delta_v);

    for (int y = output->height-1; y >= 0; y--) {
        for (int x = 0; x < output->width; x++) {
            glm::fvec3 pixel_center = first_pixel 
                + (static_cast<float>(x) * pixel_delta_u) 
                + (static_cast<float>(y) * pixel_delta_v);
            glm::fvec3 ray_direction = pixel_center - camera_position;
            Raybaser::Ray r(camera_position, ray_direction);
            auto pixel_color = ray_color_at(r);
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
