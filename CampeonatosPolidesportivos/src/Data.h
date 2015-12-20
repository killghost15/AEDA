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
	bool operator < (Data d)const{
		if (this->ano < d.ano)return true;
		if (this->ano == d.ano){
			if (this->mes < d.mes)return true;
			if (this->mes==d.mes){
				if (dia < d.dia)return true;
				}
			}
		return false;
	}
	bool operator==(Data d)const{
		if (dia==d.dia && mes== d.mes && ano== d.ano)return true;
		else return false;
	}

};


#endif
