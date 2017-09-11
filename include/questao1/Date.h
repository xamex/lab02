#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class Date {

    private:
        int dia;
        int mes;
        int ano;


    public:
   
    /* Construtores */
        Date();
        Date(const Date &d);
        Date(int dia, int mes, int ano);
    /* Gets e Sets */
        int getDia();
        int getMes();
        int getAno();
        void setDia(int d);
        void setMes(int m);
        void setAno(int a);
    /* Operadores */
    Date & operator=(Date const & d);
	friend std::ostream& operator<< (std::ostream &o, Date const &d);
};

#endif
