#ifndef _GAMEOFLIFE_H_
#define _GAMEOFLIFE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM_X 10
#define TAM_Y 10
#define W_STOP 0
#define W_STAR 1

struct world;

struct world *world_alloc(int tam_x, int tam_y);
void world_free(struct world *m);
void world_print(const struct world *m);
void world_iterate(struct world *m);

#endif