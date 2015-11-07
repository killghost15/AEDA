#include "Funcionario.h"



Funcionario::Funcionario(string name, unsigned int age, int work_years) : Pessoa(name, age) {
	anos_trabalho = work_years;
}


int Funcionario::getAnosTrabalho() const {
	return anos_trabalho;
}


void Funcionario::info() {
	cout << "Nome: " << getNome() << endl;
	cout << "Idade: " << getIdade() << endl;
	cout << "Anos de serviço: " << anos_trabalho << endl;
}
