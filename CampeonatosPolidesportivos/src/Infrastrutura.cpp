#include "Infrastrutura.h"


// Construtor da Classe Infrastrutura
Infrastrutura::Infrastrutura(string name, string city) {
	nome = name;
	cidade = city;
}

//getNome()
string Infrastrutura::getNome() const {
	return nome;
}

//getCidade()
string Infrastrutura::getCidade() const {
	return cidade;
}
