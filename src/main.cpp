/**
* @file 	main.cpp
* @brief 	Programa que simula um jogo de dados com 3 jogadores
* @author	Gabriel Barbosa (gbsbarbosa.gb@gmail.com)
* @since	05/05/2017
* @date		07/05/2017
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


int Player::n = 0;

int main(){

	util::limpa_tela();
	
	std::vector<Player*> vjogadores;

	cout << "Informe o número de jogadores entre 1 e 4: ";
	int njogadores;
	do{
		invalida(njogadores);
	}while(njogadores > 4 || njogadores < 1);

	for (int i = 0; i < njogadores; ++i)
	{
		vjogadores.push_back(new Player());
	}

	inicio:

	print_menu(vjogadores);
	cout << "Informe o valor da aposta para a essa partida: ";
	int n;
	cin >> n;
	Player::set_n(n);

	int nplayers = njogadores;
	int lost = 0;
	int cont = 0;

	while(nplayers >= 1){
		util::limpa_tela();
		srand(time(NULL));
		
		for(vector<Player*>::iterator it = vjogadores.begin(); it < vjogadores.end(); ++it)
		{
			(*it)->dice_rand();
		}


		/**
		* @brief	mostra os dados dos jogadors
		*/
		show_dices(vjogadores, nplayers);

		/**
		* @brief	mostra o resultado dos jogadors
		*/
		scoreboard(vjogadores, nplayers);

		if(bingo(vjogadores, n, cont) == 1){
			winner(vjogadores, n, cont);
			goto inicio;
		}

		/**
		* @brief	checa se algum jodador ultrapassou a aposta da rodada
		*/
		overloaded(vjogadores, nplayers, n, lost);

		/**
		* @brief	checa se algum jodador quer parar de jogar na rodada
		*/
		give_up(vjogadores, nplayers, lost);


		/**
		* @brief	se dois jogadores perderem ganha oque está ativo
		*/
		if(lost == njogadores - 1)
		{
			for(vector<Player*>::iterator it = vjogadores.begin(); it < vjogadores.end(); ++it)
			{
				if((*it)->get_status()==1)
				{
					(*it)->set_victories(1); 
					cout << "\nO Vencedor da rodada foi o jogador " << (*it)->get_id() << endl;
				}
			}
			goto fim;
		}
	}

	fim:

	if(lost == njogadores){cout << "\nNão houve vencedores nesta rodada\n";}

	/**
	* @brief	checa quem ganhou
	*/	
	winner(vjogadores, n, cont);

	/**
	* @brief	vai para label inicio
	*/
	goto inicio;

	return 0;
}