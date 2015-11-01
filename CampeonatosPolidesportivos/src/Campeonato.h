#ifndef CAMPEONATO_H
#define CAMPEONATO_H


#include <iostream>
#include <fstream>
#include <vector>
#include "Atleta.h"
#include "Desporto.h"
#include "Infrastrutura.h"

#define file_atletas "atletas.txt"
#define file_desportos "desportos.txt"
#define file_infrastruturas "infrastruturas.txt"

using namespace std;


class Campeonato {
	vector<Desporto> desportos;
	vector<Infrastrutura> infrastruturas;
public:
	// Metodos get
	vector<Desporto> getDesportos();
	vector<Infrastrutura> getInfrastruturas();
	// Metodos sobre Infrastruturas
	void loadInfrastruturas();
	void saveInfrastrutura();
	void addInfrastrutura(Infrastrutura &infra);
	// Metodos sobre Desportos
	void loadDesportos();
	void saveDesporto();
	void addDesporto(Desporto &desp);
};



#endif
