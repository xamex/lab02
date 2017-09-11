#ifndef PROGRAMA_H
#define PROGRAMA_H

#include <iostream>
#include "Empresa.h"
#include "Funcionario.h"
#include "Date.h"
#include <vector>
#include <sstream>
using namespace std;
/*
	Classe utilizada para gerenciar a execução do programa.
*/
class Programa{
	
	private: 
		string line;
		int valor;

		vector<Empresa> empresas;

	public:

	Programa();
	/*
		loop() é a função "main" do programa, a qual gerencia as chamadas.
	*/
	void loop();
	/*
		teste() faz a gerenciação de valores validos.
	*/
	int teste();
	/*
		criarEmpresa() adiciona uma empresa;
	*/
	void criarEmpresa(string nome, string cnpj);
	/*
		buscarEmpresa() impede a criação de empresas com nomes repetidos;
	*/
    bool buscarEmpresa(Empresa & e);
    /*
    	adicionarFuncionario() adiciona um funcionario a uma empresa valida;
    */
	void adicionarFuncionario(Empresa & empresa, Funcionario & funcionario);
	/*
		imprimir() imprime os dados de uma empresa, como nome, cnpj e funcionarios.
	*/
	void imprimir(Empresa & empresa);
	/*
		bonus() função chamada para dar aumento no salario dos funcionarios de uma determinada empresa.
	*/
	void bonus(Empresa & empresa , int x);
	/*
		imprimirRecentes() imprime os funcionarios com - de 90 dias na empresa a partir da data informada.
	*/
	void imprimirRecentes(Empresa & empresa , Date & date );
	/*
		mediafuncionario() monstra a media de funcionarios por empresa;
	*/
	void mediaFuncionario();
	/*
		Lista apenas o nome das empresas e seu numero referente para utilizar as demais funções.
	*/
	void listarEmpresas();

};
#endif 