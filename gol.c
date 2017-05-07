#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gol.h"


void world_init(struct world *m)
{
	
	 for (int i=0; i<TAM_X; i++)
		for (int j=0; j<TAM_Y; j++)
			m->m1[i][j]=false;
					

	
		m->m1[0][1]=true;
		m->m1[1][2]=true;
		m->m1[2][0]=true;
		m->m1[2][1]=true;
		m->m1[2][2]=true;
}

void world_print(const struct world *m)
{
	
	 for (int i=0; i<TAM_X; i++)
	{
		for (int j=0; j<TAM_Y; j++)
				printf("%s ", world_get_cell(m, i, j) ? "#" : ".");
			
		printf("\n");
	}
}

void world_step(struct world *m)
{
	
	 int vivas = 0;
	 
	 for (int i=0; i<TAM_X; i++)
	{
		for (int j=0; j<TAM_Y; j++)
		{
			vivas = world_count_neighbors(m, i, j);
			m->m2[i][j] = (m->m1[i][j] && vivas == 2) || vivas == 3;
		}
	}
	
	world_copy(m);
}

int world_count_neighbors(const struct world *m, int i, int j)
{
	
	int vecinos = 0;
	
	vecinos += world_get_cell(m, i + 1, j);
	vecinos += world_get_cell(m, i + 1, j - 1);
	vecinos += world_get_cell(m, i , j - 1);
	vecinos += world_get_cell(m, i - 1 , j - 1);
	vecinos += world_get_cell(m, i - 1  , j );
	vecinos += world_get_cell(m, i - 1, j + 1);
	vecinos += world_get_cell(m, i , j +  1);
	vecinos += world_get_cell(m, i + 1, j + 1);
	
	return vecinos;
}

bool world_get_cell(const struct world *m, int i, int j)
{
	
		if (i == -1)
			i += TAM_X;
		else if (i == TAM_X)
			i -= TAM_X;
		if (j == -1)
			j += TAM_Y;
		else if (j == TAM_Y)
			j -= TAM_Y;

		return m->m1[i][j];
}

void world_copy(struct world *m)
{

	for (int i=0; i<TAM_X; i++)
			for (int j=0; j<TAM_Y; j++)
				m->m1[i][j] = m->m2[i][j];
}
