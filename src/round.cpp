/**
* @file	 	roud.cpp
* @brief	Arquivo de corpo contendo a implementação das funções que
*			controlam as ações de uma rodada
* @author	Gabriel Barbosa (gbsbarbosa.gb@gmail.com)
* @since	05/05/2017
* @date		07/05/2017
* @sa		player.h
* @sa		round.h
*/

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

#include <vector>
using std::vector;

#include "player.h"
#include "round.h"
#include "util.h"
using namespace util;

/** 
 * @brief	Função que imprime o placar do jogadores
 * @param	a A jogador 1
 * @param	b B jogador 2
 * @param	c C jogador 3
 * @param	nplayers NPLAYERS numero de jogadores ativos e
 * 			nao pausados
 */

void scoreboard(vector<Player*> &vjog, int nplayers)
{
	if(nplayers > 0)
	{
		cout << "\n-----------------------\n";
		cout << "\nPLACAR\n";
		for(vector<Player*>::iterator it = vjog.begin(); it < vjog.end(); ++it)
		{
			if((*it)->get_status() != 0)
			{
				cout << "Jogador " << (*it)->get_id() << ": " << (*it)->get_score();
				if((*it)->get_status()==2){cout <<" (pausado)";}
				cout << endl;

			}else{
				(cout << "Jogador " << (*it)->get_id() << ": Eliminado\n");
 			}
		}
	}

	cout << "\nAposta da rodada: " << Player::get_n() << endl;
	cout << "\n-----------------------\n";
	cout << endl;
}


/** 
 * @brief	Função que imprime os dados dos jogadores
 * @param	a A jogador 1
 * @param	b B jogador 2
 * @param	c C jogador 3
 * @param	nplayers NPLAYERS numero de jogadores ativos e
 * 			nao pausados
 */
void show_dices(vector<Player*> &vjog, int nplayers)
{
	if(nplayers > 0)
	{
		for(vector<Player*>::iterator it = vjog.begin(); it < vjog.end(); ++it)
		{
			if((*it)->get_status() == 1)
			{
				cout << "\nJogador " << (*it)->get_id() << ": ";
				(*it)->get_dice();
			}
		}
		
	}
}


/** 
 * @brief	Função que checa o vencedor ou vencedores no caso
 *			dos 3 jogadores decidirem pausar a rodada
 * @param	a A jogador 1
 * @param	b B jogador 2
 * @param	c C jogador 3
 * @param	n N valor da aposta da rodada
 */
/*
void check(Player &a, Player &b, Player &c, int n){

	if(a.get_score() == b.get_score() && a.get_score() != c.get_score()){
		cout << "\nEmpate entre jogador " << a.get_id() << " e jogador " << b.get_id() << endl;
		a.set_status(3);
		b.set_status(3);
	}else if(a.get_score() == c.get_score() && a.get_score() != b.get_score()){
		cout << "\nEmpate entre jogador " << a.get_id() << " e jogador " << c.get_id() << endl;
		b.set_status(3);
		c.set_status(3);
	}else if(c.get_score() == b.get_score() && c.get_score() != a.get_score()){
		c.set_status(3);
		b.set_status(3);
		cout << "\nEmpate entre jogador " << c.get_id() << " e jogador " << b.get_id() << endl;
	}

	if(a.get_score() == b.get_score() && a.get_score() == c.get_score()){
		cout << "\nEmpate entre jogador " << a.get_id() << ", jogador " << b.get_id() << " e jogador " << c.get_id() << endl;
	}else{
		if(a.get_score()-n > b.get_score()-n){
			if(a.get_score()-n > c.get_score()-n){
				a.set_status(3);
			}else{c.set_status(3);}
		}else{
			if(b.get_score()-n > c.get_score()-n){
				b.set_status(3);
			}else{c.set_status(3);}
		}
	}
}
*/

/** 
 * @brief	Função que checa o vencedor ou vencedores no caso
 *			de 2 jogadores decidirem pausar a rodada
 * @param	x X jogador x
 * @param	y Y jogador y
 * @param	n N valor da aposta da rodada
 */
void checkf2(vector<Player*> &vjog, int aposta, int pausados)
{
	vector<Player*>::iterator it, wnr;
	vector<Player*> draw;

	it = vjog.begin();
	while((*it)->get_status() != 2 && it < vjog.end()) it++;

	wnr = it;
	it++;

	for(; it < vjog.end(); ++it)
	{
		if((*it)->get_status() == 2 && (*wnr)->get_status() == 2)
		{	
			if((*it)->get_score() > (*wnr)->get_score())
			{
				wnr = it;
				draw.clear(); // limpa vetor de empates  

			}else if ((*it)->get_score() == (*wnr)->get_score())
			{
				draw.push_back((*wnr));
			
			}
		}
	}

	draw.push_back((*wnr));

	for(wnr = draw.begin(); wnr < draw.end(); wnr++)
	{
		(*wnr)->set_status(3);
	}

	vjog = draw;
}

/** 
 * @brief	Função que faz o tratamendo do vencedor(es) da rodada

 * @param   quantv Cont numero de jogadores que obteram resultado igual
 *			ao da aposta da rodada
 * @param	aposta APOSTA valor da aposta da rodada
 */
void winner(vector<Player*> &vjog, int aposta, int &quantv)
{
	vector<Player*>::iterator it;
	int pause = 0;

	if(quantv > 0)
	{
		vencedores:
		pause = 0;
		cout << "\nVencedor(es) da rodada:\n";
		for (it = vjog.begin(); it < vjog.end(); ++it)
			if((*it)->get_status() == 3){(*it)->set_victories(1); cout << "jogador " << (*it)->get_id() << endl;}

		cout << endl;

	}else
	{
		for (it = vjog.begin(); it < vjog.end(); ++it)
			if((*it)->get_status() == 2) pause++;

		if(pause == 1)
		{
			for (it = vjog.begin(); it < vjog.end(); ++it)
				if((*it)->get_status() == 2){(*it)->set_victories(1); cout << "\nO vencedor da rodada foi o jogador: " << (*it)->get_id() << endl;}	
		}

		if(pause > 1)
		{
			checkf2(vjog, aposta, pause);
			quantv++;
			goto vencedores;
		}
	}

}


/** 
 * @brief	Função que checa se um jogador especifico quer
 *			parar de jogar na rodada
 * @param	x X jogador x
 * @param	nplayers NPLAYERS numero de jogadores ativos e
 * 			nao pausados
 */
void choice(vector<Player*> &v, int &nplayers)
{
	int choice;

	vector<Player*>::iterator it;
	for (it = v.begin(); it < v.end(); ++it)
	{
		if(nplayers > 0 && (*it)->get_status()==1)
		{
			cout << "Jogador " << (*it)->get_id() << " deseja parar?\n";
			cout << "1 - Sim\n" << "2 - Não\n\n";

			do{
				invalida(choice);
			}while(choice != 1 && choice != 2);

			if(choice == 1)
			{
				cout << "\njogador " << (*it)->get_id() << " parou\n\n";
				nplayers--;
				(*it)->set_status(2);
			}
		}
	}  
}


/** 
 * @brief	Função que se algum jogador quer parar de jogar na rodada atual
 * @param	a A jogador 1
 * @param	b B jogador 2
 * @param	c C jogador 3
 * @param   nplayers NPLAYERS numero de jogadores ativos e
 * 			nao pausados
 * @param	lost LOST numero de jogadores que perderam
 */
void give_up(vector<Player*> &v, int &nplayers, int lost)
{
	int gv;
	if(nplayers > 0 && lost <=1)
	{
		cout << "Algum jogador deseja parar?\n";
		cout << "1 - Sim\n" << "2 - Não\n\n";

		do{
			invalida(gv);
		}while(gv < 1 && gv > 2);

		if(gv == 1)
		{
			choice(v, nplayers);
		}
	}
}


/** 
 * @brief	Função que desativa jogadores que passaram 
 *			do valor da aposta
 * @param	x X jogador 1
 * @param	y Y jogador 2
 * @param	z Z jogador 3
 * @param   nplayers NPLAYERS numero de jogadores ativos e
 * 			nao pausados
 * @param	lost LOST numero de jogadores que perderam
 */
int overloaded(vector<Player*> &v, int &nplayers, int n, int &lost)
{
	vector<Player*>::iterator it;
	for (it = v.begin(); it < v.end(); ++it)
	{
		if((*it)->get_status()!=0 && (*it)->get_score() > n)
		{
			(*it)->set_status(0);
			nplayers--;
			lost++;
			cout << "\nJogador " << (*it)->get_id() << " ultrapassou o limite da aposta\n\n";
		}
	}     
	return lost;
	
}


/** 
 * @brief	Função que checa se algum jogador atingiu
 *			o valor da aposta
 * @param   n N valor da aposta da rodada
 * @param 	cont CONT numero de jogadores que atingiram
 *			o valor da aposta na rodada
 */
int bingo(vector<Player*> &v, int n, int &cont)
{
	vector<Player*>::iterator it;
	for (it = v.begin(); it < v.end(); ++it)
	{
		if((*it)->get_score() == n)
		{
			(*it)->set_status(3);
			cont++;	
		}
	}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               

	if(cont == 0){
		return 0;
	}else{
		return 1;
	}
}


/** 
 * @brief	Função que imprime a quantidade de vitorias
 * 			de cada jogador
 * @param	a A jogador 1
 * @param	b B jogador 2
 * @param	c C jogador 3
 */
/*
void print_victories(vector<Player*> &vjog){
	cout << "\n\n----------Quadro de Vitórias----------\n\n";
	cout << "--------------------------------------\n";
	cout << "--------------------------------------\n";
	cout << "-------------JOGADOR 1: " << a.get_victories() << "-------------\n";
	cout << "-------------JOGADOR 2: " << b.get_victories() << "-------------\n";
	cout << "-------------JOGADOR 3: " << c.get_victories() << "-------------\n";
	cout << "--------------------------------------\n";
	cout << "--------------------------------------\n";
	cout << "--------------------------------------\n";

}
*/


void novo_jogo(vector<Player*> &vjog)
{
	cout << "Informe o número de jogadores entre 1 e 4: ";
			int njogadores;

			do{
				invalida(njogadores);
			}while(njogadores > 4 || njogadores < 1);

			for (int i = 0; i < njogadores; ++i)
				vjog.push_back(new Player());

			cout << "\nInforme o nome de cada jogador\n";
			string nome;
			cin.ignore();
			for(vector<Player*>::iterator it = vjog.begin(); it < vjog.end(); ++it)
			{
				getline(cin, nome, '\n');
				(*it)->set_id(nome);
			}
}
/** 
 * @brief	Função que imprime o menu
 * @param	a A jogador 1
 * @param	b B jogador 2
 * @param	c C jogador 3
 */
int print_menu(vector<Player*> &vjog)
{
	inicio:
	cout << "\n\n----------------Menu----------------\n\n";
	cout << "1 - Novo Jogo\n";
	cout << "2 - Regras do Jogo\n";
	cout << "3 - Placar de Vitórias\n";
	cout << "4 - Sair\n";

	int menu;
	menu = 0;

	do{
		invalida(menu);
		if(menu < 1 || menu > 4){limpa_tela(); print_menu(vjog);}
	}while(menu < 1 || menu > 4);

	switch(menu){
		case 1:
			limpa_tela();
			novo_jogo(vjog);
	 		limpa_tela();
	 		break;

		case 2:
		
			limpa_tela();
			cout << "REGRAS:\n";
			cout << "A cada rodada é jogado 2 dados para cada jogador.\n";
			cout << "A soma dos valores dos dados é acumulado.\n\n";

			cout << "OBJETIVO:\n" << "O objetivo é ficar o mais próximo e abaixo do valor N\n" "a ser estabelecido no início de cada rodada.";
			cout << " Ao obter\num valor agregado superior a N, o jogador é considerado\nexcluído da rodada.\n\nA cada vez de jogar, o jogador pode optar por jogar os\ndados ou parar (e não jogar mais até a rodada acabar).\n\n";
			cout << "Uma rodada é finalizada quando:\n\n(1) resta\napenas um jogador, uma vez que os outros foram excluídos\n\n(2) quando não há mais jogadores a jogar, ou seja,\ntodos os jogadores “ativos” decidiram parar\n\n";
			cout << "(3) quando um dos jogadores atinge exatamente o valor N.\n\nVence a rodada:\nO jogador que permanecer na rodada (ou seja, não for excluído)\ne obtiver o número de pontos agregados mais próximo de N\n\n";
			print_menu(vjog);
			break;

		case 3:
			limpa_tela();
			//print_victories(vjog);
			goto inicio;
			break;

		case 4:
			limpa_tela();
			cout << "Saindo...";
			exit(0);
			break;

		default:
			cout << "\nINFORME UM VALOR VÁLIDO\n";
			break;
	}

	return menu;
}