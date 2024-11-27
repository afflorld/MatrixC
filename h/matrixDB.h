#pragma once

struct t_matica {

    int riadky;
    int stlpce;
    int** matica;
    char poradie;

    struct t_matica* dalsia;

};

void save(int** matica, int riadky, int stlpce, struct t_matica** uk_prva, char poradie);

