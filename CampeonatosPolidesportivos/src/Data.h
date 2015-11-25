#ifndef DATA_H
#define DATA_H


#include <iostream>

using namespace std;


class Data {
	unsigned int dia, mes, ano;
public:
	Data(unsigned int day, unsigned int month, unsigned int year);
	// Metodos get
	unsigned int getDia() const;
	unsigned int getMes() const;
	unsigned int getAno() const;
	// Metodos check para verificar se os valores dos membros-dado estão de acordo com o estipulado no calendario juliano
	bool checkData(unsigned int day, unsigned int month, unsigned int year);
};


#endif
