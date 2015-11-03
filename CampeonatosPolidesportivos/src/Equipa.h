#ifndef EQUIPA_H
#define EQUIPA_H


#include <iostream>
#include <vector>
//#include "Desporto.h"

using namespace std;


class Equipa {
	string nome;
	vector<string> desportos;
public:
	Equipa(string name);
	// Metodos get
	string getNome() const;
	vector<string> getDesportos();
	// outros metodos
	void pushDesporto(string desp);
};


#endif
