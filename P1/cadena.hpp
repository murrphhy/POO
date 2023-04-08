

#ifndef __CADENA_H__
#define __CADENA_H__

#include <iostream>
#include <cstring>
#include <stdexcept>

using namespace std;


class Cadena
{
	public:

// 		################ ATRIBUTOS ESTÁTICOS ################		

		static char NULO;


// 		################ CONSTRUCTORES ################

		explicit Cadena(size_t tam = 0, char c = ' ');	// Constructor con 2,1 parámetros

		Cadena(const Cadena& C);							// Constructor de copia
		
		Cadena(const char* cad);							// Constructor de un objeto Cadena con un parametro de tipo const char*

		Cadena& operator = (const Cadena& C);				// Operador de asignación

		explicit operator const char*() const;						//  Operador de conversión Cadena -> const char*.


// 		################ OBSERVADORES ################

		size_t length() const;


// 		################ OPERADORES ################

		Cadena& operator += (const Cadena& D);				// Suma con asignación

// 		################ OPERADORES DE INDIZACIÓN ################
		
		char& operator [](size_t indice); 					// Modificadora
		const char& operator[](size_t indice) const ; 		// Observadora

		char& at(size_t indice);
		const char& at(size_t indice) const;

		Cadena substr(size_t indice, size_t tam) const;


		~Cadena();

	private:

		size_t tam_;
		char* s_;


};


//################ OPERADORES ARITMÉTICOS ################

Cadena operator + (const Cadena& C, const Cadena& D);


//################ OPERADORES LÓGICOS ################

bool operator < (const Cadena& C, const Cadena& D);

bool operator == (const Cadena& C, const Cadena& D);

bool operator <= (const Cadena& C, const Cadena& D);

bool operator != (const Cadena& C, const Cadena& D);

bool operator > (const Cadena& C, const Cadena& D);

bool operator >= (const Cadena& C, const Cadena& D);



#endif	







/*

 	Constructor con 2 parámetros - HECHO
 	Constructor con 1 parámetro - HECHO
 	Constructor sin parámetros - HECHO
	Conversor de Const char a cadena.


*/