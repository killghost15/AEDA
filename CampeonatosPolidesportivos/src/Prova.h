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
	int duracao;
	Data *data;
	Hora *hora;
	Modalidade *modalidade;
	Infrastrutura *infrastrutura;
	map<Atleta*, int> classificacoes_atletas;
public:
	Prova(string name, int duration);
	// Metodos get
	string getNome() const;
	int getDuracao() const;
	Data* getData()const;
	Hora* getHoraInicio();
	Hora* getHoraFim();
	Modalidade* getModalidade();
	Infrastrutura* getInfrastrutura();
	map<Atleta*, int> getClassificacoesAtletas();
	// Metodo set
	void setData(Data *date);
	void setHora(Hora *hour);
	void setModalidade(Modalidade *mod);
	void setInfrastrutura(Infrastrutura *infra);
	void setClassificacoesAtletas(map<Atleta*, int> map);
	bool operator < ( const Prova prova)const{
		if (getData()< prova.getData())return true;
		if (getData()==prova.getData()){
			if (getNome() < prova.getNome())return true;
		}
		return false;
	};
};


#endif
