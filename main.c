#include <stdio.h>
#include "raylib.h"
#define STB_DS_IMPLEMENTATION
#include "stb_ds.h"

#define WIDTH 1920
#define HEIGHT 1080
#define FPS 60

#define DIMS 20
#define GRIDSIZE 50

const char *TITLE = "Cells";

typedef struct {
    Rectangle rect;
    Color fillColor;
    Color lineColor;
    bool alive;
} Cell;

Cell createCell(Rectangle rect) {
    Cell cell;
    cell.rect = rect;
    cell.alive = false;
    cell.fillColor = DARKGRAY;
    cell.lineColor = RAYWHITE;
    return cell;
}

void drawCell(Cell c) {
    DrawRectangle(c.rect.x, c.rect.y, c.rect.width, c.rect.height, c.fillColor);
    DrawRectangleLines(c.rect.x, c.rect.y, c.rect.width, c.rect.height, c.lineColor);
}

int main(void) {
    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(WIDTH, HEIGHT, TITLE);
    SetTargetFPS(FPS);

    Cell *cells = NULL;

    for (int x = 0; x < DIMS; ++x) {
        for (int y = 0; y < DIMS; ++y) {
            Cell newCell = createCell((Rectangle){x*GRIDSIZE+500, y*GRIDSIZE+25, GRIDSIZE, GRIDSIZE});
            arrput(cells, newCell);
        }
    }

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(DARKGRAY);

        DrawText("Snake", 80, 50, 70, WHITE);

        for (int i = 0; i < arrlen(cells); ++i) {
            drawCell(cells[i]);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;    
}


