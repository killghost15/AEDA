#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

#include "Campeonato.h"
#include "Infrastrutura.h"
#include "Exceptions.h"

using namespace std;


bool exception_finish = true;
void MenuInicial();


Campeonato campeonato;


/**
 *  MENUS RELACIONADOS COM AS EQUIPAS E ATLETAS
 */


// Apresenta o form para a adição da equipa ao campeonato
void AdicionarEquipa() {
	string nome_equipa, nome_desporto, nome_atleta;
	float peso_atleta, estatura_atleta;
	unsigned int num_desportos, num_atletas, idade_atleta;

	cin.clear();
	cin.sync();

	exception_finish = true;
	while (exception_finish) {
		try {
			cout << " Nome da equipa: ";
			getline(cin, nome_equipa);
			if( campeonato.existsEquipa(nome_equipa) == true )
				throw EquipaJaExistente(nome_equipa);
			else
				exception_finish = false;
		} catch (EquipaJaExistente &e) {
			e.what();
		}
	}

	exception_finish = true;
	while (exception_finish) {
		try {
			cout << " Em quantos desportos a equipa vai participar: ";
			cin >> num_desportos;
			if( num_desportos < 1 || num_desportos > campeonato.getDesportos().size())
				throw NumDesportosInvalido(campeonato.getDesportos().size());
			else
				exception_finish = false;
			cout << endl;
		} catch (NumDesportosInvalido &e) {
			e.what();
		}
	}

	vector<string> sports;

	//form para todos os desportos da equipa
	for ( unsigned int i = 0; i < num_desportos; i++ ) {
		cin.clear();
		cin.sync();

		exception_finish = true;
		while (exception_finish) {
			try {
				cout << " Nome do Desporto " << i+1 << ": ";
				getline(cin, nome_desporto);
				if( campeonato.existsDesporto(nome_desporto) == false )
					throw DesportoInexistente(nome_desporto);
				else
					exception_finish = false;
			} catch (DesportoInexistente &e) {
				e.what();
			}
		}

		sports.push_back(nome_desporto);
	}

	cout << endl;


	exception_finish = true;
	while (exception_finish) {
		try {
			cout << " Quantos atletas tem a equipa inicialmente: ";
			cin >> num_atletas;
			if( num_atletas < 1)
				throw NumAtletasInvalido();
			else
				exception_finish = false;
			cout << endl;
		} catch (NumAtletasInvalido &e) {
			e.what();
		}
	}

	vector<Atleta*> athletes;

	//form para todos os atletas da equipa
	for ( unsigned int i = 0; i < num_atletas; i++ ) {
		cin.clear();
		cin.sync();

		exception_finish = true;
		while (exception_finish) {
			try {
				cout << " Nome do Atleta " << i+1 << ": ";
				getline(cin, nome_atleta);
				if( campeonato.existsAtleta(nome_atleta) == true )
					throw AtletaJaExistente(nome_atleta);
				else
					exception_finish = false;
			} catch (AtletaJaExistente &e) {
				e.what();
			}
		}

		exception_finish = true;
		while (exception_finish) {
			try {
				cout << " Idade do Atleta " << i+1 << ": ";
				cin >> idade_atleta;
				if( idade_atleta < 18 )
					throw IdadeInvalida();
				else
					exception_finish = false;
			} catch (IdadeInvalida &e) {
				e.what();
			}
		}

		cout << " Peso do Atleta " << i+1 << ": ";
		cin >> peso_atleta;
		cout << " Estatura do Atleta " << i+1 << ": ";
		cin >> estatura_atleta;
		cout << endl;

		Atleta *atlet = new Atleta(nome_atleta, idade_atleta, peso_atleta, estatura_atleta);
		athletes.push_back(atlet);
	}

	//criaçao do objeto da classe equipa para adicionar ao campeonato
	Equipa *equi = new Equipa(nome_equipa);

	for ( unsigned int j = 0; j < sports.size(); j++ ) {
		string desporto_string = sports[j];
		equi->pushDesporto(desporto_string);
	}

	// adiciona a equipa ao vector e guarda no ficheiro
	campeonato.addEquipa(equi);

	//criaçao do objeto da classe atleta para adicionar ao campeonato
	Atleta *atl;

	for ( unsigned int j = 0; j < athletes.size(); j++ ) {
		string atletaNome = athletes[j]->getNome();
		unsigned int atletaIdade = athletes[j]->getIdade();
		float atletaPeso = athletes[j]->getPeso();
		float atletaEstatura = athletes[j]->getEstatura();
		atl = new Atleta(atletaNome, atletaIdade, atletaPeso, atletaEstatura);
		atl->setEquipa(equi);

		campeonato.addAtleta(atl);
	}

	cout << " Equipa e atletas adicionados com sucesso!";
}


// Apaga uma equipa com um nome especifico e respetivos atletas do campeonato
void RetirarEquipa() {
	string nome_equipa;

	cin.clear();
	cin.sync();

	exception_finish = true;
	while (exception_finish) {
		try {
			cout << " Qual o nome da equipa que pretende apagar: ";
			getline(cin, nome_equipa);
			if( campeonato.existsEquipa(nome_equipa) == false )
				throw EquipaInexistente(nome_equipa);
			else
				exception_finish = false;
		} catch (EquipaInexistente &e) {
			e.what();
		}
	}

	cout << endl;

	campeonato.eraseEquipa(nome_equipa);

	campeonato.saveEquipa();
	campeonato.saveAtleta();
	campeonato.saveModalidade();

	cout << " Equipa apagada do campeonato com sucesso!";
}


// Apresenta o form para adicionar atletas à equipa
void AdicionarAtletasEquipa() {
	string nome_equipa, nome_atleta;
	float peso_atleta, estatura_atleta;
	unsigned int num_atletas, idade_atleta;

	cin.clear();
	cin.sync();

	exception_finish = true;
	while(exception_finish) {
		try {
			cout << " Em que equipa pretende adicionar atletas: ";
			getline(cin, nome_equipa);
			if( campeonato.existsEquipa(nome_equipa) == false )
				throw EquipaInexistente(nome_equipa);
			else
				exception_finish = false;
		} catch (EquipaInexistente &e) {
			e.what();
		}
	}

	exception_finish = true;
	while (exception_finish) {
		try {
			cout << " Quantos atletas pretende adicionar: ";
			cin >> num_atletas;
			if( num_atletas < 1)
				throw NumAtletasInvalido();
			else
				exception_finish = false;
			cout << endl;
		} catch (NumAtletasInvalido &e) {
			e.what();
		}
	}

	vector<Atleta*> athletes;

	//form para todos os atletas da equipa
	for ( unsigned int i = 0; i < num_atletas; i++ ) {
		cin.clear();
		cin.sync();

		exception_finish = true;
		while (exception_finish) {
			try {
				cout << " Nome do Atleta " << i+1 << ": ";
				getline(cin, nome_atleta);
				if( campeonato.existsAtleta(nome_atleta) == true )
					throw AtletaJaExistente(nome_atleta);
				else
					exception_finish = false;
			} catch (AtletaJaExistente &e) {
				e.what();
			}
		}

		exception_finish = true;
		while (exception_finish) {
			try {
				cout << " Idade do Atleta " << i+1 << ": ";
				cin >> idade_atleta;
				if( idade_atleta < 18 )
					throw IdadeInvalida();
				else
					exception_finish = false;
			} catch (IdadeInvalida &e) {
				e.what();
			}
		}

		cout << " Peso do Atleta " << i+1 << ": ";
		cin >> peso_atleta;
		cout << " Estatura do Atleta " << i+1 << ": ";
		cin >> estatura_atleta;
		cout << endl;

		Atleta *atlet = new Atleta(nome_atleta, idade_atleta, peso_atleta, estatura_atleta);
		athletes.push_back(atlet);
	}

	Equipa *equi = campeonato.findEquipa(nome_equipa);

	//criaçao do objeto da classe atleta para adicionar ao campeonato
	Atleta *atl;

	for ( unsigned int j = 0; j < athletes.size(); j++ ) {
		string atletaNome = athletes[j]->getNome();
		unsigned int atletaIdade = athletes[j]->getIdade();
		float atletaPeso = athletes[j]->getPeso();
		float atletaEstatura = athletes[j]->getEstatura();
		atl = new Atleta(atletaNome, atletaIdade, atletaPeso, atletaEstatura);
		atl->setEquipa(equi);

		campeonato.addAtleta(atl);
	}

	cout << " Atletas adicionados à equipa com sucesso!";
}


// Expulsa um atleta com um nome especifico do campeonato
void RetirarAtleta() {
	string nome_atleta;

	cin.clear();
	cin.sync();

	exception_finish = true;
	while (exception_finish) {
		try {
			cout << " Qual o nome do atleta que pretende expulsar: ";
			getline(cin, nome_atleta);
			if( campeonato.existsAtleta(nome_atleta) == false )
				throw AtletaInexistente(nome_atleta);
			else
				exception_finish = false;
		} catch (AtletaInexistente &e) {
			e.what();
		}
	}

	cout << endl;

	campeonato.eraseAtleta(nome_atleta);

	campeonato.saveAtleta();
	campeonato.saveModalidade();

	cout << endl << " Atleta expulso do campeonato com sucesso!";
}


// Muda um atleta com um nome especifico de equipa
void MudarAtletaEquipa() {
	string nome_atleta, nome_equipa;

	cin.clear();
	cin.sync();

	exception_finish = true;
	while (exception_finish) {
		try {
			cout << " Qual o nome do atleta que pretende mudar de equipa: ";
			getline(cin, nome_atleta);
			if( campeonato.existsAtleta(nome_atleta) == false )
				throw AtletaInexistente(nome_atleta);
			else
				exception_finish = false;
		} catch (AtletaInexistente &e) {
			e.what();
		}
	}

	cout << endl;

	exception_finish = true;
	while (exception_finish) {
		try {
			cout << " Qual o nome da equipa para a qual pretende mudar: ";
			getline(cin, nome_equipa);
			if( campeonato.existsEquipa(nome_equipa) == false )
				throw EquipaInexistente(nome_equipa);
			else
				exception_finish = false;
		} catch (EquipaInexistente &e) {
			e.what();
		}
	}

	cout << endl;

	Equipa *equi = campeonato.findEquipa(nome_equipa);

	int index_atleta = campeonato.findAtletaIndex(nome_atleta);
	campeonato.changeEquipa(index_atleta, equi);

	campeonato.saveAtleta();

	cout << " Atleta mudou de equipa com sucesso!";
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
	cout << "- 4. Expulsar um Atleta do Campeonato         -" << endl;
	cout << "- 5. Mudar Equipa de um Atleta                -" << endl;
	cout << "- 6. Voltar ao Menu Principal                 -" << endl;
	cout << "-                                             -" << endl;
	cout << "-----------------------------------------------" << endl;

	cout << " O que pretende fazer? ";
	cin >> escolha_equipas;

	if ( escolha_equipas != 1 && escolha_equipas != 2 && escolha_equipas != 3 && escolha_equipas != 4  && escolha_equipas != 5  && escolha_equipas != 6) {
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
			RetirarEquipa();
			cout << string(8,'\n');
			MenuInicial();
			break;
		case 3:
			cout << string(8,'\n');
			AdicionarAtletasEquipa();
			cout << string(8,'\n');
			MenuInicial();
			break;
		case 4:
			cout << string(8,'\n');
			RetirarAtleta();
			cout << string(8,'\n');
			MenuInicial();
			break;
		case 5:
			cout << string(8,'\n');
			MudarAtletaEquipa();
			cout << string(8,'\n');
			MenuInicial();
			break;
		case 6:
			cout << string(8,'\n');
			MenuInicial();
			break;
	}
}


/**
 *  MENUS RELACIONADOS COM DESPORTOS E MODALIDADES
 */


// Apresenta o form para a adição do desporto ao campeonato
void AdicionarDesporto() {
	string nome_desporto, nome_modalidade;
	unsigned int num_modalidades;

	cin.clear();
	cin.sync();

	exception_finish = true;
	while (exception_finish) {
		try {
			cout << " Nome do desporto: ";
			getline(cin, nome_desporto);
			if( campeonato.existsDesporto(nome_desporto) == true )
				throw DesportoJaExistente(nome_desporto);
			else
				exception_finish = false;
		} catch (DesportoJaExistente &e) {
			e.what();
		}
	}

	exception_finish = true;
	while (exception_finish) {
		try {
			cout << " Quantos modalidades tem o desporto: ";
			cin >> num_modalidades;
			if( num_modalidades < 1 )
				throw NumModalidadesInvalido();
			else
				exception_finish = false;
		} catch (NumModalidadesInvalido &e) {
			e.what();
		}
	}

	cout << endl;

	vector<string> mods;

	//form para todas as modalidades do desporto
	for ( unsigned int i = 0; i < num_modalidades; i++ ) {
		cin.clear();
		cin.sync();

		exception_finish = true;
		while (exception_finish) {
			try {
				cout << " Nome da Modalidade " << i+1 << ": ";
				getline(cin, nome_modalidade);
				if( campeonato.existsModalidade(nome_modalidade) == true )
					throw ModalidadeJaExistente(nome_modalidade);
				else
					exception_finish = false;
			} catch (ModalidadeJaExistente &e) {
				e.what();
			}
		}

		mods.push_back(nome_modalidade);
	}

	//criaçao do objeto da classe desporto para adicionar ao campeonato
	Desporto *desp = new Desporto(nome_desporto);

	for ( unsigned int j = 0; j < mods.size(); j++ ) {
		string modalidade_string = mods[j];
		Modalidade *modal = new Modalidade(modalidade_string);
		desp->pushModalidade(modal);
		campeonato.addModalidade(modal);
	}

	campeonato.addDesporto(desp);

	cout << endl << " Desporto e modalidades adicionados com sucesso!";
}


// Apaga um desporto com um nome especifico e respetivas modalidades do campeonato
void RetirarDesporto() {
	string nome_desporto;

	cin.clear();
	cin.sync();

	exception_finish = true;
	while (exception_finish) {
		try {
			cout << " Qual o nome do desporto que pretende apagar: ";
			getline(cin, nome_desporto);
			if( campeonato.existsDesporto(nome_desporto) == false )
				throw DesportoInexistente(nome_desporto);
			else
				exception_finish = false;
		} catch (DesportoInexistente &e) {
			e.what();
		}
	}

	cout << endl;

	campeonato.eraseDesporto(nome_desporto);

	campeonato.saveModalidade();
	campeonato.saveDesporto();

	cout << " Equipa apagada do campeonato com sucesso!";
}


// Apresenta o form para adicionar atletas à modalidade
void AdicionarAtletasModalidade() {
	string nome_modalidade, nome_atleta;
	unsigned int num_atletas;

	cin.clear();
	cin.sync();

	exception_finish = true;
	while (exception_finish) {
		try {
			cout << " Em que modalidade pretende adicionar atletas: ";
			getline(cin, nome_modalidade);
			if( campeonato.existsModalidade(nome_modalidade) == false )
				throw ModalidadeInexistente(nome_modalidade);
			else
				exception_finish = false;
		} catch (ModalidadeInexistente &e) {
			e.what();
		}
	}

	exception_finish = true;
	while (exception_finish) {
		try {
			cout << " Quantos atletas pretende adicionar: ";
			cin >> num_atletas;
			if( num_atletas < 1 )
				throw NumAtletasInvalido();
			else
				exception_finish = false;
		} catch (NumAtletasInvalido &e) {
			e.what();
		}
	}

	cout << endl;

	Atleta *atl;
	vector<Atleta*> athletes;

	//form para todos os atletas a adicionar na modalidade
	for ( unsigned int i = 0; i < num_atletas; i++ ) {
		cin.clear();
		cin.sync();

		exception_finish = true;
		while (exception_finish) {
			try {
				cout << " Nome do Atleta " << i+1 << ": ";
				getline(cin, nome_atleta);
				if( campeonato.existsAtleta(nome_atleta) == false )
					throw AtletaInexistente(nome_atleta);
				else {
					if( campeonato.CanAtletaEnterModalidade(nome_modalidade, nome_atleta) == false )
						throw ModalidadeInvalida(nome_modalidade, nome_atleta);
					else
						exception_finish = false;
				}
			} catch (AtletaInexistente &e) {
				e.what();
			} catch (ModalidadeInvalida &e) {
				e.what();
			}
		}

		atl = campeonato.findAtleta(nome_atleta);
		athletes.push_back(atl);
	}

	Modalidade *mod;
	mod = campeonato.findModalidade(nome_modalidade);
	int index = campeonato.findModalidadeIndex(nome_modalidade);

	for ( unsigned int j = 0; j < athletes.size(); j++ ) {
		mod->pushAtleta(athletes[j]);
	}

	// Troca a modalidade em index pela modalidade mod e guarda
	campeonato.changeModalidade(index, mod);
	campeonato.saveModalidade();

	cout << endl << " Atletas adicionados à modalidade com sucesso!";
}


// Retira um numero especifico de atletas da modalidade
void RetirarAtletasModalidade() {
	string nome_modalidade, nome_atleta;
	unsigned int num_atletas;

	cin.clear();
	cin.sync();

	exception_finish = true;
	while (exception_finish) {
		try {
			cout << " A que modalidade pretende retirar atletas: ";
			getline(cin, nome_modalidade);
			if( campeonato.existsModalidade(nome_modalidade) == false )
				throw ModalidadeInexistente(nome_modalidade);
			else
				exception_finish = false;
		} catch (ModalidadeInexistente &e) {
			e.what();
		}
	}

	exception_finish = true;
	while (exception_finish) {
		try {
			cout << " Quantos atletas pretende retirar: ";
			cin >> num_atletas;
			if( num_atletas < 1 )
				throw NumAtletasInvalido();
			else
				exception_finish = false;
		} catch (NumAtletasInvalido &e) {
			e.what();
		}
	}

	cout << endl;

	//form para todos os atletas a retirar na modalidade
	for ( unsigned int i = 0; i < num_atletas; i++ ) {
		cin.clear();
		cin.sync();

		exception_finish = true;
		while (exception_finish) {
			try {
				cout << " Nome do Atleta " << i+1 << ": ";
				getline(cin, nome_atleta);
				if( campeonato.existsAtleta(nome_atleta) == false )
					throw AtletaInexistente(nome_atleta);
				else
					exception_finish = false;
			} catch (AtletaInexistente &e) {
				e.what();
			}
		}

		campeonato.eraseAtletaModalidade(nome_modalidade, nome_atleta);
	}

	campeonato.saveModalidade();

	cout << endl << " Atletas retirados à modalidade com sucesso!";
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
	cout << "- 4. Retirar Atletas à Modalidade             -" << endl;
	cout << "- 5. Voltar ao Menu Principal                 -" << endl;
	cout << "-                                             -" << endl;
	cout << "-----------------------------------------------" << endl;

	cout << " O que pretende fazer? ";
	cin >> escolha_desportos;

	if ( escolha_desportos != 1 && escolha_desportos != 2 && escolha_desportos != 3 && escolha_desportos != 4  && escolha_desportos != 5) {
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
			RetirarDesporto();
			cout << string(8,'\n');
			MenuInicial();
			break;
		case 3:
			cout << string(8,'\n');
			AdicionarAtletasModalidade();
			cout << string(8,'\n');
			MenuInicial();
			break;
		case 4:
			cout << string(8,'\n');
			RetirarAtletasModalidade();
			cout << string(8,'\n');
			MenuInicial();
			break;
		case 5:
			cout << string(8, '\n');
			MenuInicial();
			break;
	}
}


/**
 *  MENUS RELACIONADOS COM PROVAS
 */


void CriarProva(){
	int dia, mes, ano;
	string nome_modalidade, nome_infrastrutura;
	string nome_prova;

	cin.clear();
	cin.sync();

	exception_finish = true;
	while (exception_finish){
		try {
			cout << " Qual a modalidade a que pertence a prova? ";
			getline(cin, nome_modalidade);
			if (campeonato.existsModalidade(nome_modalidade) == false)
				throw ModalidadeInexistente(nome_modalidade);
			else
				exception_finish = false;
		} catch (ModalidadeInexistente &e) {
			e.what();
		}
	}

	exception_finish = true;
	while (exception_finish){
		try {
			cout << " Em que infrastrutura se vai desenrolar a prova? ";
			getline(cin, nome_infrastrutura);
			if (campeonato.existsInfrastrutura(nome_infrastrutura) == false)
				throw InfrastruturaInexistente(nome_infrastrutura);
			else
				exception_finish = false;
		} catch (InfrastruturaInexistente &e) {
			e.what();
		}
	}

	cout << " Qual o nome da prova? ";
	getline(cin, nome_prova);
	cout << endl;
	cout << " Data da prova (dia mes ano): ";
	cin >> dia >> mes >> ano;
	//campeonato.findModalidade(nome)->CriarProva(prova,dia,mes,ano);

	/*for (unsigned int i =0; i<campeonato.findModalidade(nome)->getProvas().size();i++ ){
		cout << campeonato.findModalidade(nome)->getProvas()[i]->getNome();
		cout <<endl;
	}*/

	Modalidade *mod = campeonato.findModalidade(nome_modalidade);
	Infrastrutura *infra = campeonato.findInfrastrutura(nome_infrastrutura);

	//criaçao do objeto da classe prova para adicionar à modalidade
	Prova *prova;

	prova = new Prova(nome_prova, dia, mes, ano);
	prova->setModalidade(mod);
	prova->setInfrastrutura(infra);

	campeonato.addProva(prova);

	cout << " Prova adicionada à modalidade com sucesso!";

}


/*void EliminarProva(){
	string nome;
	string prova;

	exception_finish = true;
	while (exception_finish) {
		try {
			cout << " Qual a modalidade a q pretende eliminar provas? ";
			getline(cin, nome);
			if( campeonato.existsModalidade(nome) == false )
				throw ModalidadeInexistente(nome);
			else
				exception_finish = false;
		} catch (ModalidadeInexistente &e) {
			e.what();
		}
	}

	cout << " Qual o nome da prova que quer eliminar? ";
	cin >> prova;
	campeonato.findModalidade(nome)->EliminaProva(prova);
}*/


void MenuProvas() {
	int escolha_provas;

	cout << "------------------------------------------------" << endl;
	cout << "-                 ** Provas **                 -" << endl;
	cout << "-                                              -" << endl;
	cout << "- 1. Criar Prova                               -" << endl;
	cout << "- 2. Eliminar Prova                            -" << endl;
	cout << "- 3. Lançar classificações de uma prova        -" << endl;
	cout << "- 4. Mudar infrastrutura de uma prova          -" << endl;
	cout << "- 5. Voltar ao Menu Principal                  -" << endl;
	cout << "-                                              -" << endl;
	cout << "------------------------------------------------" << endl;

	cout << " O que pretende fazer? ";
	cin >> escolha_provas;

	if ( escolha_provas != 1 && escolha_provas != 2 && escolha_provas != 3 && escolha_provas != 4  && escolha_provas != 5) {
		cout << " Por favor, faça uma escolha adequada.";
		cout << string(8,'\n');
		MenuProvas();
	}

	switch (escolha_provas) {
		case 1:
			cout << string(8,'\n');
			CriarProva();
			cout << string(8,'\n');
			MenuInicial();
			break;
		case 2:
			cout << string(8,'\n');
			//EliminarProva();
			cout << string(8,'\n');
			MenuInicial();
			break;
		case 3:
			cout << string(8,'\n');
			//ClassificacaoProva();
			cout << string(8,'\n');
			MenuInicial();
			break;
		case 4:
			cout << string(8,'\n');
			//MudarInfrastrutura();
			cout << string(8,'\n');
			MenuInicial();
			break;
		case 5:
			cout << string(8, '\n');
			MenuInicial();
			break;
	}
}


/**
 *  MENUS RELACIONADOS COM INFRASTRUTURAS E FUNCIONARIOS
 */


// Apresenta o form para a adição da infrastrutura ao campeonato
void AdicionarInfrastrutura() {
	string nome_infrastrutura, cidade_infrastrutura;

	cin.clear();
	cin.sync();

	exception_finish = true;
	while (exception_finish) {
		try {
			cout << " Nome da Infrastrutura: ";
			getline(cin, nome_infrastrutura);
			if( campeonato.existsInfrastrutura(nome_infrastrutura) == true )
				throw InfrastruturaJaExistente(nome_infrastrutura);
			else
				exception_finish = false;
		} catch (InfrastruturaJaExistente &e) {
			e.what();
		}
	}

	cout << " Cidade da Infrastrutura: ";
	getline(cin, cidade_infrastrutura);
	cout << endl;

	Infrastrutura *infra = new Infrastrutura(nome_infrastrutura, cidade_infrastrutura);
	campeonato.addInfrastrutura(infra);

	cout << endl << " Infrastrutura adicionada com sucesso!";
}


// Apresenta o form para apagar a infrastrutura ao campeonato
void ApagarInfrastrutura() {
	string nome_infrastrutura;

	cin.clear();
	cin.sync();

	exception_finish = true;
	while (exception_finish) {
		try {
			cout << " Nome da Infrastrutura a apagar: ";
			getline(cin, nome_infrastrutura);
			if( campeonato.existsInfrastrutura(nome_infrastrutura) == false )
				throw InfrastruturaInexistente(nome_infrastrutura);
			else
				exception_finish = false;
		} catch (InfrastruturaInexistente &e) {
			e.what();
		}
	}

	campeonato.eraseInfrastrutura(nome_infrastrutura);
	campeonato.saveInfrastrutura();

	cout << endl << " Infrastrutura apagada com sucesso!";
}


/*void Atribuirinfrastrutura(){
	string nome;
	string nomeProva;
	string nomeinfrastrutura;
	cout << "Nome da modalidade ?";
	getline(cin,nome);
	cout << "Nome da prova ?";
	getline(cin,nomeProva);

	exception_finish = true;
	while (exception_finish) {
		try {
			cout<< "Nome da infrastrutura necessária ?";
			getline(cin, nomeinfrastrutura);
			if( campeonato.existsInfrastrutura(nomeinfrastrutura) == false )
				throw InfrastruturaInexistente(nomeinfrastrutura);
			else
				exception_finish = false;
		} catch (InfrastruturaInexistente &e) {
			e.what();
		}
	}
	campeonato.AtribuiInfrastrutura(nome,nomeProva,nomeinfrastrutura);
}


void  Retirarinfrastrutura(){
	string nome;
	string nomeProva, nomeinfrastrutura;
	cout << "Nome da modalidade ?";
	getline(cin,nome);
	cout << "Nome da prova ?";
	getline(cin,nomeProva);

	exception_finish = true;
	while (exception_finish) {
		try {
			cout<< "Nome da infrastrutura que já não é necessária ?";
			getline(cin, nomeinfrastrutura);
			if( campeonato.existsInfrastrutura(nomeinfrastrutura) == false )
				throw InfrastruturaInexistente(nomeinfrastrutura);
			else
				exception_finish = false;
		} catch (InfrastruturaInexistente &e) {
			e.what();
		}
	}
	campeonato.AtribuiInfrastrutura(nome,nomeProva,"vazio");
}*/


// Apresenta o form para a adição de um funcionário ao campeonato
void AdicionarFuncionario() {
	string nome_funcionario;
	int idade_funcionario;

	exception_finish = true;
	while (exception_finish) {
		try {
			cin.clear();
			cin.sync();
			cout << " Nome do Funcionario: ";
			getline(cin, nome_funcionario);
			if( campeonato.existsFuncionario(nome_funcionario) == true )
				throw FuncionarioJaExistente(nome_funcionario);
			else {

				cout << " Idade do Funcionario: ";
				cin >> idade_funcionario;
				if( idade_funcionario < 18 )
					throw IdadeInvalida();
				else
					exception_finish = false;
			}
		} catch (FuncionarioJaExistente &e) {
			e.what();
		} catch (IdadeInvalida &e) {
			e.what();
		}
	}

	Funcionario *func = new Funcionario(nome_funcionario, idade_funcionario, 0);
	campeonato.addFuncionario(func);

	cout << endl << " Funcionario adicionado com sucesso!";
}


// Apresenta o form para despedir o funcionario do campeonato
void ApagarFuncionario() {
	string nome_funcionario;

	cin.clear();
	cin.sync();

	exception_finish = true;
	while (exception_finish) {
		try {
			cout << " Nome do Funcionario a despedir: ";
			getline(cin, nome_funcionario);
			if( campeonato.existsFuncionario(nome_funcionario) == false )
				throw FuncionarioInexistente(nome_funcionario);
			else
				exception_finish = false;
		} catch (FuncionarioInexistente &e) {
			e.what();
		}
	}

	campeonato.eraseFuncionario(nome_funcionario);
	campeonato.saveFuncionario();

	cout << endl << " Funcionario despedido com sucesso!";
}


// Menu de Manutenção das Infrastruturas do campeonato
void MenuInfrastruturas() {
	int escolha_infrastruturas;

	cout << "----------------------------------------------" << endl;
	cout << "-     ** Infrastruturas e Funcionários**     -" << endl;
	cout << "-                                            -" << endl;
	cout << "- 1. Adicionar Infrastrutura                 -" << endl;
	cout << "- 2. Apagar Infrastrutura                    -" << endl;
	cout << "- 3. Adicionar Funcionario                   -" << endl;
	cout << "- 4. Despedir Funcionario                    -" << endl;
	cout << "- 5. Voltar ao Menu Principal                -" << endl;
	cout << "-                                            -" << endl;
	cout << "----------------------------------------------" << endl;

	cout << " O que pretende fazer? ";
	cin >> escolha_infrastruturas;

	if ( escolha_infrastruturas != 1 && escolha_infrastruturas != 2 && escolha_infrastruturas != 3 && escolha_infrastruturas != 4 && escolha_infrastruturas != 5) {
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
			ApagarInfrastrutura();
			cout << string(8,'\n');
			MenuInicial();
			break;
		case 3:
			cout <<string(8,'\n');
			AdicionarFuncionario();
			cout << string(8,'\n');
			MenuInicial();
			break;
		case 4:
			cout <<string(8,'\n');
			ApagarFuncionario();
			cout << string(8,'\n');
			MenuInicial();
			break;
		case 5:
			cout << string(8,'\n');
			MenuInicial();
			break;
	}
}


/**
 *  MENUS RELACIONADOS COM AS LISTAGENS
 */
void MenuAtletas(){
	string resposta1,modalidade;
	int num;
	for (unsigned int i=0; i< campeonato.getModalidades().size();i++){
		cout <<"Modalidade:" << campeonato.getModalidades()[i]->getNome()<<endl;
		for (unsigned int j=0; j <campeonato.getModalidades()[i]->getAtletas().size();j++){
			cout << j+1 <<":" << campeonato.getModalidades()[i]->getAtletas()[j]->getNome() << endl;
		}
		cout <<endl;
	}
	cout << "deseja ver as informações de algum atleta ? (s,n)";
	cin >>resposta1;
	bool coisa= true;
	while (coisa){
	if (resposta1 == "s"){
		cout << "Qual modalidade ?";
		cin >>modalidade;
		cout << "Qual o numero da lista é o atleta ?";
		cin >> num;
		campeonato.findModalidade(modalidade)->getAtletas()[num-1]->info();
		coisa =false;
	}
	else if (resposta1=="n") coisa=false;
	else cout <<"introduza uma opção correta, s ou n!";
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
	cout << "- 7. Voltar ao Menu Principal               -" << endl;
	cout << "-                                           -" << endl;
	cout << "---------------------------------------------" << endl;

	cout << " O que pretende fazer? ";
	cin >> escolha_listagens;

	if ( escolha_listagens != 1 && escolha_listagens != 2 && escolha_listagens != 3 && escolha_listagens != 4 && escolha_listagens != 5 && escolha_listagens != 6  && escolha_listagens != 7 ) {
		cout << " Por favor, faça uma escolha adequada.";
		cout << string(8,'\n');
		MenuInicial();
	}

	switch (escolha_listagens) {
		case 1:
			cout << string(8,'\n');
			MenuAtletas();
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

		case 7:
			cout <<string(8,'\n');
			MenuInicial();
			break;
	}
}


/**
 *  MENU INICIAL
 */
/*void MenuCalendario(){
	string nome;
	int dia,mes,ano;
	cout << "Data (dia mes ano) ?";
	cin >> dia >> mes >> ano;
	cin.ignore();
	cout << "Que modalidade deseja ver a calendarização de provas ";
	getline(cin,nome);
	cout << campeonato.findModalidade(nome)->getNome() << endl;
	cout <<endl;
	cout << "provas que já passaram: ";
	for (unsigned int i=0; i< campeonato.findModalidade(nome)->getProvas().size();i++ ){
		if (campeonato.findModalidade(nome)->getProvas()[i]->getAno()< ano)
		cout << campeonato.findModalidade(nome)->getProvas()[i]->getNome()<< " "<<campeonato.findModalidade(nome)->getProvas()[i]->getDia() <<"/"<<campeonato.findModalidade(nome)->getProvas()[i]->getMes() <<"/"<<campeonato.findModalidade(nome)->getProvas()[i]->getAno()<<endl;
		else if (campeonato.findModalidade(nome)->getProvas()[i]->getAno()==ano){
			if(campeonato.findModalidade(nome)->getProvas()[i]->getMes() < mes)
				cout << campeonato.findModalidade(nome)->getProvas()[i]->getNome()<< " "<<campeonato.findModalidade(nome)->getProvas()[i]->getDia() <<"/"<<campeonato.findModalidade(nome)->getProvas()[i]->getMes() <<"/"<<campeonato.findModalidade(nome)->getProvas()[i]->getAno()<<endl;
			else if (campeonato.findModalidade(nome)->getProvas()[i]->getMes()== mes){
				if (campeonato.findModalidade(nome)->getProvas()[i]->getDia()< dia)
					cout << campeonato.findModalidade(nome)->getProvas()[i]->getNome()<< " "<<campeonato.findModalidade(nome)->getProvas()[i]->getDia() <<"/"<<campeonato.findModalidade(nome)->getProvas()[i]->getMes() <<"/"<<campeonato.findModalidade(nome)->getProvas()[i]->getAno()<<endl;
		}
		}
}
	cout << endl;
	cout << "Provas que ainda não aconteceram ou estão a acontecer:";
	for (unsigned int i=0; i< campeonato.findModalidade(nome)->getProvas().size();i++ ){
			if (campeonato.findModalidade(nome)->getProvas()[i]->getAno()> ano)
			cout << campeonato.findModalidade(nome)->getProvas()[i]->getNome()<< " "<<campeonato.findModalidade(nome)->getProvas()[i]->getDia() <<"/"<<campeonato.findModalidade(nome)->getProvas()[i]->getMes() <<"/"<<campeonato.findModalidade(nome)->getProvas()[i]->getAno()<<endl;
			else if (campeonato.findModalidade(nome)->getProvas()[i]->getAno()==ano){
				if(campeonato.findModalidade(nome)->getProvas()[i]->getMes() > mes)
					cout << campeonato.findModalidade(nome)->getProvas()[i]->getNome()<< " "<<campeonato.findModalidade(nome)->getProvas()[i]->getDia() <<"/"<<campeonato.findModalidade(nome)->getProvas()[i]->getMes() <<"/"<<campeonato.findModalidade(nome)->getProvas()[i]->getAno()<<endl;
				else if (campeonato.findModalidade(nome)->getProvas()[i]->getMes()== mes){
					if (campeonato.findModalidade(nome)->getProvas()[i]->getDia()> dia)
						cout << campeonato.findModalidade(nome)->getProvas()[i]->getNome()<< " "<<campeonato.findModalidade(nome)->getProvas()[i]->getDia() <<"/"<<campeonato.findModalidade(nome)->getProvas()[i]->getMes() <<"/"<<campeonato.findModalidade(nome)->getProvas()[i]->getAno()<<endl;
					else if (campeonato.findModalidade(nome)->getProvas()[i]->getDia()== dia)
						cout <<"ESTA A DECORRER HOJE, APRESSE-SE A IR PARA O LOCAL " <<campeonato.findModalidade(nome)->getProvas()[i]->getNome()<< " "<<campeonato.findModalidade(nome)->getProvas()[i]->getDia() <<"/"<<campeonato.findModalidade(nome)->getProvas()[i]->getMes() <<"/"<<campeonato.findModalidade(nome)->getProvas()[i]->getAno()<<endl;
			}
			}
	}
}*/


// Menu Inicial, chama todos os outros Menus mediante a escolha do utilizador
void MenuInicial() {
	int escolha_menu;

	cout << "----------------------------------------------------" << endl;
	cout << "-            *** Menu Principal ***                -" << endl;
	cout << "-                                                  -" << endl;
	cout << "- 1. Manutenção de Equipas e Atletas               -" << endl;
	cout << "- 2. Manutenção de Desportos, Modalidades e Provas -" << endl;
	cout << "- 3. Manutenção do Calendário                      -" << endl;
	cout << "- 4. Manutenção das Provas                         -" << endl;
	cout << "- 5. Manutenção de Infrastruturas e Funcionários   -" << endl;
	cout << "- 6. Listagens                                     -" << endl;
	cout << "- 7. Terminar o programa                           -" << endl;
	cout << "-                                                  -" << endl;
	cout << "----------------------------------------------------" << endl;

	cout << " O que pretende fazer? ";
	cin >> escolha_menu;

	if ( escolha_menu != 1 && escolha_menu != 2 && escolha_menu != 3 && escolha_menu != 4 && escolha_menu != 5 && escolha_menu != 6 && escolha_menu != 7) {
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
			MenuProvas();
			break;
		case 5:
			cout << string(8,'\n');
			MenuInfrastruturas();
			break;
		case 6:
			cout << string(8,'\n');
			MenuListagens();
			break;
		case 7:
			return;
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
	if ( file_isEmpty(file_equipas) == true )
		remove(file_equipas);
	if ( file_isEmpty(file_atletas) == true )
		remove(file_atletas);
	if ( file_isEmpty(file_modalidades) == true )
		remove(file_modalidades);
	if ( file_isEmpty(file_desportos) == true )
		remove(file_desportos);
	if ( file_isEmpty(file_infrastruturas) == true )
		remove(file_infrastruturas);
	if ( file_isEmpty(file_funcionarios) == true )
		remove(file_funcionarios);
	if ( file_isEmpty(file_provas) == true )
		remove(file_provas);

	// Carrega a informação para os respetivos vetores
	campeonato.loadEquipas();
	campeonato.loadAtletas();
	campeonato.loadModalidades();
	campeonato.loadDesportos();
	campeonato.loadInfrastruturas();
	campeonato.loadFuncionarios();
	campeonato.loadProvas();

	// Chama o Menu Inicial
	MenuInicial();

	return 0;
}

