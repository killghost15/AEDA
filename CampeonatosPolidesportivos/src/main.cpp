#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Campeonato.h"
#include "Infrastrutura.h"

using namespace std;


void MenuInicial();

Campeonato campeonato;


// Apresenta o form para a adição da infrastrutura ao campeonato
void AdicionarInfrastrutura() {
	string nome_infrastrutura, cidade_infrastrutura;

	cin.clear();
	cin.sync();

	cout << " Nome da Infrastrutura: ";
	getline(cin, nome_infrastrutura);
	cout << " Cidade da Infrastrutura: ";
	getline(cin, cidade_infrastrutura);
	cout << endl;

	Infrastrutura *infra = new Infrastrutura(nome_infrastrutura, cidade_infrastrutura);
	campeonato.addInfrastrutura(*infra);

	cout << " Infrastrutura adicionada com sucesso!";
	cout << string(8,'\n');
}


// Menu de Manutenção das Infrastruturas do campeonato
void MenuInfrastruturas() {
	int escolha_infrastruturas;

	cout << "----------------------------------------------" << endl;
	cout << "-            ** Infrastruturas **            -" << endl;
	cout << "-                                            -" << endl;
	cout << "- 1. Adicionar Infrastrutura                 -" << endl;
	cout << "- 2. Apagar Infrastrutura                    -" << endl;
	cout << "- 3. Voltar ao Menu Principal                -" << endl;
	cout << "-                                            -" << endl;
	cout << "----------------------------------------------" << endl;

	cout << " O que pretende fazer? ";
	cin >> escolha_infrastruturas;

	if ( escolha_infrastruturas != 1 && escolha_infrastruturas != 2 && escolha_infrastruturas != 3 ) {
		cout << " Por favor, faça uma escolha adequada.";
		cout << string(8,'\n');
		MenuInfrastruturas();
	}

	switch (escolha_infrastruturas) {
		case 1:
			cout << string(8,'\n');
			AdicionarInfrastrutura();
			cout << string(8,'\n');
			MenuInicial();
			break;
		case 2:
			cout << string(8,'\n');
			//
			break;
		case 3:
			cout << string(8,'\n');
			MenuInicial();
			break;
	}
}


// Apresenta o form para a adição do desporto ao campeonato
void AdicionarDesporto() {
	string nome_desporto, nome_modalidade;
	unsigned int num_modalidades;

	cin.clear();
	cin.sync();

	cout << " Nome do desporto: ";
	getline(cin, nome_desporto);
	// TODO: check if desporto exists/ error if it does
	cout << " Quantos modalidades tem o desporto: ";
	cin >> num_modalidades;
	cout << endl;

	vector<string> mods;

	//form para todas as modalidades do desporto
	for ( unsigned int i = 0; i < num_modalidades; i++ ) {
		cin.clear();
		cin.sync();
		cout << " Nome da Modalidade " << i+1 << ": ";
		getline(cin, nome_modalidade);

		mods.push_back(nome_modalidade);
	}

	//criaçao do objeto da classe desporto para adicionar ao campeonato
	Desporto *desp = new Desporto(nome_desporto);

	for ( unsigned int j = 0; j < mods.size(); j++ ) {
		string modalidade_string = mods[j];
		Modalidade *modal = new Modalidade(modalidade_string);
		desp->pushModalidade(*modal);
		campeonato.addModalidade(*modal);
	}

	campeonato.addDesporto(*desp);
	cout << endl << " Desporto e modalidades adicionados com sucesso!";
}


// Menu de Manutenção dos Desportos e Modalidades, bem como dos atletas de cada modalidade
void MenuDesportosModalidades() {
	int escolha_desportos;

	cout << "-----------------------------------------------" << endl;
	cout << "-        ** Desportos e Modalidades **        -" << endl;
	cout << "-                                             -" << endl;
	cout << "- 1. Adicionar Desporto                       -" << endl;
	cout << "- 2. Apagar Desporto                          -" << endl;
	cout << "- 3. Adicionar Atletas à Modalidade           -" << endl;
	cout << "- 3. Retirar Atletas à Modalidade             -" << endl;
	cout << "- 4. Voltar ao Menu Principal                 -" << endl;
	cout << "-                                             -" << endl;
	cout << "-----------------------------------------------" << endl;

	cout << " O que pretende fazer? ";
	cin >> escolha_desportos;

	if ( escolha_desportos != 1 && escolha_desportos != 2 && escolha_desportos != 3 && escolha_desportos != 4 ) {
		cout << " Por favor, faça uma escolha adequada.";
		cout << string(8,'\n');
		MenuDesportosModalidades();
	}

	switch (escolha_desportos) {
		case 1:
			cout << string(8,'\n');
			AdicionarDesporto();
			cout << string(8,'\n');
			MenuInicial();
			break;
		case 2:
			cout << string(8,'\n');
			//
			break;
		case 3:
			cout << string(8,'\n');
			//
			break;
		case 4:
			cout << string(8,'\n');
			MenuInicial();
			break;
	}
}


// Apresenta o form para a adição da equipa ao campeonato
void AdicionarEquipa() {
	string nome_equipa, nome_desporto, nome_atleta;
	float peso_atleta, estatura_atleta;
	unsigned int num_desportos, num_atletas, idade_atleta;

	cin.clear();
	cin.sync();

	cout << " Nome da equipa: ";
	getline(cin, nome_equipa);
	// TODO: check if equipa exists/ error if it does
	cout << " Em quantos desportos a equipa vai participar: ";
	cin >> num_desportos;
	cout << endl;

	vector<string> sports;

	//form para todos os desportos da equipa
	for ( unsigned int i = 0; i < num_desportos; i++ ) {
		cin.clear();
		cin.sync();
		cout << " Nome do Desporto " << i+1 << ": ";
		getline(cin, nome_desporto);

		sports.push_back(nome_desporto);
	}

	cout << endl;

	cout << " Quantos atletas tem a equipa inicialmente: ";
	cin >> num_atletas;
	cout << endl;

	vector<Atleta> athletes;

	//form para todos os atletas da equipa
	for ( unsigned int i = 0; i < num_desportos; i++ ) {
		cin.clear();
		cin.sync();
		cout << " Nome do Atleta " << i+1 << ": ";
		getline(cin, nome_atleta);
		cout << " Idade do Atleta " << i+1 << ": ";
		cin >> idade_atleta;
		cout << " Peso do Atleta " << i+1 << ": ";
		cin >> peso_atleta;
		cout << " Estatura do Atleta " << i+1 << ": ";
		cin >> estatura_atleta;
		cout << endl;

		Atleta *atlet = new Atleta(nome_atleta, idade_atleta, peso_atleta, estatura_atleta);
		athletes.push_back(*atlet);
	}

	//criaçao do objeto da classe equipa para adicionar ao campeonato
	Equipa *equi = new Equipa(nome_equipa);

	for ( unsigned int j = 0; j < sports.size(); j++ ) {
		string desporto_string = sports[j];
		equi->pushDesporto(desporto_string);
	}

	//criaçao do objeto da classe atleta para adicionar ao campeonato
	Atleta *atl;

	for ( unsigned int j = 0; j < athletes.size(); j++ ) {
		string atletaNome = athletes[j].getNome();
		unsigned int atletaIdade = athletes[j].getIdade();
		float atletaPeso = athletes[j].getPeso();
		float atletaEstatura = athletes[j].getEstatura();
		atl = new Atleta(atletaNome, atletaIdade, atletaPeso, atletaEstatura);
		atl->setEquipa(equi);
		campeonato.addAtleta(*atl);
	}

	campeonato.addEquipa(*equi);
	cout << " Equipa e atletas adicionados com sucesso!";
}


// Menu de Manutenção das Equipas e respetivos Atletas
void MenuEquipasAtletas() {
	int escolha_equipas;

	cout << "-----------------------------------------------" << endl;
	cout << "-           ** Equipas e Atletas **           -" << endl;
	cout << "-                                             -" << endl;
	cout << "- 1. Adicionar Equipa                         -" << endl;
	cout << "- 2. Apagar Equipa                            -" << endl;
	cout << "- 3. Adicionar Atletas à Equipa               -" << endl;
	cout << "- 4. Voltar ao Menu Principal                 -" << endl;
	cout << "-                                             -" << endl;
	cout << "-----------------------------------------------" << endl;

	cout << " O que pretende fazer? ";
	cin >> escolha_equipas;

	if ( escolha_equipas != 1 && escolha_equipas != 2 && escolha_equipas != 3 && escolha_equipas != 4 ) {
		cout << " Por favor, faça uma escolha adequada.";
		cout << string(8,'\n');
		MenuEquipasAtletas();
	}

	switch (escolha_equipas) {
		case 1:
			cout << string(8,'\n');
			AdicionarEquipa();
			cout << string(8,'\n');
			MenuInicial();
			break;
		case 2:
			cout << string(8,'\n');
			//
			break;
		case 3:
			cout << string(8,'\n');
			//
			break;
		case 4:
			cout << string(8,'\n');
			MenuInicial();
			break;
	}
}


// Menu das Listagens, efetua a listagem de toda a informação que o utilizador quiser
void MenuListagens() {
	int escolha_listagens;

	cout << "---------------------------------------------" << endl;
	cout << "-             *** Listagens ***             -" << endl;
	cout << "-                                           -" << endl;
	cout << "- O que pretende listar?                    -" << endl;
	cout << "-                                           -" << endl;
	cout << "- 1. Atletas                                -" << endl;
	cout << "- 2. Equipas                                -" << endl;
	cout << "- 3. Desportos                              -" << endl;
	cout << "- 4. Modalidades                            -" << endl;
	cout << "- 5. Funcionários                           -" << endl;
	cout << "- 6. Infrastruturas                         -" << endl;
	cout << "-                                           -" << endl;
	cout << "---------------------------------------------" << endl;

	cout << " O que pretende fazer? ";
	cin >> escolha_listagens;

	if ( escolha_listagens != 1 && escolha_listagens != 2 && escolha_listagens != 3 && escolha_listagens != 4 && escolha_listagens != 5 && escolha_listagens != 6 ) {
		cout << " Por favor, faça uma escolha adequada.";
		cout << string(8,'\n');
		MenuInicial();
	}


	switch (escolha_listagens) {
		case 1:
			cout << string(8,'\n');
			//
			break;
		case 2:
			cout << string(8,'\n');
			//
			break;
		case 3:
			cout << string(8,'\n');
			//
			break;
		case 4:
			cout << string(8,'\n');
			//
			break;
		case 5:
			cout << string(8,'\n');
			//
			break;
		case 6:
			cout << string(8,'\n');
			//
			break;
	}
}


// Menu Principal, chama todos os outros Menus mediante a escolha do utilizador
void MenuInicial() {
	int escolha_menu;

	cout << "----------------------------------------------" << endl;
	cout << "-           *** Menu Principal ***           -" << endl;
	cout << "-                                            -" << endl;
	cout << "- 1. Manutenção de Equipas e Atletas         -" << endl;
	cout << "- 2. Manutenção de Desportos e Modalidades   -" << endl;
	cout << "- 3. Manutenção do Calendário das provas     -" << endl;
	cout << "- 4. Manutenção de Infrastruturas            -" << endl;
	cout << "- 5. Listagens                               -" << endl;
	cout << "-                                            -" << endl;
	cout << "----------------------------------------------" << endl;

	cout << " O que pretende fazer? ";
	cin >> escolha_menu;

	if ( escolha_menu != 1 && escolha_menu != 2 && escolha_menu != 3 && escolha_menu != 4 && escolha_menu != 5 ) {
		cout << " Por favor, faça uma escolha adequada.";
		cout << string(8,'\n');
		MenuInicial();
	}

	switch (escolha_menu) {
		case 1:
			cout << string(8,'\n');
			MenuEquipasAtletas();
			break;
		case 2:
			cout << string(8,'\n');
			MenuDesportosModalidades();
			break;
		case 3:
			cout << string(8,'\n');
			//MenuCalendario();
			break;
		case 4:
			cout << string(8,'\n');
			MenuInfrastruturas();
			break;
		case 5:
			cout << string(8,'\n');
			//MenuListagens();
			break;
	}
}


// Verifica se o ficheiro tem alguma coisa. Retorna true se nao tiver e false se tiver
bool file_isEmpty( const char* filename ) {
	ifstream file;
	string trash;
	file.open(filename);

	getline(file, trash);

	if ( trash == "" )
		return true;

	return false;
}


int main() {
	// Elimina o ficheiro se nao tiver nada
	if ( file_isEmpty(file_infrastruturas) == true )
		remove(file_infrastruturas);
	if ( file_isEmpty(file_desportos) == true )
		remove(file_desportos);
	if ( file_isEmpty(file_equipas) == true )
		remove(file_equipas);
	if ( file_isEmpty(file_modalidades) == true )
		remove(file_modalidades);

	// Carrega a informação para os respetivos vetores
	campeonato.loadEquipas();
	campeonato.loadAtletas();
	campeonato.loadModalidades();
	campeonato.loadDesportos();
	campeonato.loadInfrastruturas();

	// Chama o Menu Inicial
	MenuInicial();

	return 0;
}

