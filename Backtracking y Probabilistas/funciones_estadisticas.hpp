#ifndef FUNCIONES_ESTADISTICAS_HPP
#define FUNCIONES_ESTADISTICAS_HPP

#include <iostream>
#include <vector>

using namespace std;
	
	void ajusteFactorial_NReinas(const vector<double> &n_elementos, const vector<double> &tiemposReales, double &a0, double &a1);

	double calcula_sumatorio(const vector <double> v,double grado,const vector <double> v1,double grado1);

	void calcularTiemposEstimados_Factorial_NReinas(const vector <double> &n_elementos,const vector <double> &tiempos_reales, const double &a0, const double &a1, vector <double> &tiempos_estimados);

	double factorial(int numero);

	double calcularCoeficienteDeterminacion(const vector <double> &tiempos_reales, const vector <double> &tiempos_estimados);

	double media(const vector <double> &vector_tiempos);

	double varianza(const vector <double> &vector_tiempos);

	double calcularTiempoEstimado_Factorial_NReinas(const double &numero_a_estimar, const double &a0, const double &a1);


#endif