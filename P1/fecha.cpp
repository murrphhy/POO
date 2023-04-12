
#include "fecha.hpp"


//		#####################################################
//  	################ ATRIBUTOS ESTÁTICOS ################
//		#####################################################

const int Fecha::AnnoMinimo(1902); 
const int Fecha::AnnoMaximo(2037); // qué es más eficiente, tener que llamar a la función de ctime o hacerme un vector con los nombres de los meses?


//		###############################################
//  	################ CONSTRUCTORES ################
//		###############################################

Fecha::Fecha(int dia_, int mes_, int anno_): d(dia_), m(mes_), a(anno_)
{

	if (d == 0 || m == 0 || a == 0)	
	{
    std::time_t tiempo_calendario = std::time(nullptr);
    std::tm* tiempo_descompuesto = std::localtime(&tiempo_calendario);
		
    if (d == 0)
			d = tiempo_descompuesto->tm_mday;
		if (m == 0)
			m = tiempo_descompuesto->tm_mon+1;
		if(a == 0)
			a = tiempo_descompuesto->tm_year+1900;
	}

	fecha_valida();

}


Fecha::Fecha(const char* c)
{

	if(sscanf(c, "%d/%d/%d", &d, &m, &a) != 3)
	{
		Fecha::Invalida formato("Error en el formato de la cadena.");
		throw formato;
	}

	if (d == 0 || m == 0 || a == 0)	
	{

    std::time_t tiempo_calendario = std::time(nullptr);
    std::tm* tiempo_descompuesto = std::localtime(&tiempo_calendario);

		if (d == 0)
			d = tiempo_descompuesto->tm_mday;
		if (m == 0)
			m = tiempo_descompuesto->tm_mon+1;
		if (a == 0)
			a = tiempo_descompuesto->tm_year+1900;
	}

	fecha_valida();
}

<<<<<<< HEAD
const char* Fecha::cadena()const
{
  std::locale::global(std::locale("es_ES.utf8"));
  static char cad[36];
  
  std::tm f{};

  f.tm_mday = d;
  f.tm_mon = m - 1;
  f.tm_year = a - 1900;
  
  mktime(&f);
  
  strftime(cad,36,"%A %e de %B de %Y", &f);
  
  return cad;
}

=======

Fecha::operator const char*() const
{
	std::locale::global(std::locale("es_ES.utf8"));
	static char cadena[36];
	
	std::time_t tiempo_calendario = std::time(nullptr);
	std::tm* f = std::localtime(&tiempo_calendario);

	f->tm_mday = d;
	f->tm_mon = m-1;
	f->tm_year = a - 1900;

	mktime(f);

	strftime(cadena,36,"%A %e de %B de %Y", f);

	return cadena;
}


>>>>>>> bf3466ef235334ca557e2feeb119b43bca011b3b
Fecha::Invalida::Invalida(const char* error): e(error)
{}


//		##############################################
//  	################ OBSERVADORES ################
//		##############################################

inline int Fecha::dia() const noexcept
{
	return d;
}

inline int Fecha::mes() const noexcept
{
	return m;
}

inline int Fecha::anno() const noexcept
{
	return a;
}

const char* Fecha::Invalida::por_que() const
{
	return e;
}


//		############################################
//  	################ OPERADORES ################
//		############################################

Fecha& Fecha::operator +=(int n)
{
	struct tm fecha_tm{}; // Inicializo a 0

	fecha_tm.tm_mday = d + n;
	fecha_tm.tm_mon = m - 1;
	fecha_tm.tm_year = a - 1900;

	mktime(&fecha_tm);

	d = fecha_tm.tm_mday;
	m = fecha_tm.tm_mon + 1;
	a = fecha_tm.tm_year + 1900;

	fecha_valida();


	return *this;
}

Fecha& Fecha::operator -=(int n)
{
	return *this+= -n;
}

Fecha& Fecha::operator ++()
{
	return *this+= 1;
}

Fecha Fecha::operator ++(int)
{
	Fecha t(*this);

	*this += 1;

	return t;
}

Fecha& Fecha::operator --()
{
	return *this+= -1;
}

Fecha Fecha::operator --(int)
{
	Fecha t(*this);

	*this += -1;

	return t;
}

// ARITMÉTICOS

Fecha Fecha::operator +(int n) const
{
	Fecha t(*this);

	return  t+= n;
}

Fecha Fecha::operator -(int n) const
{
	Fecha t(*this);

	return t+= -n;
}


//		####################################################
//  	################ OPERADORES LÓGICOS ################
//		####################################################

bool operator == (const Fecha& F, const Fecha& T)
{
	return (F.dia() == T.dia() && F.mes() == T.mes() && F.anno() == T.anno());

}


bool operator < (const Fecha& F, const Fecha& T) 
{

	return (F.anno() < T.anno() || ((F.anno() == T.anno()) && F.mes() < T.mes()) || (((F.anno() == T.anno()) && F.mes() == T.mes()) && F.dia() < T.dia()));
}

bool operator >(const Fecha& F, const Fecha& T)					// 25 - 12    12- 25
{
	return (T < F);
}

bool operator <=(const Fecha& F, const Fecha& T)
{
	return !(T < F);
}

bool operator >= (const Fecha& F, const Fecha& T)
{
	return !(F < T);
}

bool operator != (const Fecha& F, const Fecha& T)
{
	return !(F == T);
}


//		##################################################
//  	################ MÉTODOS PRIVADOS ################
//		##################################################

void Fecha::fecha_valida() const
{
	if(d > dias_mes() || d < 1)
	{
		Fecha::Invalida dia_incorrecto(" Dia incorrecto");
		throw dia_incorrecto;
	}
	if(a < Fecha::AnnoMinimo || a > AnnoMaximo)
	{
		Fecha::Invalida anno_incorrecto(" Año incorrecto");
		throw anno_incorrecto;
	}

}


int Fecha::dias_mes() const
{
	switch(m)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:

			return 31;
			break;

		case 2:

			if (a % 4 == 0 && (a % 400 == 0 || a % 100 != 0))
				return 29;
			else return 28;

			break;

		case 4: case 6: case 9: case 11:

			return 30;
			break;

		default:
			Fecha::Invalida mes_incorrecto(" Mes incorrecto");
			throw mes_incorrecto;
			break;
	}
	return 0;
}
<<<<<<< HEAD


std::istream& operator >>(istream& is,Fecha& F)
{
  char dma[11];      // dd/mm/aaaa
  is.getline(dma,11); 

  try 
  {
    F = dma; 
  } catch (Fecha::Invalida e) 
  {
    is.setstate(std::ios::failbit);
    throw e;
  }

  return is;

}


std::ostream& operator <<(ostream& os, const Fecha& F) noexcept
{
  os << F.cadena();
  return os;
}
=======
>>>>>>> bf3466ef235334ca557e2feeb119b43bca011b3b
