#define RAYGUI_IMPLEMENTATION
#include "raylib.h"
#include "raygui.h"
#include <stdio.h>
#include "dados.h"
int main(void) {
    InitWindow(800, 450, "Teste");
    SetTargetFPS(60);
    char nome[50] = "";
    char link_fotos[50] = "";
    char condicao[50] = "";
    char descricao[150] = "";
    int caixaAtiva = 0;
    Rectangle caixas[4] = {
    {20, 60, 150, 30},
    {170, 60, 150, 30},
    {320, 60, 150, 30},
    {470, 60, 150, 30}};
    bool clickcaixa = false; 
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        GuiLabel((Rectangle){20, 20, 200, 24}, "Ola raygui");
        clickcaixa = false;
        for (int i=0;i<4;i++){
            if (CheckCollisionPointRec(GetMousePosition(),caixas[i]))
                clickcaixa = true;
        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && clickcaixa == false)
            caixaAtiva = 0;
        if (GuiTextBox((Rectangle)caixas[0], nome, 50, caixaAtiva == 1)) {
            caixaAtiva = 1;
        }
        if (GuiTextBox((Rectangle)caixas[1], link_fotos, 50, caixaAtiva == 2)) {
            caixaAtiva = 2;

        }
        if (GuiTextBox((Rectangle)caixas[2], condicao, 50, caixaAtiva == 3)) {
            caixaAtiva = 3;

        }
        if (GuiTextBox((Rectangle)caixas[3], descricao, 150, caixaAtiva == 4)) {
            caixaAtiva = 4;

        }
        
        if (GuiButton((Rectangle){20, 90, 200, 30}, "clique")){
            printf("%s",nome);
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}