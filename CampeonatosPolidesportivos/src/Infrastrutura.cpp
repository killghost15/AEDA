#include "Infrastrutura.h"


// Construtor da Classe Infrastrutura
Infrastrutura::Infrastrutura(string city) {
	cidade = city;
}

//getCidade()
string Infrastrutura::getCidade() const {
	return cidade;
}
