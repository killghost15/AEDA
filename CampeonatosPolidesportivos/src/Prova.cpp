#include "Prova.h"



Prova::Prova(string name, int day, int month, int year){
	nome = name;
	dia = day;
	mes = month;
	ano = year;
	infrastrutura = "vazio";
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


string Prova::getInfrastrutura() {
	return infrastrutura;
}


void Prova::setInfrastrutura(string nome) {
	infrastrutura = nome;
}



