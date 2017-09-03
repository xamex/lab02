/**
* @file	 	Player.cpp
* @brief	Arquivo de corpo contendo a implementação da classe Player
* @author	Gabriel Barbosa (gbsbarbosa.gb@gmail.com)
* @since	05/05/2017
* @date		07/05/2017S
*/

#include <iostream>
using std::cout;
using std::endl;

#include "player.h"

#include <stdlib.h>
#include <time.h>



/** 
 * @brief	construtor padrão
 */
Player::Player(){
	score = 0;
	dice[0] = 0;
	dice[1] = 0;
	status = 1;
	victories = 0;
	id = "desconhecido";
}


/** 
 * @brief	destrutor padrão
 */
Player::~Player(){
	//destrutor
}

/** 
 * @brief	Função que atribui numeros aleatorios aos dados
 */
void Player::dice_rand(){
	if(get_status()==1){
		dice[0] = rand() % 6 + 1;
		dice[1] = rand() % 6 + 1;
		score+= dice[0] + dice[1];
	}
}


/** 
 * @brief	Função que atribui um valor ao placar do jogador
 * @param	c C placar
 */
void Player::set_score(int c){
	score = 0;
}


/** 
 * @brief	Função que retorna a identidade do jogador
 * @return 	identidade do jogador
 */
string Player::get_id(){
	return id;
}


/** 
 * @brief	Função que atribui um valor ao placar do jogador
 * @param	s S identidade do jogador
 */
void Player::set_id(string s){
	id = s;
}

/** 
 * @brief	Função que imprime os dados do jogador
 */
void Player::get_dice(){
	cout << endl << "primerio dado: " << dice[0] << endl << "segundo dado: " << dice[1] << endl;
}


/** 
 * @brief	Função que atribui valores aos dados do jogador
 * @param	a A dado 1
 * @param	b B dado 2
 */
void Player::set_dices(int a, int b){
	if(get_status()==1){
		dice[0] = a;
		dice[1] = b;
		score+= dice[0] + dice[1];
	}
}

/** 
 * @brief	Função que atribui um valor a aposta
 */
void Player::set_n(int numero){
	n = numero;
}

/** 
 * @brief	Função que retorna o valor da aposta
 * @return 	o valor da aposta
 */
int Player::get_n(){
	return n;
}

/** 
 * @brief	Função que retorna o placar
 * @return 	placar
 */
int Player::get_score(){
	return score;
}

/** 
 * @brief	Função que retorna o status
 * @return 	status
 */
int Player::get_status(){
	return status;
}

/** 
 * @brief	Função que atribui valor ao status
 */
void Player::set_status(int o){
	status = o;
}

/** 
 * @brief	Função que retorna o numero de vitorias
 * @return 	numero de vitorias
 */
int Player::get_victories(){
	return victories;
}

/** 
 * @brief	Função que atribui o numero de vitorias
 */
void Player::set_victories(int l){
	victories+=l;
}
