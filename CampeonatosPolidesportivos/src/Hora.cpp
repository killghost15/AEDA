#include "Hora.h"


Hora::Hora(unsigned int hour, unsigned int minute) {
	hora = hour;
	minuto = minute;
}

unsigned int Hora::getHora() const {
	return hora;
}

unsigned int Hora::getMinuto() const {
	return minuto;
}

void Hora::checkHora(unsigned int hour, unsigned int minute) {
	bool hora_valida = true;

	if( hour > 23 )
		hora_valida = false;

	if( minute > 59 )
		hora_valida = false;

	if( hora_valida == false ) {
		stringstream ss;
		ss << hour << ":" << minute;
		throw HoraInvalida(ss.str());
	}
}
