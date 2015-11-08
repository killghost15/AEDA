#include "Campeonato.h"



vector<Equipa*> Campeonato::getEquipas() {
	return equipas;
}

vector<Atleta*> Campeonato::getAtletas() {
	return atletas;
}

vector<Modalidade*> Campeonato::getModalidades() {
	return modalidades;
}

vector<Desporto*> Campeonato::getDesportos() {
	return desportos;
}

vector<Infrastrutura*> Campeonato::getInfrastruturas() {
	return infrastruturas;
}

vector<Funcionario*> Campeonato::getFuncionarios() {
	return funcionarios;
}


/**
 *  METODOS DE PROCURA DE OBJETOS COM DETERMINADO NOME NOS VETORES
 */


// Procura uma equipa com um nome especifico no vetor equipas
Equipa* Campeonato::findEquipa(string nomeEquipa) {
	Equipa *equi;

	for( unsigned int i = 0; i < equipas.size(); i++ )
		if( equipas[i]->getNome() == nomeEquipa )
			equi = equipas[i];

	return equi;
}


// Procura um atleta com um nome especifico no vetor atletas
Atleta* Campeonato::findAtleta(string nomeAtleta) {
	Atleta *atl;

	for( unsigned int i = 0; i < atletas.size(); i++ )
		if( atletas[i]->getNome() == nomeAtleta )
			atl = atletas[i];

	return atl;
}


// Procura uma modalidade com um nome especifico no vetor modalidades
Modalidade* Campeonato::findModalidade(string nomeModalidade) {
	Modalidade *mod;

	for( unsigned int i = 0; i < modalidades.size(); i++ )
		if( modalidades[i]->getNome() == nomeModalidade )
			mod = modalidades[i];

	return mod;
}


// Procura um desporto com um nome especifico no vetor desportos
Desporto* Campeonato::findDesporto(string nomeDesporto) {
	Desporto *desp;

	for( unsigned int i = 0; i < desportos.size(); i++ )
		if( desportos[i]->getNome() == nomeDesporto )
			desp = desportos[i];

	return desp;
}


// Procura uma infrastrutura com um nome especifico no vetor infrastruturas
Infrastrutura* Campeonato::findInfrastrutura(string nomeInfrastrutura) {
	Infrastrutura *infra;

	for( unsigned int i = 0; i < infrastruturas.size(); i++ )
		if( infrastruturas[i]->getNome() == nomeInfrastrutura )
			infra = infrastruturas[i];

	return infra;
}


// Procura um funcionario com um nome especifico no vetor funcionarios
Funcionario* Campeonato::findFuncionario(string nomeFuncionario) {
	Funcionario *func;

	for( unsigned int i = 0; i < funcionarios.size(); i++ )
		if( funcionarios[i]->getNome() == nomeFuncionario )
			func = funcionarios[i];

	return func;
}


/**
 *  METODOS PARA SABER SE UM OBJETO COM UM DETERMINADO NOME EXISTE
 */


// Retorna true se uma equipa com um nome especifico existe, false otherwise
bool Campeonato::existsEquipa(string nomeEquipa) {

	for( unsigned int i = 0; i < equipas.size(); i++ )
		if( equipas[i]->getNome() == nomeEquipa )
			return true;

	return false;
}


// Retorna true se um atleta com um nome especifico existe, false otherwise
bool Campeonato::existsAtleta(string nomeAtleta) {

	for( unsigned int i = 0; i < atletas.size(); i++ )
		if( atletas[i]->getNome() == nomeAtleta )
			return true;

	return false;
}


// Retorna true se uma modalidade com um nome especifico existe, false otherwise
bool Campeonato::existsModalidade(string nomeModalidade) {

	for( unsigned int i = 0; i < modalidades.size(); i++ )
		if( modalidades[i]->getNome() == nomeModalidade )
			return true;

	return false;
}


// Retorna true se um desporto com um nome especifico existe, false otherwise
bool Campeonato::existsDesporto(string nomeDesporto) {

	for( unsigned int i = 0; i < desportos.size(); i++ )
		if( desportos[i]->getNome() == nomeDesporto )
			return true;

	return false;
}


// Retorna true se uma infrastrutura com um nome especifico existe, false otherwise
bool Campeonato::existsInfrastrutura(string nomeInfrastrutura) {

	for( unsigned int i = 0; i < infrastruturas.size(); i++ )
		if( infrastruturas[i]->getNome() == nomeInfrastrutura )
			return true;

	return false;
}


// Retorna true se um funcionario com um nome especifico existe, false otherwise
bool Campeonato::existsFuncionario(string nomeFuncionario) {

	for( unsigned int i = 0; i < funcionarios.size(); i++ )
		if( funcionarios[i]->getNome() == nomeFuncionario )
			return true;

	return false;
}


// Retorna true se a modalidade estiver nos desportos em que o atleta se pode inscrever
bool Campeonato::CanAtletaEnterModalidade(string nomeModalidade, string nomeAtleta) {
	vector<string> sports = findAtleta(nomeAtleta)->getEquipa()->getDesportos();

	for( unsigned int i = 0; i < sports.size(); i++ )
		for( unsigned int j = 0; j < desportos.size(); j++ )
			if( desportos[j]->getNome() == sports[i] ) {
				vector<Modalidade*> mods = desportos[j]->getModalidades();
				for( unsigned int k = 0; k < mods.size(); k++ )
					if( mods[k]->getNome() == nomeModalidade )
						return true;
			}

	return false;

}


/**
 *  METODOS PARA ELIMINAR OBJETOS COM UM DETERMINADO NOME DOS VETORES
 */


// Apaga o funcionario com um nome especifico do vetor funcionarios
void Campeonato::eraseFuncionario(string nomeFuncionario) {

	for( unsigned int i = 0; i < funcionarios.size(); i++ )
		if( funcionarios[i]->getNome() == nomeFuncionario )
			funcionarios.erase(funcionarios.begin()+i);
}


// Apaga a infrastrutura com um nome especifico do vetor infrastruturas
void Campeonato::eraseInfrastrutura(string nomeInfrastrutura) {

	for( unsigned int i = 0; i < infrastruturas.size(); i++ )
		if( infrastruturas[i]->getNome() == nomeInfrastrutura )
			infrastruturas.erase(infrastruturas.begin()+i);
}


// Retira o atleta com um nome especifico do vetor atletas da modalidade nomeModalidade do vetor modalidades
void Campeonato::eraseAtletaModalidade(string nomeModalidade, string nomeAtleta) {

	for( unsigned int i = 0; i < modalidades.size(); i++ )
		if( modalidades[i]->getNome() == nomeModalidade ) {
			vector<Atleta*> athletes = modalidades[i]->getAtletas();
			for ( unsigned int j = 0; j < athletes.size(); j++ )
				if ( athletes[j]->getNome() == nomeAtleta )
					modalidades[i]->eraseAtleta(j);
		}
}


// Apaga o atleta com um nome especifico do vetor atletas
void Campeonato::eraseAtleta(string nomeAtleta) {

	//apaga o atleta do vetor de atletas
	for( unsigned int i = 0; i < atletas.size(); i++ )
		if( atletas[i]->getNome() == nomeAtleta )
			atletas.erase(atletas.begin()+i);

	//apaga o atleta do vetor atletas de todas as modalidades a que pertence
	for( unsigned int j = 0; j < modalidades.size(); j++ ) {
		vector<Atleta*> athletes = modalidades[j]->getAtletas();
		for ( unsigned int k = 0; k < athletes.size(); k++ )
			if ( athletes[k]->getNome() == nomeAtleta )
				modalidades[j]->eraseAtleta(k);
	}

}


// Apaga a equipa com um nome especifico do vetor equipas
void Campeonato::eraseEquipa(string nomeEquipa) {

	//apaga a equipa do vetor equipas
	for( unsigned int w = 0; w < equipas.size(); w++ )
		if( equipas[w]->getNome() == nomeEquipa )
			equipas.erase(equipas.begin()+w);

	//apaga os atletas da equipa
	for( unsigned int i = 0; i < atletas.size(); i++ )
		if( atletas[i]->getEquipa()->getNome() == nomeEquipa )
			atletas.erase(atletas.begin()+i);

	//apaga todos os atletas pertencentes à equipa do vetor atletas de todas as modalidades a que pertencem
	for( unsigned int j = 0; j < modalidades.size(); j++ ) {
		vector<Atleta*> athletes = modalidades[j]->getAtletas();
		for( unsigned int k = 0; k < athletes.size(); k++ )
			if ( athletes[k]->getEquipa()->getNome() == nomeEquipa )
				modalidades[j]->eraseAtleta2(k);	//eraseAtleta() nao serve aqui
	}

}


// Apaga o desporto com um nome especifico do vetor desportos
void Campeonato::eraseDesporto(string nomeDesporto) {

	//apaga as modalidades do desporto do vetor de modalidades
	for( unsigned int i = 0; i < desportos.size(); i++ )
		if( desportos[i]->getNome() == nomeDesporto ) {
			for( unsigned int j = 0; j < desportos[i]->getModalidades().size(); j++ ) {
				string mod_nome = desportos[i]->getModalidades()[j]->getNome();
				for( unsigned int k = 0; k < modalidades.size(); k++ )
					if( modalidades[k]->getNome() == mod_nome ) {
						modalidades[k] = modalidades.back();
						modalidades.pop_back();
					}
			}
			desportos.erase(desportos.begin()+i);
		}
}


/**
 *  METODOS PARA ADICIONAR MUDAR UM ATLETA DE EQUIPA
 */


// Procura o indice de um atleta com um nome especifico no vetor atletas
int Campeonato::findAtletaIndex(string nomeAtleta) {
	int index;

	for( unsigned int i = 0; i < atletas.size(); i++ )
		if( atletas[i]->getNome() == nomeAtleta )
			index = i;

	return index;
}


// Troca a equipa no indice index no vetor modalidades pela modalidade mod
void Campeonato::changeEquipa(int index, Equipa *equi) {
	atletas[index]->setEquipa(equi);
}


/**
 *  METODOS PARA ADICIONAR ATLETAS A UMA MODALIDADE
 */
/*
// classificacoes das modalidades
void Campeonato::classifica(string nomeModalidade, string NomeProva){
	int posicao;
	vector<Atleta*>atl=findModalidade(nomeModalidade)->getAtletas();
	for (unsigned int i=0; i < atl.size();i++){
		cout << atl[i]->getNome() << " ,posição em que terminou (resposta: 1- ganhou, e seguintes) ?";
		cin >> posicao;
		for (unsigned int j=0; j< findModalidade(nomeModalidade)->getProvas().size();){
		if (findModalidade(nomeModalidade)->getProvas()[j]->getNome()==NomeProva){
			findModalidade(nomeModalidade)->getProvas()[j]->pushClassifica(posicao);
			break;
		}
		j++;
		if (j==findModalidade(nomeModalidade)->getProvas().size()-1){
			cout << "prova inexistente";
			return;
		}
		}


	}


}

void Campeonato::saveclassifica() {
	ofstream fileclass;
	fileclass.open(file_classificacoes);

	//guarda apenas a primeira modalidade e a primeira prova
	fileclass << modalidades[0]->getNome();
	fileclass <<modalidades[0]->getProvas()[0]->getNome();

	//guarda as classificacoes da primeira prova
	for( unsigned int i = 0; i < modalidades[0]->getProvas().size(); i++ ) {
		fileclass << endl;
		fileclass << " " << modalidades[0]->getProvas()[i]->getNome();
		fileclass << endl;
		for (unsigned int v=0; v< modalidades[0]->getProvas()[i]->getClassificacoes().size();v++)
		fileclass << modalidades[0]->getProvas()[i]->getClassificacoes()[v];
	}

	fileclass << endl;

	//guarda as restantes modalidades e as provas de cada
	for ( unsigned int j = 1; j < modalidades.size(); j++ ) {
		fileclass << endl;
		fileclass << modalidades[j]->getNome();
		for(unsigned int k=0; k < modalidades[j]->getProvas().size();k++){
		fileclass <<modalidades[j]->getProvas()[k]->getNome();
		fileclass <<endl;

		for( unsigned int l = 0; l < modalidades[j]->getProvas()[k]->getClassificacoes().size(); l++ ) {
			fileclass << " " << modalidades[j]->getProvas()[k]->getClassificacoes()[l];
			fileclass <<endl;
		}
		}
		fileclass << endl;
	}

	fileclass.close();
}*/

void Campeonato::AtribuiInfrastrutura(string nomeModalidade,string nomeProva, string Infrastrutura){
	for(unsigned int i=0;i<findModalidade(nomeModalidade)->getProvas().size();i++){
	if(findModalidade(nomeModalidade)->getProvas()[i]->getNome()==nomeProva)
		findModalidade(nomeModalidade)->getProvas()[i]->setInfrastrutura(Infrastrutura);
	}

}

// Procura o indice de uma modalidade com um nome especifico no vetor modalidades
int Campeonato::findModalidadeIndex(string nomeModalidade) {
	int index;

	for( unsigned int i = 0; i < modalidades.size(); i++ )
		if( modalidades[i]->getNome() == nomeModalidade )
			index = i;

	return index;
}


// Troca a modalidade no indice index no vetor modalidades pela modalidade mod
void Campeonato::changeModalidade(int index, Modalidade *mod) {
	modalidades[index] = mod;
}


/**
 *  METODOS DE SAVE/LOAD DOS VETORES E FICHEIROS
 */


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


// Carrega a informação dos atletas do ficheiro atletas.txt
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
			getline(fileatl, trash);	// trash não é usada para nada, apenas para ignorar 1 linha

			int idadeAtleta_int = atoi(idade_atleta.c_str());
			float pesoAtleta_float = atof(peso_atleta.c_str());
			float estaturaAtleta_float = atof(estatura_atleta.c_str());

			nome_equipa.erase(nome_equipa.begin());

			Equipa *equi = findEquipa(nome_equipa);
			atl = new Atleta(nome_atleta, idadeAtleta_int, pesoAtleta_float, estaturaAtleta_float);
			atl->setEquipa(equi);
			atletas.push_back(atl);
		}

		fileatl.close();
	}
}


// Guarda o atleta no ficheiro atletas.txt
void Campeonato::saveAtleta() {
	ofstream fileatl;
	fileatl.open(file_atletas);

	//guarda apenas o primeira atleta
	fileatl << atletas[0]->getNome() << endl;
	fileatl << atletas[0]->getIdade() << endl;
	fileatl << atletas[0]->getPeso() << endl;
	fileatl << atletas[0]->getEstatura() << endl;
	fileatl << " " << atletas[0]->getEquipa()->getNome();

	//guarda os restantes atletas
	for ( unsigned int j = 1; j < atletas.size(); j++ ) {
		fileatl << endl << endl;
		fileatl << atletas[j]->getNome() << endl;
		fileatl << atletas[j]->getIdade() << endl;
		fileatl << atletas[j]->getPeso() << endl;
		fileatl << atletas[j]->getEstatura() << endl;
		fileatl << " " << atletas[j]->getEquipa()->getNome();
	}

	fileatl.close();
}


// Adiciona o atleta no vetor e guarda no ficheiro
void Campeonato::addAtleta(Atleta *atl) {
	atletas.push_back(atl);
	saveAtleta();
}


// Carrega a informação das modalidades do ficheiro modalidades.txt
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
				Atleta *atl = findAtleta(atleta_string);
				modal->pushAtleta(atl);
			}

			athletes.clear();
			modalidades.push_back(modal);
		}

		filemod.close();
	}
}


// Guarda a modalidade no ficheiro modalidades.txt
void Campeonato::saveModalidade() {
	ofstream filemod;
	filemod.open(file_modalidades);

	//guarda apenas a primeira modalidade
	filemod << modalidades[0]->getNome();

	//guarda os atletas da primeira modalidade
	for( unsigned int i = 0; i < modalidades[0]->getAtletas().size(); i++ ) {
		filemod << endl;
		filemod << " " << modalidades[0]->getAtletas()[i]->getNome();
	}

	filemod << endl;

	//guarda as restantes modalidades
	for ( unsigned int j = 1; j < modalidades.size(); j++ ) {
		filemod << endl;
		filemod << modalidades[j]->getNome();

		for( unsigned int i = 0; i < modalidades[j]->getAtletas().size(); i++ ) {
			filemod << endl;
			filemod << " " << modalidades[j]->getAtletas()[i]->getNome();
		}

		filemod << endl;
	}

	filemod.close();
}


// Adiciona a modalidade no vetor e guarda no ficheiro
void Campeonato::addModalidade(Modalidade *modal) {
	modalidades.push_back(modal);
	saveModalidade();
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
				Modalidade *modal = findModalidade(modalidade_string);
				desp->pushModalidade(modal);
			}

			mods.clear();
			desportos.push_back(desp);
		}

		filedesp.close();
	}
}


// Guarda o desporto no ficheiro desportos.txt
void Campeonato::saveDesporto() {
	ofstream filedesp;
	filedesp.open(file_desportos);

	//guarda apenas o primeiro desporto
	filedesp << desportos[0]->getNome();

	//guarda as modalidades do primeiro desporto
	for( unsigned int i = 0; i < desportos[0]->getModalidades().size(); i++ ) {
		filedesp << endl;
		filedesp << " " << desportos[0]->getModalidades()[i]->getNome();
	}

	filedesp << endl;

	//guarda os restantes desportos
	for ( unsigned int j = 1; j < desportos.size(); j++ ) {
		filedesp << endl;
		filedesp << desportos[j]->getNome();

		for( unsigned int i = 0; i < desportos[j]->getModalidades().size(); i++ ) {
			filedesp << endl;
			filedesp << " " << desportos[j]->getModalidades()[i]->getNome();
		}

		filedesp << endl;
	}

	filedesp.close();
}


// Adiciona o desporto no vetor e guarda no ficheiro
void Campeonato::addDesporto(Desporto *desp) {
	desportos.push_back(desp);
	saveDesporto();
}


// Carrega a informação das infrastruturas do ficheiro infrastruturas.txt
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
			infrastruturas.push_back(infra);
		}

		fileinfra.close();
	}
}


// Guarda a infrastrutura no ficheiro infrastruturas.txt
void Campeonato::saveInfrastrutura() {
	ofstream fileinfra;
	fileinfra.open(file_infrastruturas);

	//guarda apenas a primeira infrastrutura
	fileinfra << infrastruturas[0]->getNome() << endl;
	fileinfra << infrastruturas[0]->getCidade();

	//guarda as restantes infrastruturas
	for ( unsigned int i = 1; i < infrastruturas.size(); i++ ) {
		fileinfra << endl << endl;
		fileinfra << infrastruturas[i]->getNome() << endl;
		fileinfra << infrastruturas[i]->getCidade();
	}

	fileinfra.close();
}


// Adiciona a infrastrutura no vetor e guarda no ficheiro
void Campeonato::addInfrastrutura(Infrastrutura *infra) {
	infrastruturas.push_back(infra);
	saveInfrastrutura();
}


// Carrega a informação dos funcionarios do ficheiro funcionarios.txt
void Campeonato::loadFuncionarios() {
	string nome_funcionario, idade_funcionario, anos_trabalho;
	string trash;
	Funcionario *func;

	ifstream filefunc;
	filefunc.open(file_funcionarios);

	if ( filefunc.is_open() ) {

		while ( !filefunc.eof() ) {
			getline(filefunc, nome_funcionario);
			getline(filefunc, idade_funcionario);
			getline(filefunc, anos_trabalho);
			getline(filefunc, trash);	// trash não é usada para nada, apenas para ignorar 1 linha

			int idadeFuncionario_int = atoi(idade_funcionario.c_str());
			float anosTrabalho_int = atof(anos_trabalho.c_str());

			func = new Funcionario(nome_funcionario, idadeFuncionario_int, anosTrabalho_int);
			funcionarios.push_back(func);
		}

		filefunc.close();
	}
}


// Guarda o funcionario no ficheiro funcionarios.txt
void Campeonato::saveFuncionario() {
	ofstream filefunc;
	filefunc.open(file_funcionarios);

	//guarda apenas o primeiro funcionario
	filefunc << funcionarios[0]->getNome() << endl;
	filefunc << funcionarios[0]->getIdade() << endl;
	filefunc << funcionarios[0]->getAnosTrabalho();

	//guarda os restantes funcionarios
	for ( unsigned int i = 1; i < funcionarios.size(); i++ ) {
		filefunc << endl << endl;
		filefunc << funcionarios[i]->getNome() << endl;
		filefunc << funcionarios[i]->getIdade() << endl;
		filefunc << funcionarios[i]->getAnosTrabalho();
	}

	filefunc.close();
}


// Adiciona o funcionario no vetor e guarda no ficheiro
void Campeonato::addFuncionario(Funcionario *func) {
	funcionarios.push_back(func);
	saveFuncionario();
}

