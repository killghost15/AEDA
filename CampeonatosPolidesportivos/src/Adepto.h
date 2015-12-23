#ifndef ADEPTO_H
#define ADEPTO_H


#include "Pessoa.h"

class Adepto: public Pessoa{
	string email;
	string morada;
	static int id;
public:
	Adepto(string nome, int idade, string email, string morada);
	string getMorada(){ return morada;};
	string getEmail(){return email;};
	void info();
};


#endif
