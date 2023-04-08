
#ifndef __FECHA_H__
#define __FECHA_H__

#include <iostream>
#include <cassert>
#include <ctime>
#include <cstdio>

using namespace std;

class Fecha
{

	public:

// 		################ ATRIBUTOS ESTÁTICOS ################

		static const int AnnoMinimo;
		static const int AnnoMaximo;
		static const char* meses[12];


//  	################ CONSTRUCTORES ################

		explicit Fecha(int dia_ = 0, int mes_ = 0, int anno_ = 0); 		// Constructor con 3, 2, 1 o 0 parámetros

		Fecha (const Fecha& F) = default;								// Constructor de copia.

		Fecha& operator = (const Fecha& F) = default;					// Operador de asignación de Fechas

		Fecha(const char* c);											// Constructor (cadena de caracteres)

		operator const char* () const;									// Constructor de conversión Fecha -> const char*


//  	################ OBSERVADORES ################
		
		int dia() const noexcept;

		int mes() const noexcept;

		int anno() const noexcept;


//  	################ DESTRUCTOR ################	

		~Fecha() = default;



//  	################ CLASE EXCEPCIÓN ################

		class Invalida
		{
			public:
				
				Invalida(const char* error);		 // Constructor de la clase Invalida

				const char* por_que() const;		 // Observador

			private:

				const char* e;
		};

//  	################ OPERADORES ################

		Fecha& operator +=(int n);
		Fecha& operator -=(int n);
		Fecha& operator ++();
		Fecha operator ++(int);			// La razón por la que se define la versión sobrecargada de f++ con un argumento int es que algunos compiladores de C++ requieren 
		Fecha& operator --();				// que las versiones prefijo y sufijo de un operador tengan diferente número de argumentos.
		Fecha operator --(int);

		// Aritméticos		
		Fecha operator +(int n) const;  
		Fecha operator -(int n) const;


	private:
		int d, m, a;
		int dias_mes() const;
		void fecha_valida() const;

};


//################ OPERADORES LÓGICOS ################

bool operator < (const Fecha& F, const Fecha& T);
	
bool operator > (const Fecha& F, const Fecha& T);

bool operator <= (const Fecha& F, const Fecha& T);

bool operator == (const Fecha& F, const Fecha& T);

bool operator != (const Fecha& F, const Fecha& T);

bool operator >= (const Fecha& F, const Fecha& T);


//################ OPERADORES ARITMÉTICOS ################

	



#endif
