/**
* @file	    round.h
* @brief	Arquivo de cabeçalho contendo a definição das funções que
*			controlam as ações de uma rodada
* @author	Gabriel Barbosa (gbsbarbosa.gb@gmail.com)
* @since	05/05/2017
* @date		07/05/2017
*/


#ifndef ROUND_H
#define ROUND_H
#include <string>
using std::string;


/** 
 * @brief	Função que imprime o placar do jogadores
 * @param	a A jogador 1
 * @param	b B jogador 2
 * @param	c C jogador 3
 * @param	nplayers NPLAYERS numero de jogadores ativos e
 * 			nao pausados
 */
void scoreboard(vector<Player*> &vjog, int nplayers);


/** 
 * @brief	Função que imprime os dados dos jogadores
 * @param	a A jogador 1
 * @param	b B jogador 2
 * @param	c C jogador 3
 * @param	nplayers NPLAYERS numero de jogadores ativos e
 * 			nao pausados
 */
void show_dices(vector<Player*> &vjog, int nplayers);


/** 
 * @brief	Função que checa o vencedor ou vencedores no caso
 *			dos 3 jogadores decidirem pausar a rodada
 * @param	a A jogador 1
 * @param	b B jogador 2
 * @param	c C jogador 3
 * @param	n N valor da aposta da rodada
 */
//void check(Player &a, Player &b, Player &c, int n);


/** 
 * @brief	Função que checa o vencedor ou vencedores no caso
 *			de 2 jogadores decidirem pausar a rodada
 * @param	x X jogador x
 * @param	y Y jogador y
 * @param	n N valor da aposta da rodada
 */
void checkf2(vector<Player*> &vjog, int aposta, int pausados);


/** 
 * @brief	Função que faz o tratamendo do vencedor(es) da rodada
 * @param	a A jogador 1
 * @param	b B jogador 2
 * @param	c C jogador 3
 * @param   cont Cont numero de jogadores que obteram resultado igual
 *			ao da aposta da rodada
 * @param	n N valor da aposta da rodada
 */
void winner(vector<Player*> &vjog, int aposta, int &quantv);


/** 
 * @brief	Função que checa se um jogador especifico quer
 *			parar de jogar na rodada
 * @param	x X jogador x=
 * @param	nplayers NPLAYERS numero de jogadores ativos e
 * 			nao pausados
 */
void choice(vector<Player*> &v, int &nplayers);


/** 
 * @brief	Função que se algum jogador quer parar de jogar na rodada atual
 * @param	a A jogador 1
 * @param	b B jogador 2
 * @param	c C jogador 3
 * @param   nplayers NPLAYERS numero de jogadores ativos e
 * 			nao pausados
 * @param	lost LOST numero de jogadores que perderam
 */
void give_up(vector<Player*> &v, int &nplayers, int lost);

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
int overloaded(vector<Player*> &v, int &nplayers, int n, int &lost);


/** 
 * @brief	Função que checa se algum jogador atingiu
 *			o valor da aposta
 * @param	a A jogador 1
 * @param	b B jogador 2
 * @param	c C jogador 3
 * @param   n N valor da aposta da rodada
 * @param 	cont CONT numero de jogadores que atingiram
 *			o valor da aposta na rodada
 */
int bingo(vector<Player*> &v, int n, int &cont);


/** 
 * @brief	Função que imprime a quantidade de vitorias
 * 			de cada jogador
 * @param	a A jogador 1
 * @param	b B jogador 2
 * @param	c C jogador 3
 */
//void print_victories(Player a, Player b, Player c);


/** 
 * @brief	Função que imprime o menu
 * @param	a A jogador 1
 * @param	b B jogador 2
 * @param	c C jogador 3
 */
int print_menu(vector<Player*> &vjog);

#endif