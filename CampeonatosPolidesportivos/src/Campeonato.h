#ifndef CAMPEONATO_H
#define CAMPEONATO_H


#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
//#include "Modalidade.h"
#include "Desporto.h"
//#include "Equipa.h"
//#include "Atleta.h"
#include "Infrastrutura.h"


#define file_atletas "atletas.txt"
#define file_desportos "desportos.txt"
#define file_equipas "equipas.txt"
#define file_infrastruturas "infrastruturas.txt"

using namespace std;


class Campeonato {
	vector<Atleta> atletas;
	vector<Desporto> desportos;
	vector<Equipa> equipas;
	vector<Infrastrutura> infrastruturas;
public:
	// Metodos get
	vector<Atleta> getAtletas();
	vector<Desporto> getDesportos();
	vector<Equipa> getEquipas();
	vector<Infrastrutura> getInfrastruturas();
	// Metodos sobre Infrastruturas
	void loadInfrastruturas();
	void saveInfrastrutura();
	void addInfrastrutura(Infrastrutura &infra);
	// Metodos sobre Desportos
	void loadDesportos();
	void saveDesporto();
	void addDesporto(Desporto &desp);
	// Metodos sobre Equipas
	void loadEquipas();
	void saveEquipa();
	void addEquipa(Equipa &equi);
	// Metodos sobre Atletas
	void loadAtletas();
	void saveAtleta();
	void addAtleta(Atleta &atl);
};



#endif
