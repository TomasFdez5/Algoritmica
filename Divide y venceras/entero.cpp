#include <iostream>
#include <string>
#include <cstdlib>
#include "entero.hpp"
#include "opciones.hpp"

using namespace std;

Entero::Entero()
{
	this->maximo_=4;
	this->setNumero("0");
}

Entero::Entero(int numero){
	this->maximo_=4;
	this->setNumero(to_string(numero));
}

Entero::Entero(string numero){
	this->maximo_=4;
	this->setNumero(numero);
}

void Entero::agregarCerosFinal(int nCeros)
{
	for (int i = 0; i < nCeros; i++)
	{
		this->setNumero(this->getNumero() + "0");
	}
}

void Entero::agregarCerosDelante(int nCeros)
{
	for (int i = 0; i < nCeros; i++)
	{
		this->setNumero("0"+this->getNumero() );
	}
}

void Entero::quitarCerosNoSignificativos()
{
	while(this->getNumero()[0] == '0')
	{
		this->numero_.erase(0,1);
	}
}

Entero Entero::multiplicarPotencia10(int potencia)
{
	this->agregarCerosFinal(potencia);
	return *this;
}

void Entero::partirCadena(Entero &cadena1, Entero &cadena2)
{
	if (this->getNumero().size() % 2 != 0)
	{
		this->agregarCerosDelante(1);
	}

	int n = this->getNumero().size()/2;

	cadena1.setNumero(this->getNumero().substr(0,n));
	cadena2.setNumero(this->getNumero().substr(n,this->getNumero().size()));
}



Entero & Entero::operator=(Entero &obj)
{
	this->setNumero(obj.getNumero());
	return *this;
}

//Si Tomás lo hiciste al reves SI -.-
bool operator!=(Entero obj1, Entero obj2)
{
	obj1.quitarCerosNoSignificativos();
	obj2.quitarCerosNoSignificativos();
	
	if (obj1.getNumero().size() != obj2.getNumero().size()){return false;}
	else
	{
		for (int z = 0; z < obj1.getNumero().size(); z++)
		{
			if(obj1.getNumero()[z] != obj2.getNumero()[z]){return false;} 
		}	
	}
	return true;
}


Entero & operator+(Entero obj1, Entero obj2)
{
	Entero *nuevo = new Entero();
	int x, y, aux;
	bool acarreo=false;
	string sumas;

	obj1.quitarCerosNoSignificativos();
	obj2.quitarCerosNoSignificativos();

	//Ajustamos el tamaño de ambos sumandos
	if (obj1.getNumero().size()>obj2.getNumero().size())
	{
		obj2.agregarCerosDelante(obj1.getNumero().size()-obj2.getNumero().size());
	}
	else
	{
		if (obj1.getNumero().size()<obj2.getNumero().size())
		{
			obj1.agregarCerosDelante(obj2.getNumero().size()-obj1.getNumero().size());
		}
	}
	//Rellenamos el resultado de ceros para evitar problemas
	nuevo->agregarCerosDelante(obj1.getNumero().size()-1);
	sumas = nuevo->getNumero(); //Inicialmente a 0

	//Ya que el más significativo está en la posicion 0
	for (int z = (obj1.getNumero().size()-1); z >= 0; z--)
	{
		x = obj1.getNumero()[z] - '0';
		y = obj2.getNumero()[z] - '0';
		aux = x + y;

		if (acarreo == true){aux+=1; acarreo=false;}
		if (aux < 10){sumas[z] = '0' + aux;}
		else
		{
			acarreo = true;
			sumas[z] = '0' + aux % 10;
		}
	}

	if (acarreo == true)
	{
		sumas = '1' + sumas;
	}
	//Sumas tiene el valor final, luego lo asignamos
	nuevo->setNumero(sumas);


	return *nuevo;
}

Entero & operator*(Entero &obj1, Entero &obj2)
{
	//IMPORTANTE DECLARARLO ASI PARA PODER UTILIZAR OPERACIONES MULTIPLES
	Entero *nuevo = new Entero();

	int s=0, aux=1;
	Entero w,x,y,z;
	Entero p,q,wz, xy;

	obj1.quitarCerosNoSignificativos();
	obj2.quitarCerosNoSignificativos();

	//Igualamos los tamaños de los operandos
	if (obj1.getNumero().size()>obj2.getNumero().size())
	{
		obj2.agregarCerosDelante(obj1.getNumero().size()-obj2.getNumero().size());
	}
	else
	{
		if (obj1.getNumero().size()<obj2.getNumero().size())
		{
			obj1.agregarCerosDelante(obj2.getNumero().size()-obj1.getNumero().size());
		}
	}

	if(obj1.getNumero().size() % 2 !=0){
		obj1.agregarCerosDelante(1);
		obj2.agregarCerosDelante(1);
	}
	//Caso base: en el que puedo multiplicar directamente
	if (obj1.getNumero().size() <= 4 && obj2.getNumero().size() <= 4)
	{
		//Si al quitar los ceros significativos la cadena se queda vacia le asigno 0
		if(obj1.getNumero().empty()){
			obj1.setNumero("0");
		}

		//Si al quitar los ceros significativos la cadena se queda vacia le asigno 0
		if(obj2.getNumero().empty()){
			obj2.setNumero("0");
		}

		aux = stoi(obj1.getNumero()) * stoi(obj2.getNumero());
		nuevo->setNumero(to_string(aux));
		return *nuevo;
	}
	else
	{
		s = obj1.getNumero().size() / 2;
		
		obj1.partirCadena(w,x);
		obj2.partirCadena(y,z);

		p = w * y;
		q = x * z;
		wz = w * z;
		xy = x * y;
		/*
			FORMULA:        p                                     q
			obj1 * obj2 = w * y * 10^2s  +  (wz + xy) * 10^s  +  xz;  
		*/
		nuevo->setNumero( ((p.multiplicarPotencia10(2*s)+(wz+xy).multiplicarPotencia10(s)+q)).getNumero() );
		return *nuevo;
	}
	return *nuevo;
}


Entero & Entero::factorial()
{
	Entero *nuevo = new Entero(1); // mi resultado

	if (this->getNumero() == "1"){return *nuevo;} //caso base del factorial
	else
	{
		Entero obj_aux, resultado_parcial, incremento;
		incremento.setNumero("1");
		obj_aux.setNumero("1");
		suma.setNumero("0");

		while(obj_aux != *this == false)
		{
			resultado_parcial = *nuevo * obj_aux; 

			nuevo->setNumero(resultado_parcial.getNumero());
			obj_aux.setNumero((obj_aux+incremento).getNumero());
		}

		resultado_parcial = *nuevo * obj_aux; 
		nuevo->setNumero(resultado_parcial.getNumero());
		return *nuevo;
	}
}


istream &operator>>(istream &stream, Entero &obj)
{
	string aux;
	stream>>aux;
	obj.setNumero(aux);
	return stream;
}
ostream &operator<<(ostream &stream, Entero &obj)
{
	stream<<obj.getNumero();
	return stream;
}