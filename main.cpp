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
            scanf(" %d", &matica[i][j]);
        }
    }    

    static int poradie = 0;
    poradie++;

    save(matica, riadky, stlpce, &prva, poradie);

}

void SUM(){

    int u;
    int v;
    int riadky;
    int stlpce;
    struct t_matica* odkaz = prva;
    struct t_matica* odkazU = prva;
    struct t_matica* odkazV = prva;
    static int cislo = 0;

    while (odkaz != NULL) {
        if((odkaz->riadky + odkaz->stlpce) % 2 == 0){ 
            printf("Matrix #%d (%d x %d)\n", odkaz->poradie, odkaz->riadky, odkaz->stlpce);
            odkaz = odkaz->dalsia;
            }
        }

    do{
    
    printf("Zadaj poradie matice u:");
    scanf(" %d", &u);
    printf("Zadaj poradie matice v:");
    scanf(" %d", &v);

    while(odkazU->dalsia){
        if(odkazU->dalsia->poradie == u){
            break;
        }
        odkazU = odkazU->dalsia;
    }

    while(odkazV->dalsia){
        if(odkazV->dalsia->poradie ==v){
            break;
        }
        odkazV = odkazV->dalsia;
    }

    if((odkazU->riadky == odkazV->riadky) && (odkazU->stlpce == odkazV->stlpce)){
            
        riadky = odkazV->riadky;
        stlpce = odkazV->stlpce;

    }

    }while((odkazU->riadky != odkazV->riadky) && (odkazU->stlpce != odkazV->stlpce));

    printf("u:\n");

    for(int i = 0; i < odkazU->riadky; i++){
        for(int j = 0; j < odkazU->stlpce; j++){
            printf("%d", odkazU->matica[i][j] );
        }
        printf("\n");
    }

    printf("v:\n");

    for(int i = 0; i < odkazV->riadky; i++){
        for(int j = 0; j < odkazV->stlpce; j++){
            printf("%d", odkazV->matica[i][j] );
        }
        printf("\n");
    }

    
    int** matica = (int**)malloc(riadky * sizeof(int*));
    for(int i = 0; i < riadky; i++){
        matica[i] = (int*)malloc(stlpce * sizeof(int));
    }

    cislo++;
    int poradie = 100 + cislo;
    printf("Nova matica #%d\n", poradie);

    for(int i = 0; i < riadky; i++){
        for(int j = 0; j < stlpce; j++){
           matica[i][j] = odkazV->matica[i][j] + odkazU->matica[i][j];
           printf("%d", matica[i][j]);
        }
        printf("\n");
    }

    save(matica, riadky, stlpce, &prva, poradie);

    }
    
void SUB(){


};
void DEL(){


};
void MUL(){



};
void INV(){


};
void DET(){


};
void GAUS(){


};


void ANS() {
    char vyber;
    struct t_matica* odkaz = prva;
    
    while (odkaz != NULL) {
        printf("Matrix #%d (%d x %d)\n", odkaz->poradie, odkaz->riadky, odkaz->stlpce);
        odkaz = odkaz->dalsia;
    }


    do{
        printf("+(+) -(-) /(/) *(*) INV(I) DET(D) GAUS(G) EXIT(E)");
        scanf(" %c", &vyber);

        switch(vyber){
            case '+':
                SUM();
                break;
            case '-':
                SUB();
                break;
            case '/':
                DEL();
                break;
            case '*':
                MUL();
                break;
            case 'I':
                INV();
                break;
            case 'D':
                DET();
                break;
            case 'G':
                GAUS();
                break;
            case 'E':
                break;
            default:
                printf("\nZadali ste zly znak\n");
                break;
        }
    }while(vyber != 'E');
}

int main(){

    char vyber;
    system("clear");
    printf("Iba pre matice 2x2 az 4x4");

    do{
        printf("\n");
        printf(
            "ADD(A) DEL(D) ANS(S) EXIT(E)"
        );
        scanf(" %c", &vyber);

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

