#ifndef CAMPEONATO_H
#define CAMPEONATO_H


#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <map>

#include "Desporto.h"
#include "Infrastrutura.h"
#include "Funcionario.h"
#include "Prova.h"


#define file_equipas "equipas.txt"
#define file_atletas "atletas.txt"
#define file_modalidades "modalidades.txt"
#define file_provas "provas.txt"
#define file_desportos "desportos.txt"
#define file_infrastruturas "infrastruturas.txt"
#define file_funcionarios "funcionarios.txt"

using namespace std;


class Campeonato {
	vector<Equipa*> equipas;
	vector<Atleta*> atletas;
	vector<Modalidade*> modalidades;
	vector<Prova*> provas;
	vector<Desporto*> desportos;
	vector<Infrastrutura*> infrastruturas;
	vector<Funcionario*> funcionarios;
	BST<Prova*> TreeProva;
public:
	// Metodos get
	vector<Equipa*> getEquipas();
	vector<Atleta*> getAtletas();
	vector<Modalidade*> getModalidades();
	vector<Prova*> getProvas();
	vector<Desporto*> getDesportos();
	vector<Infrastrutura*> getInfrastruturas();
	vector<Funcionario*> getFuncionarios();
	string getDataInicio();
	string getDataFim();
	// Metodos find
	Equipa* findEquipa(string nomeEquipa);
	Atleta* findAtleta(string nomeAtleta);
	Modalidade* findModalidade(string nomeModalidade);
	Prova* findProva(string nomeProva);
	Desporto* findDesporto(string nomeDesporto);
	Infrastrutura* findInfrastrutura(string nomeInfrastrutura);
	// Metodos exists
	bool existsEquipa(string nomeEquipa);
	bool existsAtleta(string nomeAtleta);
	bool existsModalidade(string nomeModalidade);
	bool existsProva(string nomeProva);
	bool existsDesporto(string nomeDesporto);
	bool existsInfrastrutura(string nomeInfrastrutura);
	bool existsFuncionario(string nomeFuncionario);
	bool CanAtletaEnterModalidade(string nomeModalidade, string nomeAtleta);
	// Metodos erase
	void eraseAtletaModalidade(string nomeModalidade, string nomeAtleta);
	void eraseEquipa(string nomeEquipa);
	void eraseAtleta(string nomeAtleta);
	void eraseDesporto(string nomeDesporto);
	void eraseProva(string nomeProva);
	void eraseInfrastrutura(string nomeInfrastrutura);
	void eraseFuncionario(string nomeFuncionario);
	// Metodos sobre Equipas
	void loadEquipas();
	void saveEquipa();
	void addEquipa(Equipa *equi);
	// Metodos sobre Atletas
	void loadAtletas();
	void saveAtleta();
	void addAtleta(Atleta *atl);
	// Metodos sobre Modalidades
	void loadModalidades();
	void saveModalidade();
	void addModalidade(Modalidade *modal);
	// Metodos sobre Provas
	void loadProvas();
	void saveProva();
	void addProva(Prova *prova);
	// Metodos sobre Desportos
	void loadDesportos();
	void saveDesporto();
	void addDesporto(Desporto *desp);
	// Metodos sobre Infrastruturas
	void loadInfrastruturas();
	void saveInfrastrutura();
	void addInfrastrutura(Infrastrutura *infra);
	// Metodos sobre Funcionarios
	void loadFuncionarios();
	void saveFuncionario();
	void addFuncionario(Funcionario *func);
	// Metodos para mudar um atleta de equipa
	int findAtletaIndex(string nomeAtleta);
	void changeEquipa(int index, Equipa *equi);
	// Metodos para mudar a infrastrutura de uma prova
	int findProvaIndex(string nomeProva);
	void changeInfrastrutura(int index, Infrastrutura *infra);
	// Metodos para adicionar atletas a uma modalidade
	int findModalidadeIndex(string nomeModalidade);
	void changeModalidade(int index, Modalidade *mod);
	// Metodos para determinar a data do inicio e do fim do campeonato
	//metodos da BST
	void inserirProvaBST(Prova *prova);


};



#endif
