#include "Atleta.h"


Atleta::Atleta(string name) : Pessoa(name) {
	equipa = NULL;
}


Atleta::Atleta(string name, unsigned int age, float weight, float height) : Pessoa(name, age) {
	peso = weight;
	estatura = height;
	equipa = NULL;
}


float Atleta::getPeso() const {
	return peso;
}


float Atleta::getEstatura() const {
	return estatura;
}


Equipa *Atleta::getEquipa() {
	return equipa;
}


void Atleta::setEquipa(Equipa *equi) {
	equipa = equi;
}
