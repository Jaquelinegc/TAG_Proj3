#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
/*bibliotecas necessarias*/
#include <list>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iterator>
#include <stack>

/*Constantes globais das quantidades dadas de professores e escolas*/
#define qProfessores 100
#define qEscolas 50

using namespace std;

/*Tipo Professor*/
typedef struct professor {
    int codigo; //qual o codigo do professor
    int habilitacoes; //qual a habilitacao do professor
    list<int> preferencias; // a preferencia eh a respeito de qual escola ele prefere
}Professor;

/*Tipo Escola*/
typedef struct escola {
    int codigo; //qual o codigo da escola
    list<int> habs_pretendida; //a preferencia eh a respeito de qual habilitacao do professor
    list<int> pareamento;
}Escola;

/*Listas de adjacencia declaradas de forma GLOBAL*/
extern list<Professor> lista_professores;
extern list<Escola> lista_escolas;

/*Declaracao das funcoes usadas na main e implementas em arquivos auxiliares*/


/*Le arquivo de entrada e preenche as listas de adjacencias*/
void criar_lista();/*implementada em init.cpp*/
/*Roda o algoritmo proposto por Irving (baseado em Gale-Shapley) para preencher as vagas
percorrendo a lista de professores e priorizando a primeira vaga disponivel*/
void emparelhar();/*implementada em match.cpp*/
/*Mostra na linha de comando os emparelhamentos obtidos e a quantidade
de professores que puderam ser alocados de forma estavel*/
void imprimir_resultado();/*implementada em show.cpp*/

#endif // FUNC_H_INCLUDED
