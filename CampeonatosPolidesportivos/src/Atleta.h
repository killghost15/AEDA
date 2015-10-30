#ifndef ATLETA_H
#define ATLETA_H


#include <iostream>

using namespace std;


enum Medalha {
	ouro,
	prata,
	bronze
}


class Atleta: public Pessoa {
	float estatura;
	vector<Medalha> medalhas;
	Equipa* equipa;
public:
};




#endif
