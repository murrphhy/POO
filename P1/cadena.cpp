

#include "cadena.hpp"

<<<<<<< HEAD


=======
>>>>>>> bf3466ef235334ca557e2feeb119b43bca011b3b
//		#####################################################
// 		################ ATRIBUTOS ESTÁTICOS ################
//		#####################################################

char Cadena::NULO('\0');





<<<<<<< HEAD
=======


>>>>>>> bf3466ef235334ca557e2feeb119b43bca011b3b
//		###############################################
//  	################ CONSTRUCTORES ################
//		###############################################

<<<<<<< HEAD

=======
>>>>>>> bf3466ef235334ca557e2feeb119b43bca011b3b
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


<<<<<<< HEAD
Cadena::Cadena(const char* cad): tam_(strlen(cad)), s_(new char[strlen(cad)+1])
{
	strcpy(s_, cad);
}



=======
>>>>>>> bf3466ef235334ca557e2feeb119b43bca011b3b
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


<<<<<<< HEAD
Cadena::Cadena(Cadena&& C): tam_(C.tam_), s_(C.s_)
{
  C.tam_ = 0;
  C.s_ = new char[1];
  C.s_[0] = NULO;
}


Cadena& Cadena::operator = (Cadena&& C)
{
  if(this != &C)
  {
    delete [] s_;
    s_ = C.s_;
    tam_ = C.tam_;

    C.tam_= 0;
    C.s_ = new char[1];
    C.s_[0] = NULO;
    
  }
  
  return *this;
}









const char* Cadena::cont_cad() const noexcept
{
  return this->s_;
}

Cadena::operator const char*() const
{
        return s_;
=======
Cadena::Cadena(const char* cad): tam_(strlen(cad)), s_(new char[strlen(cad)+1])
{
	strcpy(s_, cad);
}


Cadena::operator const char*() const
{
	return s_;
>>>>>>> bf3466ef235334ca557e2feeb119b43bca011b3b
}





<<<<<<< HEAD
=======


>>>>>>> bf3466ef235334ca557e2feeb119b43bca011b3b
//		##############################################
//  	################ OBSERVADORES ################
//		##############################################

<<<<<<< HEAD



inline size_t Cadena::length() const noexcept
=======
size_t Cadena::length() const
>>>>>>> bf3466ef235334ca557e2feeb119b43bca011b3b
{
	return this->tam_;
}

<<<<<<< HEAD
// - - - - - -> Indización <- - - - - -

const char& Cadena::operator [] (size_t indice) const
{
	return s_[indice];
}


const char& Cadena::at(size_t indice)const
{
	if ((long int)indice < 0 || indice >= tam_)
		throw std::out_of_range(" Se está intentando acceder a una posición que no existe.");
	else
		return s_[indice]; 	
}

// - - - - - -> ITERADORES <- - - - - -


Cadena::const_iterator Cadena::begin() const noexcept
{
  return const_iterator(s_);
}

Cadena::const_iterator Cadena::end() const noexcept
{
  return const_iterator(s_+tam_);
}

Cadena::const_iterator Cadena::cbegin() const noexcept
{
  return const_iterator(s_);
}


Cadena::const_iterator Cadena::cend() const noexcept
{
  return const_iterator(s_+tam_);
}


Cadena::const_reverse_iterator Cadena::rbegin()const noexcept
{
  return const_reverse_iterator(end());
}


Cadena::const_reverse_iterator Cadena::rend() const noexcept
{
  return const_reverse_iterator(begin());
}


Cadena::const_reverse_iterator Cadena::crbegin() const noexcept
{
  return const_reverse_iterator(end());
}


Cadena::const_reverse_iterator Cadena::crend() const noexcept
{
  return const_reverse_iterator(begin());
}




//		###############################################
//  	################ MODIFICADORES ################
//		###############################################

// - - - - - -> INDIZACIÓN <- - - - - -

char& Cadena::operator [] (size_t indice)
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


// - - - - - -> ITERADORES <- - - - - -

Cadena::iterator Cadena::begin() noexcept
{
  return s_;
}


Cadena::iterator Cadena::end() noexcept
{
  return s_+tam_;
}


Cadena::reverse_iterator Cadena::rbegin() noexcept
{
  return reverse_iterator(end());
}


Cadena::reverse_iterator Cadena::rend() noexcept
{
  return reverse_iterator(begin());
}
=======

>>>>>>> bf3466ef235334ca557e2feeb119b43bca011b3b





//		############################################
//  	################ OPERADORES ################
//		############################################

<<<<<<< HEAD

=======
>>>>>>> bf3466ef235334ca557e2feeb119b43bca011b3b
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





<<<<<<< HEAD
=======


>>>>>>> bf3466ef235334ca557e2feeb119b43bca011b3b
//		########################################################
//  	################ OPERADORES ARITMÉTICOS ################
//		########################################################

<<<<<<< HEAD

=======
>>>>>>> bf3466ef235334ca557e2feeb119b43bca011b3b
Cadena operator + (const Cadena& C, const Cadena& D)
{
	char* cadena = new char[C.length()+D.length()+1];

<<<<<<< HEAD
	strcpy(cadena,(C.cont_cad()));

	Cadena A (strcat(cadena, D.cont_cad()));
=======
	strcpy(cadena,(const char*)C);

	Cadena A (strcat(cadena, (const char*)D));
>>>>>>> bf3466ef235334ca557e2feeb119b43bca011b3b

  delete []cadena;

	return A;
}





<<<<<<< HEAD
=======


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







>>>>>>> bf3466ef235334ca557e2feeb119b43bca011b3b
//		####################################################
//  	################ OPERADORES LÓGICOS ################
//		####################################################

<<<<<<< HEAD

=======
>>>>>>> bf3466ef235334ca557e2feeb119b43bca011b3b
bool operator < (const Cadena& C, const Cadena& D)
{
	// Forma tosca es comparando el valor de la tabla ascii para ese caracter

<<<<<<< HEAD
	return strcmp(C.cont_cad(),D.cont_cad())<0;

}


bool operator == (const Cadena& C, const Cadena& D)
{
	return strcmp(C.cont_cad(), D.cont_cad()) == 0;
}


=======
	return strcmp((const char*)C, (const char*)D)<0;

}

bool operator == (const Cadena& C, const Cadena& D)
{
	return strcmp((const char*)C, (const char*)D) == 0;
}

>>>>>>> bf3466ef235334ca557e2feeb119b43bca011b3b
bool operator <= (const Cadena& C, const Cadena& D)
{
	return !(D < C);
}

<<<<<<< HEAD

=======
>>>>>>> bf3466ef235334ca557e2feeb119b43bca011b3b
bool operator != (const Cadena& C, const Cadena& D)
{
	return !(D == C);
}

<<<<<<< HEAD

=======
>>>>>>> bf3466ef235334ca557e2feeb119b43bca011b3b
bool operator > (const Cadena& C, const Cadena& D)
{
	return (D < C);
}

<<<<<<< HEAD

=======
>>>>>>> bf3466ef235334ca557e2feeb119b43bca011b3b
bool operator >= (const Cadena& C, const Cadena& D)
{
	return !(C < D);
}


<<<<<<< HEAD



// ####################################################
// ################ OPERADORES E/S ####################
// ####################################################


std::ostream& operator <<(ostream& os,const Cadena& C) noexcept
{
  os << C.cont_cad();
  return os;
}


std::istream& operator >>(istream& is,Cadena& C)
{
  char cade[33] = "";
  is.width(33);

  is >> cade;

  C = cade;


  return is;
}


=======
>>>>>>> bf3466ef235334ca557e2feeb119b43bca011b3b
Cadena::~Cadena()
{
	delete []s_;

}
