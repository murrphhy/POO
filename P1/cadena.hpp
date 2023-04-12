

#ifndef __CADENA_H__
#define __CADENA_H__

#include <iostream>
#include <cstring>
#include <stdexcept>
<<<<<<< HEAD
#include <iterator>
=======
>>>>>>> bf3466ef235334ca557e2feeb119b43bca011b3b

using namespace std;


class Cadena
{
	public:

<<<<<<< HEAD
    
    typedef char* iterator;
    typedef const char* const_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;


=======
>>>>>>> bf3466ef235334ca557e2feeb119b43bca011b3b
// 		################ ATRIBUTOS ESTÁTICOS ################		

		static char NULO;


// 		################ CONSTRUCTORES ################

<<<<<<< HEAD
		explicit Cadena(size_t tam = 0, char c = ' ');    	// Constructor con 2,1 parámetros

		Cadena(const Cadena& C);							              // Constructor de copia
		
		Cadena(const char* cad);							              // Constructor de un objeto Cadena con un parametro de tipo const char*
  
		Cadena& operator = (const Cadena& C);				        // Operador de asignación
                                                
    Cadena(Cadena&& C);                                 // Constructor de movimiento
    
    Cadena& operator = (Cadena&& C);                    // Asignación por movimiento
    
    const char* cont_cad() const noexcept;

    explicit operator const char*()const;

=======
		explicit Cadena(size_t tam = 0, char c = ' ');	// Constructor con 2,1 parámetros

		Cadena(const Cadena& C);							// Constructor de copia
		
		Cadena(const char* cad);							// Constructor de un objeto Cadena con un parametro de tipo const char*

		Cadena& operator = (const Cadena& C);				// Operador de asignación

		explicit operator const char*() const;						//  Operador de conversión Cadena -> const char*.
>>>>>>> bf3466ef235334ca557e2feeb119b43bca011b3b


// 		################ OBSERVADORES ################

<<<<<<< HEAD
		size_t length() const noexcept;                     // TAMAÑO

    
// 		################ OPERADORES ################

		Cadena& operator += (const Cadena& D);				      // Suma con Asignación
    

// 		################ OPERADORES INDIZACIÓN ################
		
		const char& operator[](size_t indice) const ; 		  
    char& operator [](size_t indice); 					        // Modificadora

		char& at(size_t indice);                            // Modificadora
		const char& at(size_t indice) const;                

		Cadena substr(size_t indice, size_t tam) const;

  
// 		################ ITERADORES ################
   
    iterator begin() noexcept;
    const_iterator begin() const noexcept;              
    
    iterator end() noexcept;
    const_iterator end()const noexcept;                 

    const_iterator cbegin() const noexcept;
    const_iterator cend() const noexcept;

    reverse_iterator rbegin() noexcept;
    const_reverse_iterator rbegin() const noexcept;  

    reverse_iterator rend() noexcept;
    const_reverse_iterator rend() const noexcept;       

    const_reverse_iterator crbegin() const noexcept;
    const_reverse_iterator crend() const noexcept;



=======
		size_t length() const;


// 		################ OPERADORES ################

		Cadena& operator += (const Cadena& D);				// Suma con asignación

// 		################ OPERADORES DE INDIZACIÓN ################
		
		char& operator [](size_t indice); 					// Modificadora
		const char& operator[](size_t indice) const ; 		// Observadora

		char& at(size_t indice);
		const char& at(size_t indice) const;

		Cadena substr(size_t indice, size_t tam) const;

>>>>>>> bf3466ef235334ca557e2feeb119b43bca011b3b

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



<<<<<<< HEAD
//################ OPERADORES E/S ################

std::ostream& operator <<(std::ostream& os,const Cadena& C) noexcept;

std::istream& operator >>(std::istream& is,Cadena& C);




=======
>>>>>>> bf3466ef235334ca557e2feeb119b43bca011b3b
#endif	







/*

 	Constructor con 2 parámetros - HECHO
 	Constructor con 1 parámetro - HECHO
 	Constructor sin parámetros - HECHO
	Conversor de Const char a cadena.


<<<<<<< HEAD
*/
=======
*/
>>>>>>> bf3466ef235334ca557e2feeb119b43bca011b3b
