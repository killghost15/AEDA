#include "Modalidade.h"



Modalidade::Modalidade(string name) {
	nome = name;
}


string Modalidade::getNome() const {
	return nome;
}


vector<Atleta*> Modalidade::getAtletas() {
	return atletas;
}


void Modalidade::pushAtleta(Atleta *atl) {
	atletas.push_back(atl);
}
vector <Prova*> Modalidade::getProvas(){
	return Provas;
}

/*
int Modalidade::getPosicao(){
	return posicao;
}
*/
void Modalidade::eraseAtleta(int index) {
	atletas.erase(atletas.begin()+index);
}


void Modalidade::eraseAtleta2(int index) {
	atletas[index] = atletas.back();
	atletas.pop_back();
}
void Modalidade::CriarProva(string nomeProva, int dia, int mes, int ano)
{
	 Prova *p= new Prova(nomeProva,dia,mes,ano);
	 Provas.push_back(p);
	}

void Modalidade::EliminaProva(string nomeProva)
{
	for (unsigned int i=0; i< Provas.size();i++){
	if (Provas[i]->getNome()==nomeProva)
		for (unsigned int j=i;j<Provas.size()-1;j++)
			Provas[j]=Provas[j+1];
	}

	}
