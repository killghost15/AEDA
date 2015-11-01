#include "Equipa.h"



Equipa::Equipa(string name) {
	nome = name;
}


string Equipa::getNome() const {
	return nome;
}


vector<Desporto> Equipa::getDesportos() {
	return desportos;
}


void Equipa::pushDesporto(Desporto &desp) {
	desportos.push_back(desp);
}
