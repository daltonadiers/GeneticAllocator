#ifndef GEN_H
#define GEN_H

#include <string>
#include <vector>
#include "professor.h"
#include "disciplina.h"
#include "sala.h"

class Gen{
    public:
        Gen();
        Gen(Professor, Sala);
        Professor getProfessor();
        Professor setNome();
        Sala getSala();
        Professor professor;
        Sala sala;
};


#endif