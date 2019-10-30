#include "func.h"

using namespace std;

void criar_lista (queue<Professor> lista_professores, queue<Escola> lista_escolas){
string line;
    instream entrada;
    entrada.open ("Others/entradaProj3TAG.txt");
    getline(entrada,line);
    cout << line << '\n';
    entrada.close();

}
