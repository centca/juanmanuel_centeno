
#include <stdbool.h>
#include "gol.h"

struct world
{	
	bool *cells[2];
 	int tam_x;
 	int tam_y;
	
};


static void fix_coords(const struct world *m, int *i, int *j);
static void inicio(struct world *m);
static bool get_cell(const struct world *m, int i, int j);
static void set_cell(struct world *m, int b, int i, int j, bool val);
static int count_neighbors(const struct world *m, int i, int j);

struct world *world_alloc(int tam_x, int tam_y)
{
	struct world *m = (struct world *)malloc(sizeof(struct world));
	if (!m)
		return NULL;

	m->cells[0] = (bool *)malloc((tam_x * tam_y) * sizeof(bool));
	
	if (!m->cells[0]){
		free(m);
		return NULL;
	}
	
	m->cells[1] = (bool *)malloc((tam_x * tam_y) * sizeof(bool));
	if (!m->cells[0]){
		
		free(m->cells[0]);
		free(m);
		return NULL;
	}
	

	m->tam_x   = tam_x;
	m->tam_y   = tam_y;

	inicio(m);

 	

	return m;
}

static void inicio(struct world *m)
{
	for (int i = 0 ; i < m->tam_x ; i++)
 		for (int j = 0; j < m->tam_y; j++)
 			set_cell(m, 0, i, j, false);
 	
	set_cell(m, 0, 0, 1 , true);
	set_cell(m, 0, 1, 2 , true);
	set_cell(m, 0, 2, 0 , true);
	set_cell(m, 0, 2, 1 , true);
	set_cell(m, 0, 2, 2 , true);
}


void world_free(struct world *m)
{
	free(m->cells[0]);
	free(m->cells[1]);
	free(m);
}


void world_print(const struct world *m)
{
	 for (int i=0; i< m->tam_x; i++)
	{
		for (int j = 0; j < m->tam_y; j++)	
			printf("%c ", get_cell(m, i, j) == 0 ? '.' : '#' );
		printf("\n");
  	}
}

void world_iterate(struct world *m)
{
  	for (int i = 0 ; i < m->tam_x ; i++) {
  		for (int j = 0; j < m->tam_y; j++) {
			
 			int vecinos = count_neighbors(m, i, j);
			set_cell(m, 1, i, j, ((get_cell(m, i, j) && vecinos == 2) || vecinos == 3) );
  		}
  	}
	
	bool *cambiar;
	cambiar = m->cells[0];
	m->cells[0] = m->cells[1];
	m->cells[1] = cambiar;
  }

static void fix_coords(const struct world *m, int *i, int *j)
{
	int tam_x = m->tam_x; 	
	int tam_y = m->tam_y;

	if (*i == -1)
		*i = tam_x - 1;
	else if (*i == tam_x)
		*i = 0;
	if (*j == -1)
		*j = tam_y - 1;
	else if (*j == tam_y)
		*j = 0;
  
	
}


static bool get_cell(const struct world *m, int i, int j)
{
	fix_coords(m, &i, &j);
	return *(m->cells[0] + (i * m->tam_y + j));
}

static void set_cell(struct world *m, int b, int i, int j, bool val)
{
	
	fix_coords(m, &i, &j);
	*(m->cells[b] + (i * m->tam_y + j)) = val;
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
