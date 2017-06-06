
#include <stdbool.h>
#include "gol.h"

struct world
{	
	bool *cells[2];
 	int tam_x;
 	int tam_y;
	
};


static void fix_coords(const struct world *m, int *i, int *j);
static bool get_cell(const struct world *m, int i, int j);
static void set_cell(struct world *m, int b, int i, int j, bool val);
static int count_neighbors(const struct world *m, int i, int j);

struct world *world_alloc(int tam_x, int tam_y)
{
	struct world *m = (struct world *)malloc(sizeof(struct world));
	if (!m)
		return NULL;

	m->cells[W_STOP] = (bool *)malloc((tam_x * tam_y) * sizeof(bool));
	
	if (!m->cells[W_STOP]){
		free(m);
		return NULL;
	}
	
	m->cells[W_STAR] = (bool *)malloc((tam_x * tam_y) * sizeof(bool));
	if (!m->cells[W_STOP]){
		
		free(m->cells[W_STOP]);
		free(m);
		return NULL;
	}
	
 	for (int i = 0 ; i < TAM_X ; i++)
 		for (int j = 0; j < TAM_Y; j++)
 			set_cell(m, W_STOP, i, j, false);
 	
	set_cell(m, W_STOP, 0, 1 , true);
	set_cell(m, W_STOP, 1, 2 , true);
	set_cell(m, W_STOP, 2, 0 , true);
	set_cell(m, W_STOP, 2, 1 , true);
	set_cell(m, W_STOP, 2, 2 , true);

	return m;
}

void world_free(struct world *m)
{
	free(m->cells[W_STOP]);
	free(m->cells[W_STAR]);
	free(m);
}


void world_print(const struct world *m)
{
	
	 for (int i=0; i<TAM_X; i++)
	{
		for (int j = 0; j < TAM_Y; j++)	
			printf("%c " , get_cell(m, i, j) == 0 ? '.' : '#' );
		
			printf("\n");	
  	}
}

void world_iterate(struct world *m)
{
  	for (int i = 0 ; i < TAM_X ; i++) {
  		for (int j = 0; j < TAM_Y; j++) {
			
 			int vecinos = count_neighbors(m, i, j);
			set_cell(m, W_STAR, i, j, ((get_cell(m, i, j) && vecinos == 2) || vecinos == 3) );
  		}
  	}
	
	bool *cambiar;
	cambiar = m->cells[W_STOP];
	m->cells[W_STOP] = m->cells[W_STAR];
	m->cells[W_STAR] = cambiar;
  }

static void fix_coords(const struct world *m, int *i, int *j)
{
 	
	if (*i == -1)
		*i = TAM_X - 1;
	else if (*i == TAM_X)
		*i = 0;
	if (*j == -1)
		*j = TAM_Y - 1;
	else if (*j == TAM_Y)
		*j = 0;
  
	
}


static bool get_cell(const struct world *m, int i, int j)
{
	fix_coords(m, &i, &j);
	return *(m->cells[W_STOP] + (i * TAM_Y + j));
}

static void set_cell(struct world *m, int b, int i, int j, bool val)
{
	
	fix_coords(m, &i, &j);
	*(m->cells[b] + (i * TAM_Y + j)) = val;
}

static int count_neighbors(const struct world *m, int i, int j)
{
	int c = 0;

	c += get_cell(m, i , j - 1);
	c += get_cell(m, i , j + 1);
	c += get_cell(m, i + 1, j - 1);
	c += get_cell(m, i + 1, j);
	c += get_cell(m, i + 1, j + 1);
	c += get_cell(m, i - 1, j - 1);
	c += get_cell(m, i - 1, j);
	c += get_cell(m, i - 1, j + 1);
  
	return c;
}
