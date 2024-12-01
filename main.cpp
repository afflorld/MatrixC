#include <stdio.h>
#include <time.h>
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
                    printf("%d ", matica[i][j] );
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
    static int poradie = 0;
    int zcislo = 0;
    int zakaz[1000];


    while(odkaz != NULL){
        printf("Matica #%d (%d x %d)\n", odkaz->poradie, odkaz->riadky, odkaz->stlpce);
        zakaz[odkaz->poradie] = odkaz->poradie;
        zcislo++;
        odkaz = odkaz->dalsia;
    }

    if(zcislo == 0){
        printf("Nemame maticu na pouzitie\n");
    }else{

        do{
            printf("Vyber maticu u ktorej chces scitat maticu:");
            scanf(" %d", &u);
        }while(zakaz[u] != u);

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

        zcislo = 0;
        for(int i = 0; i < 1000; i++){
            zakaz[i] = 0;
        }


        printf("Matice ktore mozes pricitat:\n");

        odkaz = prva;

        while (odkaz != NULL) {
            if((odkazU->riadky == odkaz->riadky) && (odkazU->stlpce == odkaz->stlpce)){ 
                printf("Matica #%d (%d x %d)\n", odkaz->poradie, odkaz->riadky, odkaz->stlpce);
                zakaz[odkaz->poradie] = odkaz->poradie;
                zcislo++;
            }

            odkaz = odkaz->dalsia;
        } 

        if(zcislo == 0){
            printf("Nemame maticu na pouzitie\n");
        }else{

            do{

                printf("Zadaj poradie matice v:");
                scanf(" %d", &v);
            }while(zakaz[v] != v);

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


            printf("u:\n");

            for(int i = 0; i < odkazU->riadky; i++){
                for(int j = 0; j < odkazU->stlpce; j++){
                    printf("%d ", odkazU->matica[i][j] );
                }
                printf("\n");
            }

            printf("v:\n");

            for(int i = 0; i < odkazV->riadky; i++){
                for(int j = 0; j < odkazV->stlpce; j++){
                    printf("%d ", odkazV->matica[i][j] );
                }
                printf("\n");
            }


            int** matica = (int**)malloc(riadky * sizeof(int*));
            for(int i = 0; i < riadky; i++){
                matica[i] = (int*)malloc(stlpce * sizeof(int));
            }

            cislo++;
            poradie = 100 + cislo;

            printf("Nova matica #%d\n", poradie);

            for(int i = 0; i < riadky; i++){
                for(int j = 0; j < stlpce; j++){
                    matica[i][j] = odkazV->matica[i][j] + odkazU->matica[i][j];
                    printf("%d ", matica[i][j]);
                }
                printf("\n");
            }


            save(matica, riadky, stlpce, &prva, poradie);

        }
    }

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
    static int poradie = 0;
    int zcislo = 0;
    int zakaz[1000];

    while(odkaz != NULL){
        printf("Matica #%d (%d x %d)\n", odkaz->poradie, odkaz->riadky, odkaz->stlpce);
        zakaz[odkaz->poradie] = odkaz->poradie;
        zcislo++;
        odkaz = odkaz->dalsia;
    }


    if(zcislo == 0){
        printf("Nemame maticu na pouzitie\n");
    }else{

        do{

            printf("Vyber maticu od ktorej chces odcitat:");
            scanf(" %d", &u);
        }while(zakaz[u] != u);
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
                printf("%d ", odkazU->matica[i][j] );
            }
            printf("\n");
        }

        zcislo =0;
        for(int i = 0; i < 1000; i++){
            zakaz[i] = 0;
        }

        printf("Matice ktore mozes odcitat:\n");

        odkaz = prva;

        while (odkaz != NULL) {
            if((odkazU->riadky == odkaz->riadky) && (odkazU->stlpce == odkaz->stlpce)){ 
                printf("Matica #%d (%d x %d)\n", odkaz->poradie, odkaz->riadky, odkaz->stlpce);
                zakaz[odkaz->poradie] = odkaz->poradie;
                zcislo++;
            }

            odkaz = odkaz->dalsia;
        } 

        if(zcislo == 0){
            printf("Nemame maticu na pouzitie\n");
        }else{

            do{
                printf("Zadaj poradie matice v:");
                scanf(" %d", &v);
            }while(zakaz[v] != v);

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


            printf("u:\n");

            for(int i = 0; i < odkazU->riadky; i++){
                for(int j = 0; j < odkazU->stlpce; j++){
                    printf("%d ", odkazU->matica[i][j] );
                }
                printf("\n");
            }

            printf("v:\n");

            for(int i = 0; i < odkazV->riadky; i++){
                for(int j = 0; j < odkazV->stlpce; j++){
                    printf("%d ", odkazV->matica[i][j] );
                }
                printf("\n");
            }


            int** matica = (int**)malloc(riadky * sizeof(int*));
            for(int i = 0; i < riadky; i++){
                matica[i] = (int*)malloc(stlpce * sizeof(int));
            }

            cislo++;
            poradie = 200 + cislo;
            printf("Nova matica #%d\n", poradie);

            for(int i = 0; i < riadky; i++){
                for(int j = 0; j < stlpce; j++){
                    matica[i][j] = odkazU->matica[i][j] - odkazV->matica[i][j];
                    printf("%d ", matica[i][j]);
                }
                printf("\n");
            }

            save(matica, riadky, stlpce, &prva, poradie);

        }
    }
}

void TRANS(){

    int u;
    int riadky;
    int stlpce;
    struct t_matica* odkaz = prva;
    struct t_matica* odkazU = prva;
    static int cislo = 0;
    static int poradie = 0;
    int zcislo = 0;
    int zakaz[1000];

    while(odkaz != NULL){
        printf("Matica #%d (%d x %d)\n", odkaz->poradie, odkaz->riadky, odkaz->stlpce);
        zakaz[odkaz->poradie] = odkaz->poradie;
        zcislo++;
        odkaz = odkaz->dalsia;
    }

    if(zcislo == 0){
        printf("Nemame maticu na pouzitie\n");
    }else{

        do{

            printf("Vyber maticu ktoru chces transponovat:");
            scanf(" %d", &u);

        }while(zakaz[u] != u);


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
                printf("%d ", odkazU->matica[i][j] );
            }
            printf("\n");
        }

        riadky = odkazU->stlpce;
        stlpce = odkazU->riadky;

        int** matica = (int**)malloc(riadky * sizeof(int*));
        for(int i = 0; i < riadky; i++){
            matica[i] = (int*)malloc(stlpce * sizeof(int));
        }

        cislo++;
        poradie = 300 + cislo;
        printf("Nova matica #%d\n", poradie);

        for(int i = 0; i < riadky; i++){
            for(int j = 0; j < stlpce; j++){
                matica[i][j] = odkazU->matica[j][i];
                printf("%d ", matica[i][j]);
            }
            printf("\n");
        }

        save(matica, riadky, stlpce, &prva, poradie);

    }
};


void MULT_I(){

    int u;
    int v;
    int riadky;
    int stlpce;
    struct t_matica* odkaz = prva;
    struct t_matica* odkazU = prva;
    static int cislo = 0;
    static int poradie = 0;
    int zcislo = 0;
    int zakaz[1000];

    while(odkaz != NULL){
        printf("Matica #%d (%d x %d)\n", odkaz->poradie, odkaz->riadky, odkaz->stlpce);
        zakaz[odkaz->poradie] = odkaz->poradie;
        zcislo++;
        odkaz = odkaz->dalsia;
    }

    if(zcislo == 0){
        printf("Nemame maticu na pouzitie\n");
    }else{

        do{
            printf("Vyber ktoru chces vynasobit cislom:");
            scanf(" %d", &u);
        }while(zakaz[u] != u);

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
                printf("%d ", odkazU->matica[i][j] );
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
        poradie = 400 + cislo;
        printf("Nova matica #%d\n", poradie);

        for(int i = 0; i < riadky; i++){
            for(int j = 0; j < stlpce; j++){
                matica[i][j] = odkazU->matica[i][j] * v;
                printf("%d ", matica[i][j]);
            }
            printf("\n");
        }

        save(matica, riadky, stlpce, &prva, poradie);

    }

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
    static int poradie = 0;
    int zcislo = 0;
    int zakaz[1000];

    while(odkaz != NULL){
        printf("Matica #%d (%d x %d)\n", odkaz->poradie, odkaz->riadky, odkaz->stlpce);
        zakaz[odkaz->poradie] = odkaz->poradie;
        zcislo++;
        odkaz = odkaz->dalsia;
    }

    if(zcislo == 0){
        printf("Nemame maticu na pouzitie\n");
    }else{

        do{

            printf("Vyber maticu ktoru chces roznasobit:");
            scanf(" %d", &u);
        }while(zakaz[u] != u);

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
                printf("%d ", odkazU->matica[i][j] );
            }
            printf("\n");
        }

        zcislo = 0;
        for(int i = 0; i < 1000; i++){
            zakaz[i] = 0;
        }


        printf("Maticu ktorou roznasobis: \n");

        odkaz = prva;

        while (odkaz != NULL) {
            if((odkazU->stlpce == odkaz->riadky) || (!(odkazU->stlpce == odkaz->stlpce) && !(odkazU->riadky == odkaz->riadky))){ 
                printf("Matica #%d (%d x %d)\n", odkaz->poradie, odkaz->riadky, odkaz->stlpce);
                zakaz[odkaz->poradie] = odkaz->poradie;
                zcislo++;
            }

            odkaz = odkaz->dalsia;
        } 

        if(zcislo == 0){
            printf("Nemame maticu na pouzitie\n");
            return;
        }else{

            do{
                printf("Zadaj poradie matice v:");
                scanf(" %d", &v);
            }while(zakaz[v] != v);

            odkazV = prva;

            while(odkazV != NULL){
                if(odkazV->poradie == v){
                    break;
                }
                odkazV = odkazV->dalsia;
            }


            riadky = odkazU->riadky;
            stlpce = odkazV->stlpce;


            printf("riadky: %d\n", riadky);
            printf("stlpce: %d\n", stlpce);


            printf("u:\n");

            for(int i = 0; i < odkazU->riadky; i++){
                for(int j = 0; j < odkazU->stlpce; j++){
                    printf("%d ", odkazU->matica[i][j] );
                }
                printf("\n");
            }

            printf("v:\n");

            for(int i = 0; i < odkazV->riadky; i++){
                for(int j = 0; j < odkazV->stlpce; j++){
                    printf("%d ", odkazV->matica[i][j] );
                }
                printf("\n");
            }


            int** matica = (int**)malloc(riadky * sizeof(int*));
            for(int i = 0; i < riadky; i++){
                matica[i] = (int*)malloc(stlpce * sizeof(int));
            }

            cislo++;
            poradie = 500 + cislo;
            printf("Nova matica #%d\n", poradie);

            for(int i = 0; i < riadky; i++){
                for(int j = 0; j < stlpce; j++){
                    for(int k = 0; k < odkazU->stlpce; k++){
                        matica[i][j] += odkazU->matica[i][k] * odkazV->matica[k][j];
                    }
                    printf("%d ", matica[i][j]);
                }
                printf("\n");
            }

            save(matica, riadky, stlpce, &prva, poradie);

        }
    }


};
void INV(){

    double det;
    int u;
    int riadky;
    int stlpce;
    struct t_matica* odkaz = prva;
    struct t_matica* odkazU = prva;
    static int cislo = 0;
    static int poradie = 0;
    double presnost = 0;
    int zcislo = 0;
    int zakaz[1000]; 

    printf("Len pre matice 2x2, 3x3, 4x4, 5x5\n");
    printf("Vyber si mieru presnosti:");
    scanf(" %lf", &presnost);

    printf("\n");

    while(odkaz != NULL){
        if((odkaz->riadky == 2 && odkaz->stlpce == 2) || (odkaz->riadky == 3 && odkaz->stlpce == 3) || (odkaz->riadky == 4 && odkaz->stlpce == 4) || (odkaz->riadky == 5 && odkaz->stlpce == 5)){
            printf("Matica #%d (%d x %d)\n", odkaz->poradie, odkaz->riadky, odkaz->stlpce);
            zakaz[odkaz->poradie] = odkaz->poradie;
            zcislo++;
        }
        odkaz = odkaz->dalsia;
    }

    if(zcislo == 0){
        printf("Nemame maticu na pouzitie\n");
        return;
    }else{

        do{
            printf("Vyber maticu ktoru chces inverznut:");
            scanf(" %d", &u);

        }while(zakaz[u] != u);

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
                printf("%d ", odkazU->matica[i][j] );
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

        if(odkazU->riadky == 2 && odkazU->stlpce == 2){

            inv[0][0] = mat[1][1];
            inv[0][1] = -mat[0][1];
            inv[1][0] = -mat[1][0];
            inv[1][1] = mat[0][0];

            det = mat[0][0] * inv[0][0] + mat[0][1] * inv[1][0];

            if(det == 0){
                printf("Nemozno inverznu maticu vytvorit\n");
            }else{

                for(int i = 0; i < riadky; i++){
                    for(int j = 0; j < stlpce; j++){
                        inv[i][j] /= det;
                        inv[i][j] *= presnost;
                    }
                }

                poradie = 600 + cislo;

                printf("Nova matica #%d:\n", poradie);

                for(int i = 0; i < 2; i++){
                    for(int j = 0; j < 2; j++){
                        matica[i][j] = int(inv[i][j]);
                        printf("%d ", matica[i][j]);
                    }

                    printf("\n");
                }

                save(matica, riadky, stlpce, &prva, poradie);

            }
        }
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
            }else{

                for(int i = 0; i < riadky; i++){
                    for(int j = 0; j < stlpce; j++){
                        inv[i][j] /= det;
                        inv[i][j] *= presnost;
                    }
                }

                poradie = 600 + cislo;

                printf("Nova matica #%d:\n", poradie);

                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        matica[i][j] = int(inv[i][j]);
                        printf("%d ", matica[i][j]);
                    }

                    printf("\n");
                }

                save(matica, riadky, stlpce, &prva, poradie);

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

                printf("Determinant je: %lf\n", det);

                if(det == 0){
                    printf("Nemozno inverznu maticu vytvorit\n");
                }else{


                    for (int i = 0; i < riadky; i++) {
                        for (int j = 0; j < stlpce; j++) {
                            double mmat[3][3];
                            int mmat_riadky = 0, mmat_stlpce;
                            for (int r = 0; r < 4; r++) {
                                if (r == i) continue;
                                mmat_stlpce = 0;
                                for (int c = 0; c < 4; c++) {
                                    if (c == j) continue;
                                    mmat[mmat_riadky][mmat_stlpce] = mat[r][c];
                                    mmat_stlpce++;
                                }
                                mmat_riadky++;
                            }

                            double mmat_det =
                                mmat[0][0] * (mmat[1][1] * mmat[2][2] - mmat[1][2] * mmat[2][1]) -
                                mmat[0][1] * (mmat[1][0] * mmat[2][2] - mmat[1][2] * mmat[2][0]) +
                                mmat[0][2] * (mmat[1][0] * mmat[2][1] - mmat[1][1] * mmat[2][0]);

                            inv[j][i] = ((i + j) % 2 == 0 ? 1 : -1) * mmat_det;
                        }
                    }


                    for (int i = 0; i < riadky; i++) {
                        for (int j = 0; j < stlpce; j++) {
                            inv[i][j] /= det;
                            inv[i][j] *= presnost;
                        }
                    }

                    poradie = 600 + cislo;

                    printf("Nova matica #%d:\n", poradie);

                    for (int i = 0; i < 4; i++) {
                        for (int j = 0; j < 4; j++) {
                            matica[i][j] = (int)(inv[i][j]);
                            printf("%d ", matica[i][j]);
                        }
                        printf("\n");
                    }

                    save(matica, riadky, stlpce, &prva, poradie);
                }
            }
            if(odkazU->riadky == 5 && odkazU->stlpce == 5){

                double nova[5][5];
                double mmat[4][4];

                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 5; j++) {
                        int mmat_riadky = 0;
                        for (int r = 0; r < 5; r++) {
                            if (r == i) continue;
                            int mmat_stlpce = 0;
                            for (int c = 0; c < 5; c++) {
                                if (c == j) continue;
                                mmat[mmat_riadky][mmat_stlpce] = mat[r][c];
                                mmat_stlpce++;
                            }
                            mmat_riadky++;
                        }


                        double mmat_det = 
                            mmat[0][0] * (mmat[1][1] * (mmat[2][2] * mmat[3][3] - mmat[2][3] * mmat[3][2])
                                    - mmat[1][2] * (mmat[2][1] * mmat[3][3] - mmat[2][3] * mmat[3][1])
                                    + mmat[1][3] * (mmat[2][1] * mmat[3][2] - mmat[2][2] * mmat[3][1]))
                            - mmat[0][1] * (mmat[1][0] * (mmat[2][2] * mmat[3][3] - mmat[2][3] * mmat[3][2])
                                    - mmat[1][2] * (mmat[2][0] * mmat[3][3] - mmat[2][3] * mmat[3][0])
                                    + mmat[1][3] * (mmat[2][0] * mmat[3][2] - mmat[2][2] * mmat[3][0]))
                            + mmat[0][2] * (mmat[1][0] * (mmat[2][1] * mmat[3][3] - mmat[2][3] * mmat[3][1])
                                    - mmat[1][1] * (mmat[2][0] * mmat[3][3] - mmat[2][3] * mmat[3][0])
                                    + mmat[1][3] * (mmat[2][0] * mmat[3][1] - mmat[2][1] * mmat[3][0]))
                            - mmat[0][3] * (mmat[1][0] * (mmat[2][1] * mmat[3][2] - mmat[2][2] * mmat[3][1])
                                    - mmat[1][1] * (mmat[2][0] * mmat[3][2] - mmat[2][2] * mmat[3][0])
                                    + mmat[1][2] * (mmat[2][0] * mmat[3][1] - mmat[2][1] * mmat[3][0]));

                        nova[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * mmat_det;

                    }
                }

                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 5; j++) {
                        inv[i][j] = nova[j][i];
                    }
                }

                det = 0.0;
                for (int i = 0; i < 5; i++) {
                    det += mat[0][i] * nova[0][i];
                }

                if (det == 0) {
                    printf("Nemozno inverznu maticu vytvorit\n");
                    return;
                }else{

                    for (int i = 0; i < 5; i++) {
                        for (int j = 0; j < 5; j++) {
                            inv[i][j] /= det;
                            inv[i][j] *= presnost;
                        }
                    }

                    poradie = 600 + cislo;
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
        }}
};
void DET(){

    double det;
    int u;
    int riadky;
    int stlpce;
    struct t_matica* odkaz = prva;
    struct t_matica* odkazU = prva;
    static int cislo = 0;
    int zcislo = 0;
    int zakaz[1000];

    printf("Len pre matice 2x2, 3x3, 4x4, 5x5\n");

    while(odkaz != NULL){
        if((odkaz->riadky == 2 && odkaz->stlpce == 2) || (odkaz->riadky == 3 && odkaz->stlpce == 3) || (odkaz->riadky == 4 && odkaz->stlpce == 4) || (odkaz->riadky == 5 && odkaz->stlpce == 5)){
            printf("Matica #%d (%d x %d)\n", odkaz->poradie, odkaz->riadky, odkaz->stlpce);
            zakaz[odkaz->poradie] = odkaz->poradie;
            zcislo++;
        }
        odkaz = odkaz->dalsia;
    }

    if(zcislo == 0){
        printf("Nemame maticu na pouzitie\n");
        return;
    }else{

        do{

            printf("Vyber maticu ktoru chces inverznut:");
            scanf(" %d", &u);

        }while(zakaz[u] != u);

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
                printf("%d ", odkazU->matica[i][j] );
            }
            printf("\n");
        }

        riadky = odkazU->riadky;
        stlpce = odkazU->stlpce;


        double mat[riadky][stlpce];

        for(int i = 0; i < riadky; i++){
            for(int j = 0; j < stlpce; j++){
                mat[i][j] = odkazU->matica[i][j];
            }
        }


        double inv[riadky][stlpce];

        if(odkazU->riadky == 2 && odkazU->stlpce == 2){

            inv[0][0] = mat[1][1];
            inv[0][1] = -mat[0][1];
            inv[1][0] = -mat[1][0];
            inv[1][1] = mat[0][0];

            det = mat[0][0] * inv[0][0] + mat[0][1] * inv[1][0];

            printf("Determinant je: %lf\n", det);

        }
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

            printf("Determinant je: %lf\n", det);

        }
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
            }else{ 
                printf("Determinant je: %lf\n", det);
            }    


        }
        if(odkazU->riadky == 5 && odkazU->stlpce == 5){

            double nova[5][5];
            double mmat[4][4];

            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    int mmat_riadky = 0;
                    for (int r = 0; r < 5; r++) {
                        if (r == i) continue;
                        int mmat_stlpce = 0;
                        for (int c = 0; c < 5; c++) {
                            if (c == j) continue;
                            mmat[mmat_riadky][mmat_stlpce] = mat[r][c];
                            mmat_stlpce++;
                        }
                        mmat_riadky++;
                    }


                    double mmat_det = 
                        mmat[0][0] * (mmat[1][1] * (mmat[2][2] * mmat[3][3] - mmat[2][3] * mmat[3][2])
                                - mmat[1][2] * (mmat[2][1] * mmat[3][3] - mmat[2][3] * mmat[3][1])
                                + mmat[1][3] * (mmat[2][1] * mmat[3][2] - mmat[2][2] * mmat[3][1]))
                        - mmat[0][1] * (mmat[1][0] * (mmat[2][2] * mmat[3][3] - mmat[2][3] * mmat[3][2])
                                - mmat[1][2] * (mmat[2][0] * mmat[3][3] - mmat[2][3] * mmat[3][0])
                                + mmat[1][3] * (mmat[2][0] * mmat[3][2] - mmat[2][2] * mmat[3][0]))
                        + mmat[0][2] * (mmat[1][0] * (mmat[2][1] * mmat[3][3] - mmat[2][3] * mmat[3][1])
                                - mmat[1][1] * (mmat[2][0] * mmat[3][3] - mmat[2][3] * mmat[3][0])
                                + mmat[1][3] * (mmat[2][0] * mmat[3][1] - mmat[2][1] * mmat[3][0]))
                        - mmat[0][3] * (mmat[1][0] * (mmat[2][1] * mmat[3][2] - mmat[2][2] * mmat[3][1])
                                - mmat[1][1] * (mmat[2][0] * mmat[3][2] - mmat[2][2] * mmat[3][0])
                                + mmat[1][2] * (mmat[2][0] * mmat[3][1] - mmat[2][1] * mmat[3][0]));

                    nova[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * mmat_det;

                }
            }

            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    inv[i][j] = nova[j][i];
                }
            }

            det = 0.0;
            for (int i = 0; i < 5; i++) {
                det += mat[0][i] * nova[0][i];
            }

            if (det == 0) {
                printf("Nemozno inverznu maticu vytvorit\n");
                return;
            }else{ 
                printf("Determinant je: %lf\n", det);
            }


        }
    }
};

void SAVE(){

    static int cislo = 0;
    static int poradie;
    struct t_matica* odkaz = prva;
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    poradie = cislo;
    FILE *fp = fopen("./history.txt", "a");

    fprintf(fp, "Historia ulozenia: %02d-%02d-%04d\n", tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);

    while (odkaz != NULL) {
        fprintf(fp, "Matica #%d (%d x %d)\n", odkaz->poradie, odkaz->riadky, odkaz->stlpce);
        for(int i = 0; i < odkaz->riadky; i++){
            for(int j = 0; j < odkaz->stlpce; j++){
                fprintf(fp, "%d ", odkaz->matica[i][j] );
            }
            fprintf(fp, "\n");
        } 
        odkaz = odkaz->dalsia;
    }

    cislo++;

    fclose(fp);

}

void ANS() {
    char vyber;
    struct t_matica* odkaz = prva;

    while (odkaz != NULL) {
        printf("Matica #%d (%d x %d)\n", odkaz->poradie, odkaz->riadky, odkaz->stlpce);
        odkaz = odkaz->dalsia;
    }


    do{
        printf("+(+) -(-) TRANS(T) MULT_I(A) MULT_M(B) INV(I) DET(D) SAVE(S) EXIT(E)");
        scanf(" %c", &vyber);

        switch(vyber){
            case '+':
                SUM();
                break;
            case '-':
                SUB();
                break;
            case 'T':
                TRANS();
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
            case 'S':
                SAVE();
                break;
            case 'E':
                break;
            default:
                printf("\nZadali ste zly znak\n");
                break;
        }
    }while(vyber != 'E');
}


void EXIT(){

    struct t_matica* odkaz = prva;

    while(odkaz != NULL){

        free(odkaz);
        odkaz = odkaz->dalsia;

    }

};

int main(){

    char vyber;
    system("clear");

    do{
        printf("ADD(A) DEL(D) ANS(S) EXIT(E):");
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
                EXIT();
                break;
            default:
                printf("\nZadali ste zly znak\n");
                break;
        }
    }while(vyber != 'E');

    return 0;

}

