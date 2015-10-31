#include <iostream>

using namespace std;

// Declaração das funções
void MenuInicial();


// Menu de Manutenção das Infrastruturas do campeonato
void MenuInfrastruturas() {
	int escolha_infrastruturas;

	cout << "----------------------------------------------" << endl;
	cout << "-            ** Infrastruturas **            -" << endl;
	cout << "-                                            -" << endl;
	cout << "- 1. Criar Infrastrutura                     -" << endl;
	cout << "- 2. Apagar Infrastrutura                    -" << endl;
	cout << "- 3. Voltar ao Menu Principal                -" << endl;
	cout << "-                                            -" << endl;
	cout << "----------------------------------------------" << endl;

	cout << "O que pretende fazer? ";
	cin >> escolha_infrastruturas;

	if ( escolha_infrastruturas != 1 && escolha_infrastruturas != 2 && escolha_infrastruturas != 3 ) {
		cout << "Por favor, faça uma escolha adequada." << endl << endl;
		MenuInfrastruturas();
	}

	switch (escolha_infrastruturas) {
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

	cout << "O que pretende fazer? ";
	cin >> escolha_desportos;

	if ( escolha_desportos != 1 && escolha_desportos != 2 && escolha_desportos != 3 && escolha_desportos != 4 ) {
		cout << "Por favor, faça uma escolha adequada." << endl << endl;
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

// Menu de Manutenção das Equipas e respetivos Atletas
void MenuEquipasAtletas() {
	int escolha_equipas;

	cout << "-----------------------------------------------" << endl;
	cout << "-           ** Equipas e Atletas **           -" << endl;
	cout << "-                                             -" << endl;
	cout << "- 1. Criar Equipa                             -" << endl;
	cout << "- 2. Apagar Equipa                            -" << endl;
	cout << "- 3. Adicionar Atletas à Equipa               -" << endl;
	cout << "- 4. Voltar ao Menu Principal                 -" << endl;
	cout << "-                                             -" << endl;
	cout << "-----------------------------------------------" << endl;

	cout << "O que pretende fazer? ";
	cin >> escolha_equipas;

	if ( escolha_equipas != 1 && escolha_equipas != 2 && escolha_equipas != 3 && escolha_equipas != 4 ) {
		cout << "Por favor, faça uma escolha adequada." << endl << endl;
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

	cout << "O que pretende fazer? ";
	cin >> escolha_menu;

	if ( escolha_menu != 1 && escolha_menu != 2 && escolha_menu != 3 && escolha_menu != 4 && escolha_menu != 5 ) {
		cout << "Por favor, faça uma escolha adequada." << endl;
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
	MenuInicial();
	return 0;
}

