#include <iostream>
#include "opciones.hpp"
#include "macros.hpp"

using namespace std;
//Producto de dos numeros
//n1*n2=pow(10,2) * (wy) + pow(10,1) * (wz+xy) + xz
//siendo s = n/2
int main(int argc, char const *argv[])
{
	int opcion = 0;

	do{
		cout << BGREEN << "\n--------------- Menu: ---------------\n" <<RESET<< endl;
		cout <<BGREEN<< "\tOpcion 1. Multiplicacion." <<RESET<< endl;
		cout <<BGREEN<< "\tOpcion 2. Suma." <<RESET<< endl;
		cout <<BGREEN<< "\tOpcion 3. Factorial." <<RESET<< endl;
		cout <<BGREEN<< "\tOpcion 4. Salir." <<RESET<< endl;

		cout << "\nSu opcion:\n> ";
		cin >> opcion;

		switch(opcion)
		{
			case 1:
				Producto();
			break;
			case 2:
				Suma();
			break;
			case 3:
				opcion_factorial();
			break;
			case 4:
				cout <<BGREEN<< "\n\n-------------Fin del programa-------------\n\n"<<RESET;
			break;
			default:
				cout <<BRED "\nERROR. "<<RESET<<"Opcion no valida." << endl;
		}

	}while(opcion!=4);
	return 0;
}