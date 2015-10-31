#ifndef ATLETA_H
#define ATLETA_H


#include <iostream>
#include "Pessoa.h"
#include "Equipa.h"

using namespace std;


enum Medalha {ouro, prata, bronze};


class Atleta: public Pessoa {
	float estatura;
	vector<Medalha> medalhas;
	Equipa* equipa;
public:
	Atleta();
};



#endif
