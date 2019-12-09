#ifndef ENTERO_HPP
#define ENTERO_HPP
#include <iostream>
#include <string>
using namespace std;

class Entero
{
	private:
		string numero_;
		int maximo_; // establecer a 4
	public:
		Entero();
		Entero(int numero);
		Entero(string numero);

		inline string getNumero(){return numero_;};

		inline void setNumero(string cadena){numero_=cadena;};

		inline int getMaximo(){return maximo_;};

		void agregarCerosFinal( int nCeros);
		
		void agregarCerosDelante( int nCeros);

		void quitarCerosNoSignificativos();

		void partirCadena(Entero &cadena1, Entero &cadena2);

		Entero multiplicarPotencia10( int potencia);

		Entero & operator=(Entero &obj);

		Entero & factorial();


};
	bool operator!=(Entero obj1, Entero obj2);
	istream & operator>>(istream &stream, Entero &obj);
	ostream & operator<<(ostream &stream, Entero &obj);
	Entero & operator+(Entero obj1, Entero obj2);
	Entero & operator*(Entero &obj1, Entero &obj2);


#endif