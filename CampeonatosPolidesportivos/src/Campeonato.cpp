#include "Campeonato.h"


vector<Atleta> Campeonato::getAtletas() {
	return atletas;
}

vector<Desporto> Campeonato::getDesportos() {
	return desportos;
}

vector<Equipa> Campeonato::getEquipas() {
	return equipas;
}

vector<Infrastrutura> Campeonato::getInfrastruturas() {
	return infrastruturas;
}



// Carraga a informação das infrastruturas do ficheiro infrastruturas.txt
void Campeonato::loadInfrastruturas() {
	string nome_infrastrutura, cidade_infrastrutura;
	string trash;
	Infrastrutura *infra;

	ifstream fileinfra;
	fileinfra.open(file_infrastruturas);

	if ( fileinfra.is_open() ) {

		while ( !fileinfra.eof() ) {
			getline(fileinfra, nome_infrastrutura);
			getline(fileinfra, cidade_infrastrutura);
			getline(fileinfra, trash);	// trash não é usada para nada, apenas para ignorar 1 linha
			infra = new Infrastrutura(nome_infrastrutura, cidade_infrastrutura);
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


// Carrega a informação das equipas do ficheiro equipas.txt
void Campeonato::loadEquipas() {
	string nome_equi, nome_desp;
	Equipa *equi;

	ifstream fileequi;
	fileequi.open(file_equipas);

	if ( fileequi.is_open() ) {

		while ( !fileequi.eof() ) {

			getline(fileequi, nome_equi);

			equi = new Equipa(nome_equi);

			vector<string> sports;
			while ( true ) {
				getline(fileequi, nome_desp);

				if ( nome_desp != "" ) {
					nome_desp.erase(nome_desp.begin());
					sports.push_back(nome_desp);
				}
				else
					break;
			}

			for ( unsigned int j = 0; j < sports.size(); j++ ) {
				string desporto_string = sports[j];
				equi->pushDesporto(desporto_string);
			}

			sports.clear();
			equipas.push_back(*equi);
		}

		fileequi.close();
	}
}


// Guarda a equipa no ficheiro equipas.txt
void Campeonato::saveEquipa() {
	ofstream fileequi;
	fileequi.open(file_equipas);

	//guarda apenas a primeira equipa
	fileequi << equipas[0].getNome();

	//guarda os desportos da primeira equipa
	for( unsigned int i = 0; i < equipas[0].getDesportos().size(); i++ ) {
		fileequi << endl;
		fileequi << " " << equipas[0].getDesportos()[i];
	}

	fileequi << endl;

	//guarda as restantes equipas
	for ( unsigned int j = 1; j < equipas.size(); j++ ) {
		fileequi << endl;
		fileequi << equipas[j].getNome();

		for( unsigned int i = 0; i < equipas[j].getDesportos().size(); i++ ) {
			fileequi << endl;
			fileequi << " " << equipas[j].getDesportos()[i];
		}

		fileequi << endl;
	}

	fileequi.close();
}


// Adiciona a equipa no vetor e guarda no ficheiro
void Campeonato::addEquipa(Equipa &equi) {
	equipas.push_back(equi);
	saveEquipa();
}


// Carrega a informação dos atletas do ficheiro atletas.txt
void Campeonato::loadAtletas() {
	string nome_atleta, nome_equipa;
	unsigned int idade_atleta;
	float peso_atleta, estatura_atleta;
	string trash;

	Atleta *atl;

	ifstream fileatl;
	fileatl.open(file_atletas);

	if ( fileatl.is_open() ) {

		while ( !fileatl.eof() ) {
			cout << "asd";
				int flag;
				cin >> flag;
			getline(fileatl, nome_atleta);
			fileatl >> idade_atleta;	//também faz \n
			fileatl >> peso_atleta;
			fileatl >> estatura_atleta;
			getline(fileatl, nome_equipa);
			getline(fileatl, trash);	// trash não é usada para nada, apenas para ignorar 1 linha
			Equipa *equi = new Equipa(nome_equipa);
			atl = new Atleta(nome_atleta, idade_atleta, peso_atleta, estatura_atleta);
			atl->setEquipa(equi);
			atletas.push_back(*atl);
		}

		fileatl.close();
	}
}


// Guarda o atleta no ficheiro atletas.txt
void Campeonato::saveAtleta() {
	ofstream fileatl;
	fileatl.open(file_atletas);

	//guarda apenas a primeira equipa
	fileatl << atletas[0].getNome() << endl;
	fileatl << atletas[0].getIdade() << endl;
	fileatl << atletas[0].getPeso() << endl;
	fileatl << atletas[0].getEstatura() << endl;
	fileatl << " " << atletas[0].getEquipa()->getNome();

	//guarda os restantes atletas
	for ( unsigned int j = 1; j < atletas.size(); j++ ) {
		fileatl << endl << endl;
		fileatl << atletas[j].getNome() << endl;
		fileatl << atletas[j].getIdade() << endl;
		fileatl << atletas[j].getPeso() << endl;
		fileatl << atletas[j].getEstatura() << endl;
		fileatl << " " << atletas[j].getEquipa()->getNome();
	}

	fileatl.close();
}


// Adiciona o atleta no vetor e guarda no ficheiro
void Campeonato::addAtleta(Atleta &atl) {
	atletas.push_back(atl);
	saveAtleta();
}


