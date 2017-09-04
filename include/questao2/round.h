/**
* @file	    round.h
* @brief	Arquivo de cabeçalho contendo a definição das funções que
*			controlam as ações de uma rodada
* @author	Gabriel Barbosa (gbsbarbosa.gb@gmail.com)
* @since	05/05/2017
* @date		04/09/2017
*/


#ifndef ROUND_H
#define ROUND_H
#include <string>
using std::string;


/** 
 * @brief	Função que imprime o placar do jogadores
 * @param	vjog VJOG vetor de jogadores
 * @param	nplayers NPLAYERS numero de jogadores ativos e
 * 			nao pausados
 */
void scoreboard(vector<Player*> &vjog, int nplayers);


/** 
 * @brief	Função que imprime os dados dos jogadores
 * @param	vjog VJOG vetor de jogadores
 * @param	nplayers NPLAYERS numero de jogadores ativos e
 * 			nao pausados
 */
void show_dices(vector<Player*> &vjog, int nplayers);


/** 
 * @brief	Função que checa o vencedor ou vencedores no caso
 *			de mais de 1 jogadores decidir pausar a rodada
 * @param	vjog VJOG vetor de jogadores
 */
void check(vector<Player*> &vjog);


/** 
 * @brief	Função que faz o tratamendo do(s) vencedor(es) da rodada
 * @param	vjog VJOG vetor de jogadores
 * @param   quantv QUANT numero de jogadores que estão com status de vitória
 */
void winner(vector<Player*> &vjog, int quantv);


/** 
 * @brief	Função que checa se um jogador especifico quer
 *			parar de jogar na rodada
 * @param	vjog VJOG vetor de jogadores
 * @param	nplayers NPLAYERS numero de jogadores ativos e
 * 			nao pausados
 */
void choice(vector<Player*> &v, int &nplayers);


/** 
 * @brief	Função que se algum jogador quer parar de jogar na rodada atual
 * @param	vjog VJOG vetor de jogadores
 * @param   nplayers NPLAYERS numero de jogadores ativos e
 * 			nao pausados
 * @param	lost LOST numero de jogadores que perderam
 */
void give_up(vector<Player*> &v, int &nplayers, int lost);

/** 
 * @brief	Função que desativa jogadores que passaram 
 *			do valor da aposta
 * @param	vjog VJOG vetor de jogadores
 * @param   nplayers NPLAYERS numero de jogadores ativos e
 * 			nao pausados
 * @param	lost LOST numero de jogadores que perderam
 * @return 	numero de jogadores que perderam
 */
int overloaded(vector<Player*> &v, int &nplayers, int &lost);


/** 
 * @brief	Função que checa se algum jogador atingiu
 *			o valor da aposta
 * @param	vjog VJOG vetor de jogadores
 * @param   n N valor da aposta da rodada
 * @param 	cont CONT numero de jogadores que atingiram
 *			o valor da aposta na rodada
 */
int bingo(vector<Player*> &v, int &cont);


/** 
 * @brief	Função que imprime a quantidade de vitorias
 * 			de cada jogador
 * @param	vjog VJOG vetor de jogadores
 */
void print_victories(Player a, Player b, Player c);


/** 
 * @brief	Função que imprime o menu
 * @param	vjog VJOG vetor de jogadores
 * @return 	opção escolhida pelo usuário
 */
int print_menu(vector<Player*> &vjog);


/** 
 * @brief	Tela inicial do jogo onde são escolhido o numero de jogadores
 *			e informado o nome de cada um.
 * @param	vjog VJOG vetor de jogadores
 */
void inicio_jogo(vector<Player*> &vjog);

#endif