#ifndef PROVA_H
#define PROVA_H


#include <iostream>
#include <vector>
#include <map>

#include "Atleta.h"
#include "Modalidade.h"
#include "Infrastrutura.h"
#include "Data.h"
#include "Hora.h"

using namespace std;


class Prova {
	string nome;
	Data *data;
	Hora *hora;
	Modalidade *modalidade;
	Infrastrutura *infrastrutura;
	map<Atleta*, int> classificacoes_atletas;
public:
	Prova(string name);
	// Metodos get
	string getNome() const;
	Data* getData();
	Hora* getHora();
	Modalidade* getModalidade();
	Infrastrutura* getInfrastrutura();
	map<Atleta*, int> getClassificacoesAtletas();
	// Metodo set
	void setData(Data *date);
	void setHora(Hora *hour);
	void setModalidade(Modalidade *mod);
	void setInfrastrutura(Infrastrutura *infra);
	void setClassificacoesAtletas(map<Atleta*, int> map);
};


#endif
