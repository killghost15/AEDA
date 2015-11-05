#ifndef PROVA_H
#define PROVA_H


#include <iostream>
#include <vector>
#include "Atleta.h"
using namespace std;


class Prova {
	vector <int> classificacao;
	string nome;
	int ano,mes,dia;
public:
	Prova(string name, int day, int month, int year);
	Prova();

	vector<int> getClassificacoes();
void pushClassifica(int num);
string getNome(){
	return nome;

};
int getAno(){
	return ano;
};
int getMes(){
	return mes;
};
int getDia(){
	return dia;
};

};


#endif
