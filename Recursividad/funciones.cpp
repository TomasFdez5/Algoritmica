
#include <iostream>
#include <vector>
#include <fstream>
#include "funciones.hpp"

using namespace std;

//Recuerda: ¿por qué un vector se pasaba como referencia y otro no?
//& porque vamos a querer modificar siempre el mismo vector de indices
//Mientras que el otro no tiene porque ser el mismo, mas bien es diferente para cada camino.
int calcula_camino( int fila, int columa,vector<vector<Casilla> > &indice_camino,vector<Casilla> caminos)
{
	//Creo una casilla que contenga los datos pasados a la funcion
	Casilla p1;
	p1.a=fila;
	p1.c=columa;

	//Compruebo el caso absurdo, es decir, la casilla está fuera del tablero.
	if (p1.a<1 or p1.c<1 or p1.a>8 or p1.c>8)
	{
		return 0;
	}
	
	caminos.push_back(p1);

	if (p1.a==1) 
	{
		/* Si llegamos a la fila 1 quiere decir que no hay caminos 
		hasta llegar a ella, luego guardamos el camino entero y devolvemos 1*/
		indice_camino.push_back(caminos);
		return 1;
	}
	//Que no ocurre nada de lo anterior, realizamos las llamadas recursivas necesarias.
	return calcula_camino(p1.a-1, p1.c-2,indice_camino,caminos) + calcula_camino(p1.a-1, p1.c+2,indice_camino,caminos) + calcula_camino(p1.a-2, p1.c-1,indice_camino,caminos) + calcula_camino(p1.a-2, p1.c+1,indice_camino,caminos);
	
}

int calcula_camino_inverso( int fila, int columa, vector<vector<Casilla> > &indice_camino,vector<Casilla> caminos)
{
	Casilla p1;
	p1.a=fila;
	p1.c=columa;
	//Caso absurdos
	if (p1.a<1 or p1.c<1 or p1.a>8 or p1.c>8)
	{
		return 0;
	}
	
	caminos.push_back(p1);

	if (p1.a==8)
	{
		/*
			Como en este caso vamos avanzando sobre el tablero en vez de retroceder
			comprobamos si hemos llegado a la ultima fila
		*/
		indice_camino.push_back(caminos);
		return 1;
	}
	//Realizamos las llamadas recursivas aumentando las posiciones en vez de restarlas
	return calcula_camino_inverso(p1.a+1, p1.c+2,indice_camino,caminos) + calcula_camino_inverso(p1.a+1, p1.c-2,indice_camino,caminos) + calcula_camino_inverso(p1.a+2, p1.c+1,indice_camino,caminos) + calcula_camino_inverso(p1.a+2, p1.c-1,indice_camino,caminos);
	
}

void muestra_caminos(vector<Casilla> caminos, int tipo)
{
	int tamano=caminos.size();
	switch(tipo){
		case 1:
			for (int i = tamano-1; i >=0; i--)
			{
				cout << "--> (" << caminos[i].a << "," << caminos[i].c << ") ";
			}
			cout <<"\n"<< endl;
		
		break;
		case 2:
			for (unsigned int i = 0; i < tamano; i++)
			{
				cout << "--> (" << caminos[i].a << "," << caminos[i].c << ") ";
			}
			cout <<"\n"<< endl;
		break;
		default:
			for (unsigned int i = 0; i < tamano; i++)
			{
				cout << "--> (" << caminos[i].a << "," << caminos[i].c << ") ";
			}
			cout <<"\n"<< endl;

	};
}


void muestra_tablero(vector<Casilla> caminos)
{
	string tablero[8][8];
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			tablero[i][j]=" ";
		}
	}
	for (unsigned int i = 0; i < caminos.size(); i++)
	{
		tablero[caminos[i].a-1][caminos[i].c-1]="x";
	}
	for (int i = 7; i >= 0; i--)
	{
		cout << "      ";//6 espacios
		for (int j = 0; j <=7; j++)
		{
			cout << "[" << tablero[i][j] << "]"; 
		}
		cout << endl;
	}
	cout << "\n\n" << endl;
}
