#include "funciones_probabilista.hpp"
#include "funciones_general.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector> 

using namespace std;

void Probabilista_NReinas(int n_reinas, vector<int>  &solucion_reina, bool &existe)
{
	vector<int> ok(n_reinas+1,0);

	int contador = 0;
	int columna = 0;

	for (int i = 1; i <=n_reinas; i++) // Inicializacion de la solucion a 0
	{
		solucion_reina[i] = 0;
	}

	for (int k = 1; k <= n_reinas; k++)
	{
		contador = 0;

		for (int j = 1; j <= n_reinas; j++)
		{
			solucion_reina[k]=j;
			if (Posicion_correcta_reina(k,solucion_reina) == true)
			{
				contador = contador + 1;
				ok[contador] = j;
			}
		}

		if (contador == 0 ){break;}

		columna = ok[1+rand()%contador];
		solucion_reina[k] = columna;
	}

	if (contador == 0){existe = false;} 	// 	No hay solucion
	else{existe = true;}					//	Si hay solucion
}
