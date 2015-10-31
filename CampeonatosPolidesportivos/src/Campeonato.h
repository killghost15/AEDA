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
	vector<Atleta> atletas;
	vector<Desporto> desportos;
	vector<Infrastrutura> infrastruturas;
public:
	// Métodos sobre Infrastruturas
	void addInfrastrutura(Infrastrutura &infra);
	void loadInfrastrutura();
	void saveInfrastrutura();
};



#endif
