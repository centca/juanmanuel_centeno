#ifndef _GAMEOFLIFE_H_
#define _GAMEOFLIFE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM_X 10
#define TAM_Y 10

void world_init(bool m[TAM_X][TAM_Y]);
void world_print(bool m[TAM_X][TAM_Y]);
void world_step(bool m1[TAM_X][TAM_Y], bool m2[TAM_X][TAM_Y]);
int world_count_neighbors(bool m[TAM_X][TAM_Y], int i, int j);
bool world_get_cell(bool m[TAM_X][TAM_Y], int i, int j);
void world_copy(bool destino[TAM_X][TAM_Y], bool fuente[TAM_X][TAM_Y]);

#endif