#ifndef FUNCIONES_H
#define FUNCIONES_H

using namespace std;

	typedef struct Casilla
	{
		int f; // altura = fila
		int c; // columa 

	}Casilla;

	void muestra_caminos(vector<Casilla> caminos, int tipo);

	int calcula_camino( int fila, int columa, vector<vector<Casilla> > &indice_camino,vector<Casilla> caminos);

	int calcula_camino_inverso( int fila, int columa, vector<vector<Casilla> > &indice_camino,vector<Casilla> caminos);

	void muestra_tablero(vector<Casilla> caminos );


#endif
