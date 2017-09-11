#include "Programa.h"

	Programa::Programa(){
			loop();
	}

	void Programa::loop(){
		
		/*int dia,mes,ano;*/
		while(valor != 0){

			cout << "Digite um valor inteiro: " << endl;

			cout <<"1 - Criar Empresa" << endl
			<<"2 - Adicionar Funcionario" << endl
			<<"3 - Listar Funcionario" << endl
			<<"4 - Listar Funcionario com menos de 90 dias"<<endl
			<<"5 - Dar aumento a funcionarios" << endl
			<<"6 - Media de funcionarios por empresa"<< endl
			<<"7 - Listar todas as empresas e seus funcionarios"<<endl
			<<"0 - Sair"<<endl;

			valor = teste();
			if(valor < 0 or valor > 7){

				cout << endl << "[ERRO] Entrada invalida!" <<endl << endl;
				cout << "Digite um valor inteiro na faixa:  ";

			}else {
				cout<< endl << "[OK] Entrada valida: " << valor << endl;
				string nome;
				string cnpj;
				int salario=0;
				int numeroEmpresa = -1;
				int dia = 0 , mes = 0,ano = 0 , valorBonus = -1;
				switch (valor){
					case 1:

							cout << "Digite o nome da empresa : ";
							getline(cin, nome);
							cout << "Digite o nome do cnpj : ";
							getline(cin, cnpj);
							cout << endl;
							criarEmpresa(nome,cnpj);

					break;

					case 2:
							if(empresas.size() == 0){
								cout<< "Nao ah empresa para ser adicionado um funcionario." << endl << endl << endl;
							}else{

								listarEmpresas();

								while(numeroEmpresa < 1 or numeroEmpresa > (int) empresas.size()){
									cout<< "Digite o numero referente a empresa : ";
									numeroEmpresa = teste();
									cout << "Numero da empresa : " << numeroEmpresa << endl;
								}
								cout << "Digite o nome do funcionario : ";
								getline(cin , nome);
								while(salario < 1 ){
									cout << "Digite o salario : ";
									salario = teste();
								}
								while(dia < 1 or dia > 31 ){
									cout << "Digite o dia em que foi contratado : ";
									dia = teste();
								}
								while(mes < 1 or mes > 12){
									cout << "Digite o mes em que foi contradado : ";
									mes = teste();
								}while(ano < 1 ){									
									cout << "Digite o ano em que foi contratado : ";								
									ano = teste();
								}
								Funcionario adicionar (nome , salario , Date(dia, mes, ano));
								adicionarFuncionario(empresas[numeroEmpresa-1] , adicionar);


							}
					break;
					
					case 3:
							if(empresas.size() == 0){
								cout<< "Nao ah empresa para ser listado o(s) funcionario(s)." << endl << endl << endl;
							}else{

								listarEmpresas(); 

								while(numeroEmpresa < 1 or numeroEmpresa > (int) empresas.size()){
									cout<< "Digite o numero referente a empresa : ";
									numeroEmpresa = teste();
								}
								cout << endl << endl;
								imprimir(empresas[numeroEmpresa-1]);
							}
					break;
					
					case 4:

							if(empresas.size() == 0){
								cout<< "Nao ah empresa para ser listado o(s) funcionario(s)." << endl << endl << endl;
							}else{

								listarEmpresas(); 

								while(numeroEmpresa < 1 or numeroEmpresa > (int) empresas.size()){
									cout<< "Digite o numero referente a empresa : ";
									numeroEmpresa = teste();
								}
								cout << "Digite a data"<<endl;
								
								while(dia < 1 or dia > 31 ){
									cout << "Digite o dia : ";
									dia = teste();
								}
								while(mes < 1 or mes > 12){
									cout << "Digite o mes : ";
									mes = teste();
								}while(ano < 1 ){									
									cout << "Digite o ano : ";								
									ano = teste();
								}
								cout <<endl << endl;
								Date datarecente(dia,mes,ano);
								imprimirRecentes(empresas[numeroEmpresa-1], datarecente);
								cout << endl;
							}
					break;
					
					case 5:
							if(empresas.size() == 0){
								cout<< "Nao ah empresa para ser dado aumento" << endl << endl << endl;
							}else{

								listarEmpresas(); 

								while(numeroEmpresa < 1 or numeroEmpresa > (int) empresas.size()){
									cout<< "Digite o numero referente a empresa : ";
									numeroEmpresa = teste();
								}
								cout << "Digite o valor a ser bonificado, exemplo : "<<endl 
								<< "Para adicionar 10 porcento, digite 10"<< endl
								<< "Para adicionar 20 porcento, digite 20"<< endl
								<< "e assim por diante."<<endl;
								while(valorBonus < 0){
									cout<< "Bonus : ";
									valorBonus = teste();
								}
								bonus(empresas[numeroEmpresa-1] , valorBonus);
							}

					break;
					
					case 6:
							mediaFuncionario();
					break;

					case 7:
							if(empresas.size()>0){
							for(size_t i(0); i < empresas.size();i++){
								imprimir(empresas[i]);
							}
							}else{
								cout<< "Nao ah empresa para ser impressa" << endl << endl << endl;
							}
					break;
				}	
			}
		

		}
	}

	int Programa::teste( ){
		int valorInteiro;
		while(getline(cin , line)){
			stringstream ss(line);
			if((ss >> valorInteiro) && ss.eof()){
				break;
			}
			}
			
		return valorInteiro;
	}

	void Programa::criarEmpresa(string nome, string cnpj){
		Empresa adicionar(nome , cnpj);
		if(!buscarEmpresa(adicionar)){
			empresas.push_back(adicionar);	
			Empresa::NUMERO_EMPRESAS++;
		}else{
            cout << "A Empresa '"<<adicionar.getNome()<<"' já está registrada!" << endl << endl << endl;
        }
		
	}

    bool Programa::buscarEmpresa(Empresa & e){
        for(size_t i=0;i<empresas.size();i++){
            if(e.getNome() == empresas[i].getNome()){
                return true;
            }
        }
        return false;
    }

	void Programa::adicionarFuncionario(Empresa & empresa, Funcionario & funcionario)
	{
		empresa.addFuncionario(funcionario);
		Funcionario::NUMERO_FUNCIONARIO++;
	}

	void Programa::imprimir(Empresa & empresa){
		cout << empresa << endl;
	}

	void Programa::bonus(Empresa & empresa , int x){
		empresa.darAumento(x);
	}

	void Programa::imprimirRecentes(Empresa & empresa , Date & date ){
		empresa.imprimirFuncionario(date);
	}

	void Programa::mediaFuncionario(){
		if(empresas.size() == 0){
			cout <<"A media de funcionarios por empresa é = 0" << endl << endl ;
		}else {
			cout << "A media de funcionarios por empresa é = " << (Funcionario::NUMERO_FUNCIONARIO/Empresa::NUMERO_EMPRESAS) << endl<< endl ;
		}
	}

	void Programa::listarEmpresas(){
		for(size_t i=0; i<empresas.size() ; ++i){
			cout <<"Empresa " <<i+1 <<" : " <<empresas[i].getNome() << endl;
		}
	}