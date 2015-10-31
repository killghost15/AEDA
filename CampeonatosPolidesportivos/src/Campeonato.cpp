#include "Campeonato.h"


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

	if ( !file ) {
		cout << "Não consegui abrir o ficheiro com as Infrastruturas :(" << endl;
		return;
	}

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


