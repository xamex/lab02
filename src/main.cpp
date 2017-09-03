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

	int lost;
	int cont;
	int nplayers;
	int pare;
	
	vector<Player*> vjogadores;

	limpa_tela();

	while(print_menu(vjogadores) != 4)
	{
		
		cout << "Informe o valor da aposta para essa partida: ";
		int n;
		invalida(n);
		Player::set_n(n);

		nplayers = (int)vjogadores.size();
		lost = 0;
		cont = 0;
		pare = 0;
		while(nplayers >= 1 && pare == 0){
			util::limpa_tela();
			srand(time(NULL));
			
			for(vector<Player*>::iterator it = vjogadores.begin(); it < vjogadores.end(); ++it)
				(*it)->dice_rand();

			/**
			* @brief	mostra os dados dos jogadors
			*/
			show_dices(vjogadores, nplayers);

			/**
			* @brief	mostra o resultado dos jogadors
			*/
			scoreboard(vjogadores, nplayers);

			/**
			* @brief	checa se algum jogador atingiu o valor da aposta
			*/
			if(bingo(vjogadores, n, cont) == 1)
			{
				pare = 1;

			}else{
				/**
				* @brief	checa se algum jodador ultrapassou a aposta da rodada
				*/
				overloaded(vjogadores, nplayers, n, lost);

				/**
				* @brief	checa se algum jodador quer parar de jogar na rodada
				*/
				give_up(vjogadores, nplayers, lost);

				
				/**
				* @brief	se todos - 1 jogadores perderem ganha o que está ativo
				*/
				if(lost == (int)vjogadores.size() - 1)
				{	pare = 1;
					for(vector<Player*>::iterator it = vjogadores.begin(); it < vjogadores.end(); ++it)
					{
						if((*it)->get_status() == 1)
						{
							(*it)->set_victories(1);
							(*it)->set_status(3); 
						}
					}
				}
			}
		}

		if(lost == (int)vjogadores.size()){cout << "\nNão houve vencedores nesta rodada\n";}

		/**
		* @brief	checa quem ganhou
		*/	
		winner(vjogadores, n, cont);
	}

	return 0;
}