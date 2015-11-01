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
	//métodos get
	vector<Desporto> getDesportos();
	vector<Infrastrutura> getInfrastruturas();
	// Métodos sobre Infrastruturas
	void addInfrastrutura(Infrastrutura &infra);
	void loadInfrastruturas();
	void saveInfrastrutura();
	// Métodos sobre Desportos
	void addDesporto(Desporto &desp);
	void saveDesporto();
};



#endif
