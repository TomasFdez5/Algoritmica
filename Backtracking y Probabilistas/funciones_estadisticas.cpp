#include "funciones_estadisticas.hpp"
#include "sistemaEcuaciones.hpp"
#include <fstream>

using namespace std;

void ajusteFactorial_NReinas(const vector<double> &n_elementos, const vector<double> &tiemposReales, double &a0, double &a1)
{
	vector<double> cambio_variable_factorial;
    vector<vector<double> > A (2,vector<double> (2));    
    vector<vector<double> > B (2,vector<double> (1));
    vector<vector<double> > X (2,vector<double> (1,0));

    for (unsigned int i = 0; i < n_elementos.size(); i++)
    {
        cambio_variable_factorial.push_back(factorial(n_elementos[i]));
    }

    A[0][0]=cambio_variable_factorial.size();
    A[1][0]=calcula_sumatorio(cambio_variable_factorial,1,tiemposReales,0);
    A[0][1]=calcula_sumatorio(cambio_variable_factorial,1,tiemposReales,0);
    A[1][1]=calcula_sumatorio(cambio_variable_factorial,2,tiemposReales,0);

    B[0][0]=calcula_sumatorio(tiemposReales,1,cambio_variable_factorial,0);
    B[1][0]=calcula_sumatorio(cambio_variable_factorial,1,tiemposReales,1);

    resolverSistemaEcuaciones(A,B,2,X);

    a0=X[0][0];
    a1=X[1][0];
}

double calcula_sumatorio(const vector <double> v,double grado,const vector <double> v1,double grado1)
{
    double suma=0.0;
    for (unsigned int i = 0; i < v.size(); i++)
    {   
        suma=suma+(pow(v[i],grado)*pow(v1[i],grado1));        
    }
    return suma;
}

void calcularTiemposEstimados_Factorial_NReinas(const vector <double> &n_elementos,const vector <double> &tiempos_reales, const double &a0, const double &a1, vector <double> &tiempos_estimados)
{
	for (unsigned int i = 0; i < n_elementos.size(); i++)
	{
	    tiempos_estimados.push_back(a0+(a1*factorial(n_elementos[i])));
	}
}

double factorial(int numero)
{
	double resultado_factorial=1;
	for (int i = 1; i <=numero; i++)
	{
		resultado_factorial = resultado_factorial * i;
	}
	return resultado_factorial;
}

double calcularCoeficienteDeterminacion(const vector <double> &tiempos_reales, const vector <double> &tiempos_estimados)
{
	return varianza(tiempos_estimados)/varianza(tiempos_reales);
}

double media(const vector <double> &vector_tiempos)
{
	double media=0.0;
	for (unsigned int i = 0; i < vector_tiempos.size(); i++)
	{
	    media=media+vector_tiempos[i];
	}
	return media/vector_tiempos.size();
}

double varianza(const vector <double> &vector_tiempos)
{
	double calculo_varianza=0.0;
	double calculo_media=media(vector_tiempos);
	for (unsigned int i = 0; i < vector_tiempos.size(); i++)
	{
	    calculo_varianza+=pow(vector_tiempos[i]-calculo_media,2);
	}
	return calculo_varianza/vector_tiempos.size();
}

double calcularTiempoEstimado_Factorial_NReinas(const double &numero_a_estimar, const double &a0, const double &a1)
{
	double conversion,resultado;
	conversion=a0+a1*factorial(numero_a_estimar);
	resultado=conversion*1.1574074074074074*pow(10,-11);
	return resultado;

}