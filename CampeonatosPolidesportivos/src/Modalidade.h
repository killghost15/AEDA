#ifndef MODALIDADE_H
#define MODALIDADE_H


#include <iostream>


#include "Atleta.h"

using namespace std;


class Modalidade {
	string nome;
	vector<Atleta*> atletas;
public:
	Modalidade(string name);
	// metodos get
	string getNome() const;
	vector<Atleta*> getAtletas();
	// outros metodos
	void pushAtleta(Atleta *atl);
	void eraseAtleta(int index);
	void eraseAtleta2(int index);
};


#endif
