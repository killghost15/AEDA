#ifndef CAMPEONATO_H
#define CAMPEONATO_H


#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

#include "Desporto.h"
#include "Infrastrutura.h"
#include "Funcionario.h"


#define file_atletas "atletas.txt"
#define file_desportos "desportos.txt"
#define file_equipas "equipas.txt"
#define file_modalidades "modalidades.txt"
#define file_infrastruturas "infrastruturas.txt"
#define file_classificacoes "classificacoes.txt"
#define file_funcionarios "funcionarios.txt"

using namespace std;


class Campeonato {
	vector<Atleta*> atletas;
	vector<Desporto*> desportos;
	vector<Equipa*> equipas;
	vector<Modalidade*> modalidades;
	vector<Infrastrutura*> infrastruturas;
	vector<Funcionario*> funcionarios;
public:
	// Metodos get
	vector<Equipa*> getEquipas();
	vector<Atleta*> getAtletas();
	vector<Modalidade*> getModalidades();
	vector<Desporto*> getDesportos();
	vector<Infrastrutura*> getInfrastruturas();
	vector<Funcionario*> getFuncionarios();
	// Metodos find
	Equipa* findEquipa(string nomeEquipa);
	Atleta* findAtleta(string nomeAtleta);
	Modalidade* findModalidade(string nomeModalidade);
	Desporto* findDesporto(string nomeDesporto);
	Infrastrutura* findInfrastrutura(string nomeInfrastrutura);
	Funcionario* findFuncionario(string nomeFuncionario);
	// Metodos exists
	bool existsEquipa(string nomeEquipa);
	bool existsAtleta(string nomeAtleta);
	bool existsModalidade(string nomeModalidade);
	bool existsDesporto(string nomeDesporto);
	bool existsInfrastrutura(string nomeInfrastrutura);
	bool existsFuncionario(string nomeFuncionario);
	bool CanAtletaEnterModalidade(string nomeModalidade, string nomeAtleta);
	// Metodos erase
	void eraseAtletaModalidade(string nomeModalidade, string nomeAtleta);
	void eraseEquipa(string nomeEquipa);
	void eraseAtleta(string nomeAtleta);
	void eraseDesporto(string nomeEquipa);
	void eraseInfrastrutura(string nomeInfrastrutura);
	void eraseFuncionario(string nomeFuncionario);
	// Metodos sobre Funcionarios
	void loadFuncionarios();
	void saveFuncionario();
	void addFuncionario(Funcionario *func);
	// Metodos sobre Infrastruturas
	void loadInfrastruturas();
	void saveInfrastrutura();
	void addInfrastrutura(Infrastrutura *infra);
	// Metodos sobre Desportos
	void loadDesportos();
	void saveDesporto();
	void addDesporto(Desporto *desp);
	// Metodos sobre Equipas
	void loadEquipas();
	void saveEquipa();
	void addEquipa(Equipa *equi);
	// Metodos sobre Atletas
	void loadAtletas();
	void saveAtleta();
	void addAtleta(Atleta *atl);
	// Metodos sobre Atletas
	void loadModalidades();
	void saveModalidade();
	void addModalidade(Modalidade *modal);
	// Metodos para adicionar atletas a uma modalidade
	int findModalidadeIndex(string nomeModalidade);
	void changeModalidade(int index, Modalidade *mod);
	// Metodos para mudar um atleta de equipa
	int findAtletaIndex(string nomeAtleta);
	void changeEquipa(int index, Equipa *equi);
	//classificacao de uma modalidade
	void classifica(string nomeModalidade,string nomeProva);
	void saveclassifica();
	void loadclassifica();
	void AtribuiInfrastrutura(string nomeModalidade, string nomeProva, string infrastrutura);
};



#endif
