#include "Funcionario.h"

    int Funcionario::NUMERO_FUNCIONARIO = 0;

    /* Construtores */
    Funcionario::Funcionario (const Funcionario &f):nome(f.nome), salario(f.salario), dataAdmissao(f.dataAdmissao){ 
        
    }
    Funcionario::Funcionario(string nome, float salario, Date dataAdmissao):nome(nome), salario(salario), dataAdmissao(dataAdmissao){
    }

    /* Gets e Sets*/
    string Funcionario::getNome(){
        return nome;
    }
    void Funcionario::setNome(string n){
        nome = n;
    }
    float Funcionario::getSalario(){
        return salario;
    }
    void Funcionario::setSalario(float s){
        salario = s;
    }
    Date Funcionario::getDataAdmissao(){
        return dataAdmissao;
    }
    void Funcionario::setDataAdmissao(Date d){
        dataAdmissao = d;
    }
    
    /* Operadores */
    Funcionario & Funcionario::operator=(Funcionario const & f){
        nome = f.nome;
        salario = f.salario;
        dataAdmissao = f.dataAdmissao;
        return *this;
    }

    std::ostream& operator<< (std::ostream &o, Funcionario const &d){
	
	o << "Funcionario : " << d.nome << endl
	<< "Salario : " << d.salario << endl
	<< d.dataAdmissao;

	return o;
    }

    

