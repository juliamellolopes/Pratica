#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

class Menu
{
	private:
		int opc;
		int al;
	public:
		void menu();
		void menuinicial();
		void opcao1();
		void opcao2();
		void questao4();
};
#endif
