#include "Empresa.h"
    int Empresa::NUMERO_EMPRESAS = 0;
    Empresa::Empresa(string nome, string cnpj):nome(nome), cnpj(cnpj) {
        
    }

    void Empresa::addFuncionario(Funcionario &f){
        if(!buscarFuncionario(f)){
            funcionarios.push_back(f);
        }else{
            cout << "O funcionário '"<<f.getNome()<<"' já está registrado!" << endl;
        }
    }

    bool Empresa::buscarFuncionario(Funcionario & f){
        for(size_t i=0;i<funcionarios.size();i++){
            if(f.getNome() == funcionarios[i].getNome()){
                return true;
            }
        }
        return false;
    }
    

    void Empresa::darAumento(float x){
        for(size_t i=0;i<funcionarios.size();i++){
            darAumento(funcionarios[i], x);
        }
    }

    void Empresa::imprimirFuncionario(Date d){
	cout << "Funcionarios com menos de 90 dias : " << endl;
        for(size_t i=0;i<funcionarios.size();i++){
            Date d1 = funcionarios[i].getDataAdmissao();
            int x = d1.getAno()*365+d1.getMes()*30+d1.getDia();
            int x2 = d.getAno()*365+d.getMes()*30+d.getDia();
            if(x2-x < 90 ){
                cout << "Funcionario : " << funcionarios[i] << endl;
            }
        }
    }

    /* Gets e Sets */
    string Empresa::getNome() {
        return nome;
    }
    void Empresa::setNome(string n){
        nome = n;
    }
    string Empresa::getCNPJ(){
        return cnpj;
    }
    void Empresa::setCNPJ(string c){
        cnpj = c;
    }
    vector<Funcionario> & Empresa::getFuncionarios(){
        return funcionarios;
    }

    /* Operadores */
    std::ostream& operator<< (std::ostream &o, Empresa const &d){
	o << "Empresa : " << d.nome << endl
	<< "CNPJ : " << d.cnpj << endl;
	for(size_t i=0;i<d.funcionarios.size();i++){
		o << d.funcionarios[i] << endl;		
	}
	return o;
    }

    void Empresa::darAumento(Funcionario &f, float x){
        float novoSalario = calcularNovoSalario(f, x);
        f.setSalario(novoSalario);
    }

    float Empresa::calcularNovoSalario(Funcionario &f, float x){
        return f.getSalario() * (1 + (x/100.0) );
    }
