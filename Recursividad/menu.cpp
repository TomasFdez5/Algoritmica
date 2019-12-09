#include <iostream>
#include "opciones.hpp"

using namespace std; 


int main(int argc, char const *argv[])
{
	int opcion=0;

	do{
		cout << "\n\tMENU:\n_________________________________________________________________________________________________\n" << endl;
		cout << "Opcion 1. Caminos posibles hasta una casilla seleccionada." <<endl;
		cout << "Opcion 2. Caminos posibles para llegar a la fila 8 desde la casilla inicial (1,2)." <<endl;
		cout << "Opcion 3. Caminos posibles para llegar a la fila 8 desde la casilla inicial (1,7)." << endl;
		cout << "Opcion 4. Salir." << endl;
		cin >> opcion;
		switch(opcion){
			case 1:
				opcion_uno();
			break;
			case 2:
				opcion_dos();
			break;
			case 3:
				opcion_tres();
			break;
			case 4:
				cout << "Fin del programa." << endl;
			break;
			default:
				cout << "Opcion no valida." << endl;

		}
	}while(opcion!=4);
	
	return 0;
}