#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <vector> //para manejar la clase vector de la STL>
#include <cassert>
#include <ctime>
#include <fstream>
#include <cstdio>
#include <cstring> //Para usar memset
#include <stdint.h> // Para usar uint64_t

using namespace std;

	void rellenarVector(vector<int> &v);

	void estaOrdenado(const vector <int> &v);

	int divide(vector <int> &v, int start, int end);

	void quicksort(	vector <int> &v, int start, int end);

	void imprime(const vector <int> &v);

	void ajusteNlogN(const vector <double> &n_elementos, const vector <double> &tiemposReales, double &a0, double &a1);
	
	void calcularTiemposEstimadosNlogN(const vector <double> &n_elementos,const vector <double> &tiempos_reales,const double &a0, const double &a1, vector <double> &tiempos_estimados);
	
	double calcularTiempoEstimadoNlogN(const double &n, const double &a0, const double &a1);

#endif