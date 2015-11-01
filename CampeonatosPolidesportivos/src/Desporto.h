#ifndef DESPORTO_H
#define DESPORTO_H


#include <iostream>
#include "Modalidade.h"

using namespace std;


class Desporto {
	string nome;
	vector<Modalidade> modalidades;
public:
	void pushModalidade(Modalidade &modal);
	string getNome() const;
	vector<Modalidade> getModalidades();
	Desporto(string name);
};



#endif
