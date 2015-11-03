#include "Modalidade.h"



Modalidade::Modalidade(string name) {
	nome = name;
}


string Modalidade::getNome() const {
	return nome;
}


vector<Atleta*> Modalidade::getAtletas() {
	return atletas;
}


void Modalidade::pushAtleta(Atleta *atl) {
	atletas.push_back(atl);
}
