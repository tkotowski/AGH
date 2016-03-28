#ifndef bib
#define bib
#include <stdio.h>
#include <stdlib.h>

typedef struct {int roww, column;
		int **table;
}data;

int ** create(int, int);

void delaslong(int, int**);

void delaslong2(int, int**); 

void create_struct(data*); 

void delaslong_struct(data*);

int ** resize(int**, int, int);

void resize_struct(data*, int, int);

void insert(data*, int, int, int);

void at(data, int, int); 

void print_table(data);

void read_file(data*);

void save_file(FILE*, data);

void tabula_rasa(void);

unsigned char keyPressed ();

#endif
