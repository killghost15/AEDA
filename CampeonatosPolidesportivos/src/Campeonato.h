#ifndef CAMPEONATO_H
#define CAMPEONATO_H


#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

#include "Desporto.h"
#include "Infrastrutura.h"


#define file_atletas "atletas.txt"
#define file_desportos "desportos.txt"
#define file_equipas "equipas.txt"
#define file_modalidades "modalidades.txt"
#define file_infrastruturas "infrastruturas.txt"

using namespace std;


class Campeonato {
	vector<Atleta*> atletas;
	vector<Desporto*> desportos;
	vector<Equipa*> equipas;
	vector<Modalidade*> modalidades;
	vector<Infrastrutura*> infrastruturas;
public:
	// Metodos get
	vector<Equipa*> getEquipas();
	vector<Atleta*> getAtletas();
	vector<Modalidade*> getModalidades();
	vector<Desporto*> getDesportos();
	vector<Infrastrutura*> getInfrastruturas();
	// Metodos find
	Equipa* findEquipa(string nomeEquipa);
	Atleta* findAtleta(string nomeAtleta);
	Modalidade* findModalidade(string nomeModalidade);
	Desporto* findDesporto(string nomeDesporto);
	Infrastrutura* findInfrastrutura(string nomeInfrastrutura);
	// Metodos erase
	void eraseInfrastrutura(string nomeInfrastrutura);
	// Metodos sobre Infrastruturas
	void loadInfrastruturas();
	void saveInfrastrutura();
	void addInfrastrutura(Infrastrutura *infra);
	// Metodos sobre Desportos
	void loadDesportos();
	void saveDesporto();
	void addDesporto(Desporto *desp);
	// Metodos sobre Equipas
	void loadEquipas();
	void saveEquipa();
	void addEquipa(Equipa *equi);
	// Metodos sobre Atletas
	void loadAtletas();
	void saveAtleta();
	void addAtleta(Atleta *atl);
	// Metodos sobre Atletas
	void loadModalidades();
	void saveModalidade();
	void addModalidade(Modalidade *modal);
	// Metodos para adicionar atletas a uma modalidade
	int findModalidadeIndex(string nomeModalidade);
	void changeModalidade(int index, Modalidade *mod);
};



#endif
