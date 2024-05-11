#ifndef CROMOSSOMO_H
#define CROMOSSOMO_H

#include <string>
#include <vector>
#include "professor.h"
#include "disciplina.h"
#include "sala.h"
#include "gen.h"

class Cromossomo{
    public:
        Cromossomo(int nd);
        std::vector<Gen> cromo;
};

#endif