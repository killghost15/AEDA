#include "Adepto.h"


Adepto::Adepto(string nome, int idade, string email, string morada):Pessoa(nome,idade){
	this->email = email;
	this->morada = morada;
}


void Adepto::info() {
	cout << "Nome: " << getNome() << endl;
	cout << "Idade: " << getIdade() << endl;
	cout << "Email: " << getEmail() << endl;
	cout << "Morada: " << getMorada() << endl;

}

