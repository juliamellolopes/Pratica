#include "Funcoes.hpp"
#include "Lista.hpp"
#include "Fila.hpp"
#include "Pilha.hpp"
#include <cstdio>
#include <math.h>
#include <iostream>
#include <json.hpp>
#include <fstream>

using namespace std;
using json = nlohmann::json;

void Funcoes::opcao1a(){
	List<int> par;
  	List<int> impar;
	List<tuple> tuplas;
	
	for (int i = 0; i < 200; i++) {
		if (i % 2 == 0)
		 	par.push(i);
	   	else
	      	impar.push(i);
	}
	
	node<int> *pIm = impar.HEAD;
 	node<int> *pPar = par.HEAD;
 	
	 
	for (int i = 0; i < 100; i++) {
	    tuplas.push({pPar->dado, pIm->dado});
	    pIm = pIm->prox;
	    pPar = pPar->prox;
	}
	
	node<tuple> *ptuple = tuplas.HEAD;
	
	for (int i = 0; i < 100; i++) {
	    cout << "{ " << ptuple->dado.n1 << ", " << ptuple->dado.n2 << "}";
	    ptuple = ptuple->prox;
	}
}

void Funcoes::opcao1b(){
	List<int>L1;
	List<int>L2;
	int somaL1 = 0;
	int somaL2 = 0;
	node<int> *pL1 = L1.HEAD;
	node<int> *pL2 = L2.HEAD;
	
	for(int i = 0; i < 3; i++){
		L1.push(rand()%13);
		L2.push(rand()%13);
		pL1 = pL1->prox;
		pL2 = pL2->prox;
	}
	
	int num = rand()%13;
	pL1 = L1.HEAD;
	pL2 = L2.HEAD;
	cout << endl;
	for(int i = 0; i < 3; i++){
		cout << "{ " << pL1->.dado << ", " << pL2->dado << "}";
		pL1 = pL1->prox;
		pL2 = pL2->prox;
	}

	pL1 = L1.HEAD;
	pL2 = L2.HEAD;
	for(int i = 0; i < 3; i++){
		pL1->dado = pL1->dado - num;
		pL1 = pL1->prox;
		pL2->dado = pL2->dado - num;
		pL2 = pL2->prox;
	}
	
	pL1 = L1.HEAD;
	pL2 = L2.HEAD;
	for(int i = 0; i < 3; i++){
		somaL1 += pL1->dado;
		somaL2 += pL2->dado;
		pL1 = pL1->prox;
		pL2 = pL2->prox;
	}
	
	if(somaL1 > somaL2){
		cout << "\nO vencedor e L1" << endl;
	}else{
		cout << "\nO vencedor e L2" << endl;
	}
}

void Funcoes::opcao1c(){
	List<produto>L1;
	List<supermercado>L2;
	List<fornecedor>L3;
	List<fornecedor>L4;
	node<produto> *pL1 = L1.HEAD;
	node<supermercado> *pL2 = L2.HEAD;
	node<fornecedor> *pL3 = L3.HEAD;
	node<fornecedor> *pL4 = L4.HEAD;
	json j;
	ifstream file;
	
	file.open("j.json");
	file >> j;
	
	
	//cout << "quantos produtos vc deseja passar?" << endl;
	//cin >> n;
	//for(int i = 0; i < n; i++){
	//	cout << "Informe o nome o produto: " << endl;
	//	cin >> nome;
	//	for(int j = 0; j < 2; j++){
	//		x = L1->nome;
	//		pL1 = pL1->prox;
	//		if(nome == x){
	//			aux1 = L1->cod;
	//		}
	//	}	
	//	for(int j = 0; j < 2; j++){
	//		x = L2->cod;
	//		pL2 = pL2->prox;
	//		if(aux1 == x){
	//			aux2 = L2->id;
	//			x = L3->cod;
	//			pL3 = pL3->prox;
	//			if(aux2 == x){
	//				//
	//			}
	//		}
	//	L4.push({aux2,aux1,aux3});	
	//	pL4 = pL4->prox;
	 //   }
	//}
	//cout << "\n\tLISTA FINAL" << endl;
	//for(int i = 0; i < 2; i++){
	//	cout << "{ " << L4->id << ", " << L4->cod << " " << L4->valor << "}" << endl;
	//	pL4 = pL4->prox;
	//}
}

void Funcoes::opcao2a(){
	string str;
	Pilha<char>P1;

	cout << "Informe a expressao matematica:" << endl;
	cin >>  str;
	
	for(long unsigned int i = 0; i < str.size(); i++){
		if(str[i] == '(' ){
			P1.push(str[i]);
		}else if(str[i] == ')'){
			P1.pop();
		}
	}
	
	cout << endl;
	if(P1.HEAD == NULL){
		cout << "\n\nExpressao com parenteses CORRETO!" << endl;
	}else{
		cout << "\n\nEcpressao com parenteses INCORRETO!" << endl;
	}
}

void Funcoes::opcao2b(){
	Pilha<int>P1;
	Pilha<int>P2;
	
	for(int i = 0; i < 10; i++){
		P1.push(rand()%10);
	}
	
	for(int i = 0; i < 10; i++){
		P2.push(rand()%10);
	}
	
	aux = P1.HEAD;
	P1.HEAD = P2.HEAD;
	P2.HEAD = aux;
	aux = P1.TAIL;
	P1.TAIL = P2.TAIL;
	P2.TAIL = aux;

	cout << endl;
	for(int i = 0; i < 10; i++){
		cout << " " << pP2->dado << endl;
	    pP2 = pP2->prox;
	}
}

void Funcoes::opcao2c(){
	Pilha<int>P;
	node<int> *pP = P.HEAD;
	
	for(int i = 0; i < 20; i++){
		P.push(rand%100);
	}
	
	int x;
	int cont = 0;
	for(int i = 0; i < 20; i++){
		x = pP.dado;
		pP = pP->prox;
		cout << " Co-Primos de " << x << endl;
		cout << "{";
		for(int i = 0; i =< x ;i++){
			//if(i % 2 != 0){
				//cout << " " << i;
			    //cont++
			//}	
		}
		cout << "}" << endl;
		cout << "\nTOTAL DE CO-PRIMOS: " << cont <<endl;;
	}
}

void Funcoes::opcao3a(){
	Fila<tuple>F1;
	Fila<string>FResultante;
	int x, y,K;
	nope<tuple> *pF1 = F1.HEAD;
	nope<string> *pFR = FResultante.HEAD;

	for(int i = 0; i < 5; i++){
		F1.push({x,y,i});	
	}
	
	for(int i = 0; i < 5; i++){
		FResultante.push(pow((pF1->x + pF1->y),pFi->k));	
		pFR = pFR->prox;	
	}
	
	cout << endl;
	for(int i = 0; i < 10; i++){
		cout << " " << pFR->dado << endl;
	    pFR = pFR->prox;
	}
}

void Funcoes::opcao3b(){
	Fila<dupla>F1;
	Fila<dupli>F2;
	int x, y, z[5];
	nope<dupla> *pF1 = F1.HEAD;
	nope<dupli> *pF2 = F2.HEAD;
	
	for(int i = 0; i < 10; i++){
		x = rand()%100;
		y = pF1->at;
		pF1 = pF1->prox;
		if(x != y){
			for(int i = 0; i < 5; i++){
				z[i] = rand()%100;
			}
		F1.push(x,z);
		}
	}
	
	int maior = z[1];
	
	pF1 = F1.HEAD;
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 5; j++){
			if(maior < z[i]){
				maior = i;
			}
		}
		F2.push(pF1->at, maior);
		pF1 = pF1->prox;
		pF2 = pF2->prox;
	}
	
	cout << "\n\tATRIBUTO E CLASSE:" << endl;
	for(int i = 0; i < 10; i++){
		cout << "{ " << pF2->at << ", " << pF2->classe  << "}"<< endl;
		pF2 = pF2->prox;
	}
}

void Funcoes::opcao4(){
	Fila<cliene>F;
	Pilha<float>P;
	List<produtos>L;
	string CPF;
	char nome;
	float preco;
	float somador = 0;
	float faturamento = 0;
	int vol;
	nope<cliente> pF = F.HEAD;
	nope<produtos> pL = L.HEAD;
	nope<float> pP = P.HEAD;
	
	for(int i = 0; i < 10; i++){
		cout << "Informe o numero de volumes: " << endl;
		cin >> vol;
		if(vol == 10){
			cout << "Informre o CPF: ";
			cin >> CPF;
			for(int j = 0; j < vol; i++){
				cout << "Informe o nome do produto: " << endl;
				cin >> nome;
				cout << "Informe o preco do produto: " << endl;
				cin >> preco;
				somador += preco;
				L.push(nome, preco);
			}
			F.push(CPF, pL->dado);
			PL = pL->prox;
			P.push(somador);
		}else{
			cout << "VOLUME DE PRODUTOS MAIOR QUE O PERMITIDO!" << endl;
		}
	} 

	pF = F.HEAD;
	pL = L.HEAD;
	pP = P.HEAD;
	cout << "\n\tCLIENTES DO DIA:" << endl;
	for(int i = 0; i < 10; i++){
		cout << "[i+1]Cpf: " << pF.cpf << endl;
		for(int j = 0; j < 10; j++){
			cout << "[i+1]: " << pF.L->dado << endl;
			pL = pL->prox;
		}
		pF = pF->prox;
		cout << "\nValor total: " << pP->dado;
		pP = pP->prox;
	}
	
	pP = P.HEAD;
	for(int i = 0; i < 10; i++){
		faturamento += pP->dado;
		pP = pP->prox;
	}
	
	cout << "\nFATURAMENTO DO DIA: " << faturamento;
}
