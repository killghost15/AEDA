#ifndef EQUIPA_H
#define EQUIPA_H


#include <iostream>
#include <vector>
//#include "Desporto.h"

using namespace std;


class Equipa {
	string nome;
	int ouro, prata, bronze;
	vector<string> desportos;
public:
	Equipa(string name, int gold, int silver, int brass);
	// Metodos get
	string getNome() const;
	int getOuro()const;
	int getPrata()const;
	int getBronze()const;
	vector<string> getDesportos();
	// Metodos set
	void incOuro();
	void incPrata();
	void incBronze();
	// outros metodos
	void pushDesporto(string desp);
	bool operator <( const Equipa equi )const;
};


#endif
