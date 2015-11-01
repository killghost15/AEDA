#ifndef EQUIPA_H
#define EQUIPA_H


#include <iostream>
#include "Desporto.h"

using namespace std;


class Equipa {
	string nome;
	vector<Desporto> desportos;
public:
	Equipa(string name);
	// metodos get
	string getNome() const;
	vector<Desporto> getDesportos();
	// outros metodos
	void pushDesporto(Desporto &desp);
};


#endif
