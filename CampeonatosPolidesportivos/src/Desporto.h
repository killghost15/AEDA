#ifndef DESPORTO_H
#define DESPORTO_H


#include <iostream>
#include <vector>
#include "Modalidade.h"

using namespace std;


class Desporto {
	string nome;
	vector<Modalidade> modalidades;
public:
	Desporto(string name);
	// Metodos get
	string getNome() const;
	vector<Modalidade> getModalidades();
	// outros metodos
	void pushModalidade(Modalidade &modal);
};



#endif
