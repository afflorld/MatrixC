#pragma once

struct t_matica {

    int riadky;
    int stlpce;
    int** matica;
    int poradie;

    struct t_matica* dalsia;

};

void save(int** matica, int riadky, int stlpce, struct t_matica** uk_prva, int poradie);

