/* Projeto desenvolvido para a disciplina de Inteligência Artificial - Universidade de Passo Fundo
 * @author Dalton Oberdan Adiers
 * @brief Esse projeto visa simular alocação de professores, salas e disciplinas, sem maiores conflitos
 * utilizando de algoritmo genético;
 */
#include "cabecalhos/cromossomo.h"
#include "filler.cpp"
#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

default_random_engine generator(std::random_device{}());
vector<Professor> professores;
vector<Sala> salas;
vector<Disciplina> disciplinas;
vector<pair<Cromossomo, int>> cromos;
size_t sdisc;

int fitness(Cromossomo &cromo){
    int nclonfitos = 0;
    size_t cromoSize = cromo.cromo.size();
    for(size_t i=0; i<cromoSize-1; i++){
        string name = cromo.cromo[i].professor.nome;
        int nsala = cromo.cromo[i].sala.numero;
        for(size_t j = i+1; j<cromoSize; j++){
            if(cromo.cromo[j].professor.nome==name || cromo.cromo[j].sala.numero==nsala)nclonfitos++;
        }
    }
    return nclonfitos;
}


bool cromo_isValid(Gen &newGen, int dis){
    bool foundProfessor = false;
    for(auto &e:disciplinas[dis].professores){
        if(newGen.professor.nome == e.nome)foundProfessor=true;
    }
    return foundProfessor;
}

void firstPopulation(int &pi){
    size_t sprof = professores.size();
    size_t ssalas = salas.size();
    for(int i=0; i<pi; i++){
        
        Cromossomo novo((int)sdisc);
        
        for(size_t j=0; j<sdisc; j++){
            uniform_int_distribution<int> distribution1(0,sprof-1);
            novo.cromo[j].professor = professores[distribution1(generator)];
            uniform_int_distribution<int> distribution2(0,ssalas-1);
            novo.cromo[j].sala = salas[distribution2(generator)];
            if( !cromo_isValid(novo.cromo[j], j))j--;
        }
        cromos.push_back({novo, fitness(novo)});
    }
}

void debugger(){
    cout << "Eu sou o número de cromossomos: " << cromos.size() << "\n";
    for(auto &e:cromos){
        cout << "\n\nCROMOSSOMO:\n";
        for(int i=0; i<(int)disciplinas.size();i++){
            cout << "Professor: " << e.first.cromo[i].professor.nome << " Sala: " <<  e.first.cromo[i].sala.numero << " Número de conflitos: " << e.second << "\n";
        }
    }
}
vector<Cromossomo> cross(Cromossomo &dad, Cromossomo &mom){
    int sizeofcromo =dad.cromo.size();
    std::uniform_int_distribution<int> dis(0, sizeofcromo-1);
    int pontoDeCorte = dis(generator);
    Cromossomo filho1(sizeofcromo), filho2(sizeofcromo);
    for (int i = 0; i < pontoDeCorte; ++i) {
        filho1.cromo[i]=dad.cromo[i];
        filho2.cromo[i]=mom.cromo[i];
    }
    for (int i = pontoDeCorte; i < dad.cromo.size(); ++i) {
        filho1.cromo[i]=mom.cromo[i];
        filho2.cromo[i]=dad.cromo[i];
    }
    bool f1=true, f2=true;
    for(size_t i=0; i<filho1.cromo.size();i++){
        if(!cromo_isValid(filho1.cromo[i], i))f1=false;
    }
    for(size_t i=0; i<filho2.cromo.size();i++){
        if(!cromo_isValid(filho2.cromo[i], i))f2=false;
    }
    vector<Cromossomo> crossed;
    if(f1)crossed.push_back(filho1);
    if(f2)crossed.push_back(filho2);
    return crossed;
}
Cromossomo mutator(Cromossomo mutar){
    size_t sizeOfCromo = mutar.cromo.size();
    for(size_t i =0; i<sizeOfCromo; i++){
        std::uniform_int_distribution<int> dis(0, 1);
        int numeroAleatorio = dis(generator);
        int numeroAleatorio2 = dis(generator);
        if(numeroAleatorio){
            uniform_int_distribution<int> distribution1(0,professores.size()-1);
            mutar.cromo[i].professor = professores[distribution1(generator)];
        }
        if(numeroAleatorio2){
            uniform_int_distribution<int> distribution2(0,salas.size()-1);
            mutar.cromo[i].sala = salas[distribution2(generator)];
        }
        if(!cromo_isValid(mutar.cromo[i], i))i--;
    }
    return mutar;
}

void newGeneration(int &tc, int &tm){
    vector<Cromossomo> cr;
    std::uniform_int_distribution<int> dis(0, 100);
    //PROCESSO DE SELEÇÃO PARA CROSSOVER
    for(size_t i=0; i<cromos.size(); i++){
        int numeroAleatorio = dis(generator);
        if(tc<numeroAleatorio)cr.push_back(cromos[i].first);
    }
    for (size_t i = 0; i + 1 < cr.size(); i += 2) {
        vector<Cromossomo> posCross = cross(cr[i], cr[i+1]);
        for(auto &e:posCross)cromos.push_back({e, fitness(e)});
    }
    cr.clear();
    //PROCESSO DE SELEÇÃO PARA MUTAÇÃO
    for(size_t i=0; i<cromos.size(); i++){
        int numeroAleatorio = dis(generator);
        if(tm<numeroAleatorio){
            Cromossomo cm = mutator(cromos[i].first);
            cromos.push_back({cm, fitness(cm)});
        }
    }
}
void eliminator(int &max){
    sort(cromos.begin(), cromos.end(), [](const std::pair<Cromossomo, int>& a, const std::pair<Cromossomo, int>& b) {
        return a.second < b.second;
    });
    if(cromos.size()>max){
        cromos.erase(cromos.begin() + max, cromos.end());
    }
}

int main(int argc, char* argv[]){
    if(argc!=6){
        cout << "Uso indevido de argumentos!\n";
        return -1;
    }
    int populacao_inicial = stoi(argv[1]);
    int num_geracoes = stoi(argv[2]);
    int taxa_crossover = stoi(argv[3]);
    int taxa_mutacao = stoi(argv[4]);
    int max_population = stoi(argv[5]);
    Filler Filler(professores, disciplinas, salas);
    sdisc=disciplinas.size();
    firstPopulation(populacao_inicial);
    while(num_geracoes--){
        newGeneration(taxa_crossover, taxa_mutacao);
        eliminator(max_population);
    }
    sort(cromos.begin(), cromos.end(), [](const std::pair<Cromossomo, int>& a, const std::pair<Cromossomo, int>& b) {
        return a.second < b.second;
    });
    cout << "Terminamos a execução, cromossomos encontrados: \n";
    debugger();
    return 0;
}