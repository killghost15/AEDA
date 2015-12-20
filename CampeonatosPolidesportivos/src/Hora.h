#ifndef HORA_H
#define HORA_H


#include <iostream>
#include <sstream>

#include "Exceptions.h"

using namespace std;


class Hora {
	unsigned int hora, minuto;
public:
	Hora(unsigned int hour, unsigned int minute);
	// Metodos get
	unsigned int getHora() const;
	unsigned int getMinuto() const;
	// Metodo check para verificar se os valores dos membros-dado estão de acordo com as horas a que se podem realizar provas (9:00 - 18:00).
	void checkHora(unsigned int hour, unsigned int minute);
	bool operator <(const Hora h)const{
		if (hora <h.getHora())return true;
		if (hora==h.getHora()){
			if(minuto < h.getMinuto())return true;

		}
		return false;


	}
};



#endif
