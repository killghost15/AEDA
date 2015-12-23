#ifndef CAMPEONATO_H
#define CAMPEONATO_H



#include <fstream>
#include <vector>
#include <stdlib.h>
#include "BST.h"
#include <map>
#include<tr1/unordered_set>

#include "Bilhete.h"
#include "Desporto.h"
#include "Infrastrutura.h"
#include "Funcionario.h"
#include "Prova.h"


#define file_equipas "equipas.txt"
#define file_atletas "atletas.txt"
#define file_modalidades "modalidades.txt"
#define file_provas "provas.txt"
#define file_desportos "desportos.txt"
#define file_infrastruturas "infrastruturas.txt"
#define file_funcionarios "funcionarios.txt"
#define file_bilhetes "bilhetes.txt"

using namespace std;

typedef struct  {

	int operator()(Bilhete *b) const{
		int hash = b->getId();
		return hash;
	}

	bool operator()( Bilhete *b1,  Bilhete *b2) const {
		return b1->getId() == b2->getId();
	}
}hashBilhete;

typedef tr1::unordered_set<Bilhete*, hashBilhete> Tabela;


class Campeonato {
	vector<Equipa*> equipas;
	vector<Atleta*> atletas;
	vector<Modalidade*> modalidades;
	vector<Prova*> provas;
	vector<Desporto*> desportos;
	vector<Infrastrutura*> infrastruturas;
	vector<Funcionario*> funcionarios;
	vector<Adepto*> adeptos;
	Tabela bilhetes;

public:
	BST<Prova> TreeProva;
	Campeonato(Prova prova):
		TreeProva(prova){
	};
	// Metodos get
	vector<Equipa*> getEquipas();
	vector<Atleta*> getAtletas();
	vector<Modalidade*> getModalidades();
	vector<Prova*> getProvas()const;
	vector<Desporto*> getDesportos();
	vector<Infrastrutura*> getInfrastruturas();
	vector<Funcionario*> getFuncionarios();
	string getDataInicio();
	string getDataFim();
	// Metodos find
	Equipa* findEquipa(string nomeEquipa);
	Atleta* findAtleta(string nomeAtleta);
	Modalidade* findModalidade(string nomeModalidade);
	Prova* findProva(string nomeProva);
	Desporto* findDesporto(string nomeDesporto);
	Infrastrutura* findInfrastrutura(string nomeInfrastrutura);
	// Metodos exists
	bool existsEquipa(string nomeEquipa);
	bool existsAtleta(string nomeAtleta);
	bool existsModalidade(string nomeModalidade);
	bool existsProva(string nomeProva);
	bool existsDesporto(string nomeDesporto);
	bool existsInfrastrutura(string nomeInfrastrutura);
	bool existsFuncionario(string nomeFuncionario);
	bool CanAtletaEnterModalidade(string nomeModalidade, string nomeAtleta);
	// Metodos erase
	void eraseAtletaModalidade(string nomeModalidade, string nomeAtleta);
	void eraseEquipa(string nomeEquipa);
	void eraseAtleta(string nomeAtleta);
	void eraseDesporto(string nomeDesporto);
	void eraseProva(string nomeProva);
	void eraseInfrastrutura(string nomeInfrastrutura);
	void eraseFuncionario(string nomeFuncionario);
	// Metodos sobre Equipas
	void loadEquipas();
	void saveEquipa();
	void addEquipa(Equipa *equi);
	// Metodos sobre Atletas
	void loadAtletas();
	void saveAtleta();
	void addAtleta(Atleta *atl);
	// Metodos sobre Modalidades
	void loadModalidades();
	void saveModalidade();
	void addModalidade(Modalidade *modal);
	// Metodos sobre Provas
	void loadProvas();
	void saveProva();
	void addProva(Prova *prova);
	// Metodos sobre Desportos
	void loadDesportos();
	void saveDesporto();
	void addDesporto(Desporto *desp);
	// Metodos sobre Infrastruturas
	void loadInfrastruturas();
	void saveInfrastrutura();
	void addInfrastrutura(Infrastrutura *infra);
	// Metodos sobre Funcionarios
	void loadFuncionarios();
	void saveFuncionario();
	void addFuncionario(Funcionario *func);
	// Metodos para mudar um atleta de equipa
	int findAtletaIndex(string nomeAtleta);
	void changeEquipa(int index, Equipa *equi);
	// Metodos para mudar a infrastrutura de uma prova
	int findProvaIndex(string nomeProva);
	void changeInfrastrutura(int index, Infrastrutura *infra);
	// Metodos para adicionar atletas a uma modalidade
	int findModalidadeIndex(string nomeModalidade);
	void changeModalidade(int index, Modalidade *mod);
	// Metodos para determinar a data do inicio e do fim do campeonato
	//metodos da BST
	Prova encontraProvaBST(string nome){
		for(BSTItrIn<Prova> it(TreeProva);!it.isAtEnd();it.advance()){
					if (it.retrieve().getNome()==nome){
						return it.retrieve();
					}
		}

	}

	void removeProvaBST(string nome){
		for(BSTItrIn<Prova> it(TreeProva);!it.isAtEnd();it.advance()){
			if (it.retrieve().getNome()==nome){
				TreeProva.remove(it.retrieve());
				return;
			}
		}
	};
	void inserirProvaBST(const Prova prova){
		TreeProva.insert(prova);
	};
	void provasToBST(){
		for (vector<Prova*>::const_iterator it=provas.begin();it!=provas.end();it++ ){
			//Cena para disfarçar o problema do load...
			if ((*it)->getNome()==""){}
			else{
			TreeProva.insert(*(*it));
		}
		}

	}
	void showProvasCalendar(){
		for(BSTItrIn<Prova> it(TreeProva);!it.isAtEnd();it.advance()){
			cout<< it.retrieve().getNome()<<":"<<" Data: "<<it.retrieve().getData()->getDia()<<"/"<<it.retrieve().getData()->getMes()<<"/"<<it.retrieve().getData()->getAno()<<" hora de inicio "<<it.retrieve().getHoraInicio()->getHora()<<":"<<it.retrieve().getHoraInicio()->getMinuto() <<" duração "<< it.retrieve().getDuracao()<<endl;
		}
	}
	vector <Prova> getDayorNext(unsigned int &dia,unsigned int &mes, unsigned int ano){
		vector<Prova>v;

		for(BSTItrIn<Prova> it(TreeProva);!it.isAtEnd();it.advance()){
			if (it.retrieve().getData()->getAno()==ano){
				if(it.retrieve().getData()->getMes()==mes){
					if(it.retrieve().getData()->getDia()==dia)
						v.push_back(it.retrieve());
				}
			}

		}
		if (v.size()==0){

			for(BSTItrIn<Prova> it2(TreeProva);!it2.isAtEnd();it2.advance()){
						if (it2.retrieve().getData()->getAno()==ano){
							if(it2.retrieve().getData()->getMes()==mes){
								if(it2.retrieve().getData()->getDia() > dia)
									dia=it2.retrieve().getData()->getDia();
									v.push_back(it2.retrieve());
							}
						}

			}
		}
		if (v.size()==0){
					mes++;
					for(BSTItrIn<Prova> it3(TreeProva);!it3.isAtEnd();it3.advance()){
								if (it3.retrieve().getData()->getAno()==ano){
									if(it3.retrieve().getData()->getMes()==mes){
										if(it3.retrieve().getData()->getDia() == 1)
											dia=it3.retrieve().getData()->getDia();
											v.push_back(it3.retrieve());
									}
								}

					}
				}
		return v;
	};

	//HASHTABLE FUNCS

	void addBilhete(Bilhete* b){
		bilhetes.insert(b);
	}

	void retirarBilhete(Adepto* ad){
		Tabela::iterator it = bilhetes.begin();
		for(;it!=bilhetes.end();it++){
			if((*it)->getAdepto()->getEmail() == ad->getEmail()){
				bilhetes.erase(it);
			}
		}
	}

	bool existeAdepto(string nome){
		for(unsigned int i=0;i<adeptos.size();i++){
			if(adeptos[i]->getNome()==nome)
				return true;
		}
		return false;
	}

	void venderBilhete(){
		string nome_adepto;
		vector<Prova*> provas_bil;
		while(1){
			cout<<"Nome do adepto(0 para sair): ";
			cin>>nome_adepto;
			cin.get();
			if(nome_adepto=="0")
				return;

			if(!existeAdepto(nome_adepto)){
				cout<<endl<<"Nao existe um adepto com esse nome"<<endl;
				continue;
			}

			Tabela::iterator it = bilhetes.begin();

			for(;it!=bilhetes.end();it++){
				if((*it)->getAdepto()->getNome()==nome_adepto){
					provas_bil = (*it)->getProvas();
					provas_bil.clear();
					(*it)->setProvas(provas_bil);
				}
			}
			cout<<endl<<"O bilhete foi vendido com sucesso"<<endl;
			return;
		}
	}

	void comprarBilhete(){
		string nome_adepto,prova_str;
		bool found_adepto = false;
		Adepto* ad;
		vector<Prova*> provas_adepto;
		string novo, novo_nome, novo_idade, novo_email, novo_morada;
		int idade;

		cout<<endl<<"Novo adepto? (0 - Sim / 1- Nao / Outro - Sair)"<<endl;
		cin>>novo;
		cin.clear();
		if(novo == "0"){
			while(1){

				cout<<endl<<"Nome: ";
				cin>>novo_nome;
				cin.get();
				if(existeAdepto(novo_nome)){
					cout<<endl<<"Ja existe um adepto com esse nome"<<endl;
				}
				else
					break;
			}
				cout<<endl<<"Idade: ";
				cin>>novo_idade;
				cin.get();

				cout<<endl<<"Email: ";
				cin>>novo_email;
				cin.get();

				cout<<endl<<"Morada: ";
				cin>>novo_morada;
				cin.get();

				idade = atoi(novo_idade.c_str());
				ad = new Adepto(novo_nome, idade, novo_email, novo_morada);
				adeptos.push_back(ad);

				cout <<endl<< "Provas?"<<endl;
				while(1){
					cout<<endl<<"Nome (0 to exit):";
					getline(cin,prova_str);
					if(prova_str == "0") break;
					for(unsigned int i=0;i<provas.size();i++){
						if(provas[i]->getNome()==prova_str){
							provas_adepto.push_back(provas[i]);
							cout<<endl<<"Prova junta ao bilhete com sucesso!";
						}
					}
				}
				if(provas_adepto.size() == 0){
					cout<<endl<<"O bilhete nao foi adquirido"<<endl;
					return;
				}
				Bilhete* b = new Bilhete(provas_adepto,ad);
				addBilhete(b);
				cout<<endl<<"O bilhete foi adquirido com sucesso"<<endl;
				return;
			}

		if(novo =="1"){
			while(1){
				cout<<endl<<"Nome do adepto(0 para sair): ";
				cin>>nome_adepto;
				cin.get();
				if(nome_adepto=="0")
					return;
				Tabela::iterator iter =bilhetes.begin();

				for(;iter!=bilhetes.end();iter++){
					if((*iter)->getAdepto()->getNome() == nome_adepto){
						ad = (*iter)->getAdepto();
						found_adepto = true;
					}
				}
				if(!found_adepto)
					cout<<endl<<"Nao existe nenhum adepto com esse nome"<<endl;
				else
					break;
			}
		}
		else
			return;

		cout <<endl<< "Provas a juntar ao bilhete?"<<endl;
		while(1){
			cout<<endl<<"Nome (0 to exit):";
			getline(cin, prova_str);
			if(prova_str == "0") break;
			for(unsigned int i=0;i<provas.size();i++){
				if(provas[i]->getNome()==prova_str){
					provas_adepto.push_back(provas[i]);
					cout<<endl<<"Prova junta ao bilhete com sucesso!";
				}
			}
		}
		if(provas_adepto.size() == 0){
			cout<<endl<<"Erro na operaçao"<<endl;
			return;
		}

		Tabela::iterator it = bilhetes.begin();
		for(;it!=bilhetes.end();it++){
			if((*it)->getAdepto()->getNome()==ad->getNome()){
				for(unsigned int k=0;k<provas_adepto.size();k++){
					(*it)->addProva(provas_adepto[k]);
				}
			}
		}

		cout<<endl<<"O bilhete foi modificado com sucesso"<<endl;

	}

	void listarAdeptos(){
		Tabela::iterator it = bilhetes.begin();
		for(;it!=bilhetes.end();it++){
			(*it)->getAdepto()->info();
			cout<<endl;
		}
	}

	void listarAdeptosComBilhete(){
		vector<Prova*> provas_adepto;
		Tabela::iterator it = bilhetes.begin();
		for(;it!=bilhetes.end();it++){
			if((*it)->getProvas().size()!=0){
				cout<<endl<<"Nome: "<< (*it)->getAdepto()->getNome()<<endl;
				cout<<"Provas"<<endl;
				provas_adepto =(*it)->getProvas();
				for(unsigned int i=0;i<provas_adepto.size();i++){
					cout<<".."<< provas_adepto[i]->getNome()<<endl;
				}
				provas_adepto.clear();
			}
		}
	}

	void criaAdepto(){
		string novo_nome, novo_idade, novo_email,novo_morada;
		int idade;
		Adepto* ad;
			while(1){

				cout<<endl<<"Nome: ";
				cin>>novo_nome;
				cin.get();
				if(existeAdepto(novo_nome)){
					cout<<endl<<"Ja existe um adepto com esse nome"<<endl;
				}
				else
					break;
			}
				cout<<endl<<"Idade: ";
				cin>>novo_idade;
				cin.get();

				cout<<endl<<"Email: ";
				cin>>novo_email;
				cin.get();

				cout<<endl<<"Morada: ";
				cin>>novo_morada;
				cin.get();

				idade = atoi(novo_idade.c_str());
				ad = new Adepto(novo_nome, idade, novo_email, novo_morada);
				adeptos.push_back(ad);

				vector<Prova*>provas_adepto;
				Bilhete* b = new Bilhete(provas_adepto,ad);
				addBilhete(b);
				cout<<endl<<"Ja existe um novo adepto!"<<endl;
				return;
	}


	void loadBilhetes();
	void saveBilhetes();

};



#endif
