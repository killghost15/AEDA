#ifndef PROVA_H
#define PROVA_H


#include <iostream>
#include <vector>
#include <map>

#include "Atleta.h"
#include "Modalidade.h"
#include "Infrastrutura.h"
#include "Data.h"

using namespace std;


class Prova {
	string nome;
	Data *data;
	Modalidade *modalidade;
	map<Atleta*, int> classificacoes_atletas;
	Infrastrutura *infrastrutura;
public:
	Prova(string name);
	// Metodos get
	string getNome() const;
	Data* getData();
	Modalidade* getModalidade();
	map<Atleta*, int> getClassificacoesAtletas();
	Infrastrutura* getInfrastrutura();
	// Metodo set
	void setData(Data *date);
	void setModalidade(Modalidade *mod);
	void setInfrastrutura(Infrastrutura *infra);
	void setClassificacoesAtletas(map<Atleta*, int> map);
};


#endif
