#include <stdio.h>
#include <stdlib.h>
#include "h/matrixDB.h"
struct t_matica* prva = NULL;

void ADD(){

    int stlpce;
    int riadky;
    printf("Zadaj aka velka je matica:\n");
    printf("Riadky:");
    scanf("%d", &riadky);
    printf("\nStlpce:");
    scanf("%d", &stlpce);
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
    static int poradie = 200 + cislo;
    printf("Nova matica #%d\n", poradie);

    for(int i = 0; i < riadky; i++){
        for(int j = 0; j < stlpce; j++){
            matica[i][j] = odkazU->matica[i][j] - odkazV->matica[i][j];
            printf("%d", matica[i][j]);
        }
        printf("\n");
    }

    save(matica, riadky, stlpce, &prva, poradie);

}


void MULT_I(){

    int u;
    int v;
    int riadky;
    int stlpce;
    struct t_matica* odkaz = prva;
    struct t_matica* odkazU = prva;
    static int cislo = 0;

    printf("Vyber ktoru chces vynasobit cislom:");
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

    printf("Zadaj nasobok:");
    scanf(" %d", &v);

    riadky = odkazU->riadky;
    stlpce = odkazU->stlpce;

    int** matica = (int**)malloc(riadky * sizeof(int*));
    for(int i = 0; i < riadky; i++){
        matica[i] = (int*)malloc(stlpce * sizeof(int));
    }

    cislo++;
    static int poradie = 300 + cislo;
    printf("Nova matica #%d\n", poradie);

    for(int i = 0; i < riadky; i++){
        for(int j = 0; j < stlpce; j++){
            matica[i][j] = odkazU->matica[i][j] * v;
            printf("%d", matica[i][j]);
        }
        printf("\n");
    }

    save(matica, riadky, stlpce, &prva, poradie);

};

void MULT_M(){

    int u;
    int v;
    int riadky;
    int stlpce;
    struct t_matica* odkaz = prva;
    struct t_matica* odkazU = prva;
    struct t_matica* odkazV = prva;
    static int cislo = 0;

    printf("Vyber maticu ktoru chces roznasobit:");
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

    printf("Maticu ktorou roznasobis: :\n");

    odkaz = prva;

    while (odkaz != NULL) {
        if((odkazU->stlpce == odkaz->riadky) || (!(odkazU->stlpce == odkaz->stlpce) && !(odkazU->riadky == odkaz->riadky))){ 
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


        riadky = odkazU->riadky;
        stlpce = odkazV->stlpce;


    }while((odkazU->riadky == odkazV->riadky) && (odkazU->stlpce == odkazV->stlpce));

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
    static int poradie = 400 + cislo;
    printf("Nova matica #%d\n", poradie);

    for(int i = 0; i < riadky; i++){
        for(int j = 0; j < stlpce; j++){
            for(int k = 0; k < odkazU->stlpce; k++){
                matica[i][j] += odkazU->matica[i][k] * odkazV->matica[k][j];
                printf("%d", matica[i][j]);
            }
        }
        printf("\n");
    }

    save(matica, riadky, stlpce, &prva, poradie);

};
void INV(){

    double det;
    int u;
    int riadky;
    int stlpce;
    struct t_matica* odkaz = prva;
    struct t_matica* odkazU = prva;
    static int cislo = 0;

    printf("Vyber maticu ktoru chces inversnut:");
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

    riadky = odkazU->riadky;
    stlpce = odkazU->stlpce;

    int** matica = (int**)malloc(riadky * sizeof(int*));
    for(int i = 0; i < riadky; i++){
        matica[i] = (int*)malloc(stlpce * sizeof(int));
    }

    double mat[riadky][stlpce];

    for(int i = 0; i < riadky; i++){
        for(int j = 0; j < stlpce; j++){
            mat[i][j] = odkazU->matica[i][j];
        }
    }


    double inv[riadky][stlpce];

    if(odkazU->riadky == 3 && odkazU->stlpce == 3){

        inv[0][0] = mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1];
        inv[0][1] = mat[0][2] * mat[2][1] - mat[0][1] * mat[2][2];
        inv[0][2] = mat[0][1] * mat[1][2] - mat[0][2] * mat[1][1];

        inv[1][0] = mat[1][2] * mat[2][0] - mat[1][0] * mat[2][2];
        inv[1][1] = mat[0][0] * mat[2][2] - mat[0][2] * mat[2][0];
        inv[1][2] = mat[0][2] * mat[1][0] - mat[0][0] * mat[1][2];

        inv[2][0] = mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0];
        inv[2][1] = mat[0][1] * mat[2][0] - mat[0][0] * mat[2][1];
        inv[2][2] = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];

        det = mat[0][0] * inv[0][0] + mat[0][1] * inv[1][0] + mat[0][2] * inv[2][0];

        if(det == 0){
            printf("Nemozno inverznu maticu vytvorit\n");
        }

        for(int i = 0; i < riadky; i++){
            for(int j = 0; j < stlpce; j++){
                inv[i][j] /= det;
                inv[i][j] *= 100;
            }
        }

        static int poradie = 500 + cislo;

        printf("Nova matica #%d:\n", poradie);

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                matica[i][j] = int(inv[i][j]);
                printf("%d", matica[i][j]);
            }

            printf("\n");
        }
    }else{
        if(odkazU->riadky == 4 && odkazU->stlpce == 4){

            inv[0][0] = mat[1][1] * mat[2][2] * mat[3][3] -
                mat[1][1] * mat[2][3] * mat[3][2] -
                mat[2][1] * mat[1][2] * mat[3][3] +
                mat[2][1] * mat[1][3] * mat[3][2] +
                mat[3][1] * mat[1][2] * mat[2][3] -
                mat[3][1] * mat[1][3] * mat[2][2];

            inv[0][1] = -mat[0][1] * mat[2][2] * mat[3][3] +
                mat[0][1] * mat[2][3] * mat[3][2] +
                mat[2][1] * mat[0][2] * mat[3][3] -
                mat[2][1] * mat[0][3] * mat[3][2] -
                mat[3][1] * mat[0][2] * mat[2][3] +
                mat[3][1] * mat[0][3] * mat[2][2];

            inv[0][2] = mat[0][1] * mat[1][2] * mat[3][3] -
                mat[0][1] * mat[1][3] * mat[3][2] -
                mat[1][1] * mat[0][2] * mat[3][3] +
                mat[1][1] * mat[0][3] * mat[3][2] +
                mat[3][1] * mat[0][2] * mat[1][3] -
                mat[3][1] * mat[0][3] * mat[1][2];

            inv[0][3] = -mat[0][1] * mat[1][2] * mat[2][3] +
                mat[0][1] * mat[1][3] * mat[2][2] +
                mat[1][1] * mat[0][2] * mat[2][3] -
                mat[1][1] * mat[0][3] * mat[2][2] -
                mat[2][1] * mat[0][2] * mat[1][3] +
                mat[2][1] * mat[0][3] * mat[1][2];

            det = mat[0][0] * inv[0][0] +
                mat[0][1] * inv[0][1] +
                mat[0][2] * inv[0][2] +
                mat[0][3] * inv[0][3];

            if(det == 0){
                printf("Nemozno inverznu maticu vytvorit\n");
            }


            for (int i = 0; i < riadky; i++) {
                for (int j = 0; j < stlpce; j++) {
                    double minor[3][3];
                    int minor_row = 0, minor_col;
                    for (int r = 0; r < 4; r++) {
                        if (r == i) continue;
                        minor_col = 0;
                        for (int c = 0; c < 4; c++) {
                            if (c == j) continue;
                            minor[minor_row][minor_col] = mat[r][c];
                            minor_col++;
                        }
                        minor_row++;
                    }

                    double minor_det =
                        minor[0][0] * (minor[1][1] * minor[2][2] - minor[1][2] * minor[2][1]) -
                        minor[0][1] * (minor[1][0] * minor[2][2] - minor[1][2] * minor[2][0]) +
                        minor[0][2] * (minor[1][0] * minor[2][1] - minor[1][1] * minor[2][0]);

                    inv[j][i] = ((i + j) % 2 == 0 ? 1 : -1) * minor_det;
                }
            }

            for (int i = 0; i < riadky; i++) {
                for (int j = 0; j < stlpce; j++) {
                    inv[i][j] /= det;
                    inv[i][j] *= 100;
                }
            }

            static int poradie = 500 + cislo;

            printf("Nova matica #%d:\n", poradie);

            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    matica[i][j] = (int)(inv[i][j]);
                    printf("%d", matica[i][j]);
                }
                printf("\n");
            }

            save(matica, riadky, stlpce, &prva, poradie);

        }
        if(odkazU->riadky == 5 && odkazU->stlpce == 5){
            
            double cofactors[5][5];
            double minor[4][4];

            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    int minor_row = 0;
                    for (int r = 0; r < 5; r++) {
                        if (r == i) continue;
                        int minor_col = 0;
                        for (int c = 0; c < 5; c++) {
                            if (c == j) continue;
                            minor[minor_row][minor_col] = mat[r][c];
                            minor_col++;
                        }
                        minor_row++;
                    }

                    double minor_det = 
                        minor[0][0] * (minor[1][1] * (minor[2][2] * minor[3][3] - minor[2][3] * minor[3][2])
                                - minor[1][2] * (minor[2][1] * minor[3][3] - minor[2][3] * minor[3][1])
                                + minor[1][3] * (minor[2][1] * minor[3][2] - minor[2][2] * minor[3][1]))
                        - minor[0][1] * (minor[1][0] * (minor[2][2] * minor[3][3] - minor[2][3] * minor[3][2])
                                - minor[1][2] * (minor[2][0] * minor[3][3] - minor[2][3] * minor[3][0])
                                + minor[1][3] * (minor[2][0] * minor[3][2] - minor[2][2] * minor[3][0]))
                        + minor[0][2] * (minor[1][0] * (minor[2][1] * minor[3][3] - minor[2][3] * minor[3][1])
                                - minor[1][1] * (minor[2][0] * minor[3][3] - minor[2][3] * minor[3][0])
                                + minor[1][3] * (minor[2][0] * minor[3][1] - minor[2][1] * minor[3][0]))
                        - minor[0][3] * (minor[1][0] * (minor[2][1] * minor[3][2] - minor[2][2] * minor[3][1])
                                - minor[1][1] * (minor[2][0] * minor[3][2] - minor[2][2] * minor[3][0])
                                + minor[1][2] * (minor[2][0] * minor[3][1] - minor[2][1] * minor[3][0]));

                    cofactors[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * minor_det;
                }
            }

            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    inv[i][j] = cofactors[j][i];
                }
            }

            det = 0.0;
            for (int i = 0; i < 5; i++) {
                det += mat[0][i] * cofactors[0][i];
            }

            if (det == 0) {
                printf("Nemozno inverznu maticu vytvorit\n");
                return;
            }

            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    inv[i][j] /= det;
                    inv[i][j] *= 100;
                }
            }

            static int poradie = 500 + cislo;
            printf("Nova matica #%d:\n", poradie);

            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    matica[i][j] = (int)(inv[i][j]);
                    printf("%d ", matica[i][j]);
                }
                printf("\n");
            }

            save(matica, riadky, stlpce, &prva, poradie);

        }
    }
};
void DET(){


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

