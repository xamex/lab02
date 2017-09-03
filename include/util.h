/**
* @file     util.h
* @brief    Arquivo de cabeçalho contendo as definições de funções que realizam
*           operações utilizadas em várias partes do programa.
* @author   Gabriel Barbosa (gbsbarbosa.gb@gmail.com)
* @since    23/06/2017
* @date     25/06/2017
*/

#ifndef UTIL_H
#define UTIL_H

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;

#include <string>
#include <limits> //numeric_limits
#include <new>
using std::bad_alloc;

namespace util{


	/** 
	* @brief    Função que limpa o terminal do linux usando ANSI escape codes
	* @details  para mais detalher, acesse o link deixado como comentário ao lado do comando.
	*/
	void limpa_tela();


	/** 
	* @brief    Função que realiza o tratamento de algumas entradas do usuário
	*           verificando se são válidas ou não.
	* @details  parte da função retirada do link: http://stackoverflow.com/questions/4798936/numeric-limits-was-not-declared-in-this-scope-no-matching-function-for-call-t
	* @param    num int a ser testado
	*/
	void invalida(float &num);


	/** 
	* @brief    Função que realiza o tratamento de algumas entradas do usuário
	*           verificando se são válidas ou não.
	* @details  parte da função retirada do link: http://stackoverflow.com/questions/4798936/numeric-limits-was-not-declared-in-this-scope-no-matching-function-for-call-t
	* @param    num float a ser testado
	*/
	void invalida(int &num); 


	/** 
	* @brief    Função que limpa todo o buffer.
	*/
	void limpa_buffer();


	/** 
	* @brief	Função template que imprime os elementors do vetor passado
	* @param	v vetor onde ocorrerá a busca
	* @param	tam tamanho do vetor
	*/
	template<typename T>
	void print_array(T *v, int tam){
		cout << endl << endl;
		for (int i = 0; i < tam; ++i)
			{
				cout << v[i] << ' ';
			} 

		cout << endl << endl;	
	}


	/** 
	* @brief	Função template que faz a verificação do elemento pasasdo pelo usuário
	*			antes de inserir ele no vetor informado.
	* @param	v vetor onde ocorrerá a alteração
	* @param	tam tamanho do vetor
	*/
	template<typename T>
	void entra_elementos(T *(&v), int tam)
	{
		T aux;
		for (int i = 0; i < tam; ++i)
		{
			invalida(aux); // resolvi usar a função invalida() em vez da erro_tamanho() por ela aceitar numeros negativos.
			v[i] = aux;

		}
	}
}

#endif