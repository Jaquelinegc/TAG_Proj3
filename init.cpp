/*Incluir tools da biblioteca criada func.h*/
#include "func.h"
using namespace std;

/*Le arquivo de entrada e preenche as listas de adjacencias*/
void criar_lista (){
	/*variaveis auxiliares*/
	string line;
	char c;
	int i, pref;
	Professor prof;
	Escola escola;
	escola.pareamento.clear();
	/*Arquivo de entrada*/
	ifstream entrada ("entradaProj3TAG.txt");
	if (entrada.is_open())
	{
		/*Le os comentarios do arquivo de entrada*/
		getline(entrada, line);
		getline(entrada, line);
		getline(entrada, line);
		/*Le a parte dos professores do arquivo de entrada*/
		for (i = 0; i < qProfessores; ++i)
		{
			/*Reseta variavel auxiliar que representa um professor*/
			prof.preferencias.clear();
			/*Acha um digito e le o codigo do professor*/
			c = entrada.peek();
			while(!isdigit(c)){
				entrada.get(c);
				c = entrada.peek();
			}
			entrada >> prof.codigo;
			/*Acha um digito e le as habilitacoes do professor*/
			c = entrada.peek();
			while(!isdigit(c)){
				entrada.get(c);
				c = entrada.peek();
			}
			entrada >> prof.habilitacoes;
			/*Acha os proximos digitos e le as preferencias de escolas do professor*/
			while(c != '\n'){
				c = entrada.peek();
				if(isdigit(c)){
					entrada >> pref;
					prof.preferencias.push_back(pref);
				}
				entrada.get(c);
			}
			/*Adiciona o professor armazenado na variavel auxiliar 'prof' na lista de adjacencias*/
			lista_professores.push_back(prof);
		}
		/*Le os comentarios do arquivo de entrada*/
		getline(entrada, line);
		getline(entrada, line);
		getline(entrada, line);
		/*Le a parte das escolar do arquivo de entrada*/
		for (i = 0; i < qEscolas; ++i)
		{
			/*Reseta variavel auxiliar que representa uma escola*/
			escola.habs_pretendida.clear();
			/*Acha um digito e le o codigo da escola*/
			c = entrada.peek();
			while(!isdigit(c)){
				entrada.get(c);
				c = entrada.peek();
			}
			/*Acha os proximos digitos e le as habilitacoes pretendidas pela escola*/
			entrada >> escola.codigo;
			while(c != '\n'){
				c = entrada.peek();
				if(isdigit(c)){
					entrada >> pref;
					escola.habs_pretendida.push_back(pref);
				}
				entrada.get(c);
			}
			/*Adiciona o escola armazenado na variavel auxiliar 'escola' na lista de adjacencias*/
			lista_escolas.push_back(escola);
		}

	}
	/*Termina de ler o arquivo de entrada e fecha o arquivo*/
	entrada.close();
}
