#include <iostream>
#include <vector> //para manejar la clase vector de la STL>
#include <cassert>
#include <cstdlib>
#include <math.h>
#include <ctime>
#include <fstream>
#include "matrices_strassen.hpp"
#include "funciones.hpp"
#include "sistemaEcuaciones.hpp"

#include "strassen.hpp"
/*
    El código fuente del producto de matrices por Strassen se encuentra
    en los ficheros strassen.cpp y strassen.hpp
*/

void ajustePolinomicoStrassen(const vector <double> &n_elementos, const vector <double> &tiemposReales, vector <double> &constantes)
{
	vector<vector<double> > A (4,vector<double> (4));    
    vector<vector<double> > B (4,vector<double> (1));
    vector<vector<double> > X (4,vector<double> (1));

    A[0][0]=n_elementos.size();
    A[1][0]=sumatorio(n_elementos,1,tiemposReales,0);
    A[2][0]=sumatorio(n_elementos,2,tiemposReales,0);
    A[3][0]=sumatorio(n_elementos,2.81,tiemposReales,0);

	A[0][1]=sumatorio(n_elementos,1,tiemposReales,0);
    A[1][1]=sumatorio(n_elementos,1,n_elementos,1);
    A[2][1]=sumatorio(n_elementos,2,n_elementos,1);
    A[3][1]=sumatorio(n_elementos,2.81,n_elementos,1);

    A[0][2]=sumatorio(n_elementos,2,tiemposReales,0);
    A[1][2]=sumatorio(n_elementos,1,n_elementos,2);
    A[2][2]=sumatorio(n_elementos,2,n_elementos,2);
    A[3][2]=sumatorio(n_elementos,3,n_elementos,2);

    A[0][3]=sumatorio(n_elementos,2.81,n_elementos,0);
    A[1][3]=sumatorio(n_elementos,1,n_elementos,2.81);
    A[2][3]=sumatorio(n_elementos,2,n_elementos,2.81);
    A[3][3]=sumatorio(n_elementos,2.81,n_elementos,2.81);

    B[0][0]=sumatorio(tiemposReales,1,n_elementos,0);
    B[1][0]=sumatorio(n_elementos,1,tiemposReales,1 );
    B[2][0]=sumatorio(n_elementos,2,tiemposReales,1 );
    B[3][0]=sumatorio(n_elementos,2.81,tiemposReales,1 );

    resolverSistemaEcuaciones(A,B,4,X);

    //cout<<X.size()<< " " << constantes.size();
    for ( unsigned int i = 0; i < X.size(); i++)
    {
    	constantes.push_back(X[i][0]);
    }
}


void calcularTiemposEstimadosPolinomicoStrassen(const vector <double> &n_elementos, const	vector <double> &tiemposReales, const vector <double> &constantes, vector <double> &tiemposEstimados)
{
	for (unsigned int i = 0; i < n_elementos.size(); i++)
	{
	    tiemposEstimados.push_back(constantes[0]+(constantes[1]*n_elementos[i])+(constantes[2]*(pow(n_elementos[i],2))+(constantes[3]*(pow(n_elementos[i],2.81)))));
	}
	escribeFichero(n_elementos,tiemposReales,tiemposEstimados,"Datos_matriz_Strassen.txt");
}


double calcularTiempoEstimadoPolinomicoStrassen (const double &n, const vector <double> &constantes)
{
	double conversion,resultado;
	conversion=constantes[0]+(constantes[1]*n)+(constantes[2]*(pow(n,2))+(constantes[3]*(pow(n,2.81))));
	resultado=conversion*1.1574074074074074*pow(10,-11);
	return resultado;

}

