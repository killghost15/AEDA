#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H


#include <iostream>
#include <exception>

using namespace std;


/**
 *  EXCEÇÕES JÁEXISTENTE
 */

class EquipaJaExistente: public exception {
	string nomeEquipa;
public:
	EquipaJaExistente(string nameTeam) : nomeEquipa(nameTeam) {}
	virtual ~EquipaJaExistente() throw() {}

	virtual const char* what() const throw() {
		cout << endl;
		cout << " A equipa " << nomeEquipa << " já existe, por favor introduza outro nome." << endl;
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
		cout << " O atleta " << nomeAtleta << " já existe, por favor introduza outro nome." << endl;
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
		cout << " A modalidade " << nomeModalidade << " já existe, por favor introduza outro nome." << endl;
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
		cout << " O desporto " << nomeDesporto << " já existe, por favor introduza outro nome." << endl;
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
		cout << " A infrastrutura " << nomeInfrastrutura << " já existe, por favor introduza outro nome." << endl;
		cout << endl;

		return "";
	}
};


/**
 *  EXCEÇOES INEXISTENTE
 */

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


class ModalidadeInexistente: public exception {
	string nomeModalidade;
public:
	ModalidadeInexistente(string nameModality) : nomeModalidade(nameModality) {}
	virtual ~ModalidadeInexistente() throw() {}

	virtual const char* what() const throw() {
		cout << endl;
		cout << " A modalidade " << nomeModalidade << " não existe, por favor introduza outro nome." << endl;
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


class InfrastruturaInexistente: public exception {
	string nomeInfrastrutura;
public:
	InfrastruturaInexistente(string nameInfrastructure) : nomeInfrastrutura(nameInfrastructure) {}
	virtual ~InfrastruturaInexistente() throw() {}

	virtual const char* what() const throw() {
		cout << endl;
		cout << " A infrastrutura " << nomeInfrastrutura << " não existe, por favor introduza outro nome." << endl;
		cout << endl;

		return "";
	}
};


/**
 *  EXCEÇÕES NUMINVALIDO
 */

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


class NumModalidadesInvalido: public exception {
public:
	NumModalidadesInvalido() {}
	virtual ~NumModalidadesInvalido() throw() {}

	virtual const char* what() const throw() {
		cout << endl;
		cout << " Número de modalidades inválido (tem de ser maior que 1)." << endl;
		cout << endl;

		return "";
	}
};


// EXCEÇÃO IDADEINVALIDA
class IdadeInvalida: public exception {
public:
	IdadeInvalida() {}
	virtual ~IdadeInvalida() throw() {}

	virtual const char* what() const throw() {
		cout << endl;
		cout << " Idade inválida (tem de ser maior que 18)." << endl;
		cout << endl;

		return "";
	}
};




#endif
