#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "bib.h"
#include "alg.h"
#define COL 80
#define ROW 22

int main(int argc, char **argv[])
{	
	char j;
	FILE* output_data;
	data prime_generation;
	data descendant_generation;

	prime_generation.roww = ROW;
	prime_generation.column = COL;
	descendant_generation.roww = ROW;
	descendant_generation.column = COL;
	create_struct(&prime_generation); // create_struct wypełnia tablice zerami, ponieważ zagnieżdżona w create struct jest funkcja create, która z definicji wypełnia tablicę zerami
	create_struct(&descendant_generation);

	read_file(&prime_generation);
	read_file(&descendant_generation);
	tabula_rasa();
	print_table(prime_generation);
	do
	{	
		tabula_rasa();
		future(prime_generation, &descendant_generation);
		print_table(descendant_generation);
		usleep(100000); 
		swap(&prime_generation, &descendant_generation);
		tabula_rasa();
		print_table(prime_generation);
		if (keyPressed ()) {
			j = getchar ();
			if (j == 'K' || j == 'k')
			break;
		}
	
	}while(j != 'k' && j != 'K');

	output_data = fopen((*argv)[0], "w+");
	if (output_data == NULL) return -2;
	save_file(output_data, prime_generation);
	fclose(output_data);
	delaslong_struct(&prime_generation);
	delaslong_struct(&descendant_generation);
	return 0;
}

