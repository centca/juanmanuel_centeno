#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "gol.h"

int main()
{
	int i = 0;
	
	bool m1[TAM_X][TAM_Y];
	bool m2[TAM_X][TAM_Y]; 
	
	world_init(m1);
	do {
		printf("\033cIteration %d\n", i++);
		
		world_print(m1);
		world_step(m1, m2);
	} while (getchar() != 'q');

	return EXIT_SUCCESS;
}
