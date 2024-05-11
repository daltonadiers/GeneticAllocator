#include <iostream>
#include <vector>
#include "cabecalhos/cromossomo.h"
#include "cabecalhos/professor.h"
#include "cabecalhos/disciplina.h"
#include "cabecalhos/sala.h"

class Filler{
public:
    Filler(std::vector<Professor> &p, std::vector<Disciplina> &d, std::vector<Sala> &s){
        p.push_back(Professor("Carlos"));
        p.push_back(Professor("Amaral"));
        p.push_back(Professor("Ana"));
        p.push_back(Professor("Antonio"));
        p.push_back(Professor("Trentin"));
        p.push_back(Professor("Teixeira"));
        p.push_back(Professor("José"));
        p.push_back(Professor("Marcos"));
        d.push_back(Disciplina("IA", std::vector<Professor>{p[0], p[2]}));
        d.push_back(Disciplina("Cibercultura", std::vector<Professor>{p[5]}));
        d.push_back(Disciplina("Banco de dados", std::vector<Professor>{p[1],p[5],p[4]}));
        d.push_back(Disciplina("Banco de dados 2", std::vector<Professor>{p[1],p[5],p[4]}));
        d.push_back(Disciplina("Engenharia de Software", std::vector<Professor>{p[2],p[3],p[0]}));
        d.push_back(Disciplina("Estrutura de dados", std::vector<Professor>{p[5], p[6]}));
        s.push_back(Sala(1,20));
        s.push_back(Sala(2,30));
        s.push_back(Sala(3,70));
        s.push_back(Sala(4,40));
        s.push_back(Sala(5,25));
        s.push_back(Sala(6,32));
    }
    
};
