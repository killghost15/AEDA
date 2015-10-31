#include "Campeonato.h"


// Carraga a informação da infrastrutura do ficheiro infrastruturas.txt
int Campeonato::loadInfrastrutura() {
	string nome, cidade;
	string trash;
	Infrastrutura *infra;

	ifstream file;
	file.open(file_infrastruturas);

	if ( file.is_open() ) {

		getline(file, trash);

		while ( !file.eof() ) {
			getline(file, nome);
			getline(file, cidade);
			infra = new Infrastrutura(nome, cidade);
			infrastruturas.push_back(*infra);
		}

		file.close();

		if ( trash != "" )
			return 0;
		else
			return -1;
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

	vector<Infrastrutura>::iterator it;
	for ( it = infrastruturas.begin(); it != infrastruturas.end(); it++ ) {
		file << (*it).getNome() << endl;
		file << (*it).getCidade() << endl << endl;
	}

	file.close();
}


// Adiciona a infrastrutura no vetor e guarda no ficheiro
void Campeonato::addInfrastrutura(Infrastrutura &infra) {
	infrastruturas.push_back(infra);
	saveInfrastrutura();
}


