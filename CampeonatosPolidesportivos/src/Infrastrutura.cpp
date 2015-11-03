#include "Infrastrutura.h"



Infrastrutura::Infrastrutura(string name, string city) {
	nome = name;
	cidade = city;
}


string Infrastrutura::getNome() const {
	return nome;
}


string Infrastrutura::getCidade() const {
	return cidade;
}
