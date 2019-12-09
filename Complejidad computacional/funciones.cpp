#include <iostream>
#include <vector> //para manejar la clase vector de la STL>
#include <cassert>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include "funciones.hpp"
using namespace std;


void mostrar_tabla(const vector <double> &n_elementos,const vector <double> &tiempos_reales)
{
    cout<<"N_ELEMENTOS | Tiempos reales\n--------------------------"<<endl;
    for (unsigned int i = 0; i < tiempos_reales.size(); i++)
    {
        cout<<"    "<<n_elementos[i]<<"\t\t"<<tiempos_reales[i]<<endl;
    }
}



void escribeFichero(const vector <double> &n_elementos,const vector <double> &tiempos_reales,string nombre)
{
    // Crea un fichero de salida
    ofstream fichero(nombre.c_str());
    for (unsigned int i = 0; i < tiempos_reales.size(); i++)
    {
        fichero<<n_elementos[i]<<" "<<tiempos_reales[i]<<endl;
    }
    fichero.close();
}



void escribeFichero(const vector <double> &n_elementos,const vector <double> &tiempos_reales,const vector <double> &tiempos_estimados,string nombre)
{
    // Crea un fichero de salida
    ofstream fichero(nombre.c_str());
    for (unsigned int i = 0; i < tiempos_reales.size(); i++)
    {
        fichero<<n_elementos[i]<<" "<<tiempos_reales[i]<<" "<<tiempos_estimados[i]<<endl;
    }
    fichero.close();
}



double sumatorio(const vector <double> v,double grado,const vector <double> v1,double grado1)
{
    double suma=0.0;
    for (unsigned int i = 0; i < v.size(); i++)
    {   
        suma=suma+(pow(v[i],grado)*pow(v1[i],grado1));        
    }
    return suma;
}



double calcularCoeficienteDeterminacion(const vector <double> &tiempos_reales, const vector <double> &tiempos_estimados)
{
    double varianza_real=0.0;
    double varianza_estimada=0.0;
    double media_real=0.0;
    double media_estimada=0.0;
    //cout << tiempos_reales.size() << " " << tiempos_estimados.size()<<endl;
    for (unsigned int i = 0; i < tiempos_reales.size(); i++)
    {
        media_real=media_real+tiempos_reales[i];
        media_estimada=media_estimada+tiempos_estimados[i];
    }
    media_real=media_real/tiempos_reales.size();
    media_estimada=media_estimada/tiempos_estimados.size();


    for (unsigned int i = 0; i < tiempos_reales.size(); i++)
    {
        varianza_real+=pow(tiempos_reales[i]-media_real,2);
        varianza_estimada+=pow(tiempos_estimados[i]-media_estimada,2);
    }
    varianza_real=varianza_real/tiempos_reales.size();
    varianza_estimada=varianza_estimada/tiempos_estimados.size();

    return varianza_estimada/varianza_real;
}


void imprimirMatriz(vector<vector <double> > &v)
{
    for (unsigned int i = 0; i < v.size(); i++)
    {
        cout<<endl;
        for (unsigned int j = 0; j < v.size(); j++)
        {
            cout<<"["<<v[i][j]<<"]";
        }
    }
    cout<<endl;
}

void rellenarMatriz(vector<vector <double> > &v)
{
    srand(time(NULL));
    double variable=0.0;
    for (unsigned int i = 0; i < v.size(); i++)
    {
        for (unsigned int j = 0; j < v.size(); j++)
        {
            variable=rand()%11;
            variable=variable/100;
            variable=variable+0.95;
            v[i][j]=variable;
        }
    }
    //imprimirMatriz(v);
}