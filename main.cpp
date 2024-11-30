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
    static int poradie = 0;

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

    printf("Vyber maticu u ktorej chces scitat maticu:");
    scanf(" %d", &u);

    odkazU = prva;

    while(odkazU != NULL){
        if(odkazU->poradie == u){
            break;
        }
        odkazU = odkazU->dalsia;
    }

    printf("Vybral si u:\n");

    for(int i = 0; i < odkazU->riadky; i++){
        for(int j = 0; j < odkazU->stlpce; j++){
            printf("%d", odkazU->matica[i][j] );
        }
        printf("\n");
    }

    printf("Matice ktore mozes pricitat:\n");

    odkaz = prva;

    while (odkaz != NULL) {
        if((odkazU->riadky == odkaz->riadky) && (odkazU->stlpce == odkaz->stlpce)){ 
            printf("Matrix #%d (%d x %d)\n", odkaz->poradie, odkaz->riadky, odkaz->stlpce);
        }

        odkaz = odkaz->dalsia;
    } 

    do{
    
    printf("Zadaj poradie matice v:");
    scanf(" %d", &v);

    odkazV = prva;

    while(odkazV != NULL){
        if(odkazV->poradie == v){
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
    static int poradie = 100 + cislo;
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

    int u;
    int v;
    int riadky;
    int stlpce;
    struct t_matica* odkaz = prva;
    struct t_matica* odkazU = prva;
    struct t_matica* odkazV = prva;
    static int cislo = 0;

    printf("Vyber maticu od ktorej chces odcitat:");
    scanf(" %d", &u);

    odkazU = prva;

    while(odkazU != NULL){
        if(odkazU->poradie == u){
            break;
        }
        odkazU = odkazU->dalsia;
    }

    printf("Vybral si u:\n");

    for(int i = 0; i < odkazU->riadky; i++){
        for(int j = 0; j < odkazU->stlpce; j++){
            printf("%d", odkazU->matica[i][j] );
        }
        printf("\n");
    }

    printf("Matice ktore mozes odcitat:\n");

    odkaz = prva;

    while (odkaz != NULL) {
        if((odkazU->riadky == odkaz->riadky) && (odkazU->stlpce == odkaz->stlpce)){ 
            printf("Matrix #%d (%d x %d)\n", odkaz->poradie, odkaz->riadky, odkaz->stlpce);
        }

        odkaz = odkaz->dalsia;
    } 

    do{
    
    printf("Zadaj poradie matice v:");
    scanf(" %d", &v);

    odkazV = prva;

    while(odkazV != NULL){
        if(odkazV->poradie == v){
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
    static int poradie = 100 + cislo;
    printf("Nova matica #%d\n", poradie);

    for(int i = 0; i < riadky; i++){
        for(int j = 0; j < stlpce; j++){
           matica[i][j] = odkazV->matica[i][j] - odkazU->matica[i][j];
           printf("%d", matica[i][j]);
        }
        printf("\n");
    }

    save(matica, riadky, stlpce, &prva, poradie);

    }


void MULT_I(){



};

void MULT_M(){



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
        printf("+(+) -(-) MULT_I(A) MULT_M(B) INV(I) DET(D) GAUS(G) EXIT(E)");
        scanf(" %c", &vyber);

        switch(vyber){
            case '+':
                SUM();
                break;
            case '-':
                SUB();
                break;
            case 'A':
                MULT_I();
                break;
            case 'B':
                MULT_M();
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

