#include "Menu.hpp"
#include "Funcoes.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

void Menu::menuinicial(){
	cout << "\n\n1.Questão 01" << endl;
	cout << "2.Questão 02" << endl;
	cout << "3.Questão 03" << endl;
	cout << "4.questão 04" << endl;
	cout << "5.Sair do programa" << endl;
	cout << "Informe qual das opções acima você deseja: " << endl;
}

void Menu::opcao1(){
	cout << "\n1.Alternativa A" << endl;
	cout << "2.Alternativa B" << endl;
	cout << "3.Alternativa C" << endl;
	cout << "4.Sair da questão" << endl;
}

void Menu::opcao2(){
	cout << "\nA.Alternativa A" << endl;
	cout << "B.Alternativa B" << endl;
	cout << "C.Sair da questão" << endl;
}

void Menu::questao4(){
	cout << "Questão 4. Um programa de caixa de 10 volumes, onde tera uma fila de clientes, uma lista de produtos e uma pilha de notas fiscais.";
	cout << "Sera feita uma Fila com o CPF do cliente, uma Lista com o nome dos produtos e seus preços e uma PIlha com o valor da nota fiscal das compra.";
	cout << "O programa deve imitar uma caixa de 10 operações e no final mostrar a Fila, Lista e Pilha e o faturameno do dia." << endl;
	cout << "Deseja iniciar o programa?"<< endl;
	cout << "1.Sim" << endl;
	cout << "2.Não" << endl;
}

void Menu::menu(){
	Menu me;
	Funcoes f;
	do{
		me.menuinicial();
		cin >> opc;
		
		switch(opc){
			case 1:{ 
				me.opcao1();
				cin >> al;
				while(al!=4){
					switch(al){
						case 1:{
							f.opcao1a();
						break;
						}case 2:{
							f.opcao1b();
						break;
						}case 3:{
							f.opcao1c();
						break;
						}case 4:{
							cout << "\n\nSaindo da questão!!";
							break;
						}default:{
							cout << "Opção inálida";
						break;
						}
					}
				}
			break;
			}case 2:{
				me.opcao1();
				cin >> al;
				while(al!=4){
					switch(al){
						case 1:{
							f.opcao2a();
						break;
						}case 2:{
							f.opcao2b();
						break;
						}case 3:{
							f.opcao2c();
						break;
						}case 4:{
							cout << "\n\nSaindo da questão!!";
							break;
						}default:{
							cout << "Opção inálida";
						break;
						}
					}
				}
			break;	
			}case 3:{
				me.opcao2();
				cin >> al;
				while(al!=3){
					switch(al){
						case 1:{
							f.opcao3a();
						break;
						}case 2:{
							f.opcao3b();
						break;
						}case 3:{
							cout << "\n\nSaindo da questão!!";
							break;
						}default:{
							cout << "Opção inálida";
						break;
						}
					}
				}
			break;
			}case 4:{
					me.questao4();
					cin >> al;
					while(al!=2){
						switch(al){
							case 1:{
								f.opcao4();
							break;
							}case 2:{
								cout << "\n\nSaindo da questão!!";
								break;
							}default:{
								cout << "Opção inálida";
							break;
							}
						}
					}
				break;
			}case 5:{
				cout << "\n\nSaindo do programa!!";
				break;
			}default:{
				cout << "Opção inálida";
			break;
			}
		}	
	}while(opc!=5);
}


