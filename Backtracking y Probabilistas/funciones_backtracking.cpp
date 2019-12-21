#include "funciones_backtracking.hpp"
#include "funciones_general.hpp"
#include <vector> 
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void Backtracking_NReinas(int n_reinas, vector<vector<int> > &soluciones_reina, bool parar_primera_iteracion)
{
	//	n_reinas+1 para hacer el algoritmo 1-index
	vector<int> posiciones_reina(n_reinas+1,0);
	posiciones_reina[1]=0;	//Primera posicion de la reina en la columna 0

	int fila = 1;

	while( fila > 0 ) // Me controla que recorra todas las posibilidades
	{
		posiciones_reina[fila] = posiciones_reina[fila] + 1;

		while( posiciones_reina[fila]<= n_reinas && Posicion_correcta_reina(fila,posiciones_reina)==false )  
		{
			posiciones_reina[fila] = posiciones_reina[fila] + 1;
		}

		if (posiciones_reina[fila]<= n_reinas) // se puede colocar
		{
			if (fila == n_reinas) // es la ultima de las filas la incluimos en las soluciones
			{
				soluciones_reina.push_back(posiciones_reina);
				if(parar_primera_iteracion==true){break;} 
			}
			else // no es la ultima de las filas, seguimos explorando
			{
				fila = fila + 1;
				posiciones_reina[fila] = 0;
			}
		}
		else //No existen soluciones a traves de esta rama, retrocedemos
		{
			fila = fila - 1;
		}
	}
}