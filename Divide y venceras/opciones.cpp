#include <iostream>
#include <string>
#include "opciones.hpp"
#include "entero.hpp"
#include "macros.hpp"

using namespace std;


bool esDigito(string cadena)
{
	for (int i = 0; i < cadena.size(); i++)
	{
		if(!isdigit(cadena[i]) ) {
	       	cout << "Error. No ha introducido un numero correcto." <<endl;
	       	return false;
	    }
	}
	return true;	
}

void mostrar_info_enteros(Entero obj1, Entero obj2)
{
	cout << BIYELLOW << "\nInformación sobre los enteros grandes introducidos:\n***************************************************" <<endl;
	cout << "\n\tEntero 1: " << obj1.getNumero() << endl;
	cout << "\tTamano del entero 1: " << obj1.getNumero().size() << endl;

	cout << "\n\tEntero 2: " << obj2.getNumero() << endl;
	cout << "\tTamano del entero 2: " << obj2.getNumero().size() << endl;
	cout << "\n*******************FIN INFORMACION******************\n" <<RESET<<endl;
}

void Producto()
{
	Entero obj1;
	Entero obj2;
	Entero obj3;
	string aux;

	cout << "\nIntroduzca el primer numero a multiplicar:\n> ";
	cin >> aux;
	if(esDigito(aux)==true){
		obj1.setNumero(aux);

		cout << "\nIntroduzca el segundo numero a multiplicar:\n> ";
		cin >> aux;
		if(esDigito(aux)==true){
			obj2.setNumero(aux);

			mostrar_info_enteros(obj1,obj2);

			obj3 = obj1 * obj2;
			obj3.quitarCerosNoSignificativos();
			cout << "El "<<BGREEN<<"resultado "<<RESET<<"es : " << obj3 << endl;
		}
	}
	std::cout << "Para mostrar el "<< BIGREEN << "menú, "<< RESET << "pulse " << INVERSE << "ENTER" << RESET;

	cin.ignore();
	cin.ignore();

	cout << CLEAR_SCREEN;
}

void Suma()
{
	Entero obj1;
	Entero obj2;
	Entero obj3;
	string aux;

	cout << "\nIntroduzca el primer numero a sumar:\n> ";
	cin >> aux;
	if(esDigito(aux)==true){
		obj1.setNumero(aux);

		cout << "\nIntroduzca el segundo numero a sumar:\n> ";
		cin >> aux;
		if(esDigito(aux)==true){
			obj2.setNumero(aux);

			mostrar_info_enteros(obj1,obj2);

			obj3 = obj1 + obj2;
			obj3.quitarCerosNoSignificativos();
			cout << "El "<<BGREEN<<"resultado "<<RESET<<"es : " << obj3 << endl;
		}
	}
	std::cout << "Para mostrar el "<< BIGREEN << "menú, "<< RESET << "pulse " << INVERSE << "ENTER" << RESET;

	cin.ignore();
	cin.ignore();

	cout << CLEAR_SCREEN;
}


void opcion_factorial()
{
	Entero obj1;
	Entero obj2;
	string aux;

	cout << "\nIntroduzca el numero para realizar su factorial:\n> ";
	cin>>aux;
	if(esDigito(aux)==true){
		obj1.setNumero(aux);
		obj2 = obj1.factorial();
		obj2.quitarCerosNoSignificativos();
		cout << "El "<<BGREEN<<"resultado "<<RESET<<"es : " << obj2 << endl;
	}
	std::cout << "Para mostrar el "<< BIGREEN << "menú, "<< RESET << "pulse " << INVERSE << "ENTER" << RESET;

	cin.ignore();
	cin.ignore();

	cout << CLEAR_SCREEN;
}