#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gol.h"


void world_init(bool m[TAM_X][TAM_Y])
{
	
	 for (int i=0; i<TAM_X; i++)
		for (int j=0; j<TAM_Y; j++)
			m[i][j]=false;
					

	
		m[0][1]=true;
		m[1][2]=true;
		m[2][0]=true;
		m[2][1]=true;
		m[2][2]=true;
}

void world_print(bool m[TAM_X][TAM_Y])
{
	
	 for (int i=0; i<TAM_X; i++)
	{
		for (int j=0; j<TAM_Y; j++)
		{
			if(m[i][j]==true)
					printf("#");
			else
					printf(".");
		}
			
		printf("\n");
	}
}

void world_step(bool m1[TAM_X][TAM_Y], bool m2[TAM_X][TAM_Y])
{
	
	 int vivas = 0;
	 
	 for (int i=0; i<TAM_X; i++)
	{
		for (int j=0; j<TAM_Y; j++)
		{
			vivas = world_count_neighbors(m1, i, j);
			m2[i][j] = (m1[i][j] && vivas == 2) || vivas == 3;
		}
	}
	
	world_copy(m1, m2);
}

int world_count_neighbors(bool m[TAM_X][TAM_Y], int i, int j)
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

bool world_get_cell(bool m[TAM_X][TAM_Y], int i, int j)
{
	
		if (i == -1)
			i += TAM_X;
		else if (i == TAM_X)
			i -= TAM_X;
		if (j == -1)
			j += TAM_Y;
		else if (j == TAM_Y)
			j -= TAM_Y;

		return m[i][j];
}

void world_copy(bool destino[TAM_X][TAM_Y], bool fuente[TAM_X][TAM_Y])
{

	for (int i=0; i<TAM_X; i++)
			for (int j=0; j<TAM_Y; j++)
				destino[i][j]=fuente[i][j];
}
