#include "func.h"
using namespace std;

/*Mostra na linha de comando os emparelhamentos obtidos e a quantidade
de professores que puderam ser alocados de forma estavel*/
void imprimir_resultado (){
	/*Variaveis auxiliares*/
	int stable_profs = 0;/*contador para professores alocados de forma estavel*/
	list<Escola>::iterator escola;
	escola = lista_escolas.begin();
	cout<<"----- EMPARELHAMENTOS ------"<<endl;
	/*Percorre a lista de escolas*/
	while(escola != lista_escolas.end()){
		/*Imprime o emparelhamento da primeira vaga*/
		cout << 'E' << escola->codigo << ' ' << 'P' <<escola->pareamento.front();
		stable_profs++;
		/*Imprime o emparelhamento da segunda vaga case ela exista*/
		if(escola->pareamento.size()>1){
			cout << ' ' << 'P' << escola->pareamento.back();
			stable_profs++;
		}
		escola++;
		cout << endl;
	}
	/*Imprime a quantidade de professores alocados de forma estavel*/
	cout<< "--------------------------------------------------" <<endl;
	cout<<"QUATIDADE DE PROFS ALOCADOS DE FORMA ESTAVEL: "<<stable_profs<<endl;
	cout<< "--------------------------------------------------" <<endl;
}
