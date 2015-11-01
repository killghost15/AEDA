#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Campeonato.h"
#include "Infrastrutura.h"

using namespace std;


Campeonato campeonato;

// Declaração das funções
void MenuInicial();


// Apresenta o form para a adição da infrastrutura
void AdicionarInfrastrutura() {
	string nome_infrastrutura, cidade_infrastrutura;

	cin.clear();
	cin.sync();

	//cout << "----------------------------------------------" << endl;
	cout << " Nome da Infrastrutura: ";
	getline(cin, nome_infrastrutura);
	cout << endl;
	cout << " Cidade da Infrastrutura: ";
	getline(cin, cidade_infrastrutura);
	cout << endl;
	//cout << "----------------------------------------------" << endl;

	Infrastrutura *infra = new Infrastrutura(nome_infrastrutura, cidade_infrastrutura);
	campeonato.addInfrastrutura(*infra);

	cout << "Infrastrutura adicionada com sucesso!" << endl << endl;
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
		cout << " Por favor, faça uma escolha adequada." << endl << endl;
		MenuInfrastruturas();
	}

	switch (escolha_infrastruturas) {
		case 1:
			cout << endl << endl;
			AdicionarInfrastrutura();
			MenuInicial();
			break;
		case 2:
			cout << endl << endl;
			//
			break;
		case 3:
			cout << endl;
			MenuInicial();
			break;
	}
}


// Menu de Manutenção dos Desportos e Modalidades, bem como os atletas e equipas de cada modalidade
void MenuDesportosModalidades() {
	int escolha_desportos;

	cout << "-----------------------------------------------" << endl;
	cout << "-        ** Desportos e Modalidades **        -" << endl;
	cout << "-                                             -" << endl;
	cout << "- 1. Criar Desporto                           -" << endl;
	cout << "- 2. Apagar Desporto                          -" << endl;
	cout << "- 3. Adicionar Atletas à Modalidade           -" << endl;
	cout << "- 3. Retirar Atletas à Modalidade             -" << endl;
	cout << "- 4. Voltar ao Menu Principal                 -" << endl;
	cout << "-                                             -" << endl;
	cout << "-----------------------------------------------" << endl;

	cout << " O que pretende fazer? ";
	cin >> escolha_desportos;

	if ( escolha_desportos != 1 && escolha_desportos != 2 && escolha_desportos != 3 && escolha_desportos != 4 ) {
		cout << " Por favor, faça uma escolha adequada." << endl << endl;
		MenuDesportosModalidades();
	}

	switch (escolha_desportos) {
		case 1:
			cout << endl;
			//
			break;
		case 2:
			cout << endl;
			//
			break;
		case 3:
			cout << endl;
			//
			break;
		case 4:
			cout << endl;
			MenuInicial();
			break;
	}
}


// Apresenta o form para a adição da infrastrutura
void AdicionarEquipa() {
	string nome_equipa, num_atletas;

	cin.clear();
	cin.sync();

	//cout << "----------------------------------------------" << endl;
	cout << " Nome da Equipa: ";
	getline(cin, nome_equipa);
	cout << endl;
	cout << " Quantos atletas tem a equipa inicialmente: ";
	getline(cin, num_atletas);
	cout << endl;

	int num_atletas_int = atoi(num_atletas.c_str());

	//form para todos os atletas iniciais da equipa
	for ( unsigned int i = 0; i < num_atletas_int; i++ ) {
		cout << endl;
		cout << "Nome do Atleta: ";
		getline(cin, nome_atleta);
		cout << endl;
		cout << "Idade do Atleta: ";
		getline(cin, idade_atleta);
		cout << endl;
		cout << "Peso do Atleta: ";
		getline(cin, peso_atleta);
		cout << endl;
		cout << "Altura do Atleta: ";
		getline(cin, altura_atleta);
		cout << endl;
	}

	//cout << "----------------------------------------------" << endl;

	cout << "Equipa e atletas adicionados com sucesso!" << endl << endl;
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
		cout << " Por favor, faça uma escolha adequada." << endl << endl;
		MenuEquipasAtletas();
	}

	switch (escolha_equipas) {
		case 1:
			cout << endl;
			//
			break;
		case 2:
			cout << endl;
			//
			break;
		case 3:
			cout << endl;
			//
			break;
		case 4:
			cout << endl;
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
		cout << " Por favor, faça uma escolha adequada." << endl << endl;
		MenuInicial();
	}


	switch (escolha_listagens) {
		case 1:
			cout << endl;
			//MenuEquipasAtletas();
			break;
		case 2:
			cout << endl;
			//MenuDesportosModalidades();
			break;
		case 3:
			cout << endl;
			//MenuCalendario();
			break;
		case 4:
			cout << endl;
			//MenuInfrastruturas();
			break;
		case 5:
			cout << endl;
			//MenuListagens();
			break;
		case 6:
			cout << endl;
			//MenuListagens();
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
		cout << " Por favor, faça uma escolha adequada." << endl << endl;
		MenuInicial();
	}


	switch (escolha_menu) {
		case 1:
			cout << endl;
			MenuEquipasAtletas();
			break;
		case 2:
			cout << endl;
			MenuDesportosModalidades();
			break;
		case 3:
			cout << endl;
			//MenuCalendario();
			break;
		case 4:
			cout << endl;
			MenuInfrastruturas();
			break;
		case 5:
			cout << endl;
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
	//Carrega a informação para os respetivos vetores, e elimina o ficheiro se nao tiver nada
	if ( file_isEmpty(file_infrastruturas) == true )
		remove(file_infrastruturas);

	campeonato.loadInfrastruturas();
	//Chama o Menu Inicial
	MenuInicial();

	return 0;
}

