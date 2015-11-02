#include "Campeonato.h"


vector<Atleta> Campeonato::getAtletas() {
	return atletas;
}

vector<Desporto> Campeonato::getDesportos() {
	return desportos;
}

vector<Equipa*> Campeonato::getEquipas() {
	return equipas;
}

vector<Modalidade> Campeonato::getModalidades() {
	return modalidades;
}

vector<Infrastrutura> Campeonato::getInfrastruturas() {
	return infrastruturas;
}


// Procura uma equipa com um nome especifico no vetor equipas
Equipa* Campeonato::findEquipa(string nomeEquipa) {
	//vector<Equipa>::iterator it;
	Equipa *equi;

	for( unsigned int i = 0; i < equipas.size(); i++ ) {
		if( equipas[i]->getNome() == nomeEquipa )
			equi = equipas[i];
	}

	return equi;

}



// Carraga a informa��o das infrastruturas do ficheiro infrastruturas.txt
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
			getline(fileinfra, trash);	// trash n�o � usada para nada, apenas para ignorar 1 linha
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


// Carrega a informa��o dos desportos do ficheiro desportos.txt
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


// Carrega a informa��o das equipas do ficheiro equipas.txt
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
			equipas.push_back(equi);
		}

		fileequi.close();
	}
}


// Guarda a equipa no ficheiro equipas.txt
void Campeonato::saveEquipa() {
	ofstream fileequi;
	fileequi.open(file_equipas);

	//guarda apenas a primeira equipa
	fileequi << equipas[0]->getNome();

	//guarda os desportos da primeira equipa
	for( unsigned int i = 0; i < equipas[0]->getDesportos().size(); i++ ) {
		fileequi << endl;
		fileequi << " " << equipas[0]->getDesportos()[i];
	}

	fileequi << endl;

	//guarda as restantes equipas
	for ( unsigned int j = 1; j < equipas.size(); j++ ) {
		fileequi << endl;
		fileequi << equipas[j]->getNome();

		for( unsigned int i = 0; i < equipas[j]->getDesportos().size(); i++ ) {
			fileequi << endl;
			fileequi << " " << equipas[j]->getDesportos()[i];
		}

		fileequi << endl;
	}

	fileequi.close();
}


// Adiciona a equipa no vetor e guarda no ficheiro
void Campeonato::addEquipa(Equipa *equi) {
	equipas.push_back(equi);
	saveEquipa();
}


// Carrega a informa��o dos atletas do ficheiro atletas.txt
void Campeonato::loadAtletas() {
	string nome_atleta, nome_equipa;
	string idade_atleta, peso_atleta, estatura_atleta;;
	string trash;

	Atleta *atl;

	ifstream fileatl;
	fileatl.open(file_atletas);

	if ( fileatl.is_open() ) {

		while ( !fileatl.eof() ) {
			getline(fileatl, nome_atleta);
			getline(fileatl, idade_atleta);
			getline(fileatl, peso_atleta);
			getline(fileatl, estatura_atleta);
			getline(fileatl, nome_equipa);
			getline(fileatl, trash);	// trash n�o � usada para nada, apenas para ignorar 1 linha

			nome_equipa.erase(nome_equipa.begin());
			int idadeAtleta_int = atoi(idade_atleta.c_str());
			float pesoAtleta_float = atof(peso_atleta.c_str());
			float estaturaAtleta_float = atof(estatura_atleta.c_str());

			Equipa *equi = new Equipa(nome_equipa); // nao pode ser equipa nova, reestruturar
			atl = new Atleta(nome_atleta, idadeAtleta_int, pesoAtleta_float, estaturaAtleta_float);
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

	//guarda apenas o primeira atleta
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


void Campeonato::loadModalidades() {
	string nome_mod, nome_atl;
	Modalidade *modal;

	ifstream filemod;
	filemod.open(file_modalidades);

	if ( filemod.is_open() ) {

		while ( !filemod.eof() ) {

			getline(filemod, nome_mod);

			modal = new Modalidade(nome_mod);

			vector<string> athletes;
			while ( true ) {
				getline(filemod, nome_atl);

				if ( nome_atl != "" ) {
					nome_atl.erase(nome_atl.begin());
					athletes.push_back(nome_atl);
				}
				else
					break;
			}

			for ( unsigned int j = 0; j < athletes.size(); j++ ) {
				string atleta_string = athletes[j];
				Atleta *atl = new Atleta(atleta_string);
				modal->pushAtleta(*atl);
			}

			athletes.clear();
			modalidades.push_back(*modal);
		}

		filemod.close();
	}
}


// Guarda a modalidade no ficheiro modalidades.txt
void Campeonato::saveModalidade() {
	ofstream filemod;
	filemod.open(file_modalidades);

	//guarda apenas a primeira modalidade
	filemod << modalidades[0].getNome();

	//guarda os atletas da primeira modalidade
	for( unsigned int i = 0; i < modalidades[0].getAtletas().size(); i++ ) {
		filemod << endl;
		filemod << " " << modalidades[0].getAtletas()[i].getNome();
	}

	filemod << endl;

	//guarda as restantes modalidades
	for ( unsigned int j = 1; j < modalidades.size(); j++ ) {
		filemod << endl;
		filemod << modalidades[j].getNome();

		for( unsigned int i = 0; i < modalidades[j].getAtletas().size(); i++ ) {
			filemod << endl;
			filemod << " " << modalidades[j].getAtletas()[i].getNome();
		}

		filemod << endl;
	}

	filemod.close();
}


// Adiciona o atleta no vetor e guarda no ficheiro
void Campeonato::addModalidade(Modalidade &modal) {
	modalidades.push_back(modal);
	saveModalidade();
}


