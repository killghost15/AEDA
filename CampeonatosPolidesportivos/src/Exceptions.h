#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H


#include <iostream>
#include <exception>

using namespace std;


class EquipaJaExistente: public exception {
	string nomeEquipa;
public:
	EquipaJaExistente(string nameTeam) : nomeEquipa(nameTeam) {}
	virtual ~EquipaJaExistente() throw() {}

	virtual const char* what() const throw() {
		cout << endl;
		cout << " Essa equipa já existe, por favor introduza outro nome." << endl;
		cout << endl;

		return "";
	}
};


class EquipaInexistente: public exception {
	string nomeEquipa;
public:
	EquipaInexistente(string nameTeam) : nomeEquipa(nameTeam) {}
	virtual ~EquipaInexistente() throw() {}

	virtual const char* what() const throw() {
		cout << endl;
		cout << " A equipa " << nomeEquipa << " não existe, por favor introduza outro nome." << endl;
		cout << endl;

		return "";
	}
};


class AtletaInexistente: public exception {
	string nomeAtleta;
public:
	AtletaInexistente(string nameAthlete) : nomeAtleta(nameAthlete) {}
	virtual ~AtletaInexistente() throw() {}

	virtual const char* what() const throw() {
		cout << endl;
		cout << " O atleta " << nomeAtleta << " não existe, por favor introduza outro nome." << endl;
		cout << endl;

		return "";
	}
};


class DesportoJaExistente: public exception {
	string nomeDesporto;
public:
	DesportoJaExistente(string nameSport) : nomeDesporto(nameSport) {}
	virtual ~DesportoJaExistente() throw() {}

	virtual const char* what() const throw() {
		cout << endl;
		cout << " Esse desporto já existe, por favor introduza outro nome." << endl;
		cout << endl;

		return "";
	}
};


class DesportoInexistente: public exception {
	string nomeDesporto;
public:
	DesportoInexistente(string nameSport) : nomeDesporto(nameSport) {}
	virtual ~DesportoInexistente() throw() {}

	virtual const char* what() const throw() {
		cout << endl;
		cout << " O desporto " << nomeDesporto << " não existe, por favor introduza outro nome." << endl;
		cout << endl;

		return "";
	}
};


class NumDesportosInvalido: public exception {
	int numDesportosMax;
public:
	NumDesportosInvalido(int numSportsMax) : numDesportosMax(numSportsMax) {}
	virtual ~NumDesportosInvalido() throw() {}

	virtual const char* what() const throw() {
		cout << endl;
		cout << " Número de desportos inválido (tem de estar entre 1 e " << numDesportosMax << ")." << endl;
		cout << endl;

		return "";
	}
};


class NumAtletasInvalido: public exception {
public:
	NumAtletasInvalido() {}
	virtual ~NumAtletasInvalido() throw() {}

	virtual const char* what() const throw() {
		cout << endl;
		cout << " Número de atletas inválido (tem de ser maior que 1)." << endl;
		cout << endl;

		return "";
	}
};




#endif
