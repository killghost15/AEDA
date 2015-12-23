#include "Equipa.h"



Equipa::Equipa(string name, int gold, int silver, int brass) {
	nome = name;
	ouro = gold;
	prata = silver;
	bronze = brass;
}


string Equipa::getNome() const {
	return nome;
}

int Equipa::getOuro() {
	return ouro;
}

int Equipa::getPrata() {
	return prata;
}

int Equipa::getBronze() {
	return bronze;
}

vector<string> Equipa::getDesportos() {
	return desportos;
}


void Equipa::incOuro() {
	ouro++;
}

void Equipa::incPrata() {
	prata++;
}

void Equipa::incBronze() {
	bronze++;
}


void Equipa::pushDesporto(string desp) {
	desportos.push_back(desp);
}
