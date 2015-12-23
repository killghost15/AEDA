#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <map>

#include "Campeonato.h"
#include "Infrastrutura.h"
#include "Exceptions.h"
#include "Data.h"

using namespace std;


bool exception_finish = true;
void MenuInicial();
void AdicionarEquipa();
void RetirarEquipa();
void AdicionarAtletasEquipa();
void RetirarAtleta();
void MudarAtletaEquipa();
void MenuEquipasAtletas();
void AdicionarDesporto();
void RetirarDesporto();
void AdicionarAtletasModalidade();
void RetirarAtletasModalidade();
void MenuDesportosModalidades();
void CriarProva();
void EliminarProva();
void LancaClassificacoesProva();
void MudarInfrastruturaProva();
void MenuProvas();
void MenuCalendario();
void AdicionarInfrastrutura();
void ApagarInfrastrutura();
void AdicionarFuncionario();
void ApagarFuncionario();
void MenuInfrastruturas();
void InformacoesUteis();
void ListaDeAtletas();
void ListaDeClassificacoes();
void ListaDeFuncionarios();
void MenuListagens();
void MenuBST();
void MenuHashTable();
void MenuInicial2();

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
Prova defa("vazio",0);
Campeonato campeonato(defa);
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
	campeonato.loadBilhetes();
	//maneira para corrigir o bugg mas tem q ser resolvido
	campeonato.eraseProva("");
	campeonato.provasToBST();
	//campeonato.removeProvaBST(defa);
	// Chama o Menu Inicial
	MenuInicial();

	return 0;
}


void InserirProva(){
	string nome,modalidade,infraestrutura,cidade;
	int duracao;
	cin.sync();
	cout << "Nome da prova:";
	getline(cin,nome);
	cin.sync();
	cout << "Duracao em minutos:";
	cin >>duracao;
	unsigned int hora,minuto,dia,mes,ano;
	char pontos;
	char barra;

	Prova *p=new Prova(nome,duracao);
	Prova f(nome,duracao);

	cout << "Data da prova (dia/mes/ano):";
	cin >>dia>>barra>>mes>>barra>>ano;
	cin.sync();
	Data *d=new Data(dia,mes,ano);
	p->setData(d);
	f.setData(d);
	cout << "Hora prevista de inicio (hora:minutos):";
	cin >> hora >>pontos >>minuto;
	cin.sync();
	Hora *h=new Hora(hora,minuto);
	p->setHora(h);
	f.setHora(h);
	cout << "Modalidade desta prova:";
	getline(cin,modalidade);
	cin.sync();
	Modalidade* mod=new Modalidade(modalidade);
	if (!campeonato.existsModalidade(modalidade)){
		campeonato.addModalidade(mod);
	}
	p->setModalidade(mod);
	f.setModalidade(mod);
	cout << "Nome da infrastrutura da prova:";
	getline(cin,infraestrutura);
	cin.sync();

	cout << "Cidade da infraestrutura:";
	getline(cin,cidade);
	cin.sync();
	Infrastrutura *infra=new Infrastrutura(infraestrutura,cidade);
	if (!campeonato.existsInfrastrutura(infraestrutura)){
		campeonato.addInfrastrutura(infra);
	}
	p->setInfrastrutura(infra);
	f.setInfrastrutura(infra);
	campeonato.inserirProvaBST(f);
	campeonato.addProva(p);
	string nada;
	cout <<"A sua Prova foi inserida"<<endl;
	cout << "Introduza um caracter seguido de enter para continuar para o menu das BST";
	cin >> nada;



}
void RemoverProvaBST(){
	string nome;
	cin.sync();
	cout << "Qual o nome da prova que deseja remover:";
	getline(cin,nome);
	cin.sync();
	campeonato.removeProvaBST(nome);
	campeonato.eraseProva(nome);
	cout  <<"Prova cancelada com sucesso, lamentamos a quem comprou bilhete "<<endl;
}

void ModifyProva(){

	int opcao;
	string nome;
	bool s=true;
	cout << "O que pretende alterar  ?"<<endl;
	cout << "opções: 1. mudar nome      "<<endl;
	cout << "        2. alterar a data da prova"<<endl;
	cout << "        3. alterar duração "<<endl;
	cout << "        4. alterar hora de inicio "<<endl;
	cin.sync();
	cout <<"opcao: ";
	cin>>opcao;
	cin.sync();
	while(s ){
		if(opcao == 1 || opcao==2 || opcao==3 || opcao== 4)
			s=false;
		else{
		cout << "escolha uma das opções por favor!";
		cin >>opcao;
		}
	}
	cin.sync();
	cout <<"nome da prova:";
	getline(cin,nome);
	Prova tmp=campeonato.encontraProvaBST(nome);
	Prova *p=campeonato.findProva(nome);
	campeonato.removeProvaBST(nome);
	campeonato.eraseProva(nome);
	cin.sync();
	if(opcao==1){
		string newname;
		cout << "Novo nome:";
		getline(cin,newname);
		tmp.setNome(newname);
	}

	if(opcao==2){
		unsigned int dia,mes,ano;
		char barra;
		cout <<"Data actual:"<<endl;
		cout << tmp.getData()->getDia()<<"/"<<tmp.getData()->getMes()<<"/"<<tmp.getData()->getAno()<<endl;
		cout<< "Nova Data(dia/mes/ano):";
		cin >>dia>>barra>>mes>>barra>>ano;
		Data *d=new Data(dia,mes,ano);
		tmp.setData(d);
	}
	if(opcao==3){
		int duracao;
		cout <<"Duracao actual:"<<tmp.getDuracao()<<endl;
		cin >>duracao;
		tmp.setDuracao(duracao);
	}
	if (opcao==4){
		unsigned int horas,minutos;
		char pontos;
		cout <<"Hora de inicio atual:"<<tmp.getHoraInicio()->getHora()<<":"<<tmp.getHoraInicio()->getMinuto()<<endl;
		cout <<"Nova hora (horas:minutos):";
		cin >>horas>>pontos>>minutos;
		Hora *h=new Hora(horas,minutos);
		tmp.setHora(h);
	}

	campeonato.inserirProvaBST(tmp);
	campeonato.addProva(p);

}

void MenuBST(){
	int escolha_listagens;

		cout << "-------------------------------------------------------------" << endl;
		cout << "-                     *** BST opções ***                    -" << endl;
		cout << "-                                                           -" << endl;
		cout << "- Qual das estruturas de dados pretende ?                   -" << endl;
		cout << "-                                                           -" << endl;
		cout << "- 1. Calendário com a BST                                   -" << endl;
		cout << "- 2. Ver as provas existentes numa data específica          -" << endl;
		cout << "- 3. Inserir Prova na BST                                   -" << endl;
		cout << "- 4. Cancelar Prova da BST(remover)                         -" << endl;
		cout << "- 5. Modificar uma Prova                                    -" << endl;
		cout << "- 6. Voltar ao Menu das estruturas de dados                 -" << endl;
		cout << "- 7. Voltar ao Menu Principal                               -" << endl;
		cout << "-                                                           -" << endl;
		cout << "-------------------------------------------------------------" << endl;

		cout << " O que pretende fazer? ";
		cin >> escolha_listagens;

		if ( escolha_listagens != 1 && escolha_listagens != 2 && escolha_listagens != 3 && escolha_listagens != 4 && escolha_listagens != 5 && escolha_listagens != 6 && escolha_listagens !=7) {
			cout << " Por favor, faça uma escolha adequada.";
			cout << string(8,'\n');
			MenuInicial();
		}
		char resposta;
		unsigned int dia,mes,ano;
		vector<Prova>v;
		switch (escolha_listagens) {
			case 1:
				cout << string(8,'\n');
				campeonato.showProvasCalendar();
				cout <<endl;
				cout << "Deseja voltar ao menu inicial (s/n) ?";
				cin >>resposta;

				while(resposta != 's'){
					cout << "Coloque a resposta s quando quiser sair: ";
					cin >> resposta;
				}
				cout<<string(8,'\n');
				MenuBST();
				break;
			case 2:
				cout << string(8,'\n');
				cout<< "Qual a data de que pretente obter as provas se não houver provas nesse dia será apresentado as provas do dia seguinte ou do mesmo mês até ao dia 1 do mês seguinte (dia mes ano):";
				cin >>dia >> mes >>ano;
				v=campeonato.getDayorNext(dia,mes,ano);

				if (v.size()==0){
					cout << "Não existem provas neste mês!"<<endl;
					cout<<string(8,'\n');
					MenuBST();
					break;
				}
				else{
				cout<< dia <<"/"<< mes<<"/"<<ano <<endl;
				cin.sync();
				for (unsigned int j=0;j<v.size();j++){
					cout<<v[j].getNome()<<":"<<v[j].getModalidade()->getNome()<<" "<<v[j].getHoraInicio()->getHora() <<":"<<v[j].getHoraInicio()->getMinuto() <<"Local: "<<v[j].getInfrastrutura()->getNome()<<" em "<<v[j].getInfrastrutura()->getCidade()<<endl;
				}

				cout << "Deseja voltar ao menu inicial (s/n) ?";
				cin >>resposta;

				while(resposta != 's'){
					cout << "Coloque a resposta s quando quiser sair: ";
					cin >> resposta;
					}
				cout<<string(8,'\n');
				MenuBST();
				break;
				}
			case 3:
				cout << string(8,'\n');
				InserirProva();
				cout << string(8,'\n');
				MenuBST();


				break;
			case 4:
				cout << string(8,'\n');
				RemoverProvaBST();
				cout << string(8,'\n');
				MenuBST();
				break;
			case 5:
				cout << string(8,'\n');
				ModifyProva();
				cout << string(8,'\n');
				MenuBST();
				break;
			case 6:
				cout << string(8,'\n');
				MenuInicial2();
				break;
			case 7:
				cout << string(8,'\n');
				MenuInicial();
				break;

		}
}


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
			if( num_atletas < 1 )
				throw NumAtletasInvalido(1);
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
	Equipa *equi = new Equipa(nome_equipa, 0, 0, 0);

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
			if( num_atletas < 1 )
				throw NumAtletasInvalido(1);
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
				throw NumAtletasInvalido(1);
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
				throw NumAtletasInvalido(1);
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


// Apresenta o form para a criação de uma prova de uma modalidade
void CriarProva(){
	unsigned int dia_int, mes_int, ano_int, horas_int, minutos_int;
	int duracao;
	string nome_modalidade, nome_infrastrutura;
	string nome_prova;
	string data, hora;

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

	exception_finish = true;
	while (exception_finish){
		try {
			cout << " Qual o nome da prova? ";
			getline(cin, nome_prova);
			if (campeonato.existsProva(nome_prova) == true)
				throw ProvaJaExistente(nome_prova);
			else
				exception_finish = false;
		} catch (ProvaJaExistente &e) {
			e.what();
		}
	}

	cout << endl;

	// Input da data (dia, mês e ano) por parte do utilizador
	exception_finish = true;
	Data *date;
	while(exception_finish) {
		cout << " Data (DD/MM/AAAA)? ";
		cin >> data;
		cin.ignore();

		stringstream dia, mes, ano;
		dia << data[0] << data[1];
		mes << data[3] << data[4];
		ano << data[6] << data[7] << data[8] << data[9];

		dia_int = atoi(dia.str().c_str());
		mes_int = atoi(mes.str().c_str());
		ano_int = atoi(ano.str().c_str());

		try {
			date = new Data(dia_int, mes_int, ano_int);
			date->checkData(dia_int, mes_int, ano_int);
			exception_finish = false;
		} catch( DataInvalida &e ) {
			e.what();
		}
	}

	// Input da hora (horas e minutos) por parte do utilizador
	exception_finish = true;
	Hora *hour;
	while(exception_finish) {
		cout << " Hora (HH:MM)? ";
		cin >> hora;
		cin.ignore();

		stringstream horas, minutos;
		horas << hora[0] << hora[1];
		minutos << hora[3] << hora[4];

		horas_int = atoi(horas.str().c_str());
		minutos_int = atoi(minutos.str().c_str());

		try {
			hour = new Hora(horas_int, minutos_int);
			hour->checkHora(horas_int, minutos_int);
			exception_finish = false;
		} catch( HoraInvalida &e ) {
			e.what();
		}
	}

	// Input da duracao (minutos) por parte do utilizador
	cout << " Duração da prova? ";
	cin >> duracao;
	cin.ignore();

	Modalidade *mod = campeonato.findModalidade(nome_modalidade);
	Infrastrutura *infra = campeonato.findInfrastrutura(nome_infrastrutura);

	//criaçao do objeto da classe prova para adicionar à modalidade
	Prova *prova = new Prova(nome_prova, duracao);
	prova->setData(date);
	prova->setHora(hour),
	prova->setModalidade(mod);
	prova->setInfrastrutura(infra);

	campeonato.addProva(prova);

	cout << endl << " Prova adicionada à modalidade com sucesso!";
}


// Apresenta o form para eliminar uma prova de uma modalidade
void EliminarProva(){
	string nome_prova;

	cin.clear();
	cin.sync();

	exception_finish = true;
	while (exception_finish) {
		try {
			cout << " Qual a prova que pretende eliminar? ";
			getline(cin, nome_prova);
			if( campeonato.existsProva(nome_prova) == false ) {
				cout << campeonato.getProvas().size();
				throw ProvaInexistente(nome_prova);
			}
			else
				exception_finish = false;
		} catch (ProvaInexistente &e) {
			e.what();
		}
	}

	campeonato.eraseProva(nome_prova);

	campeonato.saveProva();

	cout << endl << " Prova eliminada da modalidade com sucesso!";
}


// Lança as classificações de todos os atletas que participaram numa prova
void LancaClassificacoesProva() {
	string nome_prova, nome_atleta;
	unsigned int num_atletas;
	int classificacao_atleta;

	cin.clear();
	cin.sync();

	exception_finish = true;
	while (exception_finish) {
		try {
			cout << " Nome da prova: ";
			getline(cin, nome_prova);
			if( campeonato.existsProva(nome_prova) == false )
				throw ProvaInexistente(nome_prova);
			else
				exception_finish = false;
		} catch (ProvaInexistente &e) {
			e.what();
		}
	}

	cout << endl;

	exception_finish = true;
	while (exception_finish) {
		try {
			cout << " Quantos atletas participaram na prova: ";
			cin >> num_atletas;
			if( num_atletas < 2 )
				throw NumAtletasInvalido(2);
			else
				exception_finish = false;
			cout << endl;
		} catch (NumAtletasInvalido &e) {
			e.what();
		}
	}

	cout << endl;

	map<Atleta*, int> points_athletes;

	//form para todos os atletas da prova
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

		cout << " Classificação do atleta " << i+1 << " na prova: ";
		cin >> classificacao_atleta;

		Atleta *atlet = campeonato.findAtleta(nome_atleta);
		points_athletes.insert(pair<Atleta*, int>(atlet, classificacao_atleta));

		if ( classificacao_atleta == 1 ) {
			atlet->getEquipa()->incOuro();
			campeonato.findEquipa(atlet->getEquipa()->getNome())->incOuro();
		}
		else if ( classificacao_atleta == 2 ) {
			atlet->getEquipa()->incPrata();
			campeonato.findEquipa(atlet->getEquipa()->getNome())->incPrata();
		}
		else if ( classificacao_atleta == 3 ) {
			atlet->getEquipa()->incBronze();
			campeonato.findEquipa(atlet->getEquipa()->getNome())->incBronze();
		}

	}

	//criaçao do objeto da classe prova
	Prova *prova = campeonato.findProva(nome_prova);

	prova->setClassificacoesAtletas(points_athletes);

	campeonato.saveProva();

	cout << " Classificações da prova lançadas com sucesso!";
}


// Muda a infrastrutura de uma prova
void MudarInfrastruturaProva() {
	string nome_prova, nome_infrastrutura;

	cin.clear();
	cin.sync();

	exception_finish = true;
	while (exception_finish) {
		try {
			cout << " Qual a prova à qual pretende mudar a infrastrutura: ";
			getline(cin, nome_prova);
			if( campeonato.existsProva(nome_prova) == false )
				throw ProvaInexistente(nome_prova);
			else
				exception_finish = false;
		} catch (ProvaInexistente &e) {
			e.what();
		}
	}

	cout << endl;

	exception_finish = true;
	while (exception_finish) {
		try {
			cout << " Qual o nome nova infrastrutura da prova: ";
			getline(cin, nome_infrastrutura);
			if( campeonato.existsInfrastrutura(nome_infrastrutura) == false )
				throw InfrastruturaInexistente(nome_infrastrutura);
			else
				exception_finish = false;
		} catch (InfrastruturaInexistente &e) {
			e.what();
		}
	}

	cout << endl;

	Infrastrutura *infra = campeonato.findInfrastrutura(nome_infrastrutura);

	int index_prova = campeonato.findProvaIndex(nome_prova);
	campeonato.changeInfrastrutura(index_prova, infra);

	campeonato.saveProva();

	cout << " Alterou a infrastrutura da prova com sucesso!";
}


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
			EliminarProva();
			cout << string(8,'\n');
			MenuInicial();
			break;
		case 3:
			cout << string(8,'\n');
			LancaClassificacoesProva();
			cout << string(8,'\n');
			MenuInicial();
			break;
		case 4:
			cout << string(8,'\n');
			MudarInfrastruturaProva();
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
 *  MENU RELACIONADO COM O CALENDÁRIO
 */


void MenuCalendario(){
	string nome, data, hora;
	stringstream dia, mes, ano, horas, minutos;
	unsigned int dia_int, mes_int, ano_int, horas_int, minutos_int;

	// Input da data (dia, mês e ano) por parte do utilizador
	cout << " Data (DD/MM/AAAA)? ";
	cin >> data;
	cin.ignore();

	dia << data[0] << data[1];
	mes << data[3] << data[4];
	ano << data[6] << data[7] << data[8] << data[9];

	dia_int = atoi(dia.str().c_str());
	mes_int = atoi(mes.str().c_str());
	ano_int = atoi(ano.str().c_str());

	try {
		Data *date = new Data(dia_int, mes_int, ano_int);
		date->checkData(dia_int, mes_int, ano_int);
	} catch( DataInvalida &e ) {
		e.what();
		MenuCalendario();
	}

	// Input da hora (horas e minutos) por parte do utilizador
	exception_finish = true;
	while(exception_finish) {
		cout << " Hora (HH:MM)? ";
		cin >> hora;
		cin.ignore();

		horas << hora[0] << hora[1];
		minutos << hora[3] << hora[4];

		horas_int = atoi(horas.str().c_str());
		minutos_int = atoi(minutos.str().c_str());

		try {
			Hora *hour = new Hora(horas_int, minutos_int);
			hour->checkHora(horas_int, minutos_int);
			exception_finish = false;
		} catch( HoraInvalida &e ) {
			e.what();
		}
	}

	// Display das provas que já passaram, mediante a data e horas atuais
	cout << endl;
	cout << " Provas que já passaram:" << endl;
	for ( unsigned int i = 0; i < campeonato.getProvas().size(); i++ ) {
		string zero_init = "", zero_end = "";
		Prova *match = campeonato.getProvas()[i];
		Data *date = match->getData();
		Hora *hour = match->getHoraInicio();
		Hora *hour_end = match->getHoraFim();

		if( hour->getMinuto() < 10 )	// verificar se o minuto da hora inicial é menor que 10
			zero_init = "0";

		if( hour_end->getMinuto() < 10 )	// verificar se o minuto da hora final é menor que 10
			zero_end = "0";

		if ( date->getAno() < ano_int ) {
			cout << " - ";
			cout << match->getNome() << endl;
			cout << "    Dia: " << date->getDia() << "/" << date->getMes() << "/" << date->getAno() << endl;
			cout << "    Hora início: " << hour->getHora() << ":" << zero_init << hour->getMinuto() << endl;
			cout << "    Hora fim: " << hour_end->getHora() << ":" << zero_end << hour_end->getMinuto() << endl;
		}
		else if ( date->getAno() == ano_int ) {
			if( date->getMes() < mes_int ) {
				cout << " - ";
				cout << match->getNome() << endl;
				cout << "    Dia: " << date->getDia() << "/" << date->getMes() << "/" << date->getAno() << endl;
				cout << "    Hora início: " << hour->getHora() << ":" << zero_init << hour->getMinuto() << endl;
				cout << "    Hora fim: " << hour_end->getHora() << ":" << zero_end << hour_end->getMinuto() << endl;
			}
			else if ( date->getMes() == mes_int ) {
				if( date->getDia() < dia_int ) {
					cout << " - ";
					cout << match->getNome() << endl;
					cout << "    Dia: " << date->getDia() << "/" << date->getMes() << "/" << date->getAno() << endl;
					cout << "    Hora início: " << hour->getHora() << ":" << zero_init << hour->getMinuto() << endl;
					cout << "    Hora fim: " << hour_end->getHora() << ":" << zero_end << hour_end->getMinuto() << endl;
				}
				else if( date->getDia() == dia_int ) {
					if( hour_end->getHora() < horas_int ) {
						cout << " - ";
						cout << match->getNome() << endl;
						cout << "    Dia: " << date->getDia() << "/" << date->getMes() << "/" << date->getAno() << endl;
						cout << "    Hora início: " << hour->getHora() << ":" << zero_init << hour->getMinuto() << endl;
						cout << "    Hora fim: " << hour_end->getHora() << ":" << zero_end << hour_end->getMinuto() << endl;
					}
					else if( hour->getHora() == horas_int ) {
						if( hour_end->getMinuto() <= minutos_int ) {
							cout << " - ";
							cout << match->getNome() << endl;
							cout << "    Dia: " << date->getDia() << "/" << date->getMes() << "/" << date->getAno() << endl;
							cout << "    Hora início: " << hour->getHora() << ":" << zero_init << hour->getMinuto() << endl;
							cout << "    Hora fim: " << hour_end->getHora() << ":" << zero_end << hour_end->getMinuto() << endl;
						}
					}
				}
			}
		}
	}

	// Display das provas que estão a decorrer, mediante a data e horas atuais
	cout << endl;
	cout << " Provas que estão a decorrer:" << endl;
	for ( unsigned int i = 0; i < campeonato.getProvas().size(); i++ ) {
		string zero_init = "", zero_end = "";
		Prova *match = campeonato.getProvas()[i];
		Data *date = match->getData();
		Hora *hour = match->getHoraInicio();
		Hora *hour_end = match->getHoraFim();

		if( hour->getMinuto() < 10 )	// verificar se o minuto da hora inicial é menor que 10
			zero_init = "0";

		if( hour_end->getMinuto() < 10 )	// verificar se o minuto da hora final é menor que 10
			zero_end = "0";

		if ( date->getAno() == ano_int ) {
			if ( date->getMes() == mes_int ) {
				if( date->getDia() == dia_int ) {
					if( hour->getHora() < horas_int ) {
						if( hour_end->getHora() > horas_int ) {
							cout << " - ";
							cout << match->getNome() << endl;
							cout << "    Dia: " << date->getDia() << "/" << date->getMes() << "/" << date->getAno() << endl;
							cout << "    Hora início: " << hour->getHora() << ":" << zero_init << hour->getMinuto() << endl;
							cout << "    Hora fim: " << hour_end->getHora() << ":" << zero_end << hour_end->getMinuto() << endl;
						}
						else if( hour_end->getHora() == horas_int ) {
							if( hour->getMinuto() > minutos_int ) {
								cout << " - ";
								cout << match->getNome() << endl;
								cout << "    Dia: " << date->getDia() << "/" << date->getMes() << "/" << date->getAno() << endl;
								cout << "    Hora início: " << hour->getHora() << ":" << zero_init << hour->getMinuto() << endl;
								cout << "    Hora fim: " << hour_end->getHora() << ":" << zero_end << hour_end->getMinuto() << endl;
							}
						}
					}
					else if( hour->getHora() == horas_int ) {
						if( hour->getHora() < hour_end->getHora() ) {
							cout << " - ";
							cout << match->getNome() << endl;
							cout << "    Dia: " << date->getDia() << "/" << date->getMes() << "/" << date->getAno() << endl;
							cout << "    Hora início: " << hour->getHora() << ":" << zero_init << hour->getMinuto() << endl;
							cout << "    Hora fim: " << hour_end->getHora() << ":" << zero_end << hour_end->getMinuto() << endl;
						}
						else {
							if ( hour->getMinuto() < minutos_int && hour_end->getMinuto() > minutos_int ) {
								cout << " - ";
								cout << match->getNome() << endl;
								cout << "    Dia: " << date->getDia() << "/" << date->getMes() << "/" << date->getAno() << endl;
								cout << "    Hora início: " << hour->getHora() << ":" << zero_init << hour->getMinuto() << endl;
								cout << "    Hora fim: " << hour_end->getHora() << ":" << zero_end << hour_end->getMinuto() << endl;
							}
						}
					}
				}
			}
		}
	}

	// Display no ecrã das provas que ainda vão acontecer, mediante a data e horas atuais
	cout << endl;
	cout << " Provas que ainda vão acontecer:" << endl;
	for ( unsigned int i = 0; i < campeonato.getProvas().size(); i++ ) {
		string zero_init = "", zero_end = "";
		Prova *match = campeonato.getProvas()[i];
		Data *date = match->getData();
		Hora *hour = match->getHoraInicio();
		Hora *hour_end = match->getHoraFim();

		if( hour->getMinuto() < 10 )	// verificar se o minuto da hora inicial é menor que 10
			zero_init = "0";

		if( hour_end->getMinuto() < 10 )	// verificar se o minuto da hora final é menor que 10
			zero_end = "0";

		if ( date->getAno() > ano_int ) {
			cout << " - ";
			cout << match->getNome() << endl;
			cout << "    Dia: " << date->getDia() << "/" << date->getMes() << "/" << date->getAno() << endl;
			cout << "    Hora início: " << hour->getHora() << ":" << zero_init << hour->getMinuto() << endl;
			cout << "    Hora fim: " << hour_end->getHora() << ":" << zero_end << hour_end->getMinuto() << endl;
		}
		else if ( date->getAno() == ano_int ) {
			if( date->getMes() > mes_int ) {
				cout << " - ";
				cout << match->getNome() << endl;
				cout << "    Dia: " << date->getDia() << "/" << date->getMes() << "/" << date->getAno() << endl;
				cout << "    Hora início: " << hour->getHora() << ":" << zero_init << hour->getMinuto() << endl;
				cout << "    Hora fim: " << hour_end->getHora() << ":" << zero_end << hour_end->getMinuto() << endl;
			}
			else if ( date->getMes() == mes_int ) {
				if ( date->getDia() > dia_int ) {
					cout << " - ";
					cout << match->getNome() << endl;
					cout << "    Dia: " << date->getDia() << "/" << date->getMes() << "/" << date->getAno() << endl;
					cout << "    Hora início: " << hour->getHora() << ":" << zero_init << hour->getMinuto() << endl;
					cout << "    Hora fim: " << hour_end->getHora() << ":" << zero_end << hour_end->getMinuto() << endl;
				}
				else if ( date->getDia() == dia_int ) {
					if ( hour->getHora() > horas_int ) {
						cout << " - ";
						cout << match->getNome() << endl;
						cout << "    Dia: " << date->getDia() << "/" << date->getMes() << "/" << date->getAno() << endl;
						cout << "    Hora início: " << hour->getHora() << ":" << zero_init << hour->getMinuto() << endl;
						cout << "    Hora fim: " << hour_end->getHora() << ":" << zero_end << hour_end->getMinuto() << endl;
					}
					else if ( hour->getHora() == horas_int ) {
						if ( hour->getMinuto() > minutos_int ) {
							cout << " - ";
							cout << match->getNome() << endl;
							cout << "    Dia: " << date->getDia() << "/" << date->getMes() << "/" << date->getAno() << endl;
							cout << "    Hora início: " << hour->getHora() << ":" << zero_init << hour->getMinuto() << endl;
							cout << "    Hora fim: " << hour_end->getHora() << ":" << zero_end << hour_end->getMinuto() << endl;
						}
					}
				}
			}
		}
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
 *  MENU DE INFORMAÇÕES ÚTEIS
 */


// Dispinibiliza ao utilizador um conjunto de informações úteis acerca do campeonato
void InformacoesUteis() {
	int num_desp = campeonato.getDesportos().size();
	int num_equi = campeonato.getEquipas().size();
	int num_atl = campeonato.getAtletas().size();

	cout << "-------------------------------------------------------" << endl;
	cout << "-               ** Informações úteis **               -" << endl;
	cout << "-                                                     -" << endl;
	cout << "- Data do início do Campeonato: " << campeonato.getDataInicio() << "             -" << endl;
	cout << "- Data do fim do Campeonato: " << campeonato.getDataFim() << "               -" << endl;
	cout << "- Número de Desportos: " << num_desp << "                              -" << endl;
	cout << "- Número de Equipas: " << num_equi << "                                -" << endl;
	cout << "- Número de Atletas: " << num_atl << "                                -" << endl;
	cout << "-                                                     -" << endl;
	cout << "- 1. Voltar ao Menu Principal                         -" << endl;
	cout << "-                                                     -" << endl;
	cout << "-------------------------------------------------------" << endl;

	int escolha_listagens;
	cin >> escolha_listagens;

	if ( escolha_listagens != 1) {
		cout << " Por favor, escolha 1 para voltar ao Menu Incial.";
		cout << string(8,'\n');
		InformacoesUteis();
	} else {
		cout << string(8,'\n');
		MenuInicial();
	}
}


/**
 *  MENUS RELACIONADOS COM AS LISTAGENS
 */


// Listagem de Atletas e toda a sua informação
void ListaDeAtletas() {
	string resposta1, modalidade;
	int num;

	for( unsigned int i = 0; i < campeonato.getModalidades().size(); i++ ) {
		cout << " Modalidade: " << campeonato.getModalidades()[i]->getNome() << endl;
		for ( unsigned int j = 0; j < campeonato.getModalidades()[i]->getAtletas().size(); j++) {
			cout << " " << j+1 <<": " << campeonato.getModalidades()[i]->getAtletas()[j]->getNome() << endl;
		}
		cout << endl;
	}

	cout << " Deseja ver as informações de algum atleta? (s,n) ";
	cin >> resposta1;

	bool coisa = true;
	while (coisa) {
		if (resposta1 == "s"){
			cout << " Qual modalidade? ";
			cin >> modalidade;
			if( campeonato.findModalidade(modalidade)->getAtletas().size() == 0 ) {
				cout << " Por favor, escolha uma modalidade com algum atleta." << endl;
				continue;
			}
			cout << " Qual o número do atleta na lista acima? ";
			cin >> num;
			campeonato.findModalidade(modalidade)->getAtletas()[num-1]->info();
			coisa = false;
		}
		else if (resposta1 == "n")
			coisa = false;
		else
			cout << " Introduza uma opção correta, s ou n!";
	}
}


void ListaDeClassificacoes(){
	vector <int>classificacao;
	vector <Atleta*>atletas;
	string nome;

	cout << " Qual a modalidade que pretende ver a classificação? ";
	cin >> nome;

	for (unsigned int i=0;i <campeonato.getProvas().size();i++) {
		if(campeonato.getProvas()[i]->getModalidade()->getNome() == nome) {
			cout <<campeonato.getProvas()[i]->getNome() <<":" <<endl;
			for (map<Atleta*, int>::iterator it=campeonato.getProvas()[i]->getClassificacoesAtletas().begin() ; it != campeonato.getProvas()[i]->getClassificacoesAtletas().end();it++){
			atletas.push_back(it->first);
			classificacao.push_back(it->second);
			}
			// ordenação insertionsort
			for (unsigned int p = 1; p < atletas.size(); p++) {
				Atleta* tmp = atletas[p];
				int tmp2 = classificacao[p];
				int j;
				for (j = p; j > 0 && tmp2 < classificacao[j-1]; j--) {
					atletas[j] = atletas[j-1];
					classificacao[j]=classificacao[j-1];
				}
				atletas[j] = tmp;
				classificacao[j]=tmp2;
			}
			for (unsigned int k=0;k < atletas.size();k++) {
				cout << k+1 << ":" << atletas[k]->getNome()  <<endl;
			}
		}

		classificacao.clear();
		atletas.clear();
	}

	bool coisa=true;
	while(coisa) {
		string resposta;
		cout << " Deseja voltar ao menuInicial (s ou n)? ";
		cin >> resposta;
		if (resposta == "s")
			coisa = false;
		else if (resposta== "n") {
			ListaDeClassificacoes();
			coisa = false;
		}
		else
			cout << " Introduza uma opção valida!";
	}

}


void ListaDeFuncionarios() {
	vector<Funcionario*> v = campeonato.getFuncionarios();
	for( unsigned int j = v.size()-1; j > 0; j-- ) {
		bool troca = false;
		for( unsigned int i = 0; i < j; i++ )
			if(v[i+1]->getAnosTrabalho() < v[i]->getAnosTrabalho()) {
				swap(v[i],v[i+1]);
				troca = true;
			}
		if (!troca)
			break;
	}

	for (unsigned int i=0; i< v.size();i++){
		cout << v[i]->getNome() << ":" <<v[i]->getAnosTrabalho() << endl;
	}

}


void RankingEquipas() {
	priority_queue<Equipa*> ranking;

	for( unsigned int i = 0; i < campeonato.getEquipas().size(); i++ )
		ranking.push(campeonato.getEquipas()[0]);

	cout << "Ranking das equipas:" << endl;
	cout << "" << endl;

	while (!ranking.empty()) {
	   cout << "1: " << ranking.front() << endl;  // Print highest priority string
	   ranking.pop();                    // Remmove highest priority string
	}
	cout << "1: " << endl;

}


// Menu das Listagens, efetua a listagem de toda a informação que o utilizador quiser
void MenuListagens() {
	int escolha_listagens;

	cout << "-------------------------------------------------------------" << endl;
	cout << "-                     *** Listagens ***                     -" << endl;
	cout << "-                                                           -" << endl;
	cout << "- O que pretende listar?                                    -" << endl;
	cout << "-                                                           -" << endl;
	cout << "- 1. Atletas                                                -" << endl;
	cout << "- 2. Classificação das provas de uma modalidade             -" << endl;
	cout << "- 3. Listagem de Funcionários ordenados por anos de serviço -" << endl;
	cout << "- 4. Atletas                                                -" << endl;
	cout << "- 5. Voltar ao Menu Principal                               -" << endl;
	cout << "-                                                           -" << endl;
	cout << "-------------------------------------------------------------" << endl;

	cout << " O que pretende fazer? ";
	cin >> escolha_listagens;

	if ( escolha_listagens != 1 && escolha_listagens != 2 && escolha_listagens != 3 && escolha_listagens != 4 && escolha_listagens != 5 ) {
		cout << " Por favor, faça uma escolha adequada.";
		cout << string(8,'\n');
		MenuInicial();
	}

	switch (escolha_listagens) {
		case 1:
			cout << string(8,'\n');
			ListaDeAtletas();
			cout << string(8,'\n');
			MenuInicial();
			break;
		case 2:
			cout << string(8,'\n');
			ListaDeClassificacoes();
			cout << string(8,'\n');
			MenuInicial();
			break;
		case 3:
			cout << string(8,'\n');
			ListaDeFuncionarios();
			cout <<string(8,'\n');
			MenuInicial();
			break;
		case 4:
			cout << string(8,'\n');
			RankingEquipas();
			cout <<string(8,'\n');
			MenuInicial();
			break;
		case 5:
			cout << string(8,'\n');
			MenuInicial();
			break;

	}
}

//MENU HASHTABLE


void MenuHashTable(){
	int escolha;

		cout << "-------------------------------------------------------------" << endl;
		cout << "-                     *** HashTable opções ***              -" << endl;
		cout << "-                                                           -" << endl;
		cout << "- O que pretende?						                     -" << endl;
		cout << "-                                                           -" << endl;
		cout << "- 1. Ver lista de adeptos                                   -" << endl;
		cout << "- 2. Ver lista de adeptos com bilhete válido                -" << endl;
		cout << "- 3. Comprar bilhete                                        -" << endl;
		cout << "- 4. Vender bilhete                                         -" << endl;
		cout << "- 5. Novo adepto                                            -" << endl;
		cout << "- 6. Voltar ao Menu das estruturas de dados                 -" << endl;
		cout << "- 7. Voltar ao Menu Principal                               -" << endl;
		cout << "-                                                           -" << endl;
		cout << "-------------------------------------------------------------" << endl;

		cout << " O que pretende fazer? ";
		cin >> escolha;
		switch (escolha) {
				case 1:
					cout << string(3,'\n');
					campeonato.listarAdeptos();
					cout << string(3,'\n');
					MenuHashTable();
					break;
				case 2:
					cout << string(3,'\n');
					campeonato.listarAdeptosComBilhete();
					cout << string(3,'\n');
					MenuHashTable();
					break;
				case 3:
					cout << string(3,'\n');
					campeonato.comprarBilhete();
					campeonato.saveBilhetes();
					cout <<string(3,'\n');
					MenuHashTable();
					break;
				case 4:
					cout << string(3,'\n');
					campeonato.venderBilhete();
					campeonato.saveBilhetes();
					MenuHashTable();
					break;
				case 5:
					cout << string(8,'\n');
					campeonato.criaAdepto();
					campeonato.saveBilhetes();
					MenuHashTable();
					break;
				case 6:
					cout << string(8,'\n');
					MenuInicial2();
					break;
				case 7:
					cout << string(8,'\n');
					MenuInicial();
					break;
		}


}


/**
 *  MENU INICIAL
 */
void MenuInicial2(){
	int escolha_menu;

		cout << "----------------------------------------------------" << endl;
		cout << "-*** Menu das Estruturas de dados do 2ºtrabalho ***-" << endl;
		cout << "-                                                  -" << endl;
		cout << "- 1. BST                                           -" << endl;
		cout << "- 2. Filas de prioridade                           -" << endl;
		cout << "- 3. Tabelas de dispersão                          -" << endl;
		cout << "- 4. Voltar ao menu inicial                        -" << endl;


		cout << " O que pretende fazer? ";
		cin >> escolha_menu;

		if ( escolha_menu != 1 && escolha_menu != 2 && escolha_menu != 3 && escolha_menu != 4 ) {
			cout << " Por favor, faça uma escolha adequada.";
			cout << string(8,'\n');
			MenuInicial2();
		}

		switch (escolha_menu) {
			case 1:
				cout <<string(8,'\n');
				MenuBST();
				break;
			case 2:
				cout << string(8,'\n');
				break;
			case 3:
				cout <<string(8,'\n');
				MenuHashTable();
				break;
			case 4:
				cout <<string(8,'\n');
				MenuInicial();
				break;

}

}
// Menu Inicial, chama todos os outros Menus mediante a escolha do utilizador
void MenuInicial() {
	int escolha_menu;

	cout << "----------------------------------------------------" << endl;
	cout << "-            *** Menu Principal ***                -" << endl;
	cout << "-                                                  -" << endl;
	cout << "- 1. Menu para as Estruturas de dados do 2ºtrabalho-" << endl;
	cout << "- 2. Manutenção de Equipas e Atletas               -" << endl;
	cout << "- 3. Manutenção de Desportos e Modalidades         -" << endl;
	cout << "- 4. Manutenção das Provas                         -" << endl;
	cout << "- 5. Manutenção do Calendário                      -" << endl;
	cout << "- 6. Manutenção de Infrastruturas e Funcionários   -" << endl;
	cout << "- 7. Informações úteis                             -" << endl;
	cout << "- 8. Listagens                                     -" << endl;
	cout << "- 9. Terminar o programa                           -" << endl;
	cout << "-                                                  -" << endl;
	cout << "----------------------------------------------------" << endl;

	cout << " O que pretende fazer? ";
	cin >> escolha_menu;

	if ( escolha_menu != 1 && escolha_menu != 2 && escolha_menu != 3 && escolha_menu != 4 && escolha_menu != 5 && escolha_menu != 6 && escolha_menu != 7 && escolha_menu != 8 && escolha_menu != 9) {
		cout << " Por favor, faça uma escolha adequada.";
		cout << string(8,'\n');
		MenuInicial();
	}

	switch (escolha_menu) {
		case 1:
			cout <<string(8,'\n');
			MenuInicial2();
			break;
		case 2:
			cout << string(8,'\n');
			MenuEquipasAtletas();
			break;
		case 3:
			cout << string(8,'\n');
			MenuDesportosModalidades();
			break;
		case 4:
			cout << string(8,'\n');
			MenuProvas();
			break;
		case 5:
			cout << string(8,'\n');
			MenuCalendario();
			cout << string (8, '\n');
			break;
		case 6:
			cout << string(8,'\n');
			MenuInfrastruturas();
			break;
		case 7:
			cout << string(8,'\n');
			InformacoesUteis();
			break;
		case 8:
			cout << string(8,'\n');
			MenuListagens();
			break;
		case 9:
			return;
	}
}


