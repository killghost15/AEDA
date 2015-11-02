#include "Campeonato.h"


vector<Desporto> Campeonato::getDesportos() {
	return desportos;
}

vector<Infrastrutura> Campeonato::getInfrastruturas() {
	return infrastruturas;
}



// Carraga a informação das infrastruturas do ficheiro infrastruturas.txt
void Campeonato::loadInfrastruturas() {
	string nome, cidade;
	string trash;
	Infrastrutura *infra;

	ifstream fileinfra;
	fileinfra.open(file_infrastruturas);

	if ( fileinfra.is_open() ) {

		while ( !fileinfra.eof() ) {
			getline(fileinfra, nome);
			getline(fileinfra, cidade);
			getline(fileinfra, trash);	// trash não é usada para nada, apenas para ignorar 1 linha
			infra = new Infrastrutura(nome, cidade);
			infrastruturas.push_back(*infra);
		}

		fileinfra.close();
	}
}


// Guarda a infrastrutura no ficheiro infrastruturas.txt
void Campeonato::saveInfrastrutura() {
	ofstream fileinfra;
	fileinfra.open(file_infrastruturas);

	vector<Infrastrutura>::iterator it = infrastruturas.begin();

	//guarda apenas a primeira infrastrutura
	fileinfra << (*it).getNome() << endl;
	fileinfra << (*it).getCidade();
	it++;

	//guarda as restantes infrastruturas
	for ( ; it != infrastruturas.end(); it++ ) {
		fileinfra << endl << endl;
		fileinfra << (*it).getNome() << endl;
		fileinfra << (*it).getCidade();
	}

	fileinfra.close();
}


// Adiciona a infrastrutura no vetor e guarda no ficheiro
void Campeonato::addInfrastrutura(Infrastrutura &infra) {
	infrastruturas.push_back(infra);
	saveInfrastrutura();
}


// Carrega a informação dos desportos do ficheiro desportos.txt
void Campeonato::loadDesportos() {
	string nome_desp, nome_mod;
	Desporto *desp;

	ifstream filedesp;
	filedesp.open(file_desportos);

	if ( filedesp.is_open() ) {

		while ( !filedesp.eof() ) {

			getline(filedesp, nome_desp);

			desp = new Desporto(nome_desp);

			vector<string> mods;
			while ( true ) {
				getline(filedesp, nome_mod);

				if ( nome_mod != "" ) {
					nome_mod.erase(nome_mod.begin());
					mods.push_back(nome_mod);
				}
				else
					break;
			}

			for ( unsigned int j = 0; j < mods.size(); j++ ) {
				string modalidade_string = mods[j];
				Modalidade *modal = new Modalidade(modalidade_string);
				desp->pushModalidade(*modal);
			}

			mods.clear();
			desportos.push_back(*desp);
		}

		filedesp.close();
	}
}


// Guarda o desporto no ficheiro desportos.txt
void Campeonato::saveDesporto() {
	ofstream filedesp;
	filedesp.open(file_desportos);

	//guarda apenas o primeiro desporto
	filedesp << desportos[0].getNome();

	//guarda as modalidades do primeiro desporto
	for( unsigned int i = 0; i < desportos[0].getModalidades().size(); i++ ) {
		filedesp << endl;
		filedesp << " " << desportos[0].getModalidades()[i].getNome();
	}

	filedesp << endl;

	//guarda os restantes desportos
	for ( unsigned int j = 1; j < desportos.size(); j++ ) {
		filedesp << endl;
		filedesp << desportos[j].getNome();

		for( unsigned int i = 0; i < desportos[j].getModalidades().size(); i++ ) {
			filedesp << endl;
			filedesp << " " << desportos[j].getModalidades()[i].getNome();
		}

		filedesp << endl;
	}

	filedesp.close();
}


// Adiciona o desporto no vetor e guarda no ficheiro
void Campeonato::addDesporto(Desporto &desp) {
	desportos.push_back(desp);
	saveDesporto();
}


// Carrega a informação das equipas do ficheiro equipas.txt ///////////////////////////
/*void Campeonato::loadEquipas() {
	string nome_desp, nome_mod;
	Desporto *desp;

	ifstream filedesp;
	filedesp.open(file_desportos);

	if ( filedesp.is_open() ) {

		while ( !filedesp.eof() ) {

			getline(filedesp, nome_desp);

			desp = new Desporto(nome_desp);

			vector<string> mods;
			while ( true ) {
				getline(filedesp, nome_mod);

				if ( nome_mod != "" ) {
					nome_mod.erase(nome_mod.begin());
					mods.push_back(nome_mod);
				}
				else
					break;
			}

			for ( unsigned int j = 0; j < mods.size(); j++ ) {
				string modalidade_string = mods[j];
				Modalidade *modal = new Modalidade(modalidade_string);
				desp->pushModalidade(*modal);
			}

			mods.clear();
			desportos.push_back(*desp);
		}

		filedesp.close();
	}
}*/


// Guarda a equipa no ficheiro equipas.txt
void Campeonato::saveEquipa() {
	ofstream fileequi;
	fileequi.open(file_equipas);

	//guarda apenas a primeira equipa
	fileequi << equipas[0].getNome();

	//guarda os desportos da primeira equipa
	for( unsigned int i = 0; i < equipas[0].getDesportos().size(); i++ ) {
		fileequi << endl;
		fileequi << " " << equipas[0].getDesportos()[i].getNome();
	}

	fileequi << endl;

	//guarda as restantes equipas
	for ( unsigned int j = 1; j < equipas.size(); j++ ) {
		fileequi << endl;
		fileequi << equipas[j].getNome();

		for( unsigned int i = 0; i < equipas[j].getDesportos().size(); i++ ) {
			fileequi << endl;
			fileequi << " " << equipas[j].getDesportos()[i].getNome();
		}

		fileequi << endl;
	}

	fileequi.close();
}


// Adiciona o desporto no vetor e guarda no ficheiro
void Campeonato::addEquipa(Equipa &equi) {
	equipas.push_back(equi);
	saveEquipa();
}

