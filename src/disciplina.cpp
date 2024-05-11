#include "cabecalhos/disciplina.h"

// Implementação do construtor
Disciplina::Disciplina(const std::string& nome, std::vector<Professor> pd) : nome(nome) {
    for(auto &e:pd)Disciplina::adicionarProfessor(e);
}

// Implementação do método para adicionar professor
void Disciplina::adicionarProfessor(const Professor& professor) {
    professores.push_back(professor);
}


