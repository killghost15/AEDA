#include "Funcionario.h"



Funcionario::Funcionario(string name, unsigned int age, int work_years) : Pessoa(name, age) {
	anos_trabalho = work_years;
}
