#ifndef PESSOA_H
#define PESSOA_H


#include <iostream>

using namespace std;


class Pessoa {
	string nome;
	unsigned int idade;
public:
	Pessoa(string name, unsigned int age);
	// Metodos get
	string getNome() const;
	unsigned int getIdade() const;
	// Metodo info ---- Pure abstract class
	virtual void info() =0;
};



#endif
