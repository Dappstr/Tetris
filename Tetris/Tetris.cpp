#include <raylib.h>
#include <string>
#include "game.hpp"

namespace globals {
    constexpr size_t window_width{ 500 };
    constexpr size_t window_height{ 620 };
    double last_update_time{ 0 };
}

bool event_triggered(const double interval) {
    double current_time = GetTime();
    if (current_time - globals::last_update_time >= interval) {
        globals::last_update_time = current_time;
        return true;
    }
    return false;
}

int main()
{
    Color dark_blue = { 44, 44, 127, 255 };
    InitWindow(globals::window_width, globals::window_height, "Tetris");
    SetTargetFPS(60);

    InitAudioDevice();
    Music song = LoadMusicStream("sounds/Sounds_music.mp3");
    PlayMusicStream(song);

    Game game = Game();

    while (!WindowShouldClose()) {
        UpdateMusicStream(song);
        game.handle_input();
        if (event_triggered(0.2)) {
            game.move_block_down();
        }
        BeginDrawing();
        ClearBackground(dark_blue);
        DrawText("Score",325, 15, 38, RAYWHITE);
        DrawRectangleRounded({ 320, 55 ,170, 60 }, 0.3, 6, light_blue);

        std::string str_score = std::to_string(game.m_score);
        DrawText(str_score.c_str(), 350, 70, 38, RAYWHITE);

        DrawText("Next", 350, 250, 38, RAYWHITE);
        DrawRectangleRounded({ 320, 300 ,170, 180 }, 0.3, 6, light_blue);

        if (game.game_over) {
            DrawText("GAME OVER", 315, 550, 30, RAYWHITE);
        }

        game.draw();
        EndDrawing();
    }
    CloseAudioDevice();
    CloseWindow();
    return EXIT_SUCCESS;
}
