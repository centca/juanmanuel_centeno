#ifndef _GAMEOFLIFE_H_
#define _GAMEOFLIFE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct world;

struct world *world_alloc(int tam_x, int tam_y);
void world_free(struct world *m);
void world_print(const struct world *m);
void world_iterate(struct world *m);

#endif
