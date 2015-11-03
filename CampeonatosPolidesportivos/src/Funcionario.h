#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H


#include <iostream>

#include "Pessoa.h"

using namespace std;


class Funcionario: public Pessoa {
	int anos_trabalho;
public:
	Funcionario(string name, unsigned int age, int work_years);
};



#endif
