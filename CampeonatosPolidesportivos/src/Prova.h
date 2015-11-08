#ifndef PROVA_H
#define PROVA_H


#include <iostream>
#include <vector>
#include <map>

#include "Atleta.h"
#include "Modalidade.h"

using namespace std;


class Prova {
	string nome;
	int ano, mes, dia;
	Modalidade* modalidade;
	map<Atleta*, int> classificacoes_atletas;
	//vector<Atleta*> atletas;
	string infrastrutura;
public:
	Prova();
	Prova(string name, int day, int month, int year);
	// Metodos get
	string getNome() const;
	int getAno() const;
	int getMes() const;
	int getDia() const;
	Modalidade* getModalidade();
	map<Atleta*, int> getClassificacoesAtletas();
	string getInfrastrutura();
	// Metodo set
	void setInfrastrutura(string nome);
};


#endif
