#include "Desporto.h"


Desporto::Desporto(string name) {
	nome = name;
}


string Desporto::getNome() const {
	return nome;
}


vector<Modalidade> Desporto::getModalidades() {
	return modalidades;
}


void Desporto::pushModalidade(Modalidade &modal) {
	modalidades.push_back(modal);
}
