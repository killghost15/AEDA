#include <iostream>

#include "Bilhete.h"

int Bilhete::idBil=0;
void Bilhete::info(){
	cout<<"Bilhete id = " <<idBil<<endl;
	ad->info();
	cout<<endl<<"Provas"<<endl;

	for(unsigned int i=0; i<provas.size();i++){
		cout << "Nome" << provas[i]->getNome()<< endl;
	}
}
