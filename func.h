#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
#include <iostream>
#include <queue>
#include <fstream>
#include <string>

using namespace std;

typedef struct professor {
    int codigo; //qual o codigo do professor
    int habilitacoes; //qual a habilitacao do professor
    queue<int> preferencias; // a preferencia eh a respeito de qual escola ele prefere
    int pareamento;
}Professor;

typedef struct escola {
    int codigo; //qual o codigo da escola
    queue<int> habilitacoes_pretendida; //a preferencia eh a respeito de qual habilitacao do professor
    queue<int> pareamento;
}Escola;

void criar_lista (queue<Professor> lista_professores, queue<Escola> lista_escolas);
void emparelhar (queue<Professor> lista_professores, queue<Escola> lista_escolas);
void imprimir_resultado (queue<Professor> lista_professores, queue<Escola> lista_escolas);


#endif // FUNC_H_INCLUDED
