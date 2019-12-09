#include <iostream>
#include <vector> //para manejar la clase vector de la STL>
#include <cassert>
#include <cstdlib>
#include <math.h>
#include <ctime>
#include <fstream>
#include "matrices.hpp"
#include "quicksort.hpp"
#include "sistemaEcuaciones.hpp"
#include "funciones.hpp"
using namespace std;




void multiplicacion(vector<vector <double> > &v1,vector<vector <double> > &v2,vector<vector <double> > &v3,int orden)
{
	for(unsigned int i = 0; i < v1.size(); i++) //Recorre filas de la primera matriz
	{
		for(unsigned int j = 0; j < v1.size(); j++) //Recorre columnas de la segunda matriz
		{
			v3[i][j] = 0.0;
			for(unsigned int k = 0; k < v1.size(); k++){
				//Recorre los elementos a multiplicar (numero de columnas de la primera matriz)
				v3[i][j] = v3 [i][j] + v1[i][k]*v2[k][j];
			}
		}
	}
}


void ajustePolinomico(const vector <double> &n_elementos, const vector <double> &tiemposReales, vector <double> &constantes)
{
	vector<vector<double> > A (4,vector<double> (4));    
    vector<vector<double> > B (4,vector<double> (1));
    vector<vector<double> > X (4,vector<double> (1));

    A[0][0]=n_elementos.size();
    A[1][0]=sumatorio(n_elementos,1,tiemposReales,0);
    A[2][0]=sumatorio(n_elementos,2,tiemposReales,0);
    A[3][0]=sumatorio(n_elementos,3,tiemposReales,0);

	A[0][1]=sumatorio(n_elementos,1,tiemposReales,0);
    A[1][1]=sumatorio(n_elementos,2,tiemposReales,0);
    A[2][1]=sumatorio(n_elementos,3,tiemposReales,0);
    A[3][1]=sumatorio(n_elementos,4,tiemposReales,0);

    A[0][2]=sumatorio(n_elementos,2,tiemposReales,0);
    A[1][2]=sumatorio(n_elementos,3,tiemposReales,0);
    A[2][2]=sumatorio(n_elementos,4,tiemposReales,0);
    A[3][2]=sumatorio(n_elementos,5,tiemposReales,0);

    A[0][3]=sumatorio(n_elementos,3,tiemposReales,0);
    A[1][3]=sumatorio(n_elementos,4,tiemposReales,0);
    A[2][3]=sumatorio(n_elementos,5,tiemposReales,0);
    A[3][3]=sumatorio(n_elementos,6,tiemposReales,0);

    B[0][0]=sumatorio(tiemposReales,1,n_elementos,0);
    B[1][0]=sumatorio(n_elementos,1,tiemposReales,1 );
    B[2][0]=sumatorio(n_elementos,2,tiemposReales,1 );
    B[3][0]=sumatorio(n_elementos,3,tiemposReales,1 );

    resolverSistemaEcuaciones(A,B,4,X);

    
    for ( unsigned int i = 0; i < X.size(); i++)
    {
    	constantes.push_back(X[i][0]);
    }

}

void calcularTiemposEstimadosPolinomico(const vector <double> &n_elementos, const	vector <double> &tiempos_reales, const vector <double> &constantes, vector <double> &tiempos_estimados)
{
	for (unsigned int i = 0; i < n_elementos.size(); i++)
	{
	    tiempos_estimados.push_back(constantes[0]+(constantes[1]*n_elementos[i])+(constantes[2]*(pow(n_elementos[i],2))+(constantes[3]*(pow(n_elementos[i],3)))));
	}
	escribeFichero(n_elementos,tiempos_reales,tiempos_estimados,"Datos_matriz.txt");
}


double calcularTiempoEstimadoPolinomico (const double &n, const vector <double> &constantes)
{
	double conversion,resultado;
	conversion=constantes[0]+(constantes[1]*n)+(constantes[2]*(pow(n,2))+(constantes[3]*(pow(n,3))));
	resultado=conversion*1.1574074074074074*pow(10,-11);
	return resultado;
}