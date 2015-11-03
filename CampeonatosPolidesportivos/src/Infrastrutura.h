#ifndef INFRASTRUTURA_H
#define INFRASTRUTURA_H


#include <iostream>

using namespace std;


class Infrastrutura {
	string nome;
	string cidade;
public:
	Infrastrutura(string name, string city);
	// Metodos get
	string getNome() const;
	string getCidade() const;
};



#endif
