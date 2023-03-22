

#include "cadena.hpp"

//		#####################################################
// 		################ ATRIBUTOS ESTÁTICOS ################
//		#####################################################

char Cadena::NULO('\0');







//		###############################################
//  	################ CONSTRUCTORES ################
//		###############################################

Cadena::Cadena(size_t tam, char c): tam_(tam), s_(new char[tam+1])
{
	size_t i{0};
	while(i != tam_)
	{
		s_[i] = c;
		i++;
	}
	
	s_[i] = NULO;
}


Cadena::Cadena(const Cadena& C): tam_(C.tam_), s_(new char[C.tam_+1])
{
	strcpy(s_, C.s_);
}


Cadena& Cadena::operator = (const Cadena& C)
{
	if (this != &C)
	{
		delete [] s_;

		s_ = new char[C.tam_ + 1];

		tam_ = C.tam_;

		strcpy(s_, C.s_);
	}

	return *this;
}


Cadena::Cadena(const char* cad): tam_(strlen(cad)), s_(new char[strlen(cad)+1])
{
	strcpy(s_, cad);
}


Cadena::operator const char*() const
{
	return s_;
}







//		##############################################
//  	################ OBSERVADORES ################
//		##############################################

size_t Cadena::length() const
{
	return this->tam_;
}







//		############################################
//  	################ OPERADORES ################
//		############################################

Cadena& Cadena::operator += (const Cadena& D)
{
	size_t i{this->tam_}, j{0};

	this->tam_= this->tam_ + D.tam_;

	while(i != this->tam_)
	{
		this->s_[i] = D.s_[j];
		i++;
		j++;
	}

	this->s_[tam_] = NULO;

	return *this;
}







//		########################################################
//  	################ OPERADORES ARITMÉTICOS ################
//		########################################################

Cadena operator + (const Cadena& C, const Cadena& D)
{
	char* cadena = new char[C.length()+D.length()+1];

	strcpy(cadena,(const char*)C);

	Cadena A (strcat(cadena, (const char*)D));

	return A;
}







//		##########################################################
//  	################ OPERADORES DE INDIZACIÓN ################
//		##########################################################

char& Cadena::operator [] (size_t indice)
{
	return s_[indice];
}

const char& Cadena::operator [] (size_t indice) const
{
	return s_[indice];
}

char& Cadena::at(size_t indice)
{
	if (indice < 0 || indice > tam_)
		throw std::out_of_range(" Se está intentando acceder a una posición que no existe.");
	else
		return s_[indice]; 
}

const char& Cadena::at(size_t indice)const
{
	if (indice < 0 || indice > tam_)
		throw std::out_of_range(" Se está intentando acceder a una posición que no existe.");
	else
		return s_[indice]; 	
}






//		####################################################
//  	################ OPERADORES LÓGICOS ################
//		####################################################

bool operator < (const Cadena& C, const Cadena& D)
{
	// Forma tosca es comparando el valor de la tabla ascii para ese caracter

	return strcmp((const char*)C, (const char*)D)<0;

}

bool operator == (const Cadena& C, const Cadena& D)
{
	return strcmp((const char*)C, (const char*)D) == 0;
}

bool operator <= (const Cadena& C, const Cadena& D)
{
	return !(D < C);
}

bool operator != (const Cadena& C, const Cadena& D)
{
	return !(D == C);
}

bool operator > (const Cadena& C, const Cadena& D)
{
	return (D < C);
}

bool operator >= (const Cadena& C, const Cadena& D)
{
	return !(C < D);
}