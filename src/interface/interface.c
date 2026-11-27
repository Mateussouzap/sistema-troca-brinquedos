#define RAYGUI_IMPLEMENTATION
#include "raylib.h"
#include "raygui.h"

int main(){
    InitWindow(800, 400, "TESTE");
    SetTargetFPS(60);

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        GuiLabel((Rectangle){20,20,200,24}, "Ola raygui");
        EndDrawing();
    }
    CloseWindow()
    return 0;
}
