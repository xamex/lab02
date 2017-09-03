/**
* @file	 	Player.h
* @brief	Arquivo de cabeçalho contendo a definição da classe Player
* @author	Gabriel Barbosa (gbsbarbosa.gb@gmail.com)
* @since	05/05/2017
* @date		07/05/2017S
*/

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
	private:
		int dice[2]; // dados
		int id;		// identidade do jogador
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
	* @brief	numero que recebo o valor da aposta
	*/
		static int n;


	/** 
	 * @brief	Função que atribui um valor a aposta
	 */
		static void set_n(int numero);

	/** 
	 * @brief	Função que retorna o valor da aposta
	 * @return 	o valor da aposta
	 */
		static int get_n();


	/** 
	 * @brief	Função que retorna o status
	 * @return 	status
	 */
		int get_status(); 


	/** 
	 * @brief	Função que atribui valor ao status
	 */
		void set_status(int o);


	/** 
	 * @brief	Função que retorna o placar
	 * @return 	placar
	 */
		int get_score();


	/** 
	 * @brief	Função que atribui um valor ao placar do jogador
	 * @param	c C placar
	 */
		void set_score(int c);

	/** 
	 * @brief	Função que retorna a identidade do jogador
	 * @return 	identidade do jogador
	 */
		int get_id();

	/** 
	 * @brief	Função que atribui um valor ao placar do jogador
	 * @param	s S identidade do jogador
	 */
		void set_id(int s);


	/** 
	 * @brief	Função que atribui numeros aleatorios aos dados
	 *			de 2 jogadores decidirem pausar a rodada
	 */
		void dice_rand();

	/** 
	 * @brief	Função que imprime os dados do jogador
	 */
		void get_dice();

	/** 
	 * @brief	Função que atribui valores aos dados do jogador
	 * @param	a A dado 1
	 * @param	b B dado 2
	 */
		void set_dices(int a, int b);


	/** 
	 * @brief	Função que retorna o numero de vitorias
	 * @return 	numero de vitorias
	 */
		int get_victories();

	/** 
	 * @brief	Função que atribui o numero de vitorias
	 */
		void set_victories(int l);

	public:

'
'
	/** 
	* @brief	contrutos padrão
	*/
		Player();

	/** 
	 * @brief	destrutos padrão
	 */
		~Player();
		
};

#endif