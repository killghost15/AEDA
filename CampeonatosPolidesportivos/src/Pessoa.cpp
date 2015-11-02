#include "Pessoa.h"


Pessoa::Pessoa(string name) {
	nome = name;
}


Pessoa::Pessoa(string name, unsigned int age) {
	nome = name;
	idade = age;
}


string Pessoa::getNome() const {
	return nome;
}


unsigned int Pessoa::getIdade() const {
	return idade;
}
