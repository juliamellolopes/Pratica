#include "Funcoes.hpp"
#include "Lista.hpp"
#include "Fila.hpp"
#include "Pilha.hpp"
#include <cstdio>
#include <cmath>
#include <iostream>
#include "json.hpp"
#include <fstream>

using namespace std;
using json = nlohmann::json;

void Funcoes::opcao1a(){
	List<int> par;
  	List<int> impar;
	List<tupli> tuplas;
	
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
	
	node<tupli> *ptuple = tuplas.HEAD;
	
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
	}
	
	int num = rand()%13;

	pL1 = L1.HEAD;
	pL2 = L2.HEAD;
	cout << endl;
	for(int i = 0; i < 3; i++){
		cout << "{ " << pL1->dado << ", " << pL2->dado << "}";
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

	string nome, nome1;
	int aux1, aux2, aux3;
	int n, x;
	json j;
	ifstream file;
	
	file.open("j.json");
	file >> j;
	
	for(long unsigned int i = 0; i < 3; i++){
		L1.push({j["produto"][i]["codigo"],j["produtos"][i]["nome"],j["produtos"][i]["quantidade"]});
	}
	for(long unsigned int i = 0; i < 3; i++){
		L2.push({j["merdados"][i]["codMercados"], j["mercados"][i]["produtos"]});
	}
	for(long unsigned int i = 0; i < 3; i++){
		L3.push({j["precos"][i]["codMercados"],j["precos"][i]["codProduto"],j["precos"][i]["preco"]});
	}

	cout << "quantos produtos vc deseja passar?" << endl;
	cin >> n;
	for(int i = 0; i < n; i++){
		cout << "Informe o nome o produto: " << endl;
		cin >> nome;
		for(int j = 0; j < 2; j++){
			nome1 = pL1->dado.nome;
			pL1 = pL1->prox;
			if(nome == nome1){
				aux1 = pL1->dado.cod;
			}
		}	
		for(int j = 0; j < 2; j++){
			x = pL2->dado.cod[j];
			pL2 = pL2->prox;
			if(aux1 == x){
				aux2 = pL2->dado.id;
				x = pL3->dado.cod;
				pL3 = pL3->prox;
				if(aux2 == x){
					aux3 = pL3->dado.valor;
				}
			}
		L4.push({aux2,aux1,static_cast<float>(aux3)});
	  }
	}
	pL4 = L4.HEAD;
	cout << "\n\tLISTA FINAL" << endl;
	for(int i = 0; i < 2; i++){
		cout << "{ " << pL4->dado.id << ", " << pL4->dado.cod << " " << pL4->dado.valor << "}" << endl;
		pL4 = pL4->prox;
	}
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
	node<int> *pP2 = P2.HEAD;
	node<int> *aux = P2.HEAD;

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
	node<int> *aux = P.HEAD;

	for(int i = 0; i < 20; i++){
		P.push(rand()%100);
	}
	
	int x;
	int cont = 0;
	int div = 0;
	for(int i = 0; i < 20; i++){
		x = pP->dado;
		pP = pP->prox;
		cout << " Co-Primos de " << x << endl;
		cout << "{";
		for(int j = 0; j = x ;j++){
			div = 0;
			for(int coun = 0; coun <=sqrt(i); coun++){
				if(aux->dado%coun == 0)
                div++;
			}
			if(!div){
				cout << " " << i;
			    cont++;
			}	
		}
		cout << "}" << endl;
		cout << "\nTOTAL DE CO-PRIMOS: " << cont <<endl;;
	}
}

void Funcoes::opcao3a(){
	Fila<triple> F1;
	Fila<bono> FResultante;
	string x = "x", y = "y";
	int k = 0;
	node<triple> *pF1 = F1.HEAD;
	node<bono> *pFR = FResultante.HEAD;

	for(int i = 0; i < 5; i++){
		F1.push({x,y,i});	
	}
	
	for(int i = 0; i < 5; i++){
		FResultante.push(to_string(pow((pF1->dado.x + pF1->dado.y),pF1->dado.k)));	
		pFR = pFR->prox;	
	}
	
	cout << endl;
	for(int i = 0; i < 10; i++){
		cout << " " << pFR->dado.a << endl;
	    pFR = pFR->prox;
	}
}

void Funcoes::opcao3b(){
	Fila<dupla>F1;
	Fila<dupli>F2;
	int x, y, z[5];
	node<dupla> *pF1 = F1.HEAD;
	node<dupli> *pF2 = F2.HEAD;

	for(int i = 0; i < 10; i++){
		x = rand()%100;
		y = pF1->dado.at;
		pF1 = pF1->prox;
		if(x != y){
			for(int i = 0; i < 5; i++){
				z[i] = rand()%100;
			}
			for(int i = 0; i < 5; i++){	
				F1.push({x,z[i]});
			}
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
		F2.push({pF1->dado.at, maior});
		pF1 = pF1->prox;
		pF2 = pF2->prox;
	}
	
	cout << "\n\tATRIBUTO E CLASSE:" << endl;
	for(int i = 0; i < 10; i++){
		cout << "{ " << pF2->dado.at << ", " << pF2->dado.classe  << "}"<< endl;
		pF2 = pF2->prox;
	}
}
void Funcoes::opcao4(){
	Fila<cliente>F;
	Pilha<uno>P;
	List<produtos>L;
	string CPF;
	char nome;
	float preco;
	float somador = 0;
	float faturamento = 0;
	int vol;
	node<cliente> *pF = F.HEAD;
	node<produtos> *pL = L.HEAD;
	node<uno> *pP = P.HEAD;
	cliente c;
	c.CPF = CPF;

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
				c.L.push({nome, preco});
			}
			F.push(c);
			pL = pL->prox;
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
		cout << "[i+1]Cpf: " << pF->dado.CPF << endl;
		for(int j = 0; j < 10; j++){
			cout << "[i+1]: " << pL->dado.nome << endl;
			pL = pL->prox;
		}
		pF = pF->prox;
		cout << "\nValor total: " << pP->dado.cont;
		pP = pP->prox;
	}
	
	pP = P.HEAD;
	for(int i = 0; i < 10; i++){
		faturamento += pP->dado.cont;
		pP = pP->prox;
	}
	
	cout << "\nFATURAMENTO DO DIA: " << faturamento;
}
