#ifndef MATRICES_STRASSEN_H
#define MATRICES_STRASSEN_H

#include <iostream>
#include <vector> //para manejar la clase vector de la STL
#include <cassert>
#include <ctime>
#include <cstdio>
#include <cstring> //Para usar memset
#include <stdint.h> // Para usar uint64_t

using namespace std;

	void ajustePolinomicoStrassen(const vector <double> &n_elementos, const vector <double> &tiemposReales, vector <double> &constantes);

	void calcularTiemposEstimadosPolinomicoStrassen(const vector <double> &n, const	vector <double> &tiemposReales, const vector <double> &a, vector <double> &tiemposEstimados);

	double calcularTiempoEstimadoPolinomicoStrassen (const double &n, const vector <double> &constantes);

#endif