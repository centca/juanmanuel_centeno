#ifndef _GAMEOFLIFE_H_
#define _GAMEOFLIFE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM_X 10
#define TAM_Y 10

struct world {
        bool m1[TAM_X][TAM_Y];
        bool m2[TAM_X][TAM_Y];
};

void world_init(struct world *m);
void world_print(const struct world *m);
void world_step(struct world *m);
int world_count_neighbors(const struct world *m, int i, int j);
bool world_get_cell(const struct world *m, int i, int j);
void world_copy(struct world *m);

#endif