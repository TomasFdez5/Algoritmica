#ifndef MATRICES_H
#define MATRICES_H

#include <iostream>
#include <vector> //para manejar la clase vector de la STL>
#include <cassert>
#include <ctime>
#include <cstdio>
#include <cstring> //Para usar memset
#include <stdint.h> // Para usar uint64_t

using namespace std;


	void multiplicacion(vector<vector <double> > &v1,vector<vector <double> > &v2,vector<vector <double> > &v3,int orden);

	void ajustePolinomico(const vector <double> &n, const vector <double> &tiemposReales, vector <double> &a);

	void calcularTiemposEstimadosPolinomico(const vector <double> &n, const	vector <double> &tiemposReales, const vector <double> &a, vector <double> &tiemposEstimados);
	
	double calcularTiempoEstimadoPolinomico (const double &n, const vector <double> &constantes);

#endif