
#include "fecha.hpp"
#include "cadena.hpp"

int main()
{
	

	Cadena c, a("adios"), b("adio");



	if (a > b)
		cout << " a < b" << endl;;

	//cout << (const char*)c << " Longitud: " << c.length() << endl;
/*
	try
	{
		Fecha f("04/12/2023"); 
		Fecha c(5,12,2023);

		cout << f << endl;
		cout << c << endl;

		if(f <= c)
			cout<< "f <= c" << endl;
		else cout<< "f > c" <<  endl;




	}catch(Fecha::Invalida e)
	{
		cerr<< "Error, " << e.por_que() << endl;
	}
		
*/	
	
	return 0;

	
}




/*

 - Fecha con 3 parámetros. HECHO
 - Fecha con 2 Parámetros. HECHO
 - Fecha con 1 Parámetro. HECHO
 - Fecha con 1 parámetro ( conversión int -> fecha no permitida). HECHO (explicit)
 - Fecha sin parámetros. HECHO
 - Fecha creada a partir de otra Fecha. HECHO
 - Constructor Fecha (caracteres). HECHO
 - cout << f . POR HACER ( PREGUNTAR) 



*/