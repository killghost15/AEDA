#ifndef DATA_H
#define DATA_H


#include <iostream>
#include <sstream>

#include "Exceptions.h"

using namespace std;


class Data {
	unsigned int dia, mes, ano;
public:
	Data(unsigned int day, unsigned int month, unsigned int year);
	// Metodos get
	unsigned int getDia() const;
	unsigned int getMes() const;
	unsigned int getAno() const;
	// Metodo check para verificar se os valores dos membros-dado estão de acordo com o calendario juliano
	void checkData(unsigned int day, unsigned int month, unsigned int year);
};


#endif
