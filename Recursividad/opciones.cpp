#include <iostream>
#include <vector>
#include <stdio.h>
#include "opciones.hpp"
#include "funciones.hpp"

using namespace std;
char tecla;


void opcion_uno()
{
	//vector de casillas:
	vector<vector<Casilla> > indice_camino; //donde guardo uno a uno los caminos posibles
	//caminos almacena todas aquellas casillas que forman el camino.
	vector<Casilla> caminos;
	//Limpio los vectores por si se ha utilizado antes la opcion
	indice_camino.clear();
	caminos.clear();

	int columna=0;
	int resultado=0;

	cout << "Introduzca el valor de para la casilla de llegada (8,c)." << endl;
	cin >> columna;

	//resultado almacena el valor devuelto por la funcion que calcula el numero de caminos
	cout << "El numero de caminos posibles es: " << calcula_camino(8,columna,indice_camino,caminos) << endl;

/*	MUESTRO TODOS LOS POSIBLES CAMINOS UNO A UNO 	*/
    cin.ignore();
	for (unsigned int i = 0; i < indice_camino.size(); i++)
	{
		cout << "\n\tCAMINO POSIBLE Nº " << i+1 << "\n" << endl;
		muestra_caminos(indice_camino[i],1);
		muestra_tablero(indice_camino[i]);
		cout << "__________________________________________________________"<<endl;
		do
		{
			cout << "Presione ENTER para ver el siguiente camino..." << endl;
			tecla = getchar();
		}while(tecla!=13 and tecla!=10 and tecla!=141);			
	}
	

}

//Todo exactamente igual que la opcion 1 pero cambiando la llamada recursiva
void opcion_dos()
{
	vector<vector<Casilla> > indice_camino;
	vector<Casilla> caminos;
	indice_camino.clear();
	caminos.clear();

	int resultado=0;

	resultado+=calcula_camino_inverso(1,2,indice_camino,caminos);
	cout << "El numero de caminos posibles es: " << resultado << endl;

	
	cin.ignore();
	for (unsigned int i = 0; i < indice_camino.size(); i++)
	{
		cout << "\n\tCAMINO POSIBLE Nº " << i+1 << "\n" << endl;
		muestra_caminos(indice_camino[i],2);
		muestra_tablero(indice_camino[i]);
		cout << "__________________________________________________________"<<endl;
		do
		{
			cout << "Presione ENTER para ver el siguiente camino..." << endl;
			tecla = getchar();
		}while(tecla!=13 and tecla!=10 and tecla!=141);			
	}

}

//Exactamente igual que la opcion 2 pero cambiando la casilla de partida
void opcion_tres()
{
	vector<vector<Casilla> > indice_camino;
	vector<Casilla> caminos;
	indice_camino.clear();
	caminos.clear();

	int resultado=0;

	resultado+=calcula_camino_inverso(1,7,indice_camino,caminos);
	cout << "El numero de caminos posibles es: " << resultado << endl;


	cin.ignore();
	for (unsigned int i = 0; i < indice_camino.size(); i++)
	{
		cout << "\n\tCAMINO POSIBLE Nº " << i+1 << "\n" << endl;
		muestra_caminos(indice_camino[i],2);
		muestra_tablero(indice_camino[i]);
		cout << "__________________________________________________________"<<endl;
		do
		{
			cout << "Presione ENTER para ver el siguiente camino..." << endl;
			tecla = getchar();
		}while(tecla!=13 and tecla!=10 and tecla!=141);			
	}
}
