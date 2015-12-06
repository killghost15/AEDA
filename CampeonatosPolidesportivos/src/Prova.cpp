#include "Prova.h"



Prova::Prova(string name, int duration){
	nome = name;
	duracao = duration;
}


// Metodos get
string Prova::getNome() const {
	return nome;
}

int Prova::getDuracao() const {
	return duracao;
}

Data* Prova::getData() {
	return data;
}

Hora* Prova::getHoraInicio() {
	return hora;
}

Hora* Prova::getHoraFim() {
	Hora* hora_final;

	if( (hora->getMinuto()+duracao) < 60 )
		hora_final = new Hora(hora->getHora(), hora->getMinuto()+duracao);
	else
		hora_final = new Hora(hora->getHora()+((hora->getMinuto()+duracao)/60), (hora->getMinuto()+duracao)%60);

	return hora_final;
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



