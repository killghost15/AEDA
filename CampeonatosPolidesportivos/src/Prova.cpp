#include "Prova.h"



Prova::Prova(string name){
	nome = name;
}


// Metodos get
string Prova::getNome() const {
	return nome;
}

Data* Prova::getData() {
	return data;
}

Hora* Prova::getHora() {
	return hora;
}

Modalidade* Prova::getModalidade() {
	return modalidade;
}

Infrastrutura* Prova::getInfrastrutura() {
	return infrastrutura;
}

map<Atleta*, int> Prova::getClassificacoesAtletas(){
	return classificacoes_atletas;
}


// Metodos set
void Prova::setData(Data *date) {
	data = date;
}

void Prova::setHora(Hora *hour) {
	hora = hour;
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



