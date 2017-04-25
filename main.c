#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define TAM_X 10
#define TAM_Y 10

void world_init(bool m[TAM_X][TAM_Y]);
void world_print(bool m[TAM_X][TAM_Y]);
void world_step(/* Recibo dos mundos */);
int world_count_neighbors(/* Recibo un mundo y unas coordenadas */);
bool world_get_cell(bool m[TAM_X][TAM_Y], int i, int j);
void world_copy(bool destino[TAM_X][TAM_Y], bool fuente[TAM_X][TAM_Y]);

int main()
{
	int i = 0;
	
	bool m1[TAM_X][TAM_Y];
	bool m2[TAM_X][TAM_Y]; 
	// TODO: inicializa el mundo
	do {
		printf("\033cIteration %d\n", i++);
		// TODO: Imprime el mundo
		// TODO: Itera
	} while (getchar() != 'q');

	return EXIT_SUCCESS;
}

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

void world_step(/* Recibo dos mundos */)
{
	/*
	 * TODO:
	 * - Recorrer el mundo célula por célula comprobando si nace, sobrevive
	 *   o muere.
	 *
	 * - No se puede cambiar el estado del mundo a la vez que se recorre:
	 *   Usar un mundo auxiliar para guardar el siguiente estado.
	 *
	 * - Copiar el mundo auxiliar sobre el mundo principal
	 */
}

int world_count_neighbors(/* Recibo un mundo y unas coordenadas */)
{
	// Devuelve el número de vecinos
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
