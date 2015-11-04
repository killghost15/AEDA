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
		cout << "Essa equipa já existe, por favor introduza outro nome." << endl;
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
		cout << "Essa equipa não existe, por favor introduza outro nome." << endl;
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
		cout << "Esse atleta não existe, por favor introduza outro nome." << endl;
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
		cout << "Esse desporto não existe, por favor introduza outro nome." << endl;
		cout << endl;

		return "";
	}
};




#endif
