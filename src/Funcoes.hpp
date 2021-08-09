#ifndef FUNCOES_H
#define FUNCOES_H
#include "Lista.hpp"
#include "Fila.hpp"
#include "Pilha.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct tupli{
  int n1;
  int n2;
  tupli() = default;
  tupli(int n1, int n2) : n1(n1), n2(n2) {}
};

struct triple{
	string x;
	string y;
	int k;
	triple() = default;
	triple(string x, string y, int k) : x(x), y(y), k(k) {}
};

struct produtos{
	char nome;
	float preco;
	produtos() = default;
	produtos(char nome, float preco): nome(nome), preco(preco){}
};

struct cliente{
	string CPF;
	List<produtos>L;
	cliente() = default;
	
};

struct produto{
	int cod;
	string nome;
	int quant;
	produto() = default;
	produto(int cod, string nome, int quant):cod(cod),nome(nome), quant(quant) {}
};

struct supermercado{
	int id;
	vector<int>cod;
	supermercado() = default;
	supermercado(int id, vector<int> cod): id(id), cod(cod) {}
};

struct fornecedor{
	int id;
	int cod;
	float valor;
	fornecedor() = default;
	fornecedor(int id,int cod,float valor): id(id), cod(cod), valor(valor) {}
};

struct dupla{
	int at;
	int vet[5];
	dupla() = default;
	dupla(int at, int vet[5]):at(at){
		for(int i = 0; i < 5; i++){
			this->vet[i] = vet[i];
		}
	}
};

struct dupli{
	int at;
	int classe;
	dupli() = default;
	dupli(int at,int classe): at(at),classe(classe){}
};

struct uno{
	float cont;
	uno() = default;
	uno(float cont): cont(cont){}
};
struct duo{
	int x;
	duo()= default;
	duo(int x) : x(x){}
};

struct bono{
	string a;
	bono() = default;
	bono(string a):a(a){}
};

class Funcoes
{
	public:
		void opcao1a();
		void opcao1b();
		void opcao1c();
		void opcao2a();
		void opcao2b();
		void opcao2c();
		void opcao3a();
		void opcao3b();
		void opcao4();
};
#endif
