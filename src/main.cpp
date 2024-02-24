#include "raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main() {
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screen_width = 800;
    const int screen_height = 450;
    const int frames_count = 3;

    InitWindow(screen_width, screen_height, "raylib cmake template example - sprite animation");

    // NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)
    Texture2D anim_texture = LoadTexture("resources/anim.png");  // Texture loading

    Vector2 position = { 800.f / 2.f - 224.f / 2.f, 450.0f / 2.f - (float)anim_texture.height / 2.f };
    Rectangle frame_rect = { 0.0f, 0.0f, (float)anim_texture.width / frames_count,
                             (float)anim_texture.height };
    int current_frame = 0;

    int frames_counter = 0;
    int frames_speed = 3;  // Number of spritesheet frames shown by second

    SetTargetFPS(60);  // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())  // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        frames_counter++;

        if (frames_counter >= (60 / frames_speed)) {
            frames_counter = 0;
            current_frame++;

            if (current_frame > 5)
                current_frame = 0;

            frame_rect.x = (float)current_frame * (float)anim_texture.width / frames_count;
        }

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground({ 67, 50, 128, 255 });

        DrawText("Hello World!", 330, (int)position.y + 224, 24, BLUE);

        DrawTextureRec(anim_texture, frame_rect, position, WHITE);  // Draw part of the texture

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(anim_texture);  // Texture unloading

    CloseWindow();  // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}