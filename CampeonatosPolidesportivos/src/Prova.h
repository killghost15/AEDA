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
		if (data->getAno() < prova.getData()->getAno())return true;
		if(data->getAno() == prova.getData()->getAno()){
			if(data->getMes()<prova.getData()->getMes())return true;
			if(data->getMes()==prova.getData()->getMes()){
				if(data->getDia()<prova.getData()->getDia())return true;
				if(data->getDia()==prova.getData()->getDia()){
					if(hora->getHora()<prova.hora->getHora())return true;
					if(hora->getHora()==prova.hora->getHora()){
						if(hora->getMinuto() < prova.hora->getMinuto())return true;
						if(hora->getMinuto() == prova.hora->getMinuto()){
							if (getNome()<prova.getNome())return true;
						}
					}
				}

			}
		}

		return false;
	};
};


#endif
