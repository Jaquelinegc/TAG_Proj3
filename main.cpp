/*Incluir tools da biblioteca criada func.h*/
#include "func.h"
using namespace std;

/*Listas de adjacencias, declaradas de forma GLOBAL*/
list<Professor> lista_professores;
list<Escola> lista_escolas;

int main()
{
	/*Le arquivo de entrada e preenche as listas de adjacencias*/
    criar_lista();
    /*Roda o algoritmo proposto por Irving (baseado em Gale-Shapley) para preencher as vagas
    percorrendo a lista de professores e priorizando a primeira vaga disponivel*/
    emparelhar();
    /*Mostra na linha de comando os emparelhamentos obtidos e a quantidade
    de professores que puderam ser alocados de forma estavel*/
    imprimir_resultado();

    return 0;
}
