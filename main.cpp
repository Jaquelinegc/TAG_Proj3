#include <iostream>
#include "func.h"

using namespace std;

int main()
{
    queue<Professor> lista_professores;
    queue<Escola> lista_escolas;

    criar_lista (queue<Professor> lista_professores, queue<Escola> lista_escolas);
    emparelhar (queue<Professor> lista_professores, queue<Escola> lista_escolas);
    imprimir_resultado (queue<Professor> lista_professores, queue<Escola> lista_escolas);

    return 0;
}
