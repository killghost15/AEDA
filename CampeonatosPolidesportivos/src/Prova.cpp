#include "Prova.h"


vector<int> Prova::getClassificacoes(){
	return classificacao;
}

void Prova::pushClassifica(int num){
	classificacao.push_back(num);
}
Prova::Prova(string name, int day, int month, int year){
	nome= name;
	dia=day;
	mes=month;
	ano=year;
	infrastrutura="vazio";
}
