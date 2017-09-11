#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <iostream>
#include "Date.h"
using namespace std;


class Funcionario {
    private:
        string nome;
        float salario;
        Date dataAdmissao;

    public:
	static int NUMERO_FUNCIONARIO;
        /* Construtores */
        Funcionario (const Funcionario &f);
        Funcionario(string nome, float salario, Date dataAdmissao);



    /* Gets e Sets*/
        string getNome();
        void setNome(string n);
        float getSalario();
        void setSalario(float s);
        Date getDataAdmissao();
        void setDataAdmissao(Date d);
    
    /* Operadores */
        Funcionario & operator=(Funcionario const & f);
	   friend std::ostream& operator<< (std::ostream &o, Funcionario const &d);

};

#endif
