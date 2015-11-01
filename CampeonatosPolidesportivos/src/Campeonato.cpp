#include "Campeonato.h"


vector<Desporto> Campeonato::getDesportos() {
	return desportos;
}

vector<Infrastrutura> Campeonato::getInfrastruturas() {
	return infrastruturas;
}



// Carraga a informa��o das infrastruturas do ficheiro infrastruturas.txt
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
			getline(fileinfra, trash);	// trash n�o � usada para nada, apenas para ignorar 1 linha
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


// Carraga a informa��o dos desportos do ficheiro desportos.txt
void Campeonato::loadDesportos() {
	string nome_desp, nome_mod;
	//string trash;
	//Desporto *desp;


	ifstream filedesp;
	filedesp.open(file_desportos);

	if ( filedesp.is_open() ) {

		while ( !filedesp.eof() ) {

			getline(filedesp, nome_desp);

			Desporto *desp = new Desporto(nome_desp);

			vector<string> mods;
			while ( true ) {

				getline(filedesp, nome_mod);

				if ( nome_mod != "" ) {
					nome_mod.erase(nome_mod.begin());
					mods.push_back(nome_mod);
				}
				else {
					break;
				}

			}

			for ( unsigned int j = 0; j < mods.size(); j++ ) {
				string cena = mods[j];
				Modalidade *modal = new Modalidade(cena);
				desp->pushModalidade(*modal);
			}
			mods.clear();
			//getline(filedesp, trash);	// trash n�o � usada para nada, apenas para ignorar 1 linha
			desportos.push_back(*desp);

			//cout << "asd";
			//int qwe;
			//cin >> qwe;
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

