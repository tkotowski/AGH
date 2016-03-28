#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "bib.h"
#include "alg.h"

void future(data old_generation, data* new_generation){
	int A1, A2, B1, B2;
	data temporary = *new_generation;
	int zliczanie[old_generation.roww][old_generation.column];
	for (A1 = 1; A1 < (old_generation.roww); A1++){
  		for (A2= 1; A2< (old_generation.column+2); A2++){
			zliczanie[A1][A2] = 0;
    			for (B1= -1; B1 <= 1; B1++){
				for (B2 = -1; B2 <= 1; B2++){
					if (old_generation.table[A1+B1][A2+B2] == 1) zliczanie[A1][A2]++; 	
				}
			}
			if(old_generation.table[A1][A2] == 1)
				zliczanie[A1][A2]--;
    		}
   	}

	for (A1 = 1; A1 < (old_generation.roww); A1++){
		for (A2= 1; A2< (old_generation.column+2); A2++){
			if (zliczanie[A1][A2] == 2) 
				temporary.table[A1][A2]=old_generation.table[A1][A2]; 
			else if (zliczanie[A1][A2] == 3) 
				temporary.table[A1][A2] = 1;    
      			else 
				temporary.table[A1][A2]=0;
		}	
	}

	*new_generation = temporary;   
}

void swap(data* old_generation, data* new_generation){
	data temporary = *new_generation;
	new_generation = old_generation;
	*old_generation = temporary;
}
