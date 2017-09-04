/**
* @file	 	Player.cpp
* @brief	Arquivo de corpo contendo a implementação da classe Player
* @author	Gabriel Barbosa (gbsbarbosa.gb@gmail.com)
* @since	05/05/2017
* @date		04/09/2017
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
 * @brief	Método que atribui numeros aleatorios aos dados
 */
void Player::dice_rand(){
	if(get_status()==1){
		dice[0] = rand() % 6 + 1;
		dice[1] = rand() % 6 + 1;
		score+= dice[0] + dice[1];
	}
}


/** 
 * @brief	Método que atribui um valor ao placar do jogador
 * @param	c C placar
 */
void Player::set_score(int c){
	score = c;
}


/** 
 * @brief	Método que retorna a identidade do jogador
 * @return 	identidade do jogador
 */
string Player::get_id(){
	return id;
}


/** 
 * @brief	Método que atribui um valor ao placar do jogador
 * @param	s S identidade do jogador
 */
void Player::set_id(string s){
	id = s;
}

/** 
 * @brief	Método que imprime os dados do jogador
 */
void Player::get_dice(){
	cout << endl << "primerio dado: " << dice[0] << endl << "segundo dado: " << dice[1] << endl;
}


/** 
 * @brief	Método que atribui valores aos dados do jogador
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
 * @brief	Método que atribui um valor a aposta
 */
void Player::set_aposta(int numero){
	aposta = numero;
}

/** 
 * @brief	Método que retorna o valor da aposta
 * @return 	o valor da aposta
 */
int Player::get_aposta(){
	return aposta;
}

/** 
 * @brief	Método que retorna o placar
 * @return 	placar
 */
int Player::get_score(){
	return score;
}

/** 
 * @brief	Método que retorna o status
 * @return 	status
 */
int Player::get_status(){
	return status;
}

/** 
 * @brief	Método que atribui valor ao status
 */
void Player::set_status(int o){
	status = o;
}

/** 
 * @brief	Método que retorna o numero de vitorias
 * @return 	numero de vitorias
 */
int Player::get_victories(){
	return victories;
}

/** 
 * @brief	Método que atribui o numero de vitorias
 */
void Player::set_victories(int l){
	victories+=l;
}
