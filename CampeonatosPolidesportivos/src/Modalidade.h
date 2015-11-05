#ifndef MODALIDADE_H
#define MODALIDADE_H


#include <iostream>


#include "Prova.h"

using namespace std;


class Modalidade {
	string nome;
	vector<Atleta*> atletas;
	vector<Prova*> Provas;

public:
	Modalidade(string name);
	// metodos get
	string getNome() const;
	vector<Atleta*> getAtletas();
	// outros metodos
	void pushAtleta(Atleta *atl);
	void eraseAtleta(int index);
	void eraseAtleta2(int index);
	void pushClassifica(int num);;
	vector <Prova*> getProvas();
	//int getPosicao();
	void CriarProva(string nomeProva, int dia, int mes, int ano);
	void EliminaProva(string nomeProva);
};


#endif
