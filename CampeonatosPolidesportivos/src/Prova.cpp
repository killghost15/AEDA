#include "Prova.h"



Prova::Prova(string name, int day, int month, int year){
	nome = name;
	dia = day;
	mes = month;
	ano = year;
}


string Prova::getNome() const {
	return nome;
}


int Prova::getAno() const {
	return ano;
}


int Prova::getMes() const {
	return mes;
}


int Prova::getDia() const {
	return dia;
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


void Prova::setModalidade(Modalidade *mod) {
	modalidade = mod;
}


void Prova::setInfrastrutura(Infrastrutura *infra) {
	infrastrutura = infra;
}



