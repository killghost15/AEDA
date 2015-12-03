#include "Data.h"


Data::Data(unsigned int day, unsigned int month, unsigned int year) {
	dia = day;
	mes = month;
	ano = year;
}

unsigned int Data::getDia() const {
	return dia;
}

unsigned int Data::getMes() const {
	return mes;
}

unsigned int Data::getAno() const {
	return ano;
}

void Data::checkData(unsigned int day, unsigned int month, unsigned int year) {
	bool data_valida = true;

	if( month > 12 )
		data_valida = false;

	switch(month) {
		case 1:
			if( day > 31 ) data_valida = false;
			break;
		case 2:
			// se o ano for bissexto, fevereiro pode ter 29 dias, caso contrário só pode ter 28
			if( year%4 == 0 ) {
				if( month == 2 )
					if( day > 29 ) data_valida = false;
			} else {
				if( month == 2 )
					if( day > 28 ) data_valida = false;
			}
			break;
		case 3:
			if( day > 31 ) data_valida = false;
			break;
		case 4:
			if( day > 30 ) data_valida = false;
			break;
		case 5:
			if( day > 31 ) data_valida = false;
			break;
		case 6:
			if( day > 30 ) data_valida = false;
			break;
		case 7:
			if( day > 31 ) data_valida = false;
			break;
		case 8:
			if( day > 31 ) data_valida = false;
			break;
		case 9:
			if( day > 30 ) data_valida = false;
			break;
		case 10:
			if( day > 31 ) data_valida = false;
			break;
		case 11:
			if( day > 30 ) data_valida = false;
			break;
		case 12:
			if( day > 31 ) data_valida = false;
			break;
	}

	// lança exceção se a data for invalida
	if( data_valida == false ) {
		stringstream ss;
		ss << day << "/" << month << "/" << year;
		throw DataInvalida(ss.str());
	}

}

