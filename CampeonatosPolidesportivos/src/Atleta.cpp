#include "Atleta.h"



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


Equipa* Atleta::getEquipa() {
	return equipa;
}


void Atleta::setEquipa(Equipa *equi) {
	equipa = equi;
}


void Atleta::info(){
	cout << "Nome: " << getNome() << endl;
	cout << "Idade: " << getIdade() << endl;
	cout << "Peso: "<< peso << endl;
	cout << "Altura: " << estatura << endl;
}
