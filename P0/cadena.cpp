

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
	size_t i = 0;

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

inline size_t Cadena::length() const noexcept
{
	return this->tam_;
}







//		############################################
//  	################ OPERADORES ################
//		############################################

Cadena& Cadena::operator += (const Cadena& D)
{
  size_t j = 0;
	char *aux = new char[tam_+D.tam_+1];

  for (size_t i=0; i < tam_; i++) 
    aux[i] = s_[i];
  for (size_t i = tam_; i < (tam_+D.tam_+1); i++,j++) 
    aux[i] = D.s_[j];

  Cadena A(aux);
  delete [] aux;
  *this = A;

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

  delete []cadena;

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
	if ((long int)indice < 0 || indice >= tam_) 
		throw std::out_of_range(" Se está intentando acceder a una posición que no existe.");
	else
		return s_[indice]; 
}

const char& Cadena::at(size_t indice)const
{
	if ((long int)indice < 0 || indice >= tam_)
		throw std::out_of_range(" Se está intentando acceder a una posición que no existe.");
	else
		return s_[indice]; 	
}


Cadena Cadena::substr(size_t indice, size_t tam) const
{
	

	if ((indice + tam) > this->tam_ || (long int)tam < 0 || (long int)indice < 0)
		throw std::out_of_range(" El intervalo se sale de los límites de la cadena. ");

	Cadena cad(tam);

	for (size_t i = 0; i < tam; i++, indice++)
		cad.s_[i] = this->s_[indice];

	cad.s_[tam] = NULO;


	return cad;
	
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


Cadena::~Cadena()
{
	delete []s_;

}
