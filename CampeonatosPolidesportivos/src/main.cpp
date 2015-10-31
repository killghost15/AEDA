#include <iostream>
#include <stdio.h>
#include "Campeonato.h"
#include "Infrastrutura.h"

using namespace std;


Campeonato campeonato;

// Declara��o das fun��es
void MenuInicial();


// Apresenta o form para a adi��o da infrastrutura
void AdicionarInfrastrutura() {
	string cidade_infrastrutura, nome_infrastrutura;

	//cout << "----------------------------------------------" << endl;
	cout << " Nome da Infrastrutura: ";
	cin >> nome_infrastrutura;
	cout << endl;
	cout << " Cidade da Infrastrutura: ";
	cin >> cidade_infrastrutura;
	cout << endl;
	//cout << "----------------------------------------------" << endl;

	Infrastrutura *infra = new Infrastrutura(nome_infrastrutura, cidade_infrastrutura);
	campeonato.addInfrastrutura(*infra);

	cout << "Infrastrutura adicionada com sucesso!" << endl << endl;
}

// Menu de Manuten��o das Infrastruturas do campeonato
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
		cout << " Por favor, fa�a uma escolha adequada." << endl << endl;
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


// Menu de Manuten��o dos Desportos e Modalidades, bem como os atletas e equipas de cada modalidade
void MenuDesportosModalidades() {
	int escolha_desportos;

	cout << "-----------------------------------------------" << endl;
	cout << "-        ** Desportos e Modalidades **        -" << endl;
	cout << "-                                             -" << endl;
	cout << "- 1. Criar Desporto                           -" << endl;
	cout << "- 2. Apagar Desporto                          -" << endl;
	cout << "- 3. Adicionar Atletas � Modalidade           -" << endl;
	cout << "- 3. Retirar Atletas � Modalidade             -" << endl;
	cout << "- 4. Voltar ao Menu Principal                 -" << endl;
	cout << "-                                             -" << endl;
	cout << "-----------------------------------------------" << endl;

	cout << " O que pretende fazer? ";
	cin >> escolha_desportos;

	if ( escolha_desportos != 1 && escolha_desportos != 2 && escolha_desportos != 3 && escolha_desportos != 4 ) {
		cout << " Por favor, fa�a uma escolha adequada." << endl << endl;
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

// Menu de Manuten��o das Equipas e respetivos Atletas
void MenuEquipasAtletas() {
	int escolha_equipas;

	cout << "-----------------------------------------------" << endl;
	cout << "-           ** Equipas e Atletas **           -" << endl;
	cout << "-                                             -" << endl;
	cout << "- 1. Criar Equipa                             -" << endl;
	cout << "- 2. Apagar Equipa                            -" << endl;
	cout << "- 3. Adicionar Atletas � Equipa               -" << endl;
	cout << "- 4. Voltar ao Menu Principal                 -" << endl;
	cout << "-                                             -" << endl;
	cout << "-----------------------------------------------" << endl;

	cout << " O que pretende fazer? ";
	cin >> escolha_equipas;

	if ( escolha_equipas != 1 && escolha_equipas != 2 && escolha_equipas != 3 && escolha_equipas != 4 ) {
		cout << " Por favor, fa�a uma escolha adequada." << endl << endl;
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


// Menu das Listagens, efetua a listagem de toda a informa��o que o utilizador quiser
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
	cout << "- 5. Funcion�rios                           -" << endl;
	cout << "- 6. Infrastruturas                         -" << endl;
	cout << "-                                           -" << endl;
	cout << "---------------------------------------------" << endl;

	cout << " O que pretende fazer? ";
	cin >> escolha_listagens;

	if ( escolha_listagens != 1 && escolha_listagens != 2 && escolha_listagens != 3 && escolha_listagens != 4 && escolha_listagens != 5 && escolha_listagens != 6 ) {
		cout << " Por favor, fa�a uma escolha adequada." << endl << endl;
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
	cout << "- 1. Manuten��o de Equipas e Atletas         -" << endl;
	cout << "- 2. Manuten��o de Desportos e Modalidades   -" << endl;
	cout << "- 3. Manuten��o do Calend�rio das provas     -" << endl;
	cout << "- 4. Manuten��o de Infrastruturas            -" << endl;
	cout << "- 5. Listagens                               -" << endl;
	cout << "-                                            -" << endl;
	cout << "----------------------------------------------" << endl;

	cout << " O que pretende fazer? ";
	cin >> escolha_menu;

	if ( escolha_menu != 1 && escolha_menu != 2 && escolha_menu != 3 && escolha_menu != 4 && escolha_menu != 5 ) {
		cout << " Por favor, fa�a uma escolha adequada." << endl << endl;
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


int main() {
	//Carrega a informa��o para os respetivos vetores, e elimina o ficheiro se nao existir nada
	if ( campeonato.loadInfrastrutura() != 0 )
		remove(file_infrastruturas);

	//Chama o Menu Inicial
	MenuInicial();

	return 0;
}

