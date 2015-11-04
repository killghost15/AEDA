#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H


#include <iostream>
#include <exception>

using namespace std;


/**
 *  EXCE��ES J�EXISTENTE
 */

class EquipaJaExistente: public exception {
	string nomeEquipa;
public:
	EquipaJaExistente(string nameTeam) : nomeEquipa(nameTeam) {}
	virtual ~EquipaJaExistente() throw() {}

	virtual const char* what() const throw() {
		cout << endl;
		cout << " A equipa " << nomeEquipa << " j� existe, por favor introduza outro nome." << endl;
		cout << endl;

		return "";
	}
};


class AtletaJaExistente: public exception {
	string nomeAtleta;
public:
	AtletaJaExistente(string nameAthlete) : nomeAtleta(nameAthlete) {}
	virtual ~AtletaJaExistente() throw() {}

	virtual const char* what() const throw() {
		cout << endl;
		cout << " O atleta " << nomeAtleta << " j� existe, por favor introduza outro nome." << endl;
		cout << endl;

		return "";
	}
};


class ModalidadeJaExistente: public exception {
	string nomeModalidade;
public:
	ModalidadeJaExistente(string nameModality) : nomeModalidade(nameModality) {}
	virtual ~ModalidadeJaExistente() throw() {}

	virtual const char* what() const throw() {
		cout << endl;
		cout << " A modalidade " << nomeModalidade << " j� existe, por favor introduza outro nome." << endl;
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
		cout << " O desporto " << nomeDesporto << " j� existe, por favor introduza outro nome." << endl;
		cout << endl;

		return "";
	}
};


class InfrastruturaJaExistente: public exception {
	string nomeInfrastrutura;
public:
	InfrastruturaJaExistente(string nameInfrastructure) : nomeInfrastrutura(nameInfrastructure) {}
	virtual ~InfrastruturaJaExistente() throw() {}

	virtual const char* what() const throw() {
		cout << endl;
		cout << " A infrastrutura " << nomeInfrastrutura << " j� existe, por favor introduza outro nome." << endl;
		cout << endl;

		return "";
	}
};


/**
 *  EXCE�OES INEXISTENTE
 */

class EquipaInexistente: public exception {
	string nomeEquipa;
public:
	EquipaInexistente(string nameTeam) : nomeEquipa(nameTeam) {}
	virtual ~EquipaInexistente() throw() {}

	virtual const char* what() const throw() {
		cout << endl;
		cout << " A equipa " << nomeEquipa << " n�o existe, por favor introduza outro nome." << endl;
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
		cout << " O atleta " << nomeAtleta << " n�o existe, por favor introduza outro nome." << endl;
		cout << endl;

		return "";
	}
};


class ModalidadeInexistente: public exception {
	string nomeModalidade;
public:
	ModalidadeInexistente(string nameModality) : nomeModalidade(nameModality) {}
	virtual ~ModalidadeInexistente() throw() {}

	virtual const char* what() const throw() {
		cout << endl;
		cout << " A modalidade " << nomeModalidade << " n�o existe, por favor introduza outro nome." << endl;
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
		cout << " O desporto " << nomeDesporto << " n�o existe, por favor introduza outro nome." << endl;
		cout << endl;

		return "";
	}
};


class InfrastruturaInexistente: public exception {
	string nomeInfrastrutura;
public:
	InfrastruturaInexistente(string nameInfrastructure) : nomeInfrastrutura(nameInfrastructure) {}
	virtual ~InfrastruturaInexistente() throw() {}

	virtual const char* what() const throw() {
		cout << endl;
		cout << " A infrastrutura " << nomeInfrastrutura << " n�o existe, por favor introduza outro nome." << endl;
		cout << endl;

		return "";
	}
};


/**
 *  EXCE��ES NUMINVALIDO
 */

class NumDesportosInvalido: public exception {
	int numDesportosMax;
public:
	NumDesportosInvalido(int numSportsMax) : numDesportosMax(numSportsMax) {}
	virtual ~NumDesportosInvalido() throw() {}

	virtual const char* what() const throw() {
		cout << endl;
		cout << " N�mero de desportos inv�lido (tem de estar entre 1 e " << numDesportosMax << ")." << endl;
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
		cout << " N�mero de atletas inv�lido (tem de ser maior que 1)." << endl;
		cout << endl;

		return "";
	}
};


class NumModalidadesInvalido: public exception {
public:
	NumModalidadesInvalido() {}
	virtual ~NumModalidadesInvalido() throw() {}

	virtual const char* what() const throw() {
		cout << endl;
		cout << " N�mero de modalidades inv�lido (tem de ser maior que 1)." << endl;
		cout << endl;

		return "";
	}
};


// EXCE��O IDADEINVALIDA
class IdadeInvalida: public exception {
public:
	IdadeInvalida() {}
	virtual ~IdadeInvalida() throw() {}

	virtual const char* what() const throw() {
		cout << endl;
		cout << " Idade inv�lida (tem de ser maior que 18)." << endl;
		cout << endl;

		return "";
	}
};




#endif
