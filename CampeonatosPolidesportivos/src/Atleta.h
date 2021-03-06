#ifndef ATLETA_H
#define ATLETA_H


#include <iostream>

#include "Pessoa.h"
#include "Equipa.h"

using namespace std;


class Atleta: public Pessoa {
	float peso;
	float estatura;
	Equipa *equipa;
public:
	Atleta(string name, unsigned int age, float weight, float height);
	// Metodos get
	float getPeso() const;
	float getEstatura() const;
	Equipa* getEquipa();
	// Metodo set
	void setEquipa(Equipa *equi);
	// Metodo info
	void info();
};



#endif
