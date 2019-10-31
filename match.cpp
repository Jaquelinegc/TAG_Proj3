#include "func.h"
using namespace std;

/*Roda o algoritmo proposto por Irving (baseado em Gale-Shapley) para preencher as vagas
percorrendo a lista de professores e priorizando a primeira vaga disponivel*/
void emparelhar (){
	/*Pilha para percorrer os professores passiveis de serem alocados*/
	stack<int> pilha;
	int i = qProfessores;
	/*Preenche a fila inicialmento com todos os professores*/
	while(i){
		pilha.push(i);
		i--;
	}
	/*Variaveis auxiliares*/
	int pref;
	list<Professor>::iterator prof, prof_aux;
	list<Escola>::iterator escola;
	/*Enquanto houver professores passiveis de serem alocados: */
	while(!pilha.empty())
	{
		/*Computa o professor e o remove o professor da pilha*/
		prof = lista_professores.begin();
		advance(prof, pilha.top() - 1);
		pilha.pop();
		/*Enquanto houver escolas na lista de preferencias do professor: */
		while(!prof->preferencias.empty()){
			/*Computa escola*/
			pref = prof->preferencias.front();
			escola = lista_escolas.begin();
			advance(escola, pref - 1);
			if(escola->pareamento.empty()){
			/*Aloca o professor caso a escola tenha a vaga_1*/
				escola->pareamento.push_front(prof->codigo);
				prof->preferencias.pop_front();
				break;
			}else if(escola->pareamento.size() < escola->habs_pretendida.size()){
			/*Aloca o professor caso a escola tenha a vaga_2*/
				escola->pareamento.push_back(prof->codigo);
				prof->preferencias.pop_front();
				break;
			}else{
			/*Se a escola estiver cheia: */
				prof_aux = lista_professores.begin();
				advance(prof_aux, escola->pareamento.front() - 1);
				if(prof_aux->habilitacoes < escola->habs_pretendida.front()
					&& prof->habilitacoes >= escola->habs_pretendida.front())
				{
				/*Verifica se a alocacao da vaga_1 pode ser otimizada pelo professor*/
					escola->pareamento.front() = prof->codigo;
					/*Caso haja troca de alocacao, o professor original
					eh adicionado a pilha novamente*/
					pilha.push(prof_aux->codigo);
					prof->preferencias.pop_front();
					break;
				}
				else if(escola->habs_pretendida.size()>1){
				/*Verifica se a alocacao da vaga_2 pode ser otimizada pelo professor*/
					prof_aux = lista_professores.begin();
					advance(prof_aux, escola->pareamento.back() - 1);
					if(prof_aux->habilitacoes < escola->habs_pretendida.back()
						&& prof->habilitacoes >= escola->habs_pretendida.back())
					{
						escola->pareamento.back() = prof->codigo;
						/*Caso haja troca de alocacao, o professor original
						eh adicionado a pilha novamente*/
						pilha.push(prof_aux->codigo);
						prof->preferencias.pop_front();
						break;
					}
				}
			}
			prof->preferencias.pop_front();
			/*Fim do loop das preferencias*/
		}
	/*Fim do loop da pilha*/
	}
/*Fim da funcao cria_lista();*/
}