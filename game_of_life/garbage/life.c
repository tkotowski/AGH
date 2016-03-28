#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "bib.h"
#include "bib.c"
#include "alg.h"
#include "alg.c"
#define COL 80
#define ROW 22

int main()
{
FILE* output_data;
data prime_generation;
data descendant_generation;
int i,k;
char j;

prime_generation.roww = ROW;
prime_generation.column = COL;
descendant_generation.roww = ROW;
descendant_generation.column = COL;

create_struct(&prime_generation); /*create_struct wypełnia tablice zerami*/
create_struct(&descendant_generation);

read_file(&prime_generation);
wczytaj_dane(&descendant_generation);

tabula_rasa();
print_table(prime_generation);
do
	{
	for (i = 0; i < 30000; i++)
		{
		tabula_rasa();
		future(prime_generation, &descendant_generation);
		print_table(descendant_generation);
		usleep(500); 
		swap(&prime_generation, &descendant_generation);
		tabula_rasa();
		}
	print_table(descendant_generation);
	scanf("%c", &j);
	getchar();}
while(j!= 'k' && j != 'K');

output_data = fopen("output.txt", "r+");
if (output_data == NULL) return -2;
save_data(output_data, prime_generation);
fclose(output_data);
delaslong_struct(&prime_generation);
delaslong_struct(&descendant_generation);
return 0;
}

