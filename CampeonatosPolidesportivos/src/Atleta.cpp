#include "Atleta.h"


Atleta::Atleta(string name, unsigned int age, float weight, float height) : Pessoa(name, age) {
	peso = weight;
	estatura = height;
	equipa = NULL;
}
