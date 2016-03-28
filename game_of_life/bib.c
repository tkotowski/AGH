#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include "bib.h"
#define COL 80
#define ROW 22


void delaslong(int i ,int **tab)
	{int a;
	for (a=0; a<i; a++)
		free(tab[a]);
	free(tab);
	}

void delaslong2(int i ,int **tab){
	int a;
	for (a=0; a<i; a++)
		free(tab[a]);
}

int **create(int a, int b)
	{int **table = (int**)malloc((a+2)*sizeof(int*));
	int i,j;
	if (table==NULL)
		{printf("Nie udalo sie zaalokowac dostatecznego rozmiaru pamieci. Koniec programu\n\n");
		return NULL;}

	for(i=0; i<a; i++){
		table[i]=(int*)malloc((b+2)*sizeof(int));
		if(table[i]==NULL){
			printf("Nie udalo sie zaalokowac dostatecznego rozmiaru pamieci. Koniec programu\n\n");
			for(j=i+1; j>0; j--){
				delaslong(i, table);
				return NULL;
			}
		}
	}
			
			
	for(i=0; i<a; i++) /*wypelniam zerami*/{
		for(j=0; j<b; j++)
			table[i][j]=0;
	}
	
	return table;
}

void create_struct(data* downloaded_table){
	data temporary=*downloaded_table;
	temporary.table = create((temporary.roww+2), (temporary.column+2));
	
	if (temporary.table == NULL){
    		fprintf (stderr, "Nie Udalo sie umiescic tablicy w strukturze\n"); //Popraw
    		temporary.roww = 0;
    		temporary.column = 0;
    		*downloaded_table = temporary;
    		return;
    	}

	*downloaded_table = temporary;
	return;
}

void delaslong_struct(data* table){
	free(table);
	return;
}

int **resize(int **oldtab, int enlarge_row, int enlarge_col){ 
	int **newtab, i,j;
	newtab = (int**) malloc((ROW+enlarge_row)*sizeof(int*)); //DOPISZ OPERATOR RZUTOWANIA DO MALLOCA, DOPISAN'D
	
	if (newtab==NULL)
		{printf("Nie udalo sie zaalokowac dostatecznego rozmiaru pamieci w celu powiekszenia tablicy. Koniec programu\n\n");
		exit(0);}
	  
	for(i=0; i<(ROW+enlarge_row); i++){
		newtab[i]=malloc((COL+enlarge_col)*sizeof(int));
		if(newtab[i]==NULL){
			printf("Nie udalo sie zaalokowac dostatecznego rozmiaru pamieci w celu powiekszenia tablicy. Koniec programu\n\n");
			delaslong((ROW+enlarge_row), newtab);
			delaslong(ROW, oldtab);
			exit(0);
		}
}
	/*teraz wypełniam zerami*/
	for (i=0; i<(COL+enlarge_col); i++){
		for (j=0; j<(ROW+enlarge_row); j++){
			newtab[i][j]=0;
		}
	}


	oldtab=newtab;
	delaslong2(ROW, oldtab);
	return oldtab;
}



void at(data tab, int i, int j){
		if(tab.table[i][j]==1){
			printf("O");
		}
		else if(tab.table[i][j]==0)
			printf(" ");		
			else {printf("Blad programu, wskazana komorka ma niepoprawna wartosc wynoszaca %d \n\n", tab.table[i][j]);
			}
}

void insert(data *table, int value, int a, int b){
	data temporary = *table;
	if ((a > temporary.roww || b > temporary.column) && (a > temporary.column || b > temporary.roww)) printf ("Podales zle dane, wybierz opcje jeszcze raz \n");
	temporary.table[a][b] = value;
	*table = temporary;
}


void print_table(data table){
	int i,j;
	for (i=0; i<ROW; i++){
		for (j=0; j<COL; j++){
        		at(table, i, j);
        	}
    		printf("\n");
    	}
}


void read_file(data* table){
	data temporary = *table;
	int i,j;
	i=0; j=0;
	FILE* input_file = fopen("input.txt","r");
	if (input_file == NULL) fprintf(stderr, "blad przy otwieraniu pliku :( \n");

	while (feof(input_file) == 0){
		fscanf (input_file, "%d", &i); i++;
		fscanf (input_file, "%d", &j); j++;
	temporary.table[i][j] = 1;
	}

	fclose(input_file);
	*table = temporary;
}

void save_file(FILE* work_file, data table){ 
	int i,j,k;
	k = 0;
	data temporary = table;

	for (i=0; i < (temporary.roww); i++){
    		for (j=0; j<(temporary.column); j++){
        		k = temporary.table[i][j];
        		if (k == 1){
				fprintf (work_file, "%d %d  \n", i, j);
        	}
        }
	fprintf (work_file, "\n");
    }
}

void tabula_rasa(void){
	printf("\033[2J");
	printf("\033[0;0f");
}

unsigned char keyPressed () {
	struct termios oldt, newt;
	int ch;unsigned char keyPressed () {
	struct termios oldt, newt;
	int ch;
	int oldf;
	
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr (STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl (STDIN_FILENO, F_GETFL, 0);
	fcntl (STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
	
	ch = getchar ();
	
	tcsetattr (STDIN_FILENO, TCSANOW, &oldt);
	fcntl (STDIN_FILENO, F_SETFL, oldf);
	if (ch != EOF) {
		ungetc (ch, stdin);
		return 1;
	}
	
	return 0;
}
	int oldf;
	
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr (STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl (STDIN_FILENO, F_GETFL, 0);
	fcntl (STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
	
	ch = getchar ();
	
	tcsetattr (STDIN_FILENO, TCSANOW, &oldt);
	fcntl (STDIN_FILENO, F_SETFL, oldf);
	if (ch != EOF) {
		ungetc (ch, stdin);
		return 1;
	}
	
	return 0;
}


