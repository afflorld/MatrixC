#include <stdio.h>
#include <stdlib.h>
#include "../h/matrixDB.h" 


void save(int** matica,int riadky, int stlpce, struct t_matica** uk_prva, int poradie){

    struct t_matica* nova = (struct t_matica*)malloc(sizeof(struct t_matica));


    nova->riadky = riadky;
    nova->stlpce = stlpce;
    nova->poradie = poradie;

    

    nova->matica = (int**)malloc(riadky * sizeof(int*));
    for(int i = 0; i < riadky; i++){
        nova->matica[i] = (int*)malloc(stlpce * sizeof(int));
    }

    for(int i = 0; i < riadky; i++){
        for(int j = 0; j < stlpce; j++){
            nova->matica[i][j] = matica[i][j];
        }
    }

    nova-> dalsia = *uk_prva;
    *uk_prva = nova;

}

