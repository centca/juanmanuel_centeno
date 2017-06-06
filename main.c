#include <stdio.h>
#include <stdlib.h>
#include "gol.h"

int main()
{

  	int i = 0;
  
	struct world *m  = world_alloc(TAM_X , TAM_Y);
	if (!m) {
		perror("No se puede asignar el mundo");
		return EXIT_FAILURE;
	}
  
  	do {
  		printf("\033cIteration %d\n", i++);

		world_print(m);
		world_iterate(m);

  	} while (getchar() != 'q');
  
	world_free(m);

  	return EXIT_SUCCESS;	
} 
