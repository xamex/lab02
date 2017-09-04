/**
* @file	 	player.h
* @brief	Arquivo de cabeçalho contendo a definição da classe Player
* @author	Gabriel Barbosa (gbsbarbosa.gb@gmail.com)
* @since	05/05/2017
* @date		04/09/2017
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using std::string;

class Player
{
	private:
		int dice[2]; // dados
		string id;		// nome do jogador
		int score; // placar


	/**
	* 	@brief status dos jogadores
	*	status do jogador
	*	0 = desativado (perdeu)
	*	1 = ativo
	*	2 = pausado
	*	3 = ganhou
	*/	
		int status;
		int victories; // vitorias do jogador
		
	public:

	/** 
	* @brief	construtor padrão
	*/
		Player();

	/** 
	 * @brief	destrutor padrão
	 */
		~Player();

	/**
	* @brief	numero que recebe o valor da aposta
	*/
		static int aposta;


	/** 
	 * @brief	Método que atribui um valor a aposta
	 */
		static void set_aposta(int numero);

	/** 
	 * @brief	Método que retorna o valor da aposta
	 * @return 	valor da aposta
	 */
		static int get_aposta();


	/** 
	 * @brief	Método que retorna o status
	 * @return 	status
	 */
		int get_status(); 


	/** 
	 * @brief	Método que atribui valor ao status
	 */
		void set_status(int o);


	/** 
	 * @brief	Método que retorna o placar
	 * @return 	placar
	 */
		int get_score();


	/** 
	 * @brief	Método que atribui um valor ao placar do jogador
	 * @param	c C placar
	 */
		void set_score(int c);

	/** 
	 * @brief	Método que retorna a identidade do jogador
	 * @return 	identidade do jogador
	 */
		string get_id();

	/** 
	 * @brief	Método que atribui um valor ao placar do jogador
	 * @param	s S identidade do jogador
	 */
		void set_id(string s);


	/** 
	 * @brief	Método que atribui numeros aleatorios aos dados
	 *			de 2 jogadores decidirem pausar a rodada
	 */
		void dice_rand();

	/** 
	 * @brief	Método que imprime os dados do jogador
	 */
		void get_dice();

	/** 
	 * @brief	Método que atribui valores aos dados do jogador
	 * @param	a A dado 1
	 * @param	b B dado 2
	 */
		void set_dices(int a, int b);


	/** 
	 * @brief	Método que retorna o numero de vitorias
	 * @return 	numero de vitorias
	 */
		int get_victories();

	/** 
	 * @brief	Método que atribui o numero de vitorias
	 */
		void set_victories(int l);
		
};

#endif