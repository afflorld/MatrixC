#include <stdio.h>
#include <stdlib.h>
#include "h/matrixDB.h"
struct t_matica* prva = NULL;

void ADD(){

    int stlpce;
    int riadky;
    printf("Zadaj aka velka je matica:\n");
    printf("Stlpce:");
    scanf("%d", &stlpce);
    printf("\nRiadky:");
    scanf("%d", &riadky);

    int** matica = (int**)malloc(riadky * sizeof(int*));
    for(int i = 0; i < riadky; i++){
        matica[i] = (int*)malloc(stlpce * sizeof(int));
    }
    

    for(int i = 0; i < riadky; i++){
        for(int j = 0; j < stlpce; j++){
            matica[i][j] = 0;
     }
    }

    for(int i = 0; i < riadky; i++){
        for(int j = 0; j < stlpce; j++){

            for (int i = 0; i < riadky; i++){
                for (int j = 0; j < stlpce; j++){
                    printf("%d", matica[i][j] );
                }
                printf("\n");
            }


            printf("Zadaj hodnotu pre maticu[%d][%d]:", i, j);
            scanf("%d", &matica[i][j]);
        }
    }    

    static int poradie = 0;
    poradie++;

    save(matica, riadky, stlpce, &prva, poradie);

}

void ANS() {
    struct t_matica* odkaz = prva;

    while (odkaz != NULL) {
        printf("Matrix #%d (%d x %d):\n", odkaz->poradie, odkaz->riadky, odkaz->stlpce);
        odkaz = odkaz->dalsia;
    } 
}

int main(){

    char vyber;

    do{
        printf(
            "ADD(A) DEL(D) ANS(S) EXIT(E)"
        );
        scanf("%c", &vyber);

        switch(vyber){
            case 'A':
                ADD();
                break;
            case 'D':
                break;
            case 'S':
                ANS();
                break;
            case 'E':
                break;
            default:
                printf("\nZadali ste zly znak\n");
                break;
        }
    }while(vyber != 'E');
    
    return 0;

}

