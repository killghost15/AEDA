#include "Equipa.h"



Equipa::Equipa(string name) {
	nome = name;
}


string Equipa::getNome() const {
	return nome;
}


vector<string> Equipa::getDesportos() {
	return desportos;
}


void Equipa::pushDesporto(string desp) {
	desportos.push_back(desp);
}
