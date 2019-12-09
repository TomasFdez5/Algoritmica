#include <iostream>
#include <vector> //para manejar la clase vector de la STL>
#include <cassert>
#include <cstdlib>
#include <math.h>
#include <ctime>
#include <fstream>
#include <cstring> //Para usar memset
#include "quicksort.hpp"
#include "sistemaEcuaciones.hpp"
#include "funciones.hpp"

using namespace std;

void rellenarVector(vector<int> &v)
{
	srand(time(NULL));
	for (unsigned int i = 0; i < v.size(); i++)
	{
		v[i]=rand()%10000;
	}

}

void estaOrdenado(const vector <int> &v)
{
	for (unsigned int i = 0; i < v.size()-1; i++)
	{
		assert(v[i]<=v[i+1]);
	}
}

// Función para dividir el v y hacer los intercambios
int divide(vector <int> &v, int start, int end) {
    int left;
    int right;
    int pivot;
    int temp;
 
    pivot = v[start];
    left = start;
    right = end;
 
    // Mientras no se cruzen los índices
    while (left < right) {
        while (v[right] > pivot) {
            right--;
        }
 
        while ((left < right) && (v[left] <= pivot)) {
            left++;
        }
 
        // Si todavía no se cruzan los indices seguimos intercambiando
        if (left < right) {
            temp = v[left];
            v[left] = v[right];
            v[right] = temp;
        }
    }
 
    // Los índices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
    temp = v[right];
    v[right] = v[start];
    v[start] = temp;
 
    // La nueva posición del pivot
    return right;
}
 
// Función recursiva para hacer el ordenamiento
void quicksort(vector <int> &v, int start, int end)
{
    int pivot;
 
    if (start < end) {
        pivot = divide(v, start, end);
 
        // Ordeno la lista de los menores
        quicksort(v, start, pivot - 1);
 
        // Ordeno la lista de los mayores
        quicksort(v, pivot + 1, end);
    }
}


void imprime(const vector <int> &v)
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		cout<<v[i]<<" ";
	}
}

void ajusteNlogN(const vector<double> &n_elementos, const vector<double> &tiemposReales, double &a0, double &a1)
{
    vector<double> nlogn;
    vector<vector<double> > A (2,vector<double> (2));    
    vector<vector<double> > B (2,vector<double> (1));
    vector<vector<double> > X (2,vector<double> (1,0));

    for (unsigned int i = 0; i < n_elementos.size(); i++)
    {
        nlogn.push_back(n_elementos[i]*log(n_elementos[i]));
    }
    A[0][0]=nlogn.size();
    A[1][0]=sumatorio(nlogn,1,tiemposReales,0);
    A[0][1]=sumatorio(nlogn,1,tiemposReales,0);
    A[1][1]=sumatorio(nlogn,2,tiemposReales,0);
    B[0][0]=sumatorio(tiemposReales,1,nlogn,0);
    B[1][0]=sumatorio(nlogn,1,tiemposReales,1 );

    resolverSistemaEcuaciones(A,B,2,X);
    a0=X[0][0];
    a1=X[1][0];
}

void calcularTiemposEstimadosNlogN(const vector <double> &n_elementos,const vector <double> &tiempos_reales, const double &a0, const double &a1, vector <double> &tiempos_estimados)
{
    for (unsigned int i = 0; i < n_elementos.size(); i++)
    {
        tiempos_estimados.push_back(a0+(a1*n_elementos[i]*log(n_elementos[i])));
    }
    escribeFichero(n_elementos,tiempos_reales,tiempos_estimados,"Datos.txt");
}


double calcularTiempoEstimadoNlogN(const double &tamano, const double &a0, const double &a1)
{
    double conversion,resultado;
    conversion=a0+a1*tamano*log(tamano);
    resultado=conversion*1.1574074074074074*pow(10,-11);
    return resultado;
}


