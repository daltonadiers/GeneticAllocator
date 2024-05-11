#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>
#include <vector>
#include "professor.h"

class Disciplina {
public:
    Disciplina(const std::string& nome,std::vector<Professor>); // Construtor
    void adicionarProfessor(const Professor& professor); // Método para adicionar professor
    std::string nome;
    std::vector<Professor> professores;
};

#endif // DISCIPLINA_H
