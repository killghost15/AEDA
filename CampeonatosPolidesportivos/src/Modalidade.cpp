#include "Modalidade.h"


Modalidade::Modalidade(string name) {
	nome = name;
}


string Modalidade::getNome() const {
	return nome;
}


vector<Atleta> Modalidade::getAtletas() const {
	return atletas;
}
