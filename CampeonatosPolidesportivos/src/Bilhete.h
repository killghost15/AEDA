#ifndef BILHETE_H
#define BILHETE_H

#include "Prova.h"
#include "Adepto.h"

class Bilhete{
	vector<Prova*> provas;
	Adepto* ad;
	static int idBil;
public:
	Bilhete(vector<Prova*> p, Adepto* a){
		this->provas=p;
		this->ad = a;
	    idBil++;
	};
	vector<Prova*> getProvas(){
		return provas;
	};

	void setProvas(vector<Prova*> p){
		this->provas = p;
	}

	void addProva(Prova* p){
		provas.push_back(p);
	}

	static int getId(){
		return idBil;
	};

	Adepto* getAdepto(){
		return ad;
	}
	void info();

};



#endif
