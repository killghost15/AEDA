#include "Campeonato.h"


vector<Desporto> Campeonato::getDesportos() {
	return desportos;
}

vector<Infrastrutura> Campeonato::getInfrastruturas() {
	return infrastruturas;
}



// Carraga a informação da infrastrutura do ficheiro infrastruturas.txt
void Campeonato::loadInfrastruturas() {
	string nome, cidade;
	string trash;
	Infrastrutura *infra;

	ifstream file;
	file.open(file_infrastruturas);

	if ( file.is_open() ) {

		while ( !file.eof() ) {
			getline(file, nome);
			getline(file, cidade);
			getline(file, trash);	// trash não é usada para nada, apenas para ignorar 1 linha
			infra = new Infrastrutura(nome, cidade);
			infrastruturas.push_back(*infra);
		}

		file.close();
	}
}


// Guarda a infrastrutura no ficheiro infrastruturas.txt
void Campeonato::saveInfrastrutura() {
	ofstream file;
	file.open(file_infrastruturas);

	vector<Infrastrutura>::iterator it = infrastruturas.begin();

	//guarda apenas a primeira infrastrutura
	file << (*it).getNome() << endl;
	file << (*it).getCidade();
	it++;

	//guarda as restantes infrastruturas
	for ( ; it != infrastruturas.end(); it++ ) {
		file << endl << endl;
		file << (*it).getNome() << endl;
		file << (*it).getCidade();
	}

	file.close();
}


// Adiciona a infrastrutura no vetor e guarda no ficheiro
void Campeonato::addInfrastrutura(Infrastrutura &infra) {
	infrastruturas.push_back(infra);
	saveInfrastrutura();
}


// Guarda o desporto no ficheiro desportos.txt
void Campeonato::saveDesporto() {
	ofstream filedesp;
	filedesp.open(file_desportos);

	//vector<Desporto>::iterator it = desportos.begin();

	cout << desportos[0].getNome();
	//guarda apenas o primeiro desporto
	filedesp << desportos[0].getNome();

	//vector<Modalidade>::iterator it2 = desportos[0].getModalidades().begin();

	//guarda as modalidades do primeiro desporto
	for( int i = 0; i < desportos[0].getModalidades().size(); i++ ) {
		filedesp << endl;
		filedesp << " " << desportos[0].getModalidades()[i].getNome();
	}

	//guarda os restantes desportos
	for ( int j = 1; j < desportos.size(); j++ ) {
		filedesp << endl << endl;
		filedesp << desportos[j].getNome();

		for( int i = 0; i < desportos[j].getModalidades().size(); i++ ) {
			filedesp << endl;
			filedesp << " " << desportos[j].getModalidades()[i].getNome();
		}
	}

	filedesp.close();
}


// Adiciona o desporto no vetor e guarda no ficheiro
void Campeonato::addDesporto(Desporto &desp) {
	desportos.push_back(desp);
	//cout << desportos[0].getModalidades().size();
	saveDesporto();
}

