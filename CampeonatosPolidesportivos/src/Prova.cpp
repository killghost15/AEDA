#include "Prova.h"



Prova::Prova(string name){
	nome = name;
}


string Prova::getNome() const {
	return nome;
}

Data* Prova::getData() {
	return data;
}

Modalidade* Prova::getModalidade() {
	return modalidade;
}


map<Atleta*, int> Prova::getClassificacoesAtletas(){
	return classificacoes_atletas;
}


Infrastrutura* Prova::getInfrastrutura() {
	return infrastrutura;
}


void Prova::setData(Data *date) {
	data = date;
}


void Prova::setModalidade(Modalidade *mod) {
	modalidade = mod;
}


void Prova::setInfrastrutura(Infrastrutura *infra) {
	infrastrutura = infra;
}


void Prova::setClassificacoesAtletas(map<Atleta*, int> map) {
	classificacoes_atletas = map;
}



