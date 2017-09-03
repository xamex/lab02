/**
* @file     util.cpp
* @brief    Arquivo de corpo contendo as implementações de funções que realizam
*           operações utilizadas em várias partes do programa.
* @author   Gabriel Barbosa (gbsbarbosa.gb@gmail.com)
* @since    23/06/2017
* @date     25/06/2017
*/

#include "util.h"

    namespace util{

    /** 
    * @brief    Função que limpa o terminal do linux usando ANSI escape codes
    * @details  para mais detalher, acesse o link deixado como comentário ao lado do comando.
    */
    void limpa_tela(){
        cout << "\033[2J\033[1;1H"; // codigo retirado da stackoverflow http://stackoverflow.com/questions/4062045/clearing-terminal-in-linux-with-c-code

    }


    /** 
    * @brief    Função que realiza o tratamento de algumas entradas do usuário
    *           verificando se são válidas ou não.
    * @details  parte da função retirada do link: http://stackoverflow.com/questions/4798936/numeric-limits-was-not-declared-in-this-scope-no-matching-function-for-call-t
    * @param    num int a ser testado
    */
    void invalida(int &num){
        while (!(cin >> num)) {
        cin.clear(); 
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Entrada inválida. Por favor, digite um valor válido.\n";
        }
    }


    /** 
    * @brief    Função que realiza o tratamento de algumas entradas do usuário
    *           verificando se são válidas ou não.
    * @details  parte da função retirada do link: http://stackoverflow.com/questions/4798936/numeric-limits-was-not-declared-in-this-scope-no-matching-function-for-call-t
    * @param    num float a ser testado
    */
    void invalida(float &num){
    	while (!(cin >> num)) {
        cin.clear(); 
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Entrada inválida. Por favor, digite um valor válido.\n";
    	}
    }


    /** 
    * @brief    Função que limpa todo o buffer.
    */
    void limpa_buffer(){
        cin.clear(); 
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

}