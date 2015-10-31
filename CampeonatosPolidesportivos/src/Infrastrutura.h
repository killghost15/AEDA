#ifndef INFRASTRUTURA_H
#define INFRASTRUTURA_H


#include <iostream>

using namespace std;


class Infrastrutura {
	string cidade;
public:
	Infrastrutura(string city);
	string getCidade() const;
};



#endif
