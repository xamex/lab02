#include "Date.h"

    /* Construtores */
    Date::Date() {
        dia = 3;
        mes = 9;
        ano = 2017;
    }
    Date::Date(const Date &d):dia(d.dia), mes(d.mes), ano(d.ano){ }
    Date::Date(int dia, int mes, int ano):dia(dia), mes(mes), ano(ano){ }

    /* Gets e Sets */
    int Date::getDia(){
        return dia;
    }
    int Date::getMes(){
        return mes;
    }
    int Date::getAno(){
        return ano;
    }

    void Date::setDia(int d){
        dia = d;
    }
    void Date::setMes(int m){
        mes = m;
    }
    void Date::setAno(int a){
        ano = a;
    }

    /* Operadores */

    Date & Date::operator=(Date const & d){
        dia = d.dia;
        mes = d.mes;
        ano = d.ano;
        return *this;
    }

    std::ostream& operator<< (std::ostream &o, Date const &d)
    {
	o << "Data de adimissão : " << d.dia <<"/" << d.mes << "/" << d.ano << endl;
	return o;
    }
