#ifndef EMPRESA_H
#define EMPRESA_H



#include <iostream>
#include "Funcionario.h"
#include <string>
#include <vector>
using namespace std;



class Empresa {
    private:
        string nome;
        string cnpj;
        vector<Funcionario> funcionarios;
    public:
	static int NUMERO_EMPRESAS;
        Empresa(string nome, string cnpj);
        /*
            addFuncionario() adiciona um funcionario a empresa
        */
        void addFuncionario(Funcionario &f);
        /*
            buscarFuncionario() impede a adição de funcionarios repetidos na empresa.
        */
        bool buscarFuncionario(Funcionario & f);
        /*
            darAumento() adiciona o aumento ao salario dos funcionarios.
        */
        void darAumento(float x);
        /*
            imprimirFuncionario() imprime os funcionarios e seus dados na empresa.
        */
        void imprimirFuncionario(Date d);

    /* Gets e Sets */
        string getNome();
        void setNome(string n);
        string getCNPJ();
        void setCNPJ(string c);
        vector<Funcionario> & getFuncionarios();

    /* Operadores */
	friend std::ostream& operator<< (std::ostream &o, Empresa const &d);


    private:
        void darAumento(Funcionario &f, float x);
        float calcularNovoSalario(Funcionario &f, float x);
};

#endif
