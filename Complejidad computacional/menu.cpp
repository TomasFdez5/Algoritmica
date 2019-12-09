#include <iostream>
#include <vector> 
#include <ctime>
#include "opciones.hpp"
using namespace std;

int main()
{
	int opcion=0;
	do{
		cout<<"\t1. Quicksort.\n\t2. Producto de matrices.\n\t3. Producto de matrices por Strassen.\n\t4. Salir del programa."<<endl;
		cin>>opcion;
		switch(opcion){
			case 1:
				opcion_Quicksort();
			break;
			case 2:
				opcion_Producto_Matriz();
			break;
			case 3:
				opcion_Strassen();
			break;
			case 4:
				cout<<"Fin del programa."<<endl;
			break;
			default:
				cout<<"Opcion no valida, introduzca una correcta."<<endl;
		}
	}while(opcion!=4);	
	return 0;
}

