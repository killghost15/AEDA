#include "Campeonato.h"


void Campeonato::addInfrastrutura(Infrastrutura &infra) {
	infrastruturas.push_back(infra);
	saveInfrastrutura(infra);
}

// Guarda a infrastrutura no ficheiro infrastruturas.txt
void Campeonato::saveInfrastrutura(Infrastrutura &infra) {
	ofstream file;
	file.open(file_infrastruturas);

	if ( !file ) {
		cout << "Não consegui abrir o ficheiro com as Infrastruturas :(" << endl;
		return;
	}

	file << infra.getCidade() << endl << endl;

	file.close();
}

